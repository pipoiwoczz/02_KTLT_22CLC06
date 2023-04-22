#ifndef _Login_
#define _Login_

#include <cstring>
#include <conio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <direct.h>
#include <stdio.h>
#include <stdlib.h>
#include "main.h"
#include "profile.h"
#include "mainMenu.h"
#include "profileStudent.h"

void signUp();
void login();
void createFolder(char *name);
bool isValidUsername(char *username);
bool isStaff();

#endif