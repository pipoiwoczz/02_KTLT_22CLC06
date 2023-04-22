#ifndef _profileStaff_
#define _profileStaff_

#include <cstring>
#include <stdio.h>
#include "main.h"
#include "login.h"
#include "createClasses.h"
#include "createSY.h"
#include "SYmenu.h"
#include "mainmenu.h"
#include "menuClass.h"

void viewProfile(string username);
void editProfile(string username);
void profile_menu(string username);
bool isValidBirth(int day, int month, int year);

#endif