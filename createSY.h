#ifndef createSY.h
#include <iostream>
#include "createClasses.h"
using namespace std;

struct schoolYear
{
    string nameSY;
    Class * pArrClass = nullptr;
    Semester * pArrSemester = nullptr;
    schoolYear * pNextSY = nullptr;
};

bool isValidSY(string SY);

void createSY(schoolYear * pArrSY, int &n);

#endif createSY.h