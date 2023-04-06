#ifndef _classScoreboard_
#define _classScoreboard_

#include "main.h"
#include <iomanip>

struct courseInThisSem {
    string ID;
    courseInThisSem *next;
};

bool checkExist(courseInThisSem *head, string value);
void insertCourseAtBegin(courseInThisSem* &head, string value);
void viewClassScoreboard(schoolYear *SY, Class *className);
void deleteCourseLL(courseInThisSem* &head);

#endif