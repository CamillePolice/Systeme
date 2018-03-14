#include "audio.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>

int readInit(char *filename, int *sample_rate, int *sample_size, int *channels);

int main(int argc, char **argv) {
  // Variables
  int sample_rate, sample_size, channels, audio_read;
  char *extension = ".wav";
  char buffer[SIZE];

  // Verification of the parameters
  if(argc < 2) {
    printf("Parameters error");
    exit(1);
  }
  // Streaming of the file added in paramater
  strcat(argv[1],extension);


  // Opening the WAV-file for reading, read the file's heading
  audio_read = readInit(argv[1], &sample_rate, &sample_size, &channels);
  if(audio_read < 0)
    exit(1);

  // Close readInit and writeInit
  close(audio_read);

  // All fine
  return 0;
}


// Opening the WAV-file for reading, read the file's heading
int readInit(char *filename, int *sample_rate, int *sample_size, int *channels) {
  int audread;
  audread = aud_readinit(&filename[0], sample_rate, sample_size, channels);
  if(audread < 0) {
    printf("Can't open the following file -> %s\n", &filename[1]);
  }
  return audread;
}