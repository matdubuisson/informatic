#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>

#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#include "macro.h"

signed char working = 1;

signed int socket_fd;
signed int clients_socket_fd[_SIZE];

void send_to_all_clients(unsigned char *buffer){

    // i can't be static because several threads in same time can use this function
    for(unsigned int i = 0; i < _SIZE; i++){
        if(i != _EMPTY){
            // Defensize behavior
            if((send(*(clients_socket_fd + i), buffer, _BUFFER_LENGHT, 0) < 0) && (*(clients_socket_fd + i) != _EMPTY)){
                printf("Error to send one data to client %d !!\n", i);
            }
        }
    }

    return;
}

void *recver(void *arg){
    unsigned int index = *((unsigned int*) arg); // Create a new variable and copy the value at this address
    signed int *client_socket_fd = (clients_socket_fd + index);
    unsigned int failure_count = 0;
    unsigned char *buffer = malloc(_BUFFER_LENGHT * sizeof(unsigned char));

    // Detach thread of main thread
    if(pthread_detach(pthread_self()) < 0){            
        printf("Error to detach recver thread !!\n");
        exit(-1);
    }

    while(working){
        strncpy(buffer, "", _BUFFER_LENGHT); // Clear buffer
        // Defensize behavior
        // In case of disconnection from client, recv() updates buffer to "" and strncmp() reads it after

        if((recv(*client_socket_fd, buffer, _BUFFER_LENGHT, 0) < 0) || (!strncmp(buffer, "", _BUFFER_LENGHT))){
            // Accept _FAILURE_LIMIT failures else it closes this client
            if(failure_count >= _FAILURE_LIMIT){
                printf("Failure : Disconnection with client %d !!\n", index);
                break;
            }
            printf("Attempt %d : Wait response from client %d...\n", failure_count, index);
            usleep(_FAILURE_U_DELAY);
            failure_count += 1;
        }
        else if(!strncmp(buffer, _EXIT_COMMAND, _BUFFER_LENGHT)){
            printf("Exiting of client %d\n", index);
            break;
        }
        else{
            failure_count = 0;
            printf("Client at index %d has sent : %s\n", index, buffer);
            send_to_all_clients(buffer); // Send update to all user
        }
    }

    // Free allocated space
    free(buffer);
    // Close this client
    close(*(clients_socket_fd + index));
    *(clients_socket_fd + index) = _EMPTY;

    return NULL;
}

void *accepter(void *arg){

    signed int new_client_socket_fd;
    struct sockaddr_in client_address;
    size_t client_address_length = sizeof(client_address);

    unsigned int index;
    unsigned char found;

    // Detach thread of main thread
    if(pthread_detach(pthread_self()) < 0){
        printf("Error to detach accepter thread !!\n");
        exit(-1);
    }

    // Init the clients list
    for(index = 0; index < _SIZE; index++){
        *(clients_socket_fd + index) = _EMPTY;
    }

    while(working){
        loop_top:
        if((new_client_socket_fd = accept(socket_fd, (struct sockaddr*) &client_address, (socklen_t *) &client_address_length)) < 0){
            printf("Error to accept one client !!\n");
            goto loop_top;
        }

        // Search an empty place in the clients list for the new client
        found = 0;
        for(index = 0; index < _SIZE; index++){
            if(*(clients_socket_fd + index) == _EMPTY){
                *(clients_socket_fd + index) = new_client_socket_fd;
                found = 1;
                break;
            }
        }

        // In case if there isn't quite enough space
        if(!found){
            printf("A client is rejected because the server has missed of spaces !!\n");
            close(new_client_socket_fd);
        }
        else{
            printf("(ACCEPTER) New client at index : %d\n", index);
            pthread_t th_r;
            pthread_create(&th_r, NULL, recver, &index);
            usleep(100000); // Let time to recver to copy the value of index in a new variable
        }
    }

    return NULL;
}

void finish_main(void){  
    printf("\n=========================\nClosing of the program...\n=========================\n");
    return;              
}

unsigned int main(void){

    atexit(finish_main);

    struct sockaddr_in address;

    // Open the server socket
    if((socket_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0){
        printf("Error to create socket !!\n");
        exit(-1);
    }

    // Configure address
    address.sin_family = AF_INET;
    address.sin_port = htons(_PORT);
    address.sin_addr.s_addr = inet_addr(_IP);

    // Bind socket with encoded address
    if(bind(socket_fd, (struct sockaddr*) &address, sizeof(address)) < 0){
        printf("Error to bind socket !!\n");
        exit(-1);
    }

    // Start the listening for maximum _SIZE clients
    if(listen(socket_fd, _SIZE) < 0){
        printf("Error to listen socket !!\n");
        exit(-1);
    }

    // Thread accepter
    pthread_t th;
    pthread_create(&th, NULL, accepter, NULL);

    // Start terminal for the admin of the server
    unsigned char cmd[_BUFFER_LENGHT];
    unsigned char cmd_format[_BUFFER_LENGHT];
    sprintf(cmd_format, "%c%ds", '%', _BUFFER_LENGHT - 1);
    printf("cmd_format => %s\n", cmd_format);
    while(working){
        printf("==> ");
        scanf(cmd_format, cmd);
        if(!strncmp(cmd, _EXIT_COMMAND, _BUFFER_LENGHT)){
            printf("Ask to exit...\n");
            send_to_all_clients(_EXIT_COMMAND);
            printf("All clients prevented !!\n");
            break;
        }
    }
    working = 0;

    // Close all clients
    for(unsigned int i = 0; i < _FAILURE_LIMIT; i++){
        close(*(clients_socket_fd + i));
    }
    // Close the server socket
    close(socket_fd);
    // Close all operations
    shutdown(socket_fd, SHUT_RDWR);

    usleep(_END_U_DELAY);

    return 0;
}
