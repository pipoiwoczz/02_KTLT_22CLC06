#pragma once
#include "gui.h"
#include "guiMenu.h"
#include "guiCreate.h"

void mainmenuOpt();
void LoginPage();
void RegisterPage();
void ProfileMenuPage(string username);
void ProfilePage(string username);
void changeProfilePage(string username);
void SYMenuPage(string username, string SY);
void ClassMenuPage(string username, string SY, string classID);
void SemesterMenuPage(string username, string SY, short season);
void CourseMenuPage(string username, string SY, short season, string courseID);
void CourseClassMenuPage(string username, string SY, short season, string courseID, string classID);
void studentMenuPage(string username);
void changeStudentInfo(string username);

string getProfilePageString(string username);