#ifndef _studentInAClass_
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void displayListOfStudents(Student* pHead);
void addAStudent(Student*& pHead, ifstream& f_in);
void inputStudentsToClass(Student*& pHead);
#endif