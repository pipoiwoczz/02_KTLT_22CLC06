#include "main.h"
#include <cstdio>

void removeAStudentInCourse(Course*& pCourse)
{
	int studentID;
	cout << "Enter a student ID: ";
	cin >> studentID;
	Student* currSt = pCourse->students;
	if (studentID == currSt->studentId) {
		pCourse->students = pCourse->students->next;
		delete currSt;
		return;
	}
	Student* prevSt = currSt;
	currSt = currSt->next;
	while (currSt) {
		if (currSt->studentId == studentID) {
			prevSt->next = currSt->next;

			string profileSt = "./profile/" + to_string(studentID) + ".txt";
			ifstream fin(profileSt);
			string currYear, classSt;
			for (int i = 0; i < 3; i++)
				getline(fin, currYear);
			getline(fin, classSt);
			fin.close();
			string currSem;
			fin.open("./SY.txt");
			getline(fin, currSem);
			fin.close();
			string studentCourse = "./" + currYear + "/" + currSem + "/" + classSt + "/" + to_string(studentID) + "/" + pCourse->courseID + ".txt";
			remove(studentCourse);

			delete currSt;
			currSt = prevSt->next;
			return;
		}
		prevSt = currSt;
		currSt = currSt->next;
	}
}