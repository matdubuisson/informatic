#include <stdio.h>
#include <stdlib.h>

#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <unistd.h>

void main(void){

int sockServ = socket(AF_INET, SOCK_STREAM, 0);

struct sockaddr_in serv;
serv.sin_addr.s_addr = inet_addr("127.0.0.1");
serv.sin_family = AF_INET;
serv.sin_port = htons(1614);

int cmd = 0;
int work = 1;
while(work){

  printf("CMD : ");
  scanf("%d", &cmd);
  puts("");

  if(cmd != 0){
    connect(sockServ, (const struct sockaddr*)&serv, sizeof(serv));
    send(sockServ, &cmd, sizeof(cmd), 0);
  }
  if(cmd == 0){
    work = 0;
  }
}

return;
}
