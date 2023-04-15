#include "viewStudentInACourse.h"

void viewStudentInACourseClass(string SY, string Sem, string course) {
    // choose Course Class to view students  
	string cClass, path, chosenClass;
	ifstream courseClass;
	path = "./" + SY + "/" + Sem + "/" + course + "/class.txt";

	// View list of classes in a course
	courseClass.open(path);
		cout << "---------List of Class in this Course------------\n";
		while (!courseClass.eof()) {
			getline(courseClass, cClass);
			cout << cClass << endl;
		}
		cout << "---------------------------------------------------\n";
	courseClass.close();

	cout << "Enter class's name: ";
	cin >> chosenClass;

	// Check whether the input is correct or not
	bool exist = false;
	courseClass.open(path);
		while (!courseClass.eof()) {
			getline(courseClass, cClass);
			if (cClass == chosenClass) {
				exist = true;
				break;
			}
		}		
	courseClass.close();

	if (!exist) {
		cout << "You've entered an incorrect class name!\n";
		cout << "Enter 0 to get back to previous menu or any of other keys to enter class name again\n";
		cout << "Your choice: ";
		string temp;
		cin >> temp;
    	cout << "--------------------" << endl;

		if (temp == "0") return;
		else return viewStudentInACourseClass(SY, Sem, course);
	}

    string out;
    ifstream ifs;
        ifs.open("./" + SY + "/" + Sem + "/" + course + "/" + chosenClass + "/listStud.txt");
        int i = 1; // Ordinal number
        cout << "Student in this course class: "<< endl;
        cout << "--------------------" << endl;
        cout << left << setw(4) << "No." << setw(10) << "ID" << "Name" << endl;
        while (!ifs.eof()) {
            cout << left << setw(4) << i; // Ordinal number
            getline(ifs, out, ',');
            cout << setw(10) << out; // Id
            getline(ifs, out);
            cout << out << endl; // Name
            i++;
        }
        cout << "--------------------" << endl;
    ifs.close();
}

// This function view list of student in a course of a semester
void studentInACourse(string SY, string Sem, string course) {
	string path = "./" + SY + "/" + Sem + "/" + course + "/class.txt";
	string courseClass, studentID, studentName;
	ifstream ifs, Class;
	int i=1; // Ordinal number
	cout << "List of student in this course: " << endl;
    cout << "--------------------" << endl;
    cout << left << setw(4) << "No." << setw(10) << "ID" << setw(9) << "Class" << "Name" << endl;

	ifs.open(path);
		while (!ifs.eof()) {
			getline(ifs, courseClass);
			Class.open("./" + SY + "/" + Sem + "/" + course + "/" + courseClass + "/listStud.txt");
				while (!Class.eof()) {
					getline(Class, studentID, ',');
					getline(Class, studentName);
					if (!Class.eof()) cout << left << setw(4) << i << setw(10) << studentID << setw(9) << courseClass << studentName << endl;
					i++;
				}
			Class.close();
		}
	ifs.close();
    cout << "--------------------" << endl;
}