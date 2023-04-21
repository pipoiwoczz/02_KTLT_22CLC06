#include "saveStudentScoreboard.h"
#include "main.h"
#include "CourseMenu.h"
using namespace std;

int getCourseCredit(string curSY, string season, string courseID) {
	string courseCre;
	ifstream ifs;
	ofstream ofs;

	string coursePath = "./" + curSY + "/" + season + "/" + courseID + "/class.txt";
	string coureClass;
	ifs.open(coursePath);
	if (ifs.is_open()) {
		getline(ifs, coureClass);
		ifs.close();
	}

	string courseClassPath = "./" + curSY + "/" + season + "/" + courseID + "/" + coureClass + "/info.txt";
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

	return stoi(courseCre);
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
    string classPath = "./" + curSY + "/" + char(season + 48) + "/" + courseID + "/class.txt";
	string courseTotal;
	int courseCre = getCourseCredit(curSY, to_string(season), courseID); // get course credits
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
		cout << "There's no class in this course" << endl;
		ifs.close();
		return;
	}
	cout << "---------------------------------------------------\n";

	string className;
	cout << "Enter class's name: ";
	cin >> className;

	bool check = false;
	ifs.open(classPath);
	if (ifs.is_open()) {
		string tmp;
		while (getline(ifs, tmp)) {
			if (tmp == className) check = true;
		}
	}

	if (!check) {
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

	// CHECK THIS COURSE CLASS HAVE STUDENTS YET OR NOT
	string listStud = "./" + curSY + "/" + char(season + 48) + "/" + courseID + "/" + className + "/listStud.txt";
	ifs.open(listStud);
	if (!ifs.is_open() || ifs.eof()) {
		cout << "THIS COURSE CLASS HAS NO STUDENT YET\n";
		cout << "PLEASE IMPORT STUDENT FIRST\n";
		system("pause");
		return;
	}


	string pathOfScoreboard;
	cout << "Please enter the path of the scoreboard of this course: ";
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
		getline(fin, stID, ','); // studentid
		Class = searchStudent(stID);
		string stScore = "./" + curSY + "/" + Class + "/" + stID + "/" + courseID + ".txt";
		
		ofstream fout(stScore);
		for (int i = 0; i < 2; i++) {
			getline(fin, temp, ','); // get first name and last name
		}
		fout << className << ",";
		getline(fin, courseTotal, ',');			// get course total
		fout << courseTotal << ",";
		getline(fin, temp);
		fout << temp;

		string total = "./" + curSY + "/" + Class + "/" + stID + "/total.txt";
		string sesy = "./" + curSY + "/" + Class + "/" + stID + "/" + to_string(season) + "_" + curSY + ".txt";

		// CHECK IF This se-sy is exist or not
		bool flag = false;
		ifs.open(sesy);
		if (ifs.is_open()) {
			int seCre;
			float seGPA;
			ifs >> seGPA;
			ifs >> seCre;
			seGPA *= seCre * 1.0;
			seCre += courseCre;
			seGPA = (seGPA + courseCre * stof(courseTotal)) / seCre * 1.0;
			ofs.open("./" + curSY + "/" + Class + "/" + stID + "/tmp.txt");
			if (ofs.is_open()) {
				ofs << seGPA << endl;
				ofs << seCre;
				string temp;
				while (getline(ifs, temp))
					ofs << endl << temp;
				ofs << endl << courseID << "," << className;
				ofs.close();
			}
			ifs.close();
			remove(sesy.c_str());
			rename(("./" + curSY + "/" + Class + "/" + stID + "/tmp.txt").c_str(), sesy.c_str());
			
		}
		else {
			ifs.close();
			ofs.open(sesy);
			ofs << courseTotal << endl << courseCre << endl << courseID << "," << className;
			ofs.close();
			flag = true;
		}


		ifs.open(total); // open total.txt
		if (!ifs.is_open()) { // if there is no file total.txt before 
			ofs.open(total);
			ofs << courseTotal << endl;
			ofs << courseCre;
			if (flag == true) 
				ofs << endl << to_string(season) + "_" + curSY;
			ofs.close();
		}
		else { // if this is exist before, updating this file
			int totalCredits;
			float GPA;
			ifs >> GPA;
			ifs >> totalCredits;
			GPA *= totalCredits;
			totalCredits += courseCre;
			GPA = (GPA + courseCre * stof(courseTotal)) / totalCredits;
			ofs.open("tmp.txt");
			if (ofs.is_open()) {
				ofs << GPA << endl;
				ofs << totalCredits;
				string temp;
				while (getline(ifs, temp))
					ofs << endl <<  temp ;
				if (flag == true)
					ofs << endl << to_string(season) + "_" + curSY;
				ofs.close();
			}
			ifs.close();
			remove(total.c_str());
			rename("tmp.txt", total.c_str());
		}

		

		fout.close();
	}
	fin.close();

	string path ="./" + curSY + "/" + to_string(season) + "/" + courseID + "/" + className + "/" + "scoreboard.txt";

	ofs.open(path);
	fin.open(pathOfScoreboard);

	while (getline(fin, temp)) {
		ofs << temp << endl;
	} 

	fin.close();
	ofs.close();
}