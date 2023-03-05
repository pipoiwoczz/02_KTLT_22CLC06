#ifndef createSY.h
#include <iostream>
using namespace std;

struct schoolYear
{
    string nameSY;
    Class * pArrClass;
    Semester * pArrSemester;
};

bool isValidSY(string SY);

void createSY(schoolYear * pArrSY, int &n);

#endif createSY.h