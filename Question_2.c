//
// Created by ensea on 30/11/23.
//
#include "fonctions.h"

void Question_2(){
    char cmd[MAXSIZE]={0}; // empty array to store
    ssize_t nbChar; // variable that stores the number of characters read
    nbChar=read(STDIN_FILENO,cmd,MAXSIZE); // reads input and stores it in nbChar
    cmd[nbChar-1]='\0';// to terminate the string and to not have issues with execlp
    pid_t pid; // stores the process id in pid
    int status;// to hold exit status of the child process
    pid=fork();

    if (pid==0){ // child process execution
        execlp(cmd,cmd,NULL); // replace the child process with the command process
        exit(EXIT_FAILURE);}
    else {
        wait(&status);
        write(STDOUT_FILENO, ENSEA, strlen(ENSEA)); // writes ENSEA after child process exit
    }

    }


