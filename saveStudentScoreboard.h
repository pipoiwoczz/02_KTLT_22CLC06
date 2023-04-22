#ifndef _saveStudentScoreboard_
#define _saveStudentScoreboard_

#include "main.h"
#include "CourseMenu.h"

int getCourseCredit(string curSY, string season, string courseID);
string searchStudent(string studentID);
void saveStudentScoreboard(string curSY, int season, string courseID);

#endif