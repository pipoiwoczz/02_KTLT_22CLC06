#include "profileStudent.h"

void profileStudent(string username)
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
			case 1:
				viewProfileStudent(username);
				return profileStudent(username);
				break;
			case 2:
                changeProfile(username);
				return profileStudent(username);
				break;
			case 3: 
				viewCoursesStudent(username);
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
				system("pause");
				return mainMenu();
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
			case 2: viewStudentScoreboardAllCourses(username); break;
			default: break;
		}
	} while (opt >= 1 && opt <= 2);
	cout << "=======================\n";
	cout << "Press any keys to continue\n";
	system("pause");
}

void viewProfileStudent(string studentID)
{
	string pathProfile = "./profile/" + studentID + ".txt";
	string temp;
	ifstream ifs(pathProfile);
	if (!ifs.is_open()) {
		cout << "Something went wrong. Please try again.\n\n\n";
		system("pause");
		return;
	}

	getline(ifs, temp);
	cout << "\nUsername: " << temp << endl;

	getline(ifs, temp);
	cout << "Password: " << temp << endl;

	getline(ifs, temp);
	cout << "Current school year: " << temp << endl;

	getline(ifs, temp);
	cout << "Class: " << temp << endl;

	getline(ifs, temp);
	cout << "Student ID: " << temp << endl;

	getline(ifs, temp);
	cout << "First name: " << temp << endl;

	getline(ifs, temp);
	cout << "Last name: " << temp << endl;

	getline(ifs, temp);
	cout << "Gender: " << temp << endl;

	getline(ifs, temp);
	cout << "Date of birth: " << temp << endl;

	getline(ifs, temp);
	cout << "Social ID: " << temp << endl;

	ifs.close();
	cout << "\nPress any key to continue.\n";
	system("pause");
}

void changeProfile(string studentID) {
    int choice;
    string filename = "profile\\" + studentID + ".txt";
    string tmp;
    string confirmPass;
    char* tmpfile;
    ifstream in;
    ofstream out;

    unsigned int le = filename.length();
    tmpfile = new char[le + 1];
    for (unsigned int i = 0; i <= le; i++) {
        tmpfile[i] = filename[i];
    }

    cout << "\tWhat do you want to edit?\n";

    cout << "1. All Profile\n";
    cout << "2. Password\n";
    cout << "3. First Name\n";
    cout << "4. Last Name\n";
    cout << "5. Gender\n";
    cout << "6. Date Of Birth\n";
    cout << "7. Social ID\n";
    cout << "0. Back to profile menu\n";

    cout << "================================\n";
    cout << "Your choice is: ";

    do {
        cin >> choice;
        int line = 1;

        switch (choice) {

        case 1:
            in.open(filename);
            out.open("profile\\tmp.txt");

            getline(in, tmp);
            out << tmp << endl;
            line++;
            getline(in, tmp);

            if (line == 2) {
                cin.ignore();
                cout << "Enter the current password: ";
                cin >> confirmPass;

                while (confirmPass != tmp) {
                    cout << "Password wrong!\nPlease enter the password again.\n";
                    cout << "Enter the current password: ";
                    cin >> confirmPass;
                }

                cout << "Enter new password: ";
                cin >> confirmPass;

                out << confirmPass << "\n";
            }

            getline(in, tmp);
            out << tmp << endl;

            cout << "Enter your teacher ID: ";
            cin >> tmp;
            out << tmp << endl;


            cin.ignore();
            cout << "Enter your first name: ";
            getline(cin, tmp);
            out << tmp << endl;

            cin.ignore();
            cout << "Enter your last name: ";
            getline(cin, tmp);
            out << tmp << endl;

            cout << "Please choose your gender: \n";
            cout << "1. Male\n";
            cout << "2. Female\n";
            cout << "3. Undefined\n";
            cout << "=================================\n";
            cout << "Your gender is: ";

            int gender;

            do {
                cin >> gender;
                if (gender >= 1 && gender <= 3)
                    out << gender << "\n";
                else {
                    cout << "You've entered an invalid numbers!!\n";
                    cout << "Please enter again\n";
                }
            } while (gender < 1 || gender > 3);

            int day, month, year;
            cout << "Enter your date of birth (dd mm yy): ";
            do {
                cin >> day >> month >> year;
                if (isValidBirth(day, month, year) == false) {
                    cout << "You've enter an invalid date of birth!!\n";
                    cout << "Please enter your date of birth again\n!!";
                    cout << "Enter day, month, year respectively!!\n";
                    cout << "=========================================\n";
                }
            } while (isValidBirth(day, month, year) == false);
            out << day << " " << month << " " << year << endl;

            int ID;
            cout << "Please enter your social ID: ";
            cin >> ID;
            out << ID << endl;


            in.close();
            out.close();

            remove(tmpfile);
            rename("profile\\tmp.txt", tmpfile);
            delete(tmpfile);

            break;

        case 2:
            in.open(filename);
            out.open("profile\\tmp.txt");
            while (getline(in, tmp)) {

                if (line == 2) {
                    cout << "Enter the current password: ";
                    cin >> confirmPass;

                    while (confirmPass != tmp) {
                        cout << "Password wrong!\nPlease enter the password again.\n";
                        cout << "Enter the current password: ";
                        cin >> confirmPass;
                    }

                    cout << "Enter new password: ";
                    string newPass;
                    cin >> newPass;

                    out << newPass << "\n";
                }
                else {
                    out << tmp << "\n";
                }

                line++;
            }

            in.close();
            out.close();

            remove(tmpfile);
            rename("profile\\tmp.txt", filename.c_str());
            delete(tmpfile);

            break;

        case 3:
            in.open(filename);
            out.open("profile\\tmp.txt");
            while (getline(in, tmp)) {

                if (line == 5) {
                    string fName;
                    cin.ignore();
                    cout << "Enter your first name: ";
                    getline(cin, fName);

                    out << fName << "\n";
                }
                else {
                    out << tmp << "\n";
                }

                line++;
            }

            in.close();
            out.close();

            remove(tmpfile);
            rename("profile\\tmp.txt", tmpfile);
            delete(tmpfile);

            break;

        case 4:
            in.open(filename);
            out.open("User\\tmp.txt");
            while (getline(in, tmp)) {

                if (line == 6) {
                    string lName;
                    cin.ignore();
                    cout << "Enter your last name: ";
                    getline(cin, lName);

                    out << lName << "\n";
                }
                else {
                    out << tmp << "\n";
                }

                line++;
            }

            in.close();
            out.close();

            remove(tmpfile);
            rename("profile\\tmp.txt", filename.c_str());
            delete(tmpfile);

            break;

        case 5:
            in.open(filename);
            out.open("profile\\tmp.txt");
            while (getline(in, tmp)) {

                if (line == 7) {
                    // int gender;

                    cout << "Please choose your gender: \n";
                    cout << "1. Male\n";
                    cout << "2. Female\n";
                    cout << "3. Undefined\n";
                    cout << "=================================\n";
                    cout << "Your gender is: ";

                    do {
                        cin >> gender;
                        if (gender >= 1 && gender <= 3)
                            if (gender == 1) {
                                out << "Male" << endl;
                            }
                            else if (gender == 2) {
                                out << "Female\n";
                            }
                            else {
                                out << "Undefined\n";
                            }
                        else {
                            cout << "You've entered an invalid numbers!!\n";
                            cout << "Please enter again\n";
                        }
                    } while (gender < 1 || gender > 3);

                }
                else {
                    out << tmp << "\n";
                }

                line++;
            }

            in.close();
            out.close();

            remove(tmpfile);
            rename("profile\\tmp.txt", tmpfile);
            delete(tmpfile);

            break;

        case 6:
            in.open(filename);
            out.open("profile\\tmp.txt");
            while (getline(in, tmp)) {

                if (line == 8) {
                    // int day, month, year;
                    cout << "Enter your date of birth (dd/mm/yy): ";
                    do {
                        cin >> day >> month >> year;
                        if (isValidBirth(day, month, year) == false) {
                            cout << "You've enter an invalid date of birth!!\n";
                            cout << "Please enter your date of birth again\n!!";
                            cout << "Enter day, month, year respectively!!\n";
                            cout << "=========================================\n";
                        }
                    } while (isValidBirth(day, month, year) == false);
                }
                else {
                    out << tmp << "\n";
                }

                line++;
            }

            in.close();
            out.close();

            remove(tmpfile);
            rename("profile\\tmp.txt", tmpfile);
            delete(tmpfile);

            break;

        case 7:
            in.open(filename);
            out.open("User\\tmp.txt");
            while (getline(in, tmp)) {

                if (line == 9) {
                    // int ID;
                    cout << "Enter your social ID ";
                    cin >> ID;
                    out << ID << "\n";
                }
                else {
                    out << tmp << "\n";
                }

                line++;
            }

            in.close();
            out.close();

            remove(tmpfile);
            rename("profile\\tmp.txt", tmpfile);
            delete(tmpfile);

            break;

        case 0:
            return profile_menu(studentID.c_str());

        default:
            cout << "You've enter an invalid number!!\n";
            cout << "Please enter again\n\n";
            system("pause");
        }


    } while (choice < 0 || choice > 7);

    cout << "==================================\n";
    cout << "Press anykey to continue\n";
    system("pause");
}