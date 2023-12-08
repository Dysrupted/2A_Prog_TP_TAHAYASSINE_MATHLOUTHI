#include "fonctions.h"

void Question_6() {
    char cmd[MAXSIZE] = {0};
    ssize_t nbChar;
    struct timespec TimeStart, TimeStop;

    nbChar = read(STDIN_FILENO, cmd, MAXSIZE);
    cmd[nbChar - 1] = '\0';
    // /////////////////////////////////////////////////////////////////////////////////////////////////////////////
    // program stop it if the message sent is "exit" or ""
    // strcmp compare two string element: if they are different the result is 1 AND if they are same the result is 0
    if (strcmp(cmd, "exit") == 0 || strcmp(cmd, "") == 0) {
        write(STDOUT_FILENO, EXIT_MSG, strlen(EXIT_MSG));
        exit(EXIT_SUCCESS);
    }
    // /////////////////////////////////////////////////////////////////////////////////////////////////////////////
    pid_t pid;
    int status;
    pid = fork();
    clock_gettime(CLOCK_REALTIME, &TimeStart);

    char *elements[10];
    elements[0] = strtok(cmd, " ");
    int i;
    for (i = 1; i < 10; i++) { elements[i] = strtok(NULL, " "); }
    if (pid == 0) {
        execvp(elements[0], elements);
        exit(EXIT_FAILURE);
    } else {
        wait(&status);
        clock_gettime(CLOCK_REALTIME, &TimeStop);
        //write(STDOUT_FILENO,ENSEA, strlen(ENSEA));
        int time = (TimeStop.tv_sec - TimeStart.tv_sec) * 1000 +
                   (TimeStop.tv_nsec - TimeStart.tv_nsec) / 1000000; //time conversion in ms
        if (WIFEXITED(status)) {
            sprintf(cmd, "%s[code exit : %d | %d ms]\t", ENSEA, WEXITSTATUS(status), time);
            write(STDOUT_FILENO, cmd, strlen(cmd));
        } else if (WIFSIGNALED(status)) {
            sprintf(cmd, "%s[signal exit : %d | %d ms]\t", ENSEA, WTERMSIG(status), time);
            write(STDOUT_FILENO, cmd, strlen(cmd));
        }
    }
}


