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

	tmp = new Course;
		cout << "CourseID: ";
		cin >> tmp->courseID;
		cout << "Course name: ";
		cin.ignore();
		getline (cin, tmp->courseName);
		cout << "The number of credits: ";
		cin >> tmp->credits;

	if (!pHead) {
		pHead = tmp;
	} else {
		Course * tail = pHead;
		while (tail -> next) 
			tail = tail -> next;
		tail -> next = tmp;
	}

		cout << "\tInput classes in course\n";
		do {
			CourseClass * curCC = new CourseClass;

			cout << "Class name(input 0 if want to stop): ";

			cin >> curCC->className;
			if (curCC -> className == "0") {
				delete curCC;
				break;
			}
			cout << "The maximum number of students in the course: ";
			cin >> curCC->maxStudents;
			cout << "Day of week: ";
			cin >> curCC->dayOfWeek;
			cout << "The session performed on: ";
			cin >> curCC->session;

			if (!tmp -> CourseClass) {
				tmp -> CourseClass = curCC;
			} else {
				CourseClass * tail = tmp -> CourseClass;
				while (tail -> next) 
					tail = tail -> next;
				tail -> next = curCC;
			}

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


	path += "//info.txt";
	ofstream ofs;
	ofs.open(path);
		ofs << tmp -> courseID << endl;
		ofs << tmp -> courseName << endl;
		ofs << tmp -> credits << endl;
		curCC = tmp -> CourseClass;
		while (curCC) {
			ofs << curCC -> className << "," << curCC -> teacherName << "," << curCC -> maxStudents << "," << curCC -> dayOfWeek << "," << curCC -> session << endl;
			curCC = curCC -> next;	
		} 
		
	ofs.close();

	ifstream ifs;

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
	delete tmp;
}