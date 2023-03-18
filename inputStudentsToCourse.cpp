#include "inputStudentsToCourse.h"
#include "main.h"
#include "studentInAClass.h"

void inputStudentsToCourse(Course* pCourse, Class*& pHeadClass)
{
	Class* currClass = pHeadClass;
	ifstream fin;
	string path, temp;
	cout << "Enter the path of a CSV file containing students: ";
	cin >> path;
	fin.open(path);

	if (!fin.is_open()) {
		cout << "The file doesn't exist.";
		return;
	}

	while (!fin.eof()) {
		getline(fin, temp);
		while (currClass) {
			Student* currStudent = currClass->Students;
			while (currStudent) {
				if (currStudent->studentId == stoi(temp)) {
					if (!currStudent->pHeadGrade) {
						currStudent->pHeadGrade = new Grade;
						currStudent->pHeadGrade->courseID = stoi(temp);
					}
					else {
						Grade* new_grade = new Grade;
						new_grade->courseID = stoi(temp);
						new_grade->next = currStudent->pHeadGrade;
						currStudent->pHeadGrade = new_grade;
					}
					break;
				}
				currStudent = currStudent->next;
			}
			currClass = currClass->next;
		}
	}
	fin.close();
}