#include "SYmenu.h"
#include "main.h"
#include "createSemester.h"
#include <iostream>
using namespace std;

void SYMenu(Semester *&headSemester) {
    system("cls");
    cout << "1. Create Semester\n";
    cout << "2. View available Semester\n";
    cout << "3. Choose available Semester\n";
    cout << "0. Back to previous menu\n";

    int move;
    cout << "======================\n";
    do {
        cout << "Enter your move: ";
        cin >> move;
    }
    while (move > 3 || move < 0);

    switch (move) {
        case 1: {
            createSemester(headSemester);
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

            // if (choice == 1) 
            //     return SEMenu(headSemester);
            // if (choice == 2) 
            //     return SEMenu(headSemester -> next);
            // if (choice == 3) 
            //     return SEMenu(headSemester -> next -> next);
        }
    }
}