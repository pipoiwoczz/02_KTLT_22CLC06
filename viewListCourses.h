#ifndef _listOfCourses_
#define _listOfCourses_

#include "main.h"

struct listCourse {
    string ID;
    listCourse *next = nullptr;
};

void viewListCourses();

#endif