#include "audio.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>

int writeInit(int *sample_rate, int *sample_size, int *channels);

int main(int argc, char **argv) {
  //Variables
  int sample_rate, sample_size, channels, audio_write;

  // Writing from the WAV-File
  audio_write = writeInit(&sample_rate, &sample_size, &channels);
  if(audio_write < 0)
    exit(1);

  close(audio_write);

  // All fine
  return 0;
}


// Writing from the WAV-File
int writeInit(int *sample_rate, int *sample_size, int *channels) {
  int audwrite;
  audwrite = aud_writeinit(*sample_rate, *sample_size, *channels);
  if(audwrite < 0) {
      printf("Can't send it to the speaker\n");
  }
  return audwrite;
}