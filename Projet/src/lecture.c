#include "audio.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char **argv) {
  // Variables
  int sample_rate, sample_size, channels;
  char *pathTofileName;
  char *extension = ".wav";

  // Streaming of each files passed in parameters
  for(int i=0;i< argc;i++) {
    printf("Streaming of the following file -> %s", argc[i]);

    // Opening the WAV-file for reading
    if(aud_readinit(pathTofileName, &sample_rate, &sample_size, &channels) < 0)
      printf("Can't open the following file -> %s", argc[i]);

    // Stream the music on the speaker
    if(audio_fd = aud_writeinit(sample_rate, sample_size, channels) < 0)
      printf("Can't send it to the speaker");

    close(audio_fd);
  }

  // All fine
  return 0;
}
