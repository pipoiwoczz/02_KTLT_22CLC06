#include "deleteACourse.h"
#include "main.h"
#include "SEmenu.h"
#include <stdio.h>
#include <fstream>
#include <string>
#include <filesystem>
using namespace std;


void deleteACourse(schoolYear *year, Semester *sem, Course*& pCourse)
{
	Course* curr;
	string courseid;
	cout << "Enter the course ID needed to delete: ";
	cin >> courseid;
	curr = pCourse;

	// find course
	while (curr && curr -> courseID != courseid) {
		curr = curr -> next;
	} 
	// check if course id is not correct
	if (!curr) {
		cout << "This course's ID is not exist\n";
		cout << "Enter 0 if you want to exit or anything else if you want to continue\n";
		string choice;
		cin >> choice;
		if (choice == "0") {
			return;
		} else {
			return deleteACourse(year, sem, pCourse);
		}
	} else {
		CourseClass * curCC = curr -> CourseClass;
		while (curCC) {
			// delete file info.txt
			remove((year -> name + "/" + to_string(sem -> season) + "/" + curr -> courseID + "/" + curCC -> className + "/info.txt").c_str());
			// delete folder class
			rmdir((year -> name + "/" + to_string(sem -> season) + "/" + curr -> courseID + "/" + curCC -> className).c_str());
			// delete CourseClass of Course
			CourseClass *tmpCC = curCC;
			curCC = curCC -> next;
			delete tmpCC;
		}

		// delete class.txt in folder CourseID
		remove((year -> name + "/" + to_string(sem -> season) + "/" + curr -> courseID + "/class.txt").c_str());

		// delete folder CourseID
		rmdir((year -> name + "/" + to_string(sem -> season) + "/" + curr -> courseID).c_str());

		// delete courseID in file course.txt 
		ifstream ifs((year -> name + "/" + to_string(sem -> season) + "/" + "course.txt").c_str());
		ofstream ofs("tmp.txt");

		if (ifs.is_open()) {
			string temp;
			while (getline (ifs, temp)) {
				if (temp == courseid);
				else ofs << temp << endl;
			}
		}

		ifs.close();
		ofs.close();

		remove((year -> name + "/" + to_string(sem -> season) + "/" + "course.txt").c_str());
		rename("tmp.txt", (year -> name + "/" + to_string(sem -> season) + "/" + "course.txt").c_str());


		// delete Course
		Course * tmp = pCourse;
		if (tmp == curr) {
			pCourse = pCourse -> next;
			delete curr;
		} else {
			while (tmp -> next != curr)
				tmp = tmp -> next;
			tmp -> next = curr -> next;
			
			delete curr; 
		}
	}
}