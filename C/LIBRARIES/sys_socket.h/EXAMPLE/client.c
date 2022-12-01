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

void *sender(void *arg){
    signed int *socket_fd = arg;
    unsigned char *buffer = malloc(_BUFFER_LENGHT * sizeof(unsigned char));
    unsigned int failure_count = 0;

    // Detach thread of main thread
    if(pthread_detach(pthread_self()) < 0){
        printf("Error to detach recver thread !!\n");
        exit(-1);
    }

    while(working){
        printf("==> ");
        scanf("%40s", buffer);
        // Defensive behavior
        if(send(*socket_fd, buffer, _BUFFER_LENGHT, 0) < 0){
            // Accept _FAILURE_LIMIT failures
            if(failure_count >= _FAILURE_LIMIT){
                printf("Failure (SEND) : Disconnection with the server !!\n");
                break;
            }
            printf("Attempt %d (SEND) : Wait the server responses...\n", failure_count);
            usleep(_FAILURE_U_DELAY);
            failure_count += 1;
        }
        else if(!strncmp(buffer, _EXIT_COMMAND, _BUFFER_LENGHT)){
            break;
        }
    }

    // Free the allocated memory
    free(buffer);
    // No close of socket because main thread does it
    working = 0;

    return NULL;
}

void *recver(void *arg){
    signed int *socket_fd = arg;
    unsigned char *buffer = malloc(_BUFFER_LENGHT * sizeof(unsigned char));
    unsigned int failure_count = 0;

    // Detach thread of main thread
    if(pthread_detach(pthread_self()) < 0){
        printf("Error to detach recver thread !!\n");
        exit(-1);
    }

    while(working){
        strncpy(buffer, "", _BUFFER_LENGHT); // Clear buffer
        // Defensize behavior
        if((recv(*socket_fd, buffer, _BUFFER_LENGHT, 0) < 0) || (!strncmp(buffer, "", _BUFFER_LENGHT))){
            // Accept _FAILURE_LIMIT failures
            if(failure_count >= _FAILURE_LIMIT){
                printf("Failure (RECV) : Disconnection with the server !!\n");
                break;
            }
            printf("Attempt %d (RECV) : Wait the server responses...\n", failure_count);
            usleep(_FAILURE_U_DELAY);
            failure_count += 1;
        }
        else if(!strncmp(buffer, _EXIT_COMMAND, _BUFFER_LENGHT)){
            printf("The server has shutdown...\n");
            break;
        }
        else{
            failure_count = 0;
            printf("From server => %s\n", buffer);
        }
    }

    // Free the allocated memory
    free(buffer);
    // No close of socket because main thread does it
    working = 0;

    return NULL;
}

void finish_main(void){
    printf("\n=========================\nClosing of the program...\n=========================\n");
    return;
}

unsigned int main(void){

    atexit(finish_main);

    struct sockaddr_in address;

    // Create the socket
    if((socket_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0){
        printf("Error to create socket !!\n");
        exit(-1);
    }

    // Configure the address
    address.sin_family = AF_INET;
    address.sin_port = htons(_PORT);
    address.sin_addr.s_addr = inet_addr(_IP);

    // Connect to the server
    if(connect(socket_fd, (const struct sockaddr*) &address, sizeof(address)) < 0){
        printf("Error to connect to the server !!\n");
        exit(-1);
    }

    pthread_t th_s, th_r;
    pthread_create(&th_s, NULL, sender, &socket_fd);
    pthread_create(&th_r, NULL, recver, &socket_fd);

    while(working);

    // Close socket
    close(socket_fd);
    // Stop all sending and receiving from this client
    shutdown(socket_fd, SHUT_RDWR);

    usleep(_END_U_DELAY);

    return 0;
}
