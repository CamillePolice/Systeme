#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>

int main() {

    int status;
    int length = 100;
    char command[length];
    char command2[length];
    int fd[2];
    char buf[100];

    do {
        printf("First command => ");
        fgets(command, length, stdin);
        size_t ln = strlen(command) - 1;

        printf("Second command => ");
        fgets(command2, length, stdin);
        size_t ln2 = strlen(command2) - 1;

        if (command[ln] == '\n')
            command[ln] = '\0';

        if (command2[ln2] == '\n')
          command2[ln2] = '\0';

        if (strcmp(command, "exit") != 0 && strcmp(command2, "exit") != 0) {
            char tmp_command[100];
            char tmp_command2[100];

            strcpy(tmp_command, command);
            strcpy(tmp_command2, command2);

            char *tokenFirstCommand = strtok(tmp_command, " ");
            char *tokenSecondCommand = strtok(tmp_command2, " ");

            int args_length = 50;
            int args_length2 = 50;
/*
            while (tokenFirstCommand != NULL) {
                args_length++;
                tokenFirstCommand = strtok(NULL, " ");
            }
            while (tokenSecondCommand != NULL) {
                args_length2++;
                tokenSecondCommand = strtok(NULL, " ");
            }


            strcpy(tmp_command, command);
            tokenFirstCommand = strtok(tmp_command, " ");

            char *args2[args_length2 + 1];
            strcpy(tmp_command2, command2);
            tokenSecondCommand = strtok(tmp_command2, " ");
*/
            char *args[args_length + 1];
            char *args2[args_length2 + 1];
            int i = 0;
            args[i] = tokenFirstCommand;

            while (tokenFirstCommand != NULL){
                args[i] = tokenFirstCommand;
                i++;
                tokenFirstCommand = strtok(NULL, " ");
            }

            args[i] = NULL;

            int j = 0;
            args2[j] = tokenSecondCommand;

            while (tokenSecondCommand != NULL){
                args2[j] = tokenSecondCommand;
                j++;
                tokenSecondCommand = strtok(NULL, " ");
            }
            args2[j] = NULL;

            if(pipe(fd)<0)
              return 0;

            if (fork() == 0) {
                close(fd[0]);
                dup2(fd[1],1);
                if (execvp(args[0], args) == -1)
                    printf("Error, invalid command\n");
            }
            if(fork() == 0) {
                close(fd[1]);
                dup2(fd[0], 0);
                if(execvp(args2[0], args2) == -1)
                  printf("Error, invalid command\n");
            }
            else{
                close(fd[0]);
                close(fd[1]);
                wait(&status);
              }
        }
        else {
          return 0;
        }
    } while (1);

    return 0;
}
