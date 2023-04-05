#include "inputStudentsToCourse.h"
#include "main.h"
#include "studentInAClass.h"
#include <string>
#include <fstream>
#include <iostream>
using namespace std;

void inputStudentsToCourse(schoolYear *curSY, Semester * curSE, Course*& pCourse)
{
	cout << "Which Course Do You Want To Add Student: \n";
	Course * curC = pCourse;
	do {
		if (!pCourse) {
			cout << "There is no Course now!!\n";
			cout << "Please add a course before adding student\n";
			system("pause");
			return;
		} else {
			while (curC) {
				cout << curC -> courseID << endl;
				curC = curC -> next;
			}
			cout << "Your course is: ";
			string id;
			cin >> id;
			curC = pCourse;
			while (curC && curC -> courseID != id) {
				curC = curC -> next;
			}
			if (curC && curC -> courseID == id) {
				break;
			} else {
				cout << "You entered wrong Course ID!!\nPlease enter again\n\n";
			}
		}
	} while (1);
	
	ifstream fin;
	string path, temp;
	cout << "Enter the path of a CSV file containing students: ";
	cin >> path;
	fin.open(path);

	if (!fin.is_open()) {
		cout << "The file doesn't exist.";
		return;
	}
	Student* currStudent = pCourse -> students;
	while (!fin.eof()) {
		if (!currStudent) {
			pCourse->students = new Student;
			currStudent = pCourse->students;
		}
		else {
			currStudent->next = new Student;
			currStudent = currStudent->next;
		}
		string tmp;
		getline(fin, tmp, ',');
		currStudent -> studentId = stoi(tmp);
		getline(fin, tmp, ',');
		currStudent -> firstName = tmp;
		getline(fin, tmp);
		currStudent -> lastName = tmp;

		string path = curSY -> name + "//" + char(curSE ->season + 48) + "//" + pCourse -> courseID + "//" + "listStud.txt";
        ifstream ifs;
		ofstream ofs;

        ifs.open(path);
        ofs.open("tmp.txt");
        if (ifs.is_open()) 
            while (getline(ifs, temp)) {
                ofs << temp << endl;
            }
		ofs << currStudent -> studentId << "," << currStudent -> firstName << " " << currStudent -> lastName << endl;
        ifs.close();
        ofs.close();
        remove(path.c_str());
        rename("tmp.txt", path.c_str());
	}
	fin.close();	
}