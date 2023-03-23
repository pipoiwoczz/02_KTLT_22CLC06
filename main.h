#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Grade {
    int courseID;
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
    Grade* pHeadGrade;
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

struct Course {
    string courseName, className, teacherName;
    string dayOfWeek, session;
    int courseID;
    int credits, maxStudents = 50;
    int numberOfStudent = 0;
    Student* students = nullptr;
    Course* next = nullptr;
};

struct Semester
{
    int season;
    string SY;
    string startDate, endDate;
    Semester * next = nullptr;
    Course* Courses = nullptr;
};

struct schoolYear
{
    string name;
    Class * Classes = nullptr;
    Semester * Semesters = nullptr;
    Course * Courses = nullptr;
    schoolYear * next = nullptr;
};