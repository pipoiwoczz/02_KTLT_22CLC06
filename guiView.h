#pragma once
#include "gui.h"
#include <iomanip>
#include "guiMenu.h"

void viewSchoolYear(string username);
void chooseSchoolYear(string username);
void viewAndChooseSemesterPage(string username, string SY);
void viewAndChooseClassPage(string username, string SY);
void viewScoreboard(string username, string SY, string classID);
void viewListOfStudentsInClass(string username, string SY, string classID);
void viewAndChooseCourse(string username, string SY, int season);
void viewCourseInformation(string username, string SY, int season, string courseID);
void viewListOfStudentInACourse(string username, string SY, short season, string courseID);
void viewScoreboardOfACourse(string username, string SY, short season, string courseID);
void viewAndChooseCourseClass(string username, string SY, short season, string courseID);
void viewScoreboardOfACourseClass(string username, string SY, short season, string courseID, string className);
void viewStudentProfile(string username);
void viewStudentScoreboard(string username);
void viewListCousres(string username);
void exportListStudentToFile(string username, string SY, short season, string courseID);
void viewStudentInACourseClass(string username, string SY, short season, string courseID, string courseClassID);