#include "audio.h"
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


int main(int argc, char **argv) {
  // Variables
  int sample_rate, sample_size, channels, audio_read, audio_write, nb_bytes;
  char *pathTofileName;
  char *extension = ".wav";
  char buffer[50];

  nb_bytes = sizeof(buffer);


  // Streaming of each files passed in parameters
  for(int i=0;i< argc;i++) {
    printf("Streaming of the following file -> %s", argv[i]);
    strcat(pathTofileName, argv[i]);
    strcat(pathTofileName, exetension);
    // Opening the WAV-file for reading
    if(audio_read = aud_readinit(pathTofileName, &sample_rate, &sample_size, &channels) < 0)
      printf("Can't open the following file -> %s", argv[i]);

    read(audio_read, buffer, nb_bytes);

    // Stream the music on the speaker
    if(audio_write = aud_writeinit(sample_rate, sample_size, channels) < 0)
      printf("Can't send it to the speaker");

    write(audio_write, buffer, nb_bytes);

    close(audio_write);
  }

  // All fine
  return 0;
}
