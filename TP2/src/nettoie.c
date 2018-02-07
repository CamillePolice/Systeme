#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <strings.h>
#include <sys/sem.h>

#define TAILLE 1024

int main() {
  int shmid = shmget((key_t)1234,TAILLE+sizeof(int),0600);
  shmctl(shmid, IPC_RMID, NULL);

  int semid = semget((key_t)1456,1,0600);
  printf("%d\n", semid);

  semctl(semid, 0,IPC_RMID);
}
