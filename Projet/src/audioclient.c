#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <string.h>

void error(char *msg);

int main(){
  int clientSocket, portNum = 1234, nBytes;
  char buffer[1024];
  struct sockaddr_in serverAddr;
  socklen_t addr_size;

  // Create UDP socket
  clientSocket = socket(AF_INET, SOCK_DGRAM, 0);

  if(clientSocket < 0)
    error("Creation socket error !");


  /*Configure settings in address struct*/
  serverAddr.sin_family = AF_INET;
  serverAddr.sin_port = htons(portNum);
  serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");

  // Initialize size variable to be used later on
  addr_size = sizeof serverAddr;

  while(1){
    printf("Give your sound name:\n");
    fgets(buffer,1024,stdin);

    nBytes = strlen(buffer) + 1;

    // Send message to server
    sendto(clientSocket,buffer,nBytes,0,(struct sockaddr *)&serverAddr,addr_size);

    // Receive message from server
    nBytes = recvfrom(clientSocket,buffer,1024,0,NULL, NULL);

    printf("Received from server: %s\n",buffer);

  }

  return 0;
}

// error function
void error(char *msg) {
  perror(msg);
  exit(1);
}