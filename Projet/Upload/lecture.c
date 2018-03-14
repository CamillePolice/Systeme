#include "audio.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>

#define SIZE 16

int main(int argc, char **argv) {
  // Variables
  int sample_rate, sample_size, channels, audio_read, audio_write, nb_bytes;
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
  audio_read = aud_readinit(argv[1], &sample_rate, &sample_size, &channels);
  if(audio_read < 0) {
    printf("Can't open the following file -> %s\n", argv[1]);
    exit(1);
  }

  // Writing from the WAV-File
  audio_write = aud_writeinit(sample_rate, sample_size, channels);
  if(audio_write < 0) {
      printf("Can't send it to the speaker\n");
      exit(1);
  }

  // Stream the music on the speaker
  do {
    nb_bytes = read(audio_read, buffer, SIZE);
    write(audio_write, buffer, nb_bytes);
  } while (nb_bytes > 0);

  // Close readInit and writeInit
  close(audio_write);
  close(audio_read);

  // All fine
  return 0;
}
