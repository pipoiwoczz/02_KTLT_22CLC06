#include "saveStudentScoreboard.h"
#include "main.h"
#include <string>
#include <fstream>
#include <iostream>
using namespace std;

int getCourseCredit(string curSY, string season, string courseID) {
	int courseCre;
	ifstream ifs;
	ofstream ofs;

	string coursePath = curSY + "/" + season + "/" + courseID + "/class.txt";
	string coureClass;
	ifs.open(coursePath);
	if (ifs.is_open()) {
		getline(ifs, coureClass);
		ifs.close();
	}

	string courseClassPath = curSY + "/" + season + "/" + courseID + "/" + coureClass + "/info.txt";
	ifs.open(courseClassPath);
	if (ifs.is_open()) {
		string tmp;
		getline(ifs, tmp); // course ID 
		getline(ifs, tmp); // course Name;
		getline(ifs, tmp); // class Name
		getline(ifs, tmp); // teachername
		ifs >> courseCre;
		ifs.close();
	}

	return courseCre;
}

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
	float courseTotal;
	int courseCre = getCourseCredit(curSY, to_string(season), courseID);
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
	string stID;
	string Class;

	while (!fin.eof()) {
		getline(fin, temp, ','); // no
		getline(fin, temp, ','); // studentid
		Class = searchStudent(temp);
		stID = temp;
		string folder = "./" + curSY + "/" + Class + "/" + temp + "/" + courseID + ".txt";
		
		ofstream fout(folder);
		getline(fin, temp, ',');
		for (int i = 0; i < 4; i++) {
			getline(fin, temp, ',');
		}
		fout << className << ",";
		fin >> courseTotal;
		fout << courseTotal;
		getline(fin, temp);
		fout << temp;

		string total = curSY + "/" + Class + "/" + stID + "/total.txt";
		string sesy = curSY + "/" + Class + "/" + stID + "/" + to_string(season) + "_" + curSY + ".txt";

		// CHECK IF This se-sy is exist or not
		bool flag = false;
		ifs.open(sesy);
		if (ifs.is_open()) {
			int seCre;
			float seGPA;
			ifs >> seGPA;
			ifs >> seCre;
			seGPA *= seCre;
			seGPA += courseCre * courseTotal;
			seCre += courseCre;
			ofs.open("tmp.txt");
			if (ofs.is_open()) {
				ofs << seGPA << endl;
				ofs << seCre << endl;
				string temp;
				while (getline(ifs, temp))
					ofs << temp << endl;
				ofs.close();
			}
			remove(sesy.c_str());
			rename("tmp.txt", sesy.c_str());
			ifs.close();
		}
		else {
			ofs.open(sesy);
			ofs << courseTotal << endl << courseCre << endl << courseID << "," << Class;
			ofs.close();
			flag = true;
		}


		ifs.open(total); // open total.txt
		if (!ifs.is_open()) { // if there is no file total.txt before 
			ofs.open(total);
			ofs << courseTotal << endl;
			ofs << courseCre;
			if (flag == true) 
				ofs << curSY + "/" + Class + "/" + stID + "/" + to_string(season) + "_" + curSY;
			ofs.close();
		}
		else { // if this is exist before, updating this file
			int totalCredits;
			float GPA;
			ifs >> totalCredits;
			ifs >> GPA;
			GPA *= totalCredits;
			GPA += courseCre * courseTotal;
			totalCredits += courseCre;
			ofs.open("tmp.txt");
			if (ofs.is_open()) {
				ofs << GPA << endl;
				ofs << totalCredits << endl;
				string temp;
				while (getline(ifs, temp))
					ofs << temp << endl;
				if (flag == true)
					ofs << curSY + "/" + Class + "/" + stID + "/" + to_string(season) + "_" + curSY;
				ofs.close();
			}
			ifs.close();
			remove(total.c_str());
			rename("tmp.txt", total.c_str());
		}

		

		fout.close();
	}
	fin.close();

	string path = curSY + "//" + to_string(season) + "//" + courseID + "//" + className + "//" + "scoreboard.txt";

	ofs.open(path);
	fin.open(pathOfScoreboard);

	while (getline(fin, temp)) {
		ofs << temp << endl;
	} 

	fin.close();
	ofs.close();
}