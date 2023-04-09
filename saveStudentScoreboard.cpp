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

void saveStudentScoreboard(schoolYear *year, Semester *curSE ,string courseID)
{
	string pathOfScoreboard;
	cout << "Please enter the path of the Scoreboard of this course: ";
	cin >> pathOfScoreboard;
	ifstream fin(pathOfScoreboard);
	if (!fin.is_open()) {
		cout << "This file doesn't exist!!\nPlease enter again\n";
		system("pause");
		return saveStudentScoreboard(year, curSE, courseID);
	}
	string temp;

	while (!fin.eof()) {
		getline(fin, temp, ','); // no
		getline(fin, temp, ','); // studentid
		string className = searchStudent(temp);
		string folder = "./" + year->name + "/" + className + "/" + temp + "/" + courseID + ".txt";
		
		ofstream fout(folder);
		getline(fin, temp, ',');
		for (int i = 0; i < 3; i++) {
			getline(fin, temp, ',');
			fout << temp << ",";
		}
		getline(fin, temp);
		fout << temp;
		fout.close();
	}
	fin.close();

	ofstream ofs;
	string path = year -> name + "//" + to_string(curSE -> season) + "//" + courseID + "//" + "scoreboard.txt";
}