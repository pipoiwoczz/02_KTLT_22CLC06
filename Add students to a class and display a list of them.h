#ifndef Khiem_FUNCTION_
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Student {
	int No, studentId, socialId;
	string firstName, lastName;
	string gender, dateOfBirth;
	Student* next;
};

struct account {
	string username, password;
};

struct SchoolYear{
    string name;
    Semester* semester;
    Class* classes;
    SchoolYear* next;
};

struct Semester {
    string name;
    Course* course;
    Semester* next;
};

struct Course {
    string courseName;
    string dayOfWeek, session;
    int courseID;
    int credits, maxStudents = 50;
    int numberOfStudent = 0;
    Student* studentInCourse;
    Course* next;
};

struct Class {
    string name;
    Student* student;
    Class* next;
};

void displayListOfStudents(Student* pHead);
void changePassword(string& currPass);
void addAStudent(Student*& pHead, ifstream& f_in);
void inputStudentsToClass(Student*& pHead);
#endif // !Khiem_FUNCTION_