#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>

int main() {

    int status;
    int length = 100;
    char command[length];

    do {
        fgets(command, length, stdin);
        size_t ln = strlen(command) - 1;

        if (command[ln] == '\n')
            command[ln] = '\0';

        if (strcmp(command, "exit") != 0) {
            char tmp_command[100];
            strcpy(tmp_command, command);
            char *token = strtok(tmp_command, " ");

            int args_length = 0;

            while (token != NULL) {
                args_length++;
                token = strtok(NULL, " ");
            }

            char *args[args_length + 1];
            strcpy(tmp_command, command);
            token = strtok(tmp_command, " ");

            int i = 0;
            args[i] = token;
            args[args_length] = NULL;
            while (token != NULL){
                args[i] = token;
                i++;
                token = strtok(NULL, " ");
            }

            if (fork() == 0) {
                if (execvp(args[0], args) == -1)
                    printf("Error, invalid command\n");
            }
            else
                wait(&status);
        }
        else {
          return 0;
        }
    } while (1);

    return 0;
}
