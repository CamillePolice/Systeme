#include "audio.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>

#define SIZE 16

int readInit(char *filename, int *sample_rate, int *sample_size, int *channels);
int writeInit(int *sample_rate, int *sample_size, int *channels);
void readAud(int audread, int audwrite, char * buf, int size);

int main(int argc, char **argv) {
  // Variables
  int sample_rate, sample_size, channels, audio_read, audio_write;
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

  // Writing from the WAV-File
  audio_write = writeInit(&sample_rate, &sample_size, &channels);
  if(audio_write < 0)
    exit(1);

  // Stream the music on the speaker
  readAud(audio_read, audio_write, buffer, SIZE);
  // Close readInit and writeInit
  close(audio_write);
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

// Writing from the WAV-File
int writeInit(int *sample_rate, int *sample_size, int *channels) {
  int audwrite;
  audwrite = aud_writeinit(*sample_rate, *sample_size, *channels);
  if(audwrite < 0) {
      printf("Can't send it to the speaker\n");
  }
  return audwrite;
}

// Stream the music on the speaker
void readAud(int audread, int audwrite, char * buf, int size) {
  int nb_bytes;
  do {
    nb_bytes = read(audread, buf, size);
    write(audwrite, buf, nb_bytes);
  } while (nb_bytes > 0);
}
