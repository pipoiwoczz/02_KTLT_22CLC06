#include <iostream>
#include "main.h"
#include "mainmenu.h"
#include "login.h"
#include "profile.h"
#include <string>
#include <cstring>
using namespace std;

void mainMenu(schoolYear *& headSY, Semester *& headSemester, Class *& headClass) {
    system("cls");
    cout << "Main menu\n";
    cout << "1. Register\n";
    cout << "2. Log In\n";
    cout << "0. Stop Program\n";
    cout << "Your choice is: ";

    int choice;
    
    do {
        cin >> choice;
        switch (choice) {
            case 1: 
                signUp();
                break;
            case 2:
                login(headSY, headSemester, headClass);
                break;
            case 0:
                return;
            default:
                cout << "This is an invalid choice!!\n";
                cout << "Please choose again\n";
                cout << "Your choice is: ";
                cin >> choice;
                break;
        }
    } while (choice > 2 || choice < 0);
}
