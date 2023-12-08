//
// Created by ensea on 30/11/23.
//
#include "fonctions.h"
void Question_3(){
    char cmd[MAXSIZE]={0};
    ssize_t nbChar;
    nbChar=read(STDIN_FILENO, cmd, MAXSIZE);
    cmd[nbChar-1]='\0';
    if(strcmp(cmd, "exit")==0||strcmp(cmd, "")==0){ // compares the input with exit or an empty string, if it returns 0 it means the strings are the same
        write(STDOUT_FILENO,EXIT_MSG, strlen(EXIT_MSG));
        exit(EXIT_SUCCESS);

    }
    pid_t pid;
    int status;
    pid=fork(); // same in Question_2.c

    if(pid==0){
        execlp(cmd,cmd,NULL);
        exit(EXIT_FAILURE);
    }
    else{
        wait(&status);
        write(STDOUT_FILENO,ENSEA, strlen(ENSEA));
    }
}

