#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <strings.h>
#include <sys/sem.h>

#define TAILLE 1024

void ecrire_tableau(int *compteur, char *tableau) {
  char message[64], *msg=message;

  snprintf(message, 64, "Je suis le processus %d!\n", getpid());

  while ((*compteur<TAILLE)&&(*msg)) {
    tableau[*compteur] = *msg;
    msg++;
    usleep(10000);
    (*compteur)++;
  }
}

int main() {
  int id, *compteur;
  char *tableau;
  struct sembuf up = {0,1,0};
  struct sembuf down = {0,-1,0};
  int my_sem;

  id = shmget((key_t)1234,TAILLE+sizeof(int),0600|IPC_CREAT);
  if (id<0) { perror("Error shmget"); exit(1); }

  // Shared segment adress
  compteur = (int*) shmat(id,0,0);
  // If it failed to share a segment
  if (compteur==NULL) {
    perror("Error shmat"); exit(1);
  }

  // Create a semaphore
  if(semget((key_t)1456,1,0600)==-1){
      my_sem = semget((key_t)1456,1,0600|IPC_CREAT);
      semop(my_sem, &up, 1);
  //my_sem = create_semaphore(1456, 1, 0600);
  }
  tableau = (char *)(compteur + 1);
  semop(my_sem, &down, 1);
  ecrire_tableau(compteur, tableau);
  semop(my_sem, &up, 1);


  printf("%s\n", tableau);

  if (shmdt(compteur)<0) {
    perror("Error shmdt"); exit(1);
  }
  return 0;
}
