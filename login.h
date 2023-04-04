#ifndef _KHOA_
#define _KHOA_

void signUp(schoolYear *& headSY);

void login(schoolYear *& headSY);

void createFolder(char *name);

bool isValidUsername(char *username, bool check);

bool isStaff(schoolYear *& headSY);

#endif