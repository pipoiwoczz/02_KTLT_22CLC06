#include "removeAStudent.h"
#include "main.h"
#include <filesystem>
using namespace filesystem;

void removeProfile(string studentID)
{
	string profileSt = "./profile/" + studentID + ".txt";
	ifstream ifs(profileSt);

	string className, schoolYear;
	getline(ifs, schoolYear);
	getline(ifs, schoolYear);
	getline(ifs, schoolYear);
	getline(ifs, className);
	getline(ifs, className);
	string pathStInClass = "./" + schoolYear + "/" + className + "/" + studentID;

	remove_all(pathStInClass);
	remove(profileSt);
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