#include "include\audio.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include  <fcntl.h>

int main(int argc, char **argv) {
  // Variables
  int sample_rate, sample_size, channels, audio_fd, nbBytes;
  char *pathTofileName;
  char *extension = ".wav";
  char buffer[50];

  nbBytes = sizeOf(buffer);


  // Streaming of each files passed in parameters
  for(int i=0;i< argc;i++) {
    printf("Streaming of the following file -> %s", argv[i]);

    // Opening the WAV-file for reading
    if(aud_readinit(pathTofileName, &sample_rate, &sample_size, &channels) < 0)
      printf("Can't open the following file -> %s", argv[i]);

    // Stream the music on the speaker
    if(audio_fd = aud_writeinit(sample_rate, sample_size, channels) < 0)
      printf("Can't send it to the speaker");

    read(audio_fd, buffer, nbBytes);
    close(audio_fd);
  }

  // All fine
  return 0;
}
