#ifndef MAIN_H
#define MAIN_H

#define MAX_COMMAND_LENGTH 128
#define MAX_LINE_LENGTH 256
#define MAX_COMMAND_NUMBER 200

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string>
#include <string.h>
#include <iostream>
#include <fstream>
#include <dirent.h>

const char *listdirCmd="listdir";
const char *mycomputernameCmd="mycomputername";
const char *whatsmyipCmd="whatsmyip";
const char *printfileCmd="printfile";
const char *dididothatCmd="dididothat";
const char *hellotextCmd="hellotext";
const char *exitCmd="exit";

char *command;
char *fileName;
char line[MAX_LINE_LENGTH];

char **allCommands; 

int commandNumber;

#endif