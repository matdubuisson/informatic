#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include <pthread.h>

#define number_of_threads 4

unsigned int global_id = -1;

void *thread_f(void *arg){
    unsigned int id = (global_id += 1);
    unsigned int i; // If static, all thread will share the same variable !!
    pthread_t th_id = pthread_self();
    pthread_detach(pthread_self());
    for(i = 0; i < 7; i++){
        printf("Thread %d : %ld\n", id, th_id);
        usleep(1000000);
    }

    pthread_exit(NULL);
}

unsigned int main(void){

    unsigned int i;
    pthread_t threads[number_of_threads];

    for(i = 0; i < number_of_threads; i++){
        if(pthread_create((threads + i), NULL, thread_f, NULL)){ // Don't pass parameter
            printf("Error to create thread %d !!\n", i);
        }
    }

   
    // No need to join because join attach thread to main versus detach that detach thread of main 
    for(i = 0; i < number_of_threads; i++){
        if(pthread_join(*(threads + i), NULL)){ // Don't receive thread return
            printf("Error to join thread %d !!\n", i);
        }
    }
    

    usleep(2000000);
    printf("Cancel thread 2....\n");
    pthread_cancel(*(threads + 2));
    usleep(1000000);
    printf("Cancel thread 3....\n");
    pthread_cancel(*(threads + 3));

    if(pthread_equal(*(threads + 0), *(threads + 1))){
        printf("Thread 0 and thread 1 are equal !!\n");
    }
    else{
        printf("Thread 0 and thread 1 aren't equal !!\n");
    }

    if(pthread_equal(*(threads + 0), *(threads + 0))){
        printf("Thread 0 and thread 0 are equal !!\n");
    }    
    else{
        printf("Thread 0 and thread 0 aren't equal !!\n");
    }    

    usleep(6000000); // If main is finished, all threads are finished !!

    return 0;
}
