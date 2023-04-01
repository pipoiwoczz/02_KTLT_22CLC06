#include "addACourse.h"
#include "main.h"
#include <filesystem>
#include <unistd.h>
using namespace std;
// namespace fs = std::filesystem;

void addACourse(schoolYear *SY, Semester *semester, Course*& pHead)
{
	pHead = new Course;
	cout << "CourseID: ";
	cin >> pHead->courseID;
	cout << "Course name: ";
	cin >> pHead->courseName;
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

	// create folder and file

	string path = "./" + SY -> name + "/" + to_string(semester -> season) + "_" + SY -> name + "/" + pHead -> courseName;
	mkdir(path.c_str());
	path += "/info.txt";
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
}