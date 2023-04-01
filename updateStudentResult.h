#ifndef _FUNCTION_H_
#define _FUNCTION_H_

#include <iostream>
#include "main.h"

struct Score {
    string No, studentID, fullName, totalMark, finalMark, midtermMark, otherMark;
    Score* next = nullptr;
};

void updateStudentResultCourse(schoolYear *SY, Semester *sem, Course *course);
void exportFileInfoToLL(Score* &head, string path);
void deleteLLScore(Score* &head);

#endif