#include "viewStudentInACourse.h"
using namespace std;

void viewStudentInACourseClass(schoolYear *SY, Semester *Sem, Course *course) {
    // choose Course Class to view students  
    CourseClass * curCC = course -> CourseClass;
	cout << "---------List of Class in this Course------------\n";
	while (curCC) {
		cout << curCC -> className << endl;
		curCC = curCC -> next;
	}
	cout << "---------------------------------------------------\n";

	string className;
	cout << "Enter class's name: ";
	cin >> className;

	curCC = course -> CourseClass;
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
			return viewStudentInACourseClass(SY, Sem, course);
		}
	}

    string out;
    ifstream ifs;
        ifs.open("./" + SY -> name + "/" + to_string(Sem -> season) + "/" + course -> courseID + "/" + curCC ->className + "/listStud.txt");
        int i = 1; // Ordinal number
        cout << "Student in this course class: "<< endl;
        cout << "--------------------" << endl;
        cout << left << setw(5) << "No." << setw(12) << "ID" << "Name" << endl;
        while (!ifs.eof()) {
            cout << left << setw(5) << i; // Ordinal number
            getline(ifs, out, ',');
            cout << setw(12) << out; // Id
            getline(ifs, out);
            cout << out << endl; // Name
            i++;
        }
        cout << "--------------------" << endl;
    ifs.close();
}

void studentInACourse(schoolYear *SY, Semester *Sem, Course *course) {
	string path = "./" + SY -> name + "/" + to_string(Sem -> season) + "/" + course -> courseID + "/class.txt";
	string courseClass, studentID, studentName;
	ifstream ifs, Class;
	int i=1; // Ordinal number
	cout << "List of student in this course: " << endl;
    cout << "--------------------" << endl;
    cout << left << setw(5) << "No." << setw(12) << "ID" << setw(8) << "Class" << "Name" << endl;
	ifs.open(path);
		while (!ifs.eof()) {
			getline(ifs, courseClass);
			Class.open("./" + SY -> name + "/" + to_string(Sem -> season) + "/" + course -> courseID + "/" + courseClass + "/listStud.txt");
				while (!Class.eof()) {
					getline(Class, studentID, ',');
					getline(Class, studentName);
					cout << left << setw(5) << i << setw(12) << studentID << setw(8) << courseClass << studentName << endl;
					i++;
				}
			Class.close();
		}
	ifs.close();
}