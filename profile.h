#include <string>
#include "main.h"
using namespace std;

#ifndef _KHOA_
#define _KHOA

void viewProfile(string username);

void editProfile(string username);

void profile_menu(string username);

bool isValidBirth(int day, int month, int year);

#endif