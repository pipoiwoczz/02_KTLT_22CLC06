#include "main.h"
#include <cstdio>
#include <iostream>
#include <fstream>
using namespace std;

void removeAStudentInCourse(string curSY, int season, string courseID)
{
    // choose Course Class to remove a student  
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
			return removeAStudentInCourse(curSY, season, courseID);
		}
	}
	ifs.close();


	int studentID;
	cout << "Enter a student ID: ";
	cin >> studentID;
	
	// remove in the listStud.txt
    string path =  curSY + "/" + to_string(season) + "/" + courseID + "/" +  className + "/listStud.txt";
    ifs.open(path);

    if(!ifs.is_open()) {
        cout << "This class has no student yet\n";
        return;
    } else {
        ofs.open("tmp.txt");
        string temp;
        while (getline (ifs, temp,  ',')) {
            if (temp != to_string(studentID)) {
                ofs << temp << ",";
                getline (ifs, temp);
                ofs << temp << endl;
            } else {
                getline(ifs, temp);
            }
        }
    }
    ifs.close();
    ofs.close();
    remove(path.c_str());
    rename("tmp.txt", path.c_str());
}