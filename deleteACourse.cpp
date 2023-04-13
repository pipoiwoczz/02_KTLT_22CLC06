#include "deleteACourse.h"
#include "main.h"
#include "SEmenu.h"
#include <stdio.h>
#include <fstream>
#include <string>
#include <filesystem>
using namespace std;


void deleteACourse(string curSY, int season, string courseID)
{
	string classPath = curSY +"//" + to_string(season) + "//" + courseID + "//";

	ifstream ifs;
	ofstream ofs;

	ifs.open(classPath + "class.txt");
	if (ifs.is_open()) {
		string tmp;
		while (getline(ifs, tmp)) {
			// delete file info.txt
			remove((classPath + tmp + "//info.txt").c_str());
			// delete folder class
			rmdir((classPath + tmp).c_str());
		}
	}

	// delete class.txt in folder CourseID
	remove((classPath + "class.txt").c_str());

	// delete folder CourseID
	rmdir((curSY + "//" + to_string(season) + "//" + courseID).c_str());

	// delete courseID in file course.txt 
	ifstream ifs((curSY + "//" + to_string(season) +  "//" + "course.txt").c_str());
	ofstream ofs("tmp.txt");

	if (ifs.is_open()) {
		string temp;
		while (getline (ifs, temp)) {
			if (temp == courseID);
			else ofs << temp << endl;
		}
	}

	ifs.close();
	ofs.close();

	remove((curSY + "//" + to_string(season) +  "//" + "course.txt").c_str());
	rename("tmp.txt", (curSY + "//" + to_string(season) +  "//" + "course.txt").c_str());		
}