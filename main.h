#ifndef _main.h_
#include <iostream>
#include <fstream>
#include <string>
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

struct Student {
    int No, studentId;
    string socialId;
    string firstName, lastName;
    string gender, dateOfBirth;
    Student* next;
};

struct account {
    string username, password;
};

#endif // _main.h_