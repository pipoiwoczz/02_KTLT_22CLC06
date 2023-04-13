#include "updateCourseInfor.h"
#include "main.h"

void updateCourseInfor(string curSY, int season, string &courseID)
{
	string courseName = "0";
	string className, teacherName, dayOfWeek, session;
	int numberOfStudent;
	int credits = 0;
	ifstream ifs, fin;
	ofstream ofs;


	system("cls");
	int opt = -1;
	cout << courseID << endl;
	cout << "What do you want to update?";
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
			cin >> courseID;
		}
		if (opt == 2) {
			cin.ignore();
			cout << "New course name: ";
			getline(cin, courseName);
		}
		if (opt == 3) {
			cout << "New number of credits: ";
			cin >> credits;
		}
		if (opt == 4) {
			cout << "New course ID: ";
			cin >> courseID;
			cin.ignore();
			cout << "New course name: ";
			getline(cin, courseName);
			cout << "New number of credits: ";
			cin >> credits;
		}
		cout << "Updated successfully!\n\n";
		cout << "Option: ";
		cin >> opt;
	}

	// Update to all course classes
	string path = curSY + "//" + to_string(season) + "//" + courseID + "//class.txt";

	ifs.open(path);
	if (ifs.is_open()) {
		string tmp;
		while (getline (ifs, tmp)) {
			string infoPath = curSY + "//" + to_string(season) + "//" + courseID + "//" + tmp + "//info.txt";

			// get info of course class
			fin.open(infoPath);
			fin >> tmp;
			if (courseName == "0") fin >> courseName;
			else fin >> tmp;
			fin >> className;
			fin >> teacherName;
			if (credits == 0) fin >> credits;
			else fin >> tmp;
			fin >> numberOfStudent;
			fin >> dayOfWeek;
			fin >> session;
			fin.close();

			ofs.open(infoPath);
			ofs << courseID << endl;
			ofs << courseName << endl;
			ofs << className << endl;
			ofs << teacherName << endl;
			ofs << credits << endl;
			ofs << numberOfStudent << endl;
			ofs << dayOfWeek << endl;;
			ofs << session << endl;
			ofs.close();
		}
		ifs.close();
	}
}

void updateInforClassCourse(schoolYear* curSY, Semester* curSemester, Course*& curCourse)
{
	system("clear");

	CourseClass* currCC = curCourse->CourseClass;
	cout << "===================================\n";
	cout << "\t\tCourse classes\n";
	if (!currCC) {
		cout << "There is no classes now.\n";
		return;
	}
	while (currCC) {
		cout << currCC->className << endl;
		currCC->next;
	}
	currCC = curCourse->CourseClass;

	do {
		if (!currCC) 
			cout << "You entered an invalid class name.\nPlease enter again.\n";

		currCC = curCourse->CourseClass;
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
	cout << endl << currCC->className << endl;
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
			cin >> currCC->className;
		}
		if (opt == 2) {
			cin.ignore();
			cout << "New teacher name: ";
			getline(cin, currCC->teacherName);
		}
		if (opt == 3) {
			cout << "New day of week: ";
			cin >> currCC->dayOfWeek;
		}
		if (opt == 4) {
			cout << "New session: ";
			cin >> currCC->session;
		}
		if (opt == 5) {
			cout << "New class name: ";
			cin >> currCC->className;

			cin.ignore();
			cout << "New teacher name: ";
			getline(cin, currCC->teacherName);

			cout << "New day of week: ";
			cin >> currCC->dayOfWeek;

			cout << "New session: ";
			cin >> currCC->session;
		}
		cout << "\n Updated successfully.\n";
		cout << "Your option: ";
		cin >> opt;
	}

	string pathInfo = "./" + curSY->name + "/" + to_string(curSemester->season) + "/" + curCourse->courseID + "/" + currCC->className + "/info.txt";
	ofstream fout(pathInfo);
		fout << curCourse->courseID << endl;
		fout << curCourse->courseName << endl;
		fout << currCC->className << endl;
		fout << currCC->teacherName << endl;
		fout << curCourse->credits << endl;
		fout << currCC->numberOfStudent << endl;
		fout << currCC->dayOfWeek << endl;
		fout << currCC->session << endl;
	fout.close();
}