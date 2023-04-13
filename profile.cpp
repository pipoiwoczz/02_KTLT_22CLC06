#include "profile.h"
#include "main.h"
#include "login.h"
#include "createClasses.h"
#include "createSY.h"
#include "SYmenu.h"
#include "mainmenu.h"
#include "menuClass.h"
#include <cstring>
#include <string>
#include <iostream>
#include <stdio.h>
#include <fstream>
#include <conio.h>
using namespace std;

void viewProfile(string username) {
    string tmp;
    string filename = "User\\" + username + ".txt";
    ifstream ifs;

    ifs.open(filename, ios::in);
    if (!ifs.is_open()) {
        cout << "SOME THING WRONG \n\n\n";
        system("pause");
        return profile_menu(username);
    }
    getline(ifs, tmp);
    cout << "Username: " << tmp << endl;
    getline(ifs, tmp);
    cout << "Password: " << tmp << endl;
    getline(ifs, tmp);

    if (!getline(ifs, tmp)) {
        cout << "Teacher ID: None\n";
        cout << "First Name: None\n";
        cout << "Last Name: None\n";
        cout << "Gender: None\n";
        cout << "Date of Birth: None\n";
        cout << "Social ID: None\n";
        ifs.close();
        cout << "Press anykey to get back to profile menu\n\n";
        getch();
        profile_menu(username);
        return;
    }

    cout << "Teadcher ID: " << tmp << endl;
    
    getline(ifs, tmp);
    cout << "First Name: " << tmp << endl;

    getline(ifs, tmp);
    cout << "Last Name: " << tmp << endl;

    getline(ifs, tmp);
    cout << "Gender: " << tmp << endl;

    getline(ifs, tmp);
    cout << "Date Of Birth: " << tmp << endl;

    getline(ifs, tmp);
    cout << "Social ID: " << tmp << endl;

    ifs.close();

    cout << "Press anykey to get back to profile menu\n\n";
    getch();
    profile_menu(username);

}

void editProfile(string username){
    int choice;
    string filename = "User\\" + username + ".txt";
    string tmp;
    string confirmPass;
    char *tmpfile;
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
                out.open("User\\tmp.txt");

                    getline (in, tmp);
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
                rename("User\\tmp.txt", tmpfile);
                delete(tmpfile);

                break;

            case 2: 
                in.open(filename);
                out.open("User\\tmp.txt");
                while(getline(in, tmp)) {

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
                    } else {
                        out << tmp << "\n";
                    }

                    line++;
                }

                in.close();
                out.close();

                remove(tmpfile);
                rename("User\\tmp.txt", filename.c_str());
                delete(tmpfile);

                break;

            case 3: 
                in.open(filename);
                out.open("User\\tmp.txt");
                while(getline(in, tmp)) {

                    if (line == 5) {
                        string fName;
                        cin.ignore();
	                    cout << "Enter your first name: ";
	                    getline(cin, fName);

                        out << fName << "\n";
                    } else {
                        out << tmp << "\n";
                    }

                    line++;
                }

                in.close();
                out.close();

                remove(tmpfile);
                rename("User\\tmp.txt", tmpfile);
                delete(tmpfile);

                break;

            case 4:
                in.open(filename);
                out.open("User\\tmp.txt");
                while(getline(in, tmp)) {

                    if (line == 6) {
                        string lName;
                        cin.ignore();
	                    cout << "Enter your last name: ";
	                    getline(cin, lName);

                        out << lName << "\n";
                    } else {
                        out << tmp << "\n";
                    }

                    line++;
                }

                in.close();
                out.close();

                remove(tmpfile);
                rename("User\\tmp.txt", filename.c_str());
                delete(tmpfile);

                break;

            case 5:
                in.open(filename);
                out.open("User\\tmp.txt");
                while(getline(in, tmp)) {

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
                                } else if (gender == 2) {
                                    out << "Female\n";
                                } else {
                                    out << "Undefined\n";
                                }
                            else {
                                cout << "You've entered an invalid numbers!!\n";
                                cout << "Please enter again\n";
                            }
                        } while (gender < 1 || gender > 3);

                    } else {
                        out << tmp << "\n";
                    }

                    line++;
                }

                in.close();
                out.close();

                remove(tmpfile);
                rename("User\\tmp.txt", tmpfile);
                delete(tmpfile);

                break;

            case 6:
                in.open(filename);
                out.open("User\\tmp.txt");
                while(getline(in, tmp)) {

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
                    } else {
                        out << tmp << "\n";
                    }

                    line++;
                }

                in.close();
                out.close();

                remove(tmpfile);
                rename("User\\tmp.txt", tmpfile);
                delete(tmpfile);

                break;

            case 7:
                in.open(filename);
                out.open("User\\tmp.txt");
                while(getline(in, tmp)) {

                    if (line == 9) {
                        // int ID;
                        cout << "Enter your social ID ";
                        cin >> ID;
                        out << ID << "\n";
                    } else {
                        out << tmp << "\n";
                    }

                    line++;
                }

                in.close();
                out.close();

                remove(tmpfile);
                rename("User\\tmp.txt", tmpfile);
                delete(tmpfile);

                break;

            case 0:
                return profile_menu(username);

            default:
                cout << "You've enter an invalid number!!\n";
                cout << "Please enter again\n\n";
                system("pause");
        }


    } while (choice < 0 || choice > 7);

    cout << "==================================\n";
    cout << "Press anykey to continue\n";
    getch();
    editProfile(username);

}

bool isValidBirth(int day, int month, int year) {
    int max[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)) {
        max[2] = 29;
    }

    if (day <= 0 || month <= 0 || month > 12 || year <= 0) {
        return false;
    }

    if (day > max[month]) {
        return false;
    }

    return true;
}

void profile_menu(string username) {
    
    system("cls");
    int choice;

    cout << "\t\tMENU\n";
    cout << "===========================\n";
    cout << "1. View profile\n";
    cout << "2. Change profile\n";
    cout << "3. Create New School Year\n";
    cout << "4. View available School Year\n";
    cout << "5. Choose available School Year\n";
    cout << "0. Log out and back to main menu\n";
    cout << "===========================\n";
    cout << "Your choice is: ";
    
    do {
        cin >> choice;
        cout << "===========================\n";
        switch (choice) {
            case 1:
                return viewProfile(username);
            case 2:
                return editProfile(username);
            case 3:
                createSY();
                cout << "SY Created!!\n";
                system("pause");
                profile_menu(username);
                break;
            case 4: {
                // schoolYear * cur = headSY;
                // while(cur)  {
                //     cout << cur -> name << endl;
                //     cur = cur -> next;
                // }
                ifstream ifs("SY.txt");
                
                if (!ifs.is_open()) {
                    cout << "There is no school year now\n";
                } else {
                    string tmp;
                    while (getline (ifs, tmp)) {
                        cout << tmp << endl;
                    }
                    ifs.close();
                }
                system("pause");
                return profile_menu(username);
                break;
            }
            case 5: {
                // schoolYear * curSY = headSY;
                // while(curSY)  {
                //     cout << curSY -> name << endl;
                //     curSY = curSY -> next;
                // }

                cout << "/tAll School Year\n";
                
                ifstream ifs("SY.txt");
                
                if (!ifs.is_open()) {
                    cout << "There is no school year now\n";
                } else {
                    string tmp;
                    while (getline (ifs, tmp)) {
                        cout << tmp << endl;
                    }
                    ifs.close();
                }
                
                int move;

                string SY;
                cout << "Select your schooyear: ";
                cin >> SY;

                // curSY = headSY;
                // while (curSY) {
                //     if (curSY -> name == SY)
                //         break;
                //     else 
                //         curSY = curSY -> next;
                // }

                //     if (!curSY) {
                //         cout << "Please enter correct schoolyear (or if you want to back to previous menu, please enter 0): ";
                //         cin >> SY;
                //         if (SY == "0") 
                //             return profile_menu(username, headSY);
                //         curSY = headSY;
                //     }

                do {
                    ifs.open("SY.txt");
                
                    if (!ifs.is_open()) {
                        cout << "There is no school year now\n";
                        system("pause");
                        return profile_menu(username);
                    } else {
                        string tmp;
                        while (getline (ifs, tmp)) {
                            if (tmp == SY) {
                                ofstream ofs("curTime.txt");
                                ofs << SY << endl;
                                ofs.close();
                                return SYMenu(username, SY); // SY is now Cur SY
                            }
                        }
                        ifs.close();
                        cout << "You've enter an invalid school year\nPlease enter again\n";
                    }
                } while (!ifs.is_open());
                                
                break;
            }
            case 0: {
                cout << "You logged out successfully!!\n";
                getch();
                return mainMenu();
                break;
            }
            default:
                cout << "You entered an invalid number\n";
                cout << "Please enter again\n";
                break;
        }
    } while (choice < 0 || choice > 5);

}