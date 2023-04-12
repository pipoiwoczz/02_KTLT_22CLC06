#ifndef _profileStudent_
#define _profileStudent_

#include <conio.h>
#include "main.h"
#include "mainmenu.h"
#include "profile.h"
#include "viewCoursesStudent.h"
#include "viewStudentScoreboard.h"

void profileStudent(string username, schoolYear* headSY);
void scoreboard_menu(string username, string Class, string SY);
void viewProfile(string studentID);
void changeProfile(string studentID);

#endif