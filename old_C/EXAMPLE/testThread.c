#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

//gcc testThread.c -o test -lpthread

struct data{
  int a;
};

int work = 0;

int u = 0;

void *FCT(void *data){
  work = 1;
  struct data *myData = data;
  int e = 0;
  u++;
  while(e <= 40){
    printf("[ %d ]\n", u);
    usleep(500000);
    puts("THREAD");
    e++;
  }
  work = 0;
  return 0;
}

int main(void){

  int e = 0;
  while((e <= 2) || (work)){
    struct data myData;
    myData.a = e;
    puts("NEWTHREAD");
    pthread_t fct;
    pthread_attr_t passMyStruct;
    pthread_attr_init(&passMyStruct);
    pthread_attr_setdetachstate(&passMyStruct, PTHREAD_CREATE_DETACHED);
    pthread_create(&fct, &passMyStruct, FCT, &myData);
    pthread_join(fct, 0);
    pthread_attr_destroy(&passMyStruct);
    usleep(500000);
    e++;
  }
  usleep(10000000);
  return 0;
}
