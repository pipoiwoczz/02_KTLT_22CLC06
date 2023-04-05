#include "addACourse.h"
#include "main.h"
#include <filesystem>
#include <unistd.h>
#include <string>
using namespace std;
// namespace fs = std::filesystem;

void addACourse(schoolYear *SY, Semester *semester, Course *& pHead)
{
	Course * tmp;
	if (!pHead) {
		pHead = new Course;
		cout << "CourseID: ";
		cin >> pHead->courseID;
		cout << "Course name: ";
		cin.ignore();
		getline (cin, pHead->courseName);
		cout << "Class name: ";
		cin >> pHead->className;
		cout << "The number of credits: ";
		cin >> pHead->credits;
		cout << "The maximum number of students in the course: ";
		cin >> pHead->maxStudents;
		cout << "Day of week: ";
		cin >> pHead->dayOfWeek;
		cout << "The session performed on: ";
		cin >> pHead->session;		
	} else {
		tmp = new Course;
		cout << "CourseID: ";
		cin >> tmp->courseID;
		cout << "Course name: ";
		cin >> tmp->courseName;
		cout << "Class name: ";
		cin >> tmp->className;
		cout << "The number of credits: ";
		cin >> tmp->credits;
		cout << "The maximum number of students in the course: ";
		cin >> tmp->maxStudents;
		cout << "Day of week: ";
		cin >> tmp->dayOfWeek;
		cout << "The session performed on: ";
		cin >> tmp->session;
		tmp -> next = pHead;
		pHead = tmp;
	}


	// create folder and file

	string path = "./" + SY -> name + "/" + to_string(semester -> season) + "_" + SY -> name + "/" + pHead -> courseID;
	mkdir(path.c_str());
	path += "//info.txt";
	ofstream ofs;
	ofs.open(path);
		ofs << pHead -> courseID << endl;
		ofs << pHead -> courseName << endl;
		ofs << pHead -> className << endl;
		ofs << pHead -> credits << endl;
		ofs << pHead -> maxStudents << endl;
		ofs << pHead -> dayOfWeek << endl;
		ofs << pHead -> session << endl;
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

	
	mkdir((sy + pHead -> courseID).c_str());
}