#ifndef _KHOA_
#define _KHOA_

void signUp();

void login(schoolYear *& headSY, Semester *& headSemester, Class *& headClass);

void createFolder();

bool isValidUsername(char *username, bool check);

bool isStaff();

#endif