#include "updateCourseInfor.h"

void updateCourseInfor(schoolYear* curSY, Semester* curSemester, Course*& curCourse)
{
	system("clear");
	int opt = -1;
	cout << curCourse->courseID << endl;
	cout << "What do you want to update?"
	cout << "\n1. Course ID\n";
	cout << "2. Course Name\n";
	cout << "3. Number of credits\n";
	cout << "4. All above\n";
	cout << "QUIT, PRESS 0";
	cout << "Option: ";
	cin >> opt;
	while (opt != 0) {
		if (opt == 1) {
			cout << "New course ID: ";
			cin >> curr->courseID;
		}
		if (opt == 2) {
			cin.ignore();
			cout << "New course name: ";
			getline(cin, curr->courseName);
		}
		if (opt == 3) {
			cout << "New number of credits: ";
			cin >> curr->credits;
		}
		if (opt == 4) {
			cout << "New course ID: ";
			cin >> curr->courseID;
			cin.ignore();
			cout << "New course name: ";
			getline(cin, curr->courseName);
			cout << "New number of credits: ";
			cin >> curr->credits;
		}
		cout << "Updated successfully!\n\n";
		cout << "Option: ";
		cin >> opt;
	}

	// Update to all course classes
	string pathClasses = "./" + curSY->name + "/" + to_string(curSemester->season) + "/" + pCourse->courseID + "/class.txt";
	ifstream ifs(pathClasses);
		while (!ifs.eof()) {
			CourseClass* temp = pCourse->CourseClass;
			string classname;
			getline(ifs, classname);
				
			while (temp) {
				if (temp->className == classname) {
					string pahtClassInfor = "./" + curSY->name + "/" + to_string(curSemester->season) + "/" + pCourse->courseID + "/" + classInfo + "/info.txt";
					ofstream fout(pathClassInfor);
						fout << pCourse->courseID << endl;
						fout << pCourse->courseName << endl;
						fout << temp->className << endl;
						fout << temp->teacherName << endl;
						fout << pCourse->credits << endl;
						fout << temp->numberOfStudent << endl;
						fout << temp->dayOfWeek << endl;
						fout << temp->session << endl;
					fout.close();
					break;
				}
				temp = temp->next;
			}
		}
	ifs.close();
}

void updateInforClassCourse(schoolYear* curSY, Semester* curSemester, Course*& curCourse)
{
	system("clear");

	CourseClass* currCC = curCour->CourseClass;
	cout << "===================================\n";
	cout << "\t\tCourse classes\n";
	if (!currCC) {
		cout << "There is no classes now.\n";
		break;
	}
	while (currCC) {
		cout << currCC->className << endl;
		currCC->next;
	}
	currCC = curCour->CourseClass;

	do {
		if (!currCC) 
			cout << "You entered an invalid class name.\nPlease enter again.\n";

		curCC = curCourse->CourseClass;
		string classname;
		cout << "======================================\n";
		cout << "Enter your class name: ";
		cin >> classname;
		while (currCC && currCC->className != classname)
			currCC->next;
		if (currCC)
			break;
		else
			continue;
	} while (true);

	int opt = -1;
	cout << endl << curCC->className << endl;
	cout << "What do you want to update?\n";
	cout << "1. Class name\n";
	cout << "2. Teacher name\n";
	cout << "3. Day of week\n";
	cout << "4. Session\n";
	cout << "5. All above\n";
	cout << "PRESS 0 TO STOP\n";
	cout << "Your option: ";
	cin >> opt;
	while (opt != 0) {
		if (opt == 1) {
			cout << "New class name: ";
			cin >> curCC->className;
		}
		if (opt == 2) {
			cin.ignore();
			cout << "New teacher name: ";
			getline(cin, curCC->teacherName);
		}
		if (opt == 3) {
			cout << "New day of week: ";
			cin >> curCC->dayOfWeek;
		}
		if (opt == 4) {
			cout << "New session: ";
			cin >> curCC->session;
		}
		if (opt == 5) {
			cout << "New class name: ";
			cin >> curCC->className;

			cin.ignore();
			cout << "New teacher name: ";
			getline(cin, curCC->teacherName);

			cout << "New day of week: ";
			cin >> curCC->dayOfWeek;

			cout << "New session: ";
			cin >> curCC->session;
		}
		cout << "\n Updated successfully.\n";
		cout << "Your option: ";
		cin >> opt;
	}

	string pathInfo = "./" + curSY->name + "/" + to_string(curSemester->season) + "/" + pCourse->courseID + "/" + curCC->className + "/info.txt";
	ofstream fout(pathInfo);
		fout << pCourse->courseID << endl;
		fout << pCourse->courseName << endl;
		fout << temp->className << endl;
		fout << temp->teacherName << endl;
		fout << pCourse->credits << endl;
		fout << temp->numberOfStudent << endl;
		fout << temp->dayOfWeek << endl;
		fout << temp->session << endl;
	fout.close();
}