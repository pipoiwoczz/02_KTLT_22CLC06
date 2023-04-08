#include "profileStudent.h"

void profileStudent(string username, SchoolYear* headSY)
{
	system("cls");
	string SY, Class;
	ifstream ifs;
	ifs.open("./profile/" + username + ".txt");
		for (int i = 0; i < 3; i++) getline(ifs, SY);
		getline(ifs, Class);
	ifs.close();

	int choice;

	cout << "\t\tMENU\n";
	cout << "---------------------------\n";
	cout << "1. View profile\n";
	cout << "2. Change profile\n";
	cout << "3. View courses you will study in this semester\n";
	cout << "4. View class schedule\n";
	cout << "5. View scoreboard\n";
	cout << "0. Log out\n";
	cout << "Your choice: ";
	
	do {
		cin >> choice;
		switch (choice) {
			case 1: // FUNCTION viewProfile()
				return profileStudent(username);
				break;
			case 2: // FUNCTION changeProfileStudent()
				return profileStudent(username);
				break;
			case 3: 
				viewCourseStudent(username);
				return profileStudent(username);
				break;
			case 4: // FUNCTION viewClassSchedule()
				return profileStudent(username);
				break;
			case 5:
				scoreboard_menu(username, Class, SY);
				return profileStudent(username);
				break;
			case 0:
				cout << "LOGGED OUT SUCCESSFULLY.\n";
				getch();
				return main_menu(headSY);
				break;
		}
	} while (choice >= 1 && choice <= 5);
}

void scoreboard_menu(string username, string Class, string SY)
{
	ifstream ifs;
	viewStudentScoreboard(username);
	int opt;
	cout << "What do you want to do next?\n";
	cout << "1. Choose a semester to view scoreboard\n";
	cout << "2. View all scoreboard of all semesters\n";
	cout << "3. Exit\n";
	cout << "Your option: ";
	do {
		cin >> opt;
		switch (opt)
		{
			case 1: {
				string sem;
				ifs.open("./" + SY + "/" + Class + "/" + username + "/total.txt");
				getline(ifs, sem);
				getline(ifs, sem);
				while (!ifs.eof()) {
					getline(ifs, sem);
					cout << sem << endl;
				}
				ifs.close();
				cout << "Enter the semester you want to ";
				cin >> sem;
				viewStudentScoreboardChooseSem(username, sem, SY);
				break;
			}
			case 2: viewStudentScoreboardAllCourses(username, SY); break;
			default: break;
		}
	} while (opt >= 1 && opt <= 2);
	cout << "=======================\n";
	cout << "Press any keys to continue\n";
	getch();
}