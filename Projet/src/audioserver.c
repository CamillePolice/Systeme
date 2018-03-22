#include "audio.h"
#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdlib.h>

#define SIZE 16

int readInit(char *filename, int *sample_rate, int *sample_size, int *channels);

void error(char *msg);

// Server structure to send it to the client
struct server{
  int sample_rate;
  int sample_size;
  int channels;
};

// Param structure used to send data
struct param{
  char buffer[1024];
  int nb_bytes;
};

int main(){

  int serverSocket, bindingAddr;

  // Buffer size on 1024
  char buffer[1024];

  // Socket paramaters
  struct sockaddr_in serverAddr;
  struct sockaddr_storage datagramAddr;
  socklen_t addr_size;
  struct server structServer;
  struct param structParam;
  int audio_read;

  // Extension used on our sounds
  char *extension = ".wav";

  // Create UDP socket
  serverSocket = socket(AF_INET, SOCK_DGRAM, 0);

  // If failed to create, error triggered
  if(serverSocket < 0)
    error("Creation socket error !");

  // Configure settings in address struct
  serverAddr.sin_family = AF_INET;
  serverAddr.sin_port = htons(1234);
  serverAddr.sin_addr.s_addr = htonl(INADDR_ANY);

  // Bind socket with address struct
  bindingAddr = bind(serverSocket, (struct sockaddr *) &serverAddr, sizeof(serverAddr));

  // If failed to bind the socket, error triggered
  if(bindingAddr < 0)
    error("Binding address error");

  // Initialize size variable to be used later on
  addr_size = sizeof datagramAddr;

while (1) {
    // Try to receive any incoming UDP datagram. Request Address will be stored in datagramAddr
    recvfrom(serverSocket,buffer,sizeof(buffer),0,(struct sockaddr *)&datagramAddr, &addr_size);

    // Concatenation of the sound name and the extension
    strcat(buffer,extension);

    // Set the heading parameters
    audio_read = readInit(buffer, &structServer.sample_rate, &structServer.sample_size, &structServer.channels);


    // Send the datagram received in nbBytes on the 1234 port
    // We use datagramAddr as the address
    sendto(serverSocket,&structServer,sizeof(structServer),0,(struct sockaddr *)&datagramAddr,addr_size);

    do {
      structParam.nb_bytes = read(audio_read, structParam.buffer, SIZE*10);
      // Send the content read
      sendto(serverSocket,&structParam,sizeof(structParam),0,(struct sockaddr *)&datagramAddr,addr_size);
      // Receive the acquitment from the client
      // To carry to send datas
      recvfrom(serverSocket,buffer,sizeof(buffer),0,NULL, NULL);
    } while (structParam.nb_bytes > 0);
    close(audio_read);
}
  // All fine
  return 0;
}

// Opening the WAV-file for reading, read the file's heading
int readInit(char *filename, int *sample_rate, int *sample_size, int *channels) {
  int audread;
  audread = aud_readinit(filename, sample_rate, sample_size, channels);
  if(audread < 0) {
    printf("Can't open the following file -> %s\n", filename);
  }
  return audread;
}


// error function
void error(char *msg) {
  perror(msg);
  exit(1);
}
