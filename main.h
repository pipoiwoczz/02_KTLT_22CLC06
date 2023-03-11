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
<<<<<<< HEAD
    int season;
    schoolYear * SY;
    string startDate;
    string endDate;
    Semester * pNextSY = nullptr;
=======
    Course * pS1Courses = nullptr;
    Course * pS2Courses = nullptr;
    Course * pS3Courses = nullptr;
>>>>>>> bd8c0d1717307c61c069b2c2744c74d3034c795b
};

#endif // _main.h_