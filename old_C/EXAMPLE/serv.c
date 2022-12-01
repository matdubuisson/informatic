#include <stdio.h>
#include <stdlib.h>

#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>

#include <fcntl.h> // OPEN();
#include <unistd.h> // CLOSE();

void main(void){

int maxUser = 5;

int sockInt = socket(AF_INET, SOCK_STREAM, 0);
struct sockaddr_in servConf;
servConf.sin_addr.s_addr = inet_addr("127.0.0.1");
servConf.sin_family = AF_INET;
servConf.sin_port = htons(1614);

bind(sockInt, (const struct sockaddr*)&servConf, sizeof(servConf));
puts("Serv binded;");

listen(sockInt, maxUser);
puts("Serv is listenning;");

int work = 1;
int response = 0;
int letPass;
while(work){

  struct sockaddr_in userConf;
  socklen_t sizeUserConf = sizeof(userConf);
  letPass = accept(sockInt, (struct sockaddr *)&userConf, &sizeUserConf);
  puts("====================================");
  puts("Connection estabished :");
  recv(letPass, &response, sizeof(response), 0);
  if(response == 0){
    close(letPass);
    puts("Connection closed;");
  }
  if(response != 0){
    printf("[ %d ]\n", response);
  }
}

close(sockInt);
return;
}
