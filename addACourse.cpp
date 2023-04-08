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
	// if (!pHead) {
	// 	pHead = new Course;
	// 	cout << "CourseID: ";
	// 	cin >> pHead->courseID;
	// 	cout << "Course name: ";
	// 	cin.ignore();
	// 	getline (cin, pHead->courseName);
	// 	cout << "Class name: ";
	// 	cin >> pHead->className;
	// 	cout << "The number of credits: ";
	// 	cin >> pHead->credits;
	// 	cout << "The maximum number of students in the course: ";
	// 	cin >> pHead->maxStudents;
	// 	cout << "Day of week: ";
	// 	cin >> pHead->dayOfWeek;
	// 	cout << "The session performed on: ";
	// 	cin >> pHead->session;		
	// } else {
	// 	tmp = new Course;
	// 	cout << "CourseID: ";
	// 	cin >> tmp->courseID;
	// 	cout << "Course name: ";
	// 	cin.ignore();
	// 	getline (cin, tmp->courseName);
	// 	cout << "Class name: ";
	// 	cin >> tmp->className;
	// 	cout << "The number of credits: ";
	// 	cin >> tmp->credits;
	// 	cout << "The maximum number of students in the course: ";
	// 	cin >> tmp->maxStudents;
	// 	cout << "Day of week: ";
	// 	cin >> tmp->dayOfWeek;
	// 	cout << "The session performed on: ";
	// 	cin >> tmp->session;
	// 	tmp -> next = pHead;
	// 	pHead = tmp;
	// }

	tmp = new Course;
		cout << "CourseID: ";
		cin >> tmp->courseID;
		cout << "Course name: ";
		cin.ignore();
		getline (cin, tmp->courseName);
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

	if (!pHead) {
		pHead = tmp;
	} else {
		Course * tail = pHead;
		while (tail -> next) 
			tail = tail -> next;
		tail -> next = tmp;
	}
	


	// create folder and file

	string path = "./" + SY -> name + "/" + to_string(semester -> season) + "//" + tmp -> courseID;
	mkdir(path.c_str());
	path += "//info.txt";
	ofstream ofs;
	ofs.open(path);
		ofs << tmp -> courseID << endl;
		ofs << tmp -> courseName << endl;
		ofs << tmp -> className << endl;
		ofs << tmp -> credits << endl;
		ofs << tmp -> maxStudents << endl;
		ofs << tmp -> dayOfWeek << endl;
		ofs << tmp -> session << endl;
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
}