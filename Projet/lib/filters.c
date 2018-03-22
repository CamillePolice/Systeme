#include <stdlib.h>
#include <string.h>
#include "filters.h"

void stereoToMono(char buff[], int length) {
	for (int i=0; i<length; i+=4) {
    int temp1, temp2;

		memcpy(&temp1, buff+i, 2);
		memcpy(&temp2, buff+i+2, 2);
		temp1 = (temp1+temp2)/2;
		memcpy(buff+i, &temp1, 2);
		memcpy(buff+i+2, &temp1, 2);
	}
}

// Switch the volume
void switchVolume(char buff[], int length, float volume) {
	for (int i=0; i<length; i+=2) {
		int sound;
		memcpy(&sound, buff+i, 2);
		sound = sound*volume;
		memcpy(buff+i, &sound, 2);
	}
}

void fasterThanTheOlder(char buffer[], int *length) {
	for (int i=0; i<*length; i+=4) {
		int sound;
		memcpy(&sound, buffer+i, 2);
		memcpy(buffer+i/2, &sound, 2);
	}
	*length = *length / 2;
}

void slowerThanTheOlder(char buff[], int length, char *added, int *nLen) {
	char *tmp = (char*)malloc(length*2);

	for (int i=0; i<length; i+=2) {
		int sound;
		memcpy(&sound, buff+i, 2);
		memcpy(tmp+2*i, &sound, 2);
		memcpy(tmp+2*i+2, &sound, 2);
	}
	memcpy(buff, tmp, length);
	*nLen = length;
	added = (char *) malloc(*nLen);
	memcpy(added, tmp+length, *nLen);
	free(tmp);
}
