//
// Created by ensea on 30/11/23.
#include "fonctions.h"

void Question_4(){
    char cmd[MAXSIZE]={0};
    ssize_t nbChar;
    nbChar=read(STDIN_FILENO, cmd, MAXSIZE);
    cmd[nbChar-1]='\0';
    if(strcmp(cmd, "exit")==0||strcmp(cmd, "")==0) { //compare if it's exit or empty
        write(STDOUT_FILENO, EXIT_MSG, strlen(EXIT_MSG));
        exit(EXIT_SUCCESS); //exiting the program
    }
    pid_t pid; // storing the process id
    int status; // Storing the status
    pid=fork();

    if(pid==0){ // Child process
        execlp(cmd,cmd,NULL); // exec with the child process
        exit(EXIT_FAILURE); // exit if fail
    }
    else{ // parent process
        wait(&status);// wait for the child to finish
        if(WIFEXITED(status)){ // if the child process exited normally
            sprintf(cmd,"%s[code exit : %d]\t" ,ENSEA, WEXITSTATUS(status)); // exit status message
            write(STDOUT_FILENO,cmd, strlen(cmd));// signal termination message
        }
        else if(WIFSIGNALED(status)){ //  if it's terminated by a signal
            sprintf(cmd, "%s[signal exit : %d]\t",ENSEA, WTERMSIG(status)); // signal status message
            write(STDOUT_FILENO,cmd, strlen(cmd));
        }
    }

}
