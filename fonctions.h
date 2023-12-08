//
// Created by ensea on 30/11/23.
//

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#define WELCOME_MSG "Bienvenue dans le Shell ENSEA\nPour quitter tapez 'exit'\nenseash % "
#define MAXSIZE 1024
#define ENSEA "\nenseash % "
#define EXIT_MSG "enseash % exit \nBye bye... \n$"

void Question_1();
void Question_2();
void Question_3();
void Question_4();
void Question_5();
void Question_6();
void Question_7();