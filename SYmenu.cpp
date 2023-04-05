#include "SYmenu.h"
#include "main.h"
#include "createSemester.h"
#include "profile.h"
#include "SEmenu.h"
#include "createClasses.h"
#include "menuClass.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

void SYMenu(string username, schoolYear *& headSY, schoolYear *& curSY) {

    system("cls");
    cout << "\tSchool Year Menu: " << curSY -> name << endl;
    cout << "1. Create Semester\n";
    cout << "2. View available Semester\n";
    cout << "3. Choose available Semester\n";
    cout << "4. Create Class\n";
    cout << "5. View available Class\n";
    cout << "6. Choose available Class\n";
    cout << "0. Back to previous menu\n";

    int move;
    string nameClass;

    cout << "======================\n";
    do {
        cout << "Enter your move: ";
        cin >> move;
    }
    while (move > 6 || move < 0);

    switch (move) {
        case 1: {
            createSemester(username, headSY, curSY);
            return SYMenu(username, headSY, curSY);
            break;
        }

        case 2: {
            Semester * cur = curSY -> Semesters;
            while (cur) {
                if (cur -> season == 1) {
                    cout << "Spring\n";
                } else {
                    if (cur -> season == 2) {
                        cout << "Summer\n";
                    } else {
                        cout << "Autumn\n";
                    }
                }
                cur = cur -> next;
            }
            system("pause");
            SYMenu(username, headSY, curSY);
        }
            break;

        case 3: {
            Semester * cur = curSY -> Semesters;

            int i = 1;
            while (cur) {
                if (cur -> season == 1) {
                    cout << i << ".Spring\n";
                } else {
                    if (cur -> season == 2) {
                        cout << i << ".Summer\n";
                    } else {
                        cout << i << ".Autumn\n";
                    }
                }
                cur = cur -> next;
                i++;
            }
            int choice;
            do {
                cout << "==================\n";
                cout << "Enter your move: ";
                cin >> choice;
            } while (choice > 3 || choice < 1);

            ofstream ofs;
            ifstream ifs;
            string tmp;
            ifs.open("SY.txt");
            ofs.open("tmp.txt");
            if (ifs.is_open()) {
                ofs << choice << endl;
                while (getline (ifs, tmp)) {
                    ofs << tmp << endl;
                }
            }            
            ofs.close();
            ifs.close();
            remove("SY.txt");
            rename("tmp.txt", "SY.txt");

            return SEMenu( username, headSY,curSY, choice);
        }

        case 4:
            createClass(curSY);
            system("pause");
            SYMenu(username, headSY, curSY);
            break;

        case 5: {
            Class *curClass = curSY -> Classes;

            if (!curClass) {
                cout << "There is no class now!!\n";
                system("pause");
                return SYMenu(username, headSY, curSY);
            } else {
                while (curClass) {
                    cout << curClass -> name << endl;
                    curClass = curClass -> next;
                }
            }
            system("pause");
            SYMenu(username, headSY, curSY);
            break;
        }
            break;

        case 6: {
            Class *curClass = curSY -> Classes;

            if (!curClass) {
                cout << "There is no class now!!\n";
                system("pause");
                return SYMenu(username, headSY, curSY);
            } else {
                while (curClass) {
                    cout << curClass -> name << endl;
                    curClass = curClass -> next;
                }

                curClass = curSY -> Classes;

                do {
                    cout << "==================\n";
                    cout << "Please enter class's name: ";
                    cin >> nameClass;

                    while (curClass && curClass -> name != nameClass)
                    curClass = curClass -> next;

                    if (curClass == nullptr)
                    {
                        cout << "You've entered a non-exist class name.\n";
                        curClass = curSY -> Classes;
                    } else {
                        return classMenu(username, headSY, curSY, nameClass);
                    }

                } while (1);

            }
        }
            break;
        case 0:
            return profile_menu(username, headSY);
            break;
    }
}