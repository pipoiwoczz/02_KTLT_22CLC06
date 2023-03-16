#include "inputStudentsToCourse.h"

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
	Student* curr;
	while (!fin.eof()) {
		if (!pCourse->Students) {
			pCourse->Students = new Student;
			curr = pCourse->Students;
		}
		else {
			curr->next = new Student;
			curr = curr->next;
		}
		addAStudent(curr, fin);
		curr->next = nullptr;
	}
	fin.close();
}