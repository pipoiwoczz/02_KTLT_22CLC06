#include "addACourse.h"
#include "main.h"
#include <filesystem>
#include <unistd.h>
#include <string>
#include <iostream>
using namespace std;
// namespace fs = std::filesystem;

void addACourse(schoolYear *SY, Semester *semester, Course *& pHead)
{
	Course * tmp;
	string courseID, courseName;
	int credits;

	tmp = new Course;
		cout << "CourseID: ";
		cin >> courseID;
		cout << "Course name: ";
		cin.ignore();
		getline (cin, courseName);
		cout << "The number of credits: ";
		cin >> credits;

		cout << "\tInput classes in course\n";
		do {
			string className, teacherName, dayOfWeek, session;
			int numberOfStudents;
			CourseClass * curCC = new CourseClass;

			cout << "Class name(input 0 if want to stop): ";

			cin >> curCC->className;
			if (curCC -> className == "0") {
				delete curCC;
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
		} while (1);


	


	// create folder and file

	// string classFolder = SY -> name + "//" + to_string(semester -> season) + "//" + tmp -> courseID + "//" + tmp -> className;
	// mkdir(classFolder.c_str());

	// create CourseID folder

	string path = "./" + SY -> name + "/" + to_string(semester -> season) + "//" + tmp -> courseID;
	mkdir(path.c_str());

	// create Class in Course Folder
	CourseClass * curCC = tmp -> CourseClass;
	while (curCC) {
		string classPath = SY -> name + "/" + to_string(semester -> season) + "//" + tmp -> courseID + "//" + curCC -> className;
		mkdir(classPath.c_str());
		curCC = curCC -> next;
	}

	// create infor.txt for each class in course
	ofstream ofs;
		curCC = tmp -> CourseClass;
		while (curCC) {
			ofs.open(path + "//" + curCC -> className + "//info.txt");
			ofs << tmp -> courseID << endl;
			ofs << tmp -> courseName << endl;
			ofs << curCC -> className << endl;
			ofs << curCC -> teacherName << endl;
			ofs << tmp -> credits << endl;
			ofs << curCC -> numberOfStudent << endl;
			ofs << curCC -> dayOfWeek << endl;
			ofs << curCC -> session;
			curCC = curCC -> next;
			ofs.close();
		} 
	
	// create class.txt
	ifstream ifs;

	curCC = tmp -> CourseClass;
	path += "//class.txt";
	
	ofs.open(path);
	while (curCC) {
		ofs << curCC -> className << endl;
		curCC = curCC -> next;
	}	
	ofs.close();


	// add course to course.txt

        string sy = SY -> name + "//" + char(semester -> season + 48) + "//";

        ifs.open(sy + "course.txt");
        ofs.open(sy + "tmp.txt");

        if (ifs.is_open())
            while (!ifs.eof())  {
                string tmp;
                getline(ifs, tmp);
                ofs << tmp << endl;
            }        

        ofs << pHead -> courseID;

        ifs.close();
        ofs.close();

        remove((sy + "course.txt").c_str());
        rename((sy + "tmp.txt").c_str(), (sy + "course.txt").c_str());

	
	mkdir((sy + tmp -> courseID).c_str());

	cout << "Course created successfully!!\n";
}