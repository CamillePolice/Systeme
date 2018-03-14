#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <stdlib.h>

void error(char *msg);

int main(){
  int serverSocket, nBytes, bindingAddr;
  char buffer[1024];
  struct sockaddr_in serverAddr;
  struct sockaddr_storage datagramAddr;
  socklen_t addr_size;

  // Create UDP socket
  serverSocket = socket(AF_INET, SOCK_DGRAM, 0);

  if(serverSocket < 0)
    error("Creation socket error !");

  // Configure settings in address struct
  serverAddr.sin_family = AF_INET;
  serverAddr.sin_port = htons(1234);
  serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");

  // Bind socket with address struct
  bindingAddr = bind(serverSocket, (struct sockaddr *) &serverAddr, sizeof(serverAddr));

  if(bindingAddr < 0)
    error("Binding address error");

  // Initialize size variable to be used later on
  addr_size = sizeof datagramAddr;

  while(1){
    // Try to receive any incoming UDP datagram. Request Address will be stored in datagramAddr
    nBytes = recvfrom(serverSocket,buffer,1024,0,(struct sockaddr *)&datagramAddr, &addr_size);

    printf("message :%s\n", buffer);

    // Send the datagram received in nbBytes on the 1234 port
    // We use datagramAddr as the address
    sendto(serverSocket,buffer,nBytes,0,(struct sockaddr *)&datagramAddr,addr_size);
  }

  return 0;
}

// error function
void error(char *msg) {
  perror(msg);
  exit(1);
}