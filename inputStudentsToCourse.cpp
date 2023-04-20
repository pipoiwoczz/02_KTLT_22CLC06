#include "inputStudentsToCourse.h"
#include "main.h"
#include <string>
#include <fstream>
#include <iostream>
using namespace std;

void inputStudentsToCourse(string curSY, int season, string courseID)
{
	string classPath = curSY + "//" + char(season + 48) + "//" + courseID + "//" + "class.txt";
	ifstream ifs;
	ofstream ofs;
	cout << "---------List of Class in this Course------------\n";
	ifs.open(classPath);
	if (ifs.is_open()) {
		string tmp;
		while (getline(ifs, tmp)) {
			cout << tmp << endl;
		}
		ifs.close();
	} else {
		cout << "This course has now class\n";
		return;
	}
	cout << "---------------------------------------------------\n";

	string className;
	cout << "Enter class's name: ";
	cin >> className;
	bool flag = false;
	ifs.open(classPath);
	if (ifs.is_open()) {
		string tmp;
		while (getline(ifs, tmp)) {
			if (tmp == className) flag = true;;
		}
		ifs.close();
	}

	if (!flag) {
		ifs.close();
		cout << "You enter invalid class name!\n";
		cout << "Input 0 to get back to previous menu or anything to enter class name again\n";
		string temp;
		cin >> temp;
		if (temp == "0") {
			return;
		} else {
			return inputStudentsToCourse(curSY, season, courseID);
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

		ifstream ifs;
		ofstream ofs;

		string profilePathCheck = "profile/" + to_string(currStudent->studentId) + ".txt";
		ifs.open(profilePathCheck);
		if (!ifs.is_open()) {
			cout << currStudent->studentId << " isn't exist in this schoolyear\n";
			cout << "This student will not add to this course class\n";
			system("pause");
			continue;
		}
		else {
			ifs.close();
		}

		string path = curSY + "//" + char(season + 48) + "//" + courseID + "//" + className + "//" + "listStud.txt";
        

        ifs.open(path);
        ofs.open("tmp.txt");
        if (ifs.is_open()) 
            while (getline(ifs, temp)) {
                ofs << temp << endl;
            }
		ofs << currStudent->studentId << "," << currStudent->firstName << " " << currStudent->lastName;
        ifs.close();
        ofs.close();
        remove(path.c_str());
        rename("tmp.txt", path.c_str());
	}
	fin.close();	
	delete currStudent;
}