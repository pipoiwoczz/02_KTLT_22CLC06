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

void saveStudentScoreboard(string curSY, int season, string courseID)
{ 
    string classPath = curSY + "//" + char(season + 48) + "//" + courseID + "//" + "class.txt";
	ifstream ifs;
	ofstream ofs;

	cout << "---------List of Class in this Course------------\n";
	ifs.open(classPath);
	if (ifs.is_open()) {
		string tmp;
		while (getline(ifs, tmp)) {
			cout << tmp << endl;
		}
		ifs.close();
	} else {
		cout << "This course has now class\n";
		return;
	}
	cout << "---------------------------------------------------\n";

	string className;
	cout << "Enter class's name: ";
	cin >> className;

	ifs.open(classPath);
	if (ifs.is_open()) {
		string tmp;
		while (getline(ifs, tmp)) {
			if (tmp == className) break;
		}
	}

	if (ifs.eof()) {
		ifs.close();
		cout << "You enter invalid class name!\n";
		cout << "Input 0 to get back to previous menu or anything to enter class name again\n";
		string temp;
		cin >> temp;
		if (temp == "0") {
			return;
		} else {
			return saveStudentScoreboard(curSY, season, courseID);
		}
	}
	ifs.close();


	string pathOfScoreboard;
	cout << "Please enter the path of the Scoreboard of this course: ";
	cin >> pathOfScoreboard;
	ifstream fin(pathOfScoreboard);
	if (!fin.is_open()) {
		cout << "This file doesn't exist!!\nPlease enter again\n";
		system("pause");
		return saveStudentScoreboard(curSY, season, courseID);
	}
	string temp;

	while (!fin.eof()) {
		getline(fin, temp, ','); // no
		getline(fin, temp, ','); // studentid
		string className2 = searchStudent(temp);
		string folder = "./" + curSY + "/" + className2 + "/" + temp + "/" + courseID + ".txt";
		
		ofstream fout(folder);
		getline(fin, temp, ',');
		for (int i = 0; i < 3; i++) {
			getline(fin, temp, ',');
		}
		fout << className << ",";
		getline(fin, temp);
		fout << temp;
		fout.close();
	}
	fin.close();

	string path = curSY + "//" + to_string( season) + "//" + courseID + "//" + className + "//" + "scoreboard.txt";

	ofs.open(path);
	fin.open(pathOfScoreboard);

	while (getline(fin, temp)) {
		ofs << temp << endl;
	} 

	fin.close();
	ofs.close();
}