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
	do {
		cout << courseID << endl;
		cout << "What do you want to update?";
		cout << "\n1. Course ID\n";
		cout << "2. Course Name\n";
		cout << "3. Number of credits\n";
		cout << "4. All above\n";
		cout << "QUIT, PRESS 0" << endl;
		cout << "Your choice: ";
		cin >> opt;

		if (opt == 1) {
			cout << "New course ID: ";
			cin >> courseID;
		} else if (opt == 2) {
			cin.ignore();
			cout << "New course name: ";
			getline(cin, courseName);
		} else if (opt == 3) {
			cout << "New number of credits: ";
			cin >> credits;
		} else if (opt == 4) {
			cout << "New course ID: ";
			cin >> courseID;
			cin.ignore();
			cout << "New course name: ";
			getline(cin, courseName);
			cout << "New number of credits: ";
			cin >> credits;
		}
		cout << "Updated successfully!\n\n";
	} while (opt != 0);

	// Update to all course classes
	string path = "./" + curSY + "/" + to_string(season) + "/" + courseID + "/class.txt";

	ifs.open(path);
	if (ifs.is_open()) {
		string tmp;
		while (getline (ifs, tmp)) {
			string infoPath = "./" + curSY + "/" + to_string(season) + "/" + courseID + "/" + tmp + "/info.txt";

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

void updateInforClassCourse(string curSY, string curSemester, string curCourse)
{
	system("clear");

	string courseClass, classname, chosenClass;
	ifstream ifs;
	ifs.open("./" + curSY + "/" + curSemester + "/" + curCourse + "/class.txt");
		cout << "--------------------" << endl;
		cout << "Course classes" << endl;
		cout << "----------" << endl;
		if (!ifs.is_open()) {
			cout << "There is no class in this course" << endl;
			cout << "----------" << endl;
			ifs.close();
			return;
		}
		while (!ifs.eof()) {
			getline(ifs, courseClass);
			cout << courseClass << endl;
		}
		cout << "----------" << endl;
	ifs.close();

	ifs.open("./" + curSY + "/" + curSemester + "/" + curCourse + "/class.txt");
		bool exist = false;
		do {
			ifs.seekg(SEEK_SET);
			cout << "--------------------" << endl;
			cout << "Enter your class name: ";
			cin >> chosenClass;
			while (!ifs.eof()) {
				getline(ifs, classname);
				if (chosenClass == classname) {
					exist = true;
					break;
				}
			}
			if (!exist) cout << "You entered an invalid class name.\nPlease enter again.\n";
			cout << "--------------------" << endl;
		} while (!exist);
	ifs.close();

	int opt = -1;
	cout << chosenClass << endl;
	cout << "What do you want to update?\n";
	cout << "1. Class name\n";
	cout << "2. Teacher name\n";
	cout << "3. Day of week\n";
	cout << "4. Session\n";
	cout << "5. All above\n";
	cout << "PRESS 0 TO STOP\n";
	cout << "Your option: ";
	cin >> opt;
	string teacherName, dayOfWeek, Session;
	while (opt != 0) {
		if (opt == 1) {
			cout << "New class name: ";
			cin >> classname;
		}
		if (opt == 2) {
			cin.ignore();
			cout << "New teacher name: ";
			getline(cin, teacherName);
		}
		if (opt == 3) {
			cout << "New day of week: ";
			cin >> dayOfWeek;
		}
		if (opt == 4) {
			cout << "New session: ";
			cin >> Session;
		}
		if (opt == 5) {
			cout << "New class name: ";
			cin >> classname;

			cin.ignore();
			cout << "New teacher name: ";
			getline(cin, teacherName);

			cout << "New day of week: ";
			cin >> dayOfWeek;

			cout << "New session: ";
			cin >> Session;
		}
		cout << "\n Updated successfully.\n";
		cout << "Your option: ";
		cin >> opt;
	}

	string pathInfo = "./" + curSY + "/" + curSemester + "/" + curCourse + "/" + chosenClass + "/info.txt";
	fstream fout;
	fout.open(pathInfo, ios::in|ios::out);
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