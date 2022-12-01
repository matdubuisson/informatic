#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include <pthread.h>
// pthread_t => signed long int
#define sp() printf("Parent-Process : %d; Process : %d\n", getppid(), getpid())
#define size 40
#define thread_number 3

unsigned int count = 0;

struct pack{ 
    pthread_t th;
    unsigned char message[size];               
    unsigned int nbr;                          
};

void *thread_f(void *arg){ // This shape is essential for the working of pthread
    struct pack *pck; // This step is usefull because the function can't get directly
    pck = arg;        // elements on the pointer arg. The pck helps to manage it !!
    unsigned char *name; // No static here !!
    unsigned int *i;

    name = (*pck).message;
    i = &(*pck).nbr;
    for(*i = 0; *i < 4; (*i)++){
        printf("%s => ", name); sp();
        usleep(500000);
    }
    *i = (count += 2);
    printf("From %s addres of i=%d : %p\n", name, *i, &i);
    printf("Address of &(*pck).nbr : %p\n", &(*pck).nbr);
    pthread_exit(i);
    // Or : return i;
}

unsigned int main(void){

    unsigned int i;
    void *rts[thread_number];
    struct pack packs[thread_number];

    printf("Main process :\n");
    sp();

    for(i = 0; i < thread_number; i++){
        sprintf( (*(packs + i)).message , "Thread[%d]", i);
        // If it doesn't want to get parameters : replace (packs + i) by NULL !!
        if(pthread_create( &(*(packs + i)).th , NULL, thread_f, (packs + i))){
            printf("Error to create the thread %d !!\n", i);
        }
    }

    for(i = 0; i < thread_number; i++){
        if(pthread_join( (*(packs + i)).th , (rts + i))){
            printf("Error to join the thread %d !!\n", i);
        }
    }

    printf("All threads are done !!\n");

    unsigned int *p;
    for(i = 0; i < thread_number; i++){
        printf("From thread %d, returned address is : %p\n", i, *(rts + i));
        p = *(rts + i);
        printf("Value at this address => %d\n", *p);
    }

    return 0;
}
