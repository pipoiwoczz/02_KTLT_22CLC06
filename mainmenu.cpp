#include <iostream>
#include "mainMenu.h"
using namespace std;

void mainMenu() {
    system("cls");
    cout << "Main menu\n";
    cout << "1. Register\n";
    cout << "2. Log In\n";
    cout << "0. Stop Program\n";
    cout << "Your choice is: ";
    mainMenu_Opt();
}

void mainMenu_Opt() {
    int choice;
    
    do {
        cin >> choice;
        switch (choice) {
            case 1: 
                cout << "Log in PAGE!! \n"; // enter login function here
                break;
            case 2:
                cout << "Sign out PAGE!! \n"; // enter register function here
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