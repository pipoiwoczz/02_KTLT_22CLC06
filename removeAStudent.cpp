#include "removeAStudent.h"
#include "main.h"
#include <string>
#include <direct.h>
#include <stdio.h>
// #include <filesystem>
// using namespace filesystem;

void removeProfile(string studentID)
{
	string profileSt = "profile//" + studentID + ".txt";
	cout << profileSt << endl;
	ifstream ifs(profileSt);

	string className, schoolYear;
	getline(ifs, schoolYear);
	getline(ifs, schoolYear);
	getline(ifs, schoolYear);
	getline(ifs, className);
	string pathStInClass = schoolYear + "//" + className + "//" + studentID;

	rmdir(pathStInClass.c_str());
	
	ifs.close();
	remove(profileSt.c_str());

}

void removeAStudent(Student*& pHead)
{
	Student* curr = pHead->next;
	Student* prev = pHead;
	int id;
	cout << "Enter the ID of student: ";
	cin >> id;
	if (pHead->studentId == id) {
		pHead = pHead->next;
		removeProfile(to_string(prev->studentId));
		delete prev;
		return;
	}
	while (prev) {
		if (curr->studentId == id) {
			prev->next = curr->next;
			removeProfile(to_string(curr->studentId));
			delete curr;
			return;
		}
		prev = curr;
		curr = curr->next;
	}		
}