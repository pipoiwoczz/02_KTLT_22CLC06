#ifndef _main.h_
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct schoolYear
{
    string nameSY;
    Class * pArrClass = nullptr;
    Semester s;
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
    Course * pS1Courses = nullptr;
    Course * pS2Courses = nullptr;
    Course * pS3Courses = nullptr;
};

#endif // _main.h_