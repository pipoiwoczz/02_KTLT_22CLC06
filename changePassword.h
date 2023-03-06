#ifndef Khiem_FUNCTION_
#include <iostream>
#include <string>
using namespace std;

struct Date {
	int day, month, year;
};

struct Student {
	int No, studentID, socialID;
	Date birthday;
	string firstName, lastName, gender;
};

struct Account {
	string username, password;
};

void changePassword(string& currPass);
#endif // !Khiem_FUNCTION_

