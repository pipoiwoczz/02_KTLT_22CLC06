#ifndef _saveStudentToFile_
#define _saveStudentToFile_
#include "main.h"
#include <filesystem>
#include <iostream>
// #include <format>
#include <string>
using namespace std;
// using namespace filesystem;

void saveStudentToFile(Student* currStudent, fstream& fout);
void saveClassToFile(Class* pClass);
void saveCourseToFile(Course* pCourse);

#endif
