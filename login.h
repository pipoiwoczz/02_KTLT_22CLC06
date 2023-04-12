#ifndef _KHOA_
#define _KHOA_
#include "main.h"

void signUp(schoolYear *& headSY);

void login(schoolYear *& headSY);

void createFolder(char *name);

bool isValidUsername(char *username);

bool isStaff(schoolYear *& headSY);

#endif