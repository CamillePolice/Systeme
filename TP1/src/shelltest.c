#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>

#define WRITE_END 1
#define READ_END 0

void rec_exec(char *command[], int fd[][2], int nb_command, int i);
void execute_command(char *command);

int length = 500;

int main() {

    int status;
    char command[length];

    do {
        fgets(command, length, stdin);

        size_t ln = strlen(command) - 1;
        if (command[ln] == '\n')
            command[ln] = '\0';

        if (strcmp(command, "exit") == 0)
            return 0;

        // Count the number of pipes + store these pipes
        char tmp_command[length];
        strcpy(tmp_command, command);
        char *pipes_command = strtok(tmp_command, "|");
        int pipes_length = 0;

        int i = 0;
        char *pipes[pipes_length + 1];
        int fd[pipes_length + 1][2];
        strcpy(tmp_command, command);
        pipes_command = strtok(tmp_command, "|");
        while (pipes_command != NULL) {
            pipe(fd[i]);
            pipes[i] = pipes_command;
            i++;
            pipes_length++;
            pipes_command = strtok(NULL, "|");
        }

        if (fork() == 0) {
            rec_exec(pipes, fd, pipes_length, 0);
        }
        else {
            wait(&status);
        }
    } while(1);
    return 0;
}

void execute_command(char *command) {
    char tmp_command[length];
    strcpy(tmp_command, command);
    char *args_of_the_command = strtok(tmp_command, " ");
    int args_length = 0;
    while (args_of_the_command != NULL) {
        args_length++;
        args_of_the_command = strtok(NULL, " ");
    }

    // storing the arguments
    char *args[args_length + 1];
    strcpy(tmp_command, command);
    args_of_the_command = strtok(tmp_command, " ");
    int i = 0;
    args[i] = args_of_the_command;
    args[args_length] = NULL;
    while (args_of_the_command != NULL) {
        args[i] = args_of_the_command;
        i++;
        args_of_the_command = strtok(NULL, " ");
    }

    if (execvp(args[0], args) == -1)
        printf("Error, invalid command\n");
}

void rec_exec(char *command[], int fd[][2], int nb_command, int i) {
    pipe(fd[i]);

    if (i<nb_command-1 && fork()==0){
        rec_exec(command, fd, nb_command, ++i);
        return;
    }
    else{
        if (i!=nb_command-1){
            close(fd[i][READ_END]);
            dup2(fd[i][WRITE_END], STDOUT_FILENO);
            close(fd[i][WRITE_END]);
        }
        if (i!=0){
            close(fd[i - 1][WRITE_END]);
            dup2(fd[i - 1][READ_END], STDIN_FILENO);
            close(fd[i - 1][READ_END]);
        }
        execute_command(command[i]);
    }
}
