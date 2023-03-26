#include "inputStudentsToCourse.h"
#include "main.h"
#include "studentInAClass.h"

void inputStudentsToCourse(Course*& pCourse)
{
	ifstream fin;
	string path, temp;
	cout << "Enter the path of a CSV file containing students: ";
	cin >> path;
	fin.open(path);

	if (!fin.is_open()) {
		cout << "The file doesn't exist.";
		return;
	}
	Student* currStudent;
	while (!fin.eof()) {
		if (!currStudent) {
			pCourse->students = new Student;
			currStudent = pCourse->students;
		}
		else {
			currStudent->next = new Student;
			currStudent = currStudent->next;
		}
		addAStudent(currStudent, fin);
		currStudent->next = nullptr;
	}
	fin.close();
}