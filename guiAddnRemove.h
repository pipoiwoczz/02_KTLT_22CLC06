#pragma once
#include "gui.h"
#include "guiMenu.h"

struct Score {
    string No, studentID, fullName, totalMark, finalMark, midtermMark, otherMark;
    Score* next = nullptr;
};

void importStudentsListInClass(string username, string SY, string classID);
void addAStudentToClass(string username, string SY, string classID);
void removeAStudentInClass(string username, string SY, string classID);
void removeACourse(string username, string SY, short season);
void UpdateCourseInfor(string username, string SY, short season);
void addACourseClass(string username, string SY, short season, string courseID);
void UpdateAStudentResult(string username, string SY, short season, string courseID);
void importStudentToCourseClass(string username, string SY, short season, string courseID, string className);
void addAStudentToCourseClass(string username, string SY, short season, string courseID, string className);
void removeAStudentInCourseClass(string username, string SY, short season, string courseID, string className);
void importScoreboardToCourseClass(string username, string SY, short season, string courseID, string className);