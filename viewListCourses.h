#ifndef _listOfCourses_
#define _listOfCourses_

#include "main.h"

struct listCourse {
    string ID;
    listCourse *next = nullptr;
};

void viewListCourses();
void insertCourseBeg(listCourse* &course, string ID);
void insertCourse(listCourse* &Course, string ID);
void deleteLLCourse(listCourse* &course);
void viewCourseClass(string courseID);

#endif