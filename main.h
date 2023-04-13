#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#ifndef _main_
#define _main_
#include <iostream>
#include <fstream>
#include <string>
#include <direct.h>
using namespace std;

struct Grade {
    string courseID;
    float totalMark, finalMark, midtermMark, otherMark;
    float courseGPA;
    Grade* next = nullptr;
};

struct Student {
    int No, studentId;
    string socialId;
    string firstName, lastName;
    string gender, dateOfBirth;
    Student* next = nullptr;
    Grade* pHeadGrade = nullptr;
};

struct Class
{
    string name;
    Student * Students = nullptr;
    Class * next = nullptr;
};



struct Account {
    string username, password;
};

struct CourseClass {
    string teacherName;
    string className;
    string dayOfWeek, session;
    int maxStudents = 50;
    int numberOfStudent = 0;
    Student* students = nullptr;
    CourseClass * next = nullptr;
};

struct Course {
    string courseName;
    int credits;
    string courseID;
    CourseClass * CourseClass = nullptr;
    Course* next = nullptr;
};

struct Semester
{
    int season;
    // string SY;
    string startDate, endDate;
    Semester * next = nullptr;
    Course* Courses = nullptr;
};

struct schoolYear
{
    string name;
    Class * Classes = nullptr;
    Semester * Semesters = nullptr;
    schoolYear * next = nullptr;
};

#endif