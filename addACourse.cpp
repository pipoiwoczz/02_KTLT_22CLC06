#include "addACourse.h"
#include "main.h"
#include <filesystem>
#include <direct.h>
#include <string>
#include <iostream>
using namespace std;
// namespace fs = std::filesystem;

void addACourse(string curSY, int season)
{
	string courseID, courseName;
	int credits;
	ifstream ifs;
	ofstream ofs;

	cout << "CourseID: ";
	cin >> courseID;
	cout << "Course name: ";
	cin.ignore();
	getline (cin, courseName);
	cout << "The number of credits: ";
	cin >> credits;

	// create CourseID folder

	string path = "./" + curSY + "/" + to_string(season) + "//" + courseID;
	_mkdir(path.c_str());

	string sy = curSY + "//" + char(season + 48) + "//";

	ifs.open(sy + "course.txt");
	ofs.open(sy + "tmp.txt");

	string tmp;
	if (ifs.is_open())
		while (getline(ifs, tmp)) {
			ofs << tmp << endl;
		}

	ofs << courseID;

	ifs.close();
	ofs.close();

	remove((sy + "course.txt").c_str());
	rename((sy + "tmp.txt").c_str(), (sy + "course.txt").c_str());

	cout << "--------------------------------------\n";
	cout << "\tInput classes in course\n";

		do {
			string className, teacherName, dayOfWeek, session;
			int numberOfStudents;

			cout << "Class name(input 0 if want to stop): ";

			cin >> className;
			if (className == "0") {
				break;
			}
			cin.ignore();
			cout << "Teacher's name of this class: ";
			getline(cin, teacherName);
			cout << "The maximum number of students in the course: ";
			cin >> numberOfStudents;
			cout << "Day of week: ";
			cin >> dayOfWeek;
			cout << "The session performed on: ";
			cin >> session;
			cout << endl;


			// create Class in Course Folder
			string classPath = curSY + "/" + to_string(season) + "//" + courseID + "//" + className;
			_mkdir(classPath.c_str());


			// create infor.txt for each class in course
			ofs.open(path + "//" + className + "//info.txt");
			ofs <<  courseID << endl;
			ofs <<  courseName << endl;
			ofs <<  className << endl;
			ofs <<  teacherName << endl;
			ofs << credits << endl;
			ofs <<  numberOfStudents << endl;
			ofs << dayOfWeek << endl;
			ofs << session;
			ofs.close();


			// create class.txt
			string txtPath = curSY + "/" + to_string(season) + "//" + courseID + "//class.txt";
			ifs.open(txtPath);
			ofs.open("tmp.txt");
			if (ifs.is_open()) {
				string temp;
				while (getline(ifs, temp)) {
					ofs << temp << endl;
				}
			}
			ofs << className;
			ifs.close();
			ofs.close();
			remove(txtPath.c_str());
			rename("tmp.txt", txtPath.c_str());


			// add course to course.txt

		} while (1);

	cout << "Course created successfully!!\n";
}