#include "inputStudentsToCourse.h"
#include "main.h"
#include <string>
#include <fstream>
#include <iostream>
using namespace std;

void inputStudentsToCourse(schoolYear *curSY, Semester * curSE, Course*& pCourse)
{
	CourseClass * curCC = pCourse -> CourseClass;
	cout << "---------List of Class in this Course------------\n";
	while (curCC) {
		cout << curCC -> className << endl;
		curCC = curCC -> next;
	}
	cout << "---------------------------------------------------\n";

	string className;
	cout << "Enter class's name: ";
	cin >> className;

	curCC = pCourse -> CourseClass;
	while (curCC && curCC -> className != className) {
		curCC = curCC -> next;
	} 

	if (!curCC) {
		cout << "You enter invalid class name!\n";
		cout << "Input 0 to get back to previous menu or anything to enter class name again\n";
		string temp;
		cin >> temp;
		if (temp == "0") {
			return;
		} else {
			return inputStudentsToCourse(curSY, curSE, pCourse);
		}
	}

	ifstream fin;
	string path, temp;
	cout << "Enter the path of a CSV file containing students: ";
	cin >> path;
	fin.open(path);

	if (!fin.is_open()) {
		cout << "The file doesn't exist.";
		return;
	}

	Student* currStudent = new Student;

	while (!fin.eof()) {
		
		string tmp;
		getline(fin, tmp, ',');
		currStudent -> studentId = stoi(tmp);
		getline(fin, tmp, ',');
		currStudent -> firstName = tmp;
		getline(fin, tmp);
		currStudent -> lastName = tmp;

		string path = curSY -> name + "//" + char(curSE ->season + 48) + "//" + pCourse -> courseID + "//" + curCC -> className + "//" + "listStud.txt";
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
	delete currStudent;
}