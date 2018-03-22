#include "audio.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>


int writeInit(int sample_rate, int sample_size, int channels);
void error(char *msg);

// Client structure (as in the server)
struct client{
  int sample_rate;
  int sample_size;
  int channels;
};

// Param structure (as in the server)
struct param{
  char buffer[1024];
  int nb_bytes;
};

int main(int argc, char **argv){
  // Parameters of the connection
  int clientSocket, portNum = 1234;
  struct sockaddr_in serverAddr;
  socklen_t addr_size;
  int audio_write;
  char *ack = "OK";

  // Structure declaration
  struct client structClient;
  struct param structParam;

  // Create UDP socket
  clientSocket = socket(AF_INET, SOCK_DGRAM, 0);

  // If failed, error triggered
  if(clientSocket < 0)
    error("Creation socket error !");


  // Configure settings in address struct
  serverAddr.sin_family = AF_INET;
  serverAddr.sin_port = htons(portNum);
  serverAddr.sin_addr.s_addr = inet_addr(argv[1]);

  // Initialize size variable to be used later on
  addr_size = sizeof serverAddr;

  // Send message to server
  sendto(clientSocket,argv[2],strlen(argv[2])+1,0,(struct sockaddr *)&serverAddr,addr_size);

  // Receive message from server
  recvfrom(clientSocket,&structClient,sizeof(structClient),0,NULL, NULL);

  audio_write = writeInit(structClient.sample_rate,structClient.sample_size,structClient.channels);

  // printf("Received from server: %d\n", structClient.channels);

  do {
    // Receive datas from the server
    recvfrom(clientSocket,&structParam,sizeof(structParam),0,NULL, NULL);
    // Play on the speakers
    write(audio_write, structParam.buffer, structParam.nb_bytes);
    // Send acquitment to carry
    sendto(clientSocket,ack,sizeof(ack),0,(struct sockaddr *)&serverAddr,addr_size);
  } while (structParam.nb_bytes > 0);

  close(audio_write);

  // All fine
  return 0;
}

// Writing from the WAV-File
int writeInit(int sample_rate, int sample_size, int channels) {
  int audwrite;
  audwrite = aud_writeinit(sample_rate, sample_size, channels);
  if(audwrite < 0) {
      printf("Can't send it to the speaker\n");
  }
  return audwrite;
}

// error function
void error(char *msg) {
  perror(msg);
  exit(1);
}
