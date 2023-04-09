#include "saveStudentScoreboard.h"
#include "main.h"
#include <string>
#include <fstream>
#include <iostream>
using namespace std;

string searchStudent(string studentID)
{
	string pathProfile = "./profile/" + studentID + ".txt";
	ifstream ifs(pathProfile);
	string className;
	for (int i = 0; i < 4; i++)
		getline(ifs, className);
	ifs.close();
	return className;
}

void saveStudentScoreboard(schoolYear *year, Semester *curSE ,Course *curCourse)
{
	// choose Course Class to remove a student  
    CourseClass * curCC = curCourse -> CourseClass;
	cout << "---------List of Class in this Course------------\n";
	while (curCC) {
		cout << curCC -> className << endl;
		curCC = curCC -> next;
	}
	cout << "---------------------------------------------------\n";

	string className;
	cout << "Enter class's name: ";
	cin >> className;

	curCC = curCourse -> CourseClass;
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
			return saveStudentScoreboard(year, curSE, curCourse);
		}
	}


	string pathOfScoreboard;
	cout << "Please enter the path of the Scoreboard of this course: ";
	cin >> pathOfScoreboard;
	ifstream fin(pathOfScoreboard);
	if (!fin.is_open()) {
		cout << "This file doesn't exist!!\nPlease enter again\n";
		return saveStudentScoreboard(year, curSE, curCourse);
	}
	string temp;

	while (!fin.eof()) {
		getline(fin, temp, ','); // no
		getline(fin, temp, ','); // studentid
		string className = searchStudent(temp);
		string folder = "./" + year->name + "/" + className + "/" + temp + "/" + curCourse -> courseID + ".txt";
		
		ofstream fout(folder);
		getline(fin, temp, ',');
		for (int i = 0; i < 3; i++) {
			getline(fin, temp, ',');
		}
		fout << curCC -> className << ",";
		getline(fin, temp);
		fout << temp;
		fout.close();
	}
	fin.close();

	ofstream ofs;
	string path = year -> name + "//" + to_string(curSE -> season) + "//" + curCourse -> courseID + "//" + curCC -> className + "//" + "scoreboard.txt";

	ofs.open(path);
	fin.open(pathOfScoreboard);

	while (getline(fin, temp)) {
		ofs << temp << endl;
	} 

	fin.close();
	ofs.close();
}