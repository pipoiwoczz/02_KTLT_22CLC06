#include "updateCourseInfor.h"

void updateCourseInfor(schoolYear* curSY, Semester* curSemester, Course*& pCourse)
{
	string id;
	Course* curr = pCourse;
	cout << "Enter the course ID: ";
	cin >> id;
	while (curr) {
		if (curr->courseID == id) {
			int opt = -1;
			cout << "\n1. Course ID\n";
			cout << "2. Course Name\n";
			cout << "3. Teacher Name\n";
			cout << "4. Number of credits\n";
			cout << "5. Maximum number of students in the course\n";
			cout << "6. Day of the week\n";
			cout << "7. Session\n";
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
					cin.ignore();
					cout << "New teacher name: ";
					getline(cin, curr->teacherName);
				}
				if (opt == 4) {
					cout << "New number of credits: ";
					cin >> curr->credits;
				}
				if (opt == 5) {
					cout << "New maximum number of students: ";
					cin >> curr->maxStudents;
				}
				if (opt == 6) {
					cout << "New day of the week: ";
					cin >> curr->dayOfWeek;
				}
				if (opt == 7) {
					cout << "New session: ";
					cin >> curr->session;
				}
				cout << "Updated successfully!\n\n";
				cout << "Option: ";
				cin >> opt;
			}

			string pathCourse = "./" + curSY->name + "/" + to_string(curSemester->season) + "/" + curr->courseID + "/info.txt";
			ofstream fout(pathCourse);
			fout << curr->courseID << endl;
			fout << curr->courseName << endl;
			fout << curr->className << endl;
			fout << curr->teacherName << endl;
			fout << curr->credits << endl;
			fout << curr->numberOfStudent << endl;
			fout << curr->maxStudents << endl;
			fout << curr->dayOfWeek << endl;
			fout << curr->session;
			fout.close();
			return;
		}
		curr = curr->next;
	}
}