#include "saveStudentToFile.h"
#include <main.h>
#include <fstream>
using namespace std;

void saveStudentToFile(Student* currStudent, fstream& fout)
{
	fout << currStudent->No << ",";
	fout << currStudent->studentId << ",";
	fout << currStudent->firstName << " ";
	fout << currStudent->lastName << ",";
	fout << currStudent->gender << ",";
	fout << currStudent->dateOfBirth << ",";
	fout << currStudent->socialId << endl;
}

void saveClassToFile(Class* pClass)
{
	Student* currStudent = pClass->Students;
	string filename = pClass->name + ".txt";
	fstream fout;
	fout.open(filename, ios::out | ios::app);
	while (currStudent) {
		saveStudentToFile(currStudent, fout);
		currStudent = currStudent->next;
	}
	fout.close();
}

void saveCourseToFile(Course* pCourse)
{
	Student* currStudent = pCourse->students;
	string coursename = pCourse->courseName;
	path folder = format("../{}", coursename);

	if (!exists(folder)) {
		bool res = create_directory(folder);
		if (!res) {
			cout << "Error: Unable to create directory!" << endl;
			return;
		}
	}
	path filepath = folder / coursename;
	fstream fout(filepath.string(), ios::out | ios::app);
	while (currStudent) {
		saveStudentToFile(currStudent, fout);
		currStudent = currStudent->next;
	}
	fout.close();
}