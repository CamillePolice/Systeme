#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>

int main() {

    int status;
    int length = 50;
    char command[length];

    do {
        fgets(command, length, stdin);
        size_t ln = strlen(command) - 1;

        if (command[ln] == '\n')
            command[ln] = '\0';

        char *args[] = {command, NULL};

        if(strcmp(command, "exit") == 0)
          return 0;

        if (fork() == 0) {
            if (execvp(args[0], args) == -1)
                printf("Error, invalid command \n");
        }
        else
            wait(&status);
    } while (1);
    return 0;
}
