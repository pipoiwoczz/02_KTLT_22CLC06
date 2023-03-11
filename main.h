#ifndef _main.h_
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct schoolYear
{
    string nameSY;
    Class * pArrClass = nullptr;
    schoolYear * pNextSY = nullptr;
};

struct Class
{
    string nameClass;
    Student * pHeadStudent = nullptr;
    Class * pNextClass = nullptr;
};

struct Student {
    int No, studentId;
    string socialId;
    string firstName, lastName;
    string gender, dateOfBirth;
    Student* next;
};

struct Account {
    string username, password;
};

struct Semester
{
    int season;
    schoolYear * SY;
    string startDate;
    string endDate;
    Semester * pNextSY = nullptr;
};

#endif // _main.h_