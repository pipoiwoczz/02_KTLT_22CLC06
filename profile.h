#include <string>
#include "main.h"
using namespace std;

#ifndef _KHOA_
#define _KHOA

void viewProfile(string username, schoolYear *& headSY);

void editProfile(string username, schoolYear *& headSY);

void profile_menu(string username, schoolYear *& headSY);

bool isValidBirth(int day, int month, int year);

#endif