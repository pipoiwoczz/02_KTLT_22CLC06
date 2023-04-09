#include "viewScoreboardOfCourse.h"
#include "main.h"
#include <iostream>
#include <fstream>
using namespace std;

void viewScoreboardOfCourse(schoolYear *SY, Semester *Sem, Course *curCourse) {
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
			return viewScoreboardOfCourse(SY, Sem, curCourse);
		}
	}


    ifstream ifs;
    string out;
    ifs.open("./" + SY -> name + "/" + to_string(Sem -> season) + "/" + curCourse -> courseID + "//" + curCC -> className + "/scoreboard.txt");
    if (!ifs.is_open()) {
        cout << "This course hasn't been updated scoreboard\n";
        system("pause");
        return;
    }
    cout << "Course's scoreboard:" << endl;
    cout << "--------------------" << endl;
    cout << left << setw(5) << "No." << setw(10) << "ID" << setw(34) << "Name" << setw(8) << "Total" << setw(8) << "Final" << setw(8) << "Midterm" << setw(8) << "Other" << endl;
    while (!ifs.eof()) {
        getline(ifs, out, ','); // Ordinal number
        cout << left << setw(5) << out;
        getline(ifs, out, ','); // ID
        cout << left << setw(10) << out;
        getline(ifs, out, ','); // Name
        cout << left << setw(34) << out;
        getline(ifs, out, ','); // Total
        cout << left << setw(8) << out;
        getline(ifs, out, ','); // Final 
        cout << left << setw(8) << out;
        getline(ifs, out, ','); // Midterm
        cout << left << setw(8) << out;
        getline(ifs, out); // Other
        cout << left << setw(8) << out << endl;
    }
    ifs.close();
    cout << "--------------------" << endl;
}