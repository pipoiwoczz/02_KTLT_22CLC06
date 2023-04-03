#ifndef _studentInAClass_
#define _studentInAClass_
#include <iostream>
#include <fstream>
#include "main.h"
#include <string>
using namespace std;

void displayListOfStudents(Student* pHead, string SY, string cl);
void inputStudentsToClass(Student*& pHead, schoolYear *curSY, Class * curClass);

#endif