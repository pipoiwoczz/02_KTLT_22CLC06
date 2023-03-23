#ifndef _KHOA_
#define _KHOA_

void signUp(schoolYear *& headSY, Semester *& headSemester, Class *& headClass);

void login(schoolYear *& headSY, Semester *& headSemester, Class *& headClass);

void createFolder(char *name);

bool isValidUsername(char *username, bool check);

bool isStaff(schoolYear *& headSY, Semester *& headSemester, Class *& headClass);

#endif