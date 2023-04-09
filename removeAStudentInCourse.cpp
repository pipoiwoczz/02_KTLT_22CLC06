#include "main.h"
#include <cstdio>
#include <iostream>
#include <fstream>
using namespace std;

void removeAStudentInCourse(schoolYear * curSY, Semester * curSE ,Course* pCourse)
{
    // choose Course Class to remove a student  
    CourseClass * curCC = pCourse -> CourseClass;
	cout << "---------List of Class in this Course------------\n";
	while (curCC) {
		cout << curCC -> className << endl;
		curCC = curCC -> next;
	}
	cout << "---------------------------------------------------\n";

	string className;
	cout << "Enter class's name: ";
	cin >> className;

	curCC = pCourse -> CourseClass;
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
			return removeAStudentInCourse(curSY, curSE, pCourse);
		}
	}

	int studentID;
	cout << "Enter a student ID: ";
	cin >> studentID;
	
    string path = curSY -> name + "/" + to_string(curSE -> season) + "/" + pCourse -> courseID + "/" + curCC -> className + "/listStud.txt";
    ifstream ifs(path);
    ofstream ofs;
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