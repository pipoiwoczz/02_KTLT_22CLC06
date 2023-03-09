#include "main.h"
#include <iostream>
using namespace std;

struct Semester
{
    Course * pS1Courses = nullptr;
    Course * pS2Courses = nullptr;
    Course * pS3Courses = nullptr;
};

void createSemeter(Semester s);