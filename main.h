#ifndef _main.h_
#include <iostream>
using namespace std;

struct schoolYear
{
    string nameSY;
    Class * pArrClass = nullptr;
    Semester * pArrSemester = nullptr;
    schoolYear * pNextSY = nullptr;
};

struct Class
{
    string nameClass;
    Student * pHeadStudent = nullptr;
    Class * pNextClass = nullptr;
};
