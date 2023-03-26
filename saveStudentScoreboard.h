#ifndef _saveStudentScoreboard_
#include "main.h"
#include <filesystem>
#include <format>

string searchStudentInClass(Class* pClass, string studentID);
void saveStudentScoreboard(Class* pClass, string pathOfScoreboard, string courseName);
#endif