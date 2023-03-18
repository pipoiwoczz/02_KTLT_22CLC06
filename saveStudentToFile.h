#ifndef _saveStudentToFile_
#include <filesystem>
#include <iostream>
#include <format>
#include <string>
using namespace std;
using namespace filesystem;

void saveStudentToFile(Student* currStudent, fstream& fout);
void saveClassToFile(Class* pClass);
void saveCourseToFile(Course* pCourse);
#endif
