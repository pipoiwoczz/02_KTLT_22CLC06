#include "1StuToCourse.h"
#include "main.h"
#include <fstream>
#include <string>
#include <iostream>
using namespace std;

void add1StudentToCourse(string curSY, int season, string courseID)  {
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
			return add1StudentToCourse(curSY, season, courseID);
		}
	}
	ifs.close();

    cout << "==========Pls enter the information of the Student==========";

    string firstName, lastName;
    int id;

    cout << "\nStudent ID: ";
    cin >> id;

    cin.ignore();
    cout << "Enter student's last name: ";
    getline(cin, lastName);

    cin.ignore();
    cout << "Enter student's first name: ";
    getline(cin, firstName);
    
    

    string path = curSY + "/" + to_string(season) + "/" +  courseID + "//" + className +  "/" + "listStud.txt";
    string infoStudent = to_string(id) + "," + lastName + " " + firstName; 
    int flag = 0;

    ifstream ifs;
    ofstream ofs;

    ifs.open(path);
    ofs.open(curSY + "/" + to_string(season) + "/" + courseID + "/" + "tmp.txt");

    if (ifs.is_open())  {
        string tmp;
        while (getline(ifs, tmp))   {
            if (tmp == infoStudent) {
                flag = 1;
                break;
            }

            ofs << tmp << endl;
        }
    }

    ofs << infoStudent;
    ifs.close();
    ofs.close();

    if (flag == 1)  {
        remove((curSY + "/" + to_string(season) + "/" +  courseID + "/" + "tmp.txt").c_str());

        cout << "Student has already been in the course...";
        cout << "\nDo you want to continue adding 1 student to this course?";

        int move;
        cout << "\n1. Yes";
        cout << "\n2. No";

        do {
            cout << "\nEnter your choice: ";
            cin >> move;

            switch (move)   {
                case 1: 
                    return add1StudentToCourse(curSY, season, courseID);
                case 2:
                    return;
                default:
                    cout << "Wrong choice. Pls try again.";
                    break;
            }
        }   while (move != 1 && move != 2);
    } else {
        remove(path.c_str());
        rename((curSY + "/" + to_string( season) + "/" + courseID + "/" + "tmp.txt").c_str(), path.c_str());
    }
}