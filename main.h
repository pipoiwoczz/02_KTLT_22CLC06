#ifndef _main.h_
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct schoolYear
{
    string name;
    Class * Classes = nullptr;
    schoolYear * next = nullptr;
};

struct Class
{
    string name;
    Student * Students = nullptr;
    Class * next = nullptr;
};

struct Student {
    int No, studentId;
    string socialId;
    string firstName, lastName;
    string gender, dateOfBirth;
    Student* next;
    Grade* pHeadGrade;
};

struct Account {
    string username, password;
};

struct Semester
{
    int season;
    string SY;
    string startDate, endDate;
    Semester * next = nullptr;
    Course* Courses = nullptr;
};

struct Course {
    string courseName, className, teacherName;
    string dayOfWeek, session;
    int courseID;
    int credits, maxStudents = 50;
    int numberOfStudent = 0;
    Course* next = nullptr;
};

struct Grade {
    int courseID;
    float totalMark, finalMark, midtermMark, otherMark;
    float courseGPA;
    Grade* next = nullptr;
};

#endif // _main.h_