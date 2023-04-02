#include "SYmenu.h"
#include "main.h"
#include "createSemester.h"
#include "profile.h"
#include "SEmenu.h"
#include "createClasses.h"
#include "menuClass.h"
#include <iostream>
#include <string>
using namespace std;

void SYMenu(string username, schoolYear *& curSY, Semester *& headSemester, Class *& headClass, schoolYear * headSY) {

    system("cls");
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
            createSemester(username, curSY, headSemester, headClass);
            return SYMenu(username, curSY, headSemester, headClass, headSY);
            break;
        }

        case 2: {
            Semester * cur = headSemester;
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
            SYMenu(username, curSY, headSemester, headClass, headSY);
        }
            break;

        case 3: {
            Semester * cur = headSemester;

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

            return SEMenu( username, curSY, headSemester, headClass, choice, headSY);
        }

        case 4:
            createClass(headClass, headSY);
            system("pause");
            SYMenu(username, curSY, headSemester, headClass, headSY);
            break;

        case 5: {
            Class *curClass = headClass;

            if (!curClass) {
                cout << "There is no class now!!\n";
                system("pause");
                return SYMenu(username, curSY, headSemester, headClass, headSY);
            } else {
                while (curClass) {
                    cout << curClass -> name << endl;
                    curClass = curClass -> next;
                }
            }
            system("pause");
            SYMenu(username, curSY, headSemester, headClass, headSY);
            break;
        }
            break;

        case 6: {
            Class *curClass = headClass;

            if (!curClass) {
                cout << "There is no class now!!\n";
                system("pause");
                return SYMenu(username, curSY, headSemester, headClass, headSY);
            } else {
                while (curClass) {
                    cout << curClass -> name << endl;
                    curClass = curClass -> next;
                }

                curClass = headClass;

                do {
                    cout << "==================\n";
                    cout << "Please enter class's name: ";
                    cin >> nameClass;

                    while (curClass && curClass -> name != nameClass)
                    curClass = curClass -> next;

                    if (curClass == nullptr)
                    {
                        cout << "You've entered a non-exist class name.\n";
                        curClass = headClass;
                    } else {
                        return classMenu(headClass, nameClass, username, headSY, headSemester, headClass, curSY);
                    }

                } while (1);

            }
        }
            break;
        case 0:
            return profile_menu(username, headSY, headSemester, headClass);
            break;
    }
}