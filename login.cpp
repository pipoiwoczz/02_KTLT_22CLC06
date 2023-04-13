#include "profile.h"
#include "login.h"
#include "mainMenu.h"
#include <iostream>
#include <cstring>
#include <string>
#include <conio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "profileStudent.h"
using namespace std;

void createFolder(char *name) {
    mkdir(name);
}

bool isValidUsername(char *username) {
    unsigned int le = strlen(username);

    if (le == 0) return false;
    
    for (unsigned int i = 0; i < le; i++) {
        if (!((username[i] >= 'A' && username[i] <= 'Z') || (username[i] >= 'a' && username[i] <= 'z') || (username[i] >= '0' && username[i] <= '9'))) {
            cout << "Please enter a valid username!!\n";
            cout << "A valid user name cann't include special char or spacing\n";
            system("pause");
            return false;
        }
    } 

    return true;
}

bool isStaff() {
    string code;
    int x;

    while (true) {
            cout << "Enter teacher key code to prove you're a teacher!!\n";
            cin >> code;
            if (code == "CS101") {
                cout << "You enter correct key!!\n";
                cout << "Now you can start your register\n\n";
                return true;
            } else {
                cout << "You enter wrong key!!\n";
                cout << "You can input 1 to enter again or 0 back to main menu\n";
                do {
                    cin >> x;
                    if (x == 0) {
                        mainMenu();
                        return false;
                    }
                    if (x == 1) break;
                } while (x > 1 || x < 0);
            }
    }

    return true;
}

void signUp(){
    system("cls");
    cin.ignore();
    char *username, *password;
    char tmp[1000] = {0}, sTmp[1000] = "User\\";


    cout << "REGISTER PAGE!!\n\n";

    cout << "You can only sign up as a teacher: \n";
    cout << "=================================\n";
    isStaff();
    unsigned le;
    do { //////// NEW HERE
        cout << "Enter username (The username must not be equal to 8 numbers): ";
        cin >> tmp;
        if (strlen(tmp) != 8) break;
        for (int i=0; i<8; i++) {
            if (!isdigit(tmp[i])) break;
        }
        cout << "The username must include at least a letter or a special character" << endl;
        cout << "Please enter a valid username!" << endl;

    } while (true); ///// END NEW
    le = strlen(tmp) + 1;
    username = new char[le];
    strcpy(username, tmp);

    strcat(sTmp, username);
    strcat(sTmp,  ".txt"); // Create a path leading to the file saving user info

    cout << "Enter password: ";
    // cin.ignore();
    // cin.getline(tmp, 1000, '\n');
    cin >> tmp;

    le = strlen(tmp) + 1;
    password = new char[le];
    strcpy(password, tmp);

    if (!isValidUsername(username)) {
        return mainMenu();
    }

    char name[] = "User";
    createFolder(name);

    FILE *fi, * fc;

    fc = fopen(sTmp, "r");
    if (fc == NULL) ;
    else {
        cout << "This user name has been already exist!\n";
        cout << "Please choose another username!!\n";
        system("pause");
        delete password;
        delete username;
        signUp();
        return;
    }

    // Them tai khoan vao folder luu tru

    fi = fopen(sTmp, "w");
    fprintf(fi, "%s\n", username);
    fprintf(fi, "%s\n", password);
    fprintf(fi, "\n");
    fclose(fi);

    cout << "You signed in successfully!!\n";
    cout << "Now you can log in with your account\n";
    system("pause");

    fclose(fi);

    delete password;
    delete username;

    mainMenu();
}


void login() {
    system("cls");
    string username, password;

    cout << "LOG IN PAGE!!\n\n";

    cout << "Enter your username: "; 
    // cin.ignore();
    cin >> username;

    cout << "Enter your password: ";
    // cin.ignore();
    cin >> password;

    bool isStudent = true;
    if (username.length() == 8) {
        for (char c : username) {
            if (!isdigit(c)) {
                isStudent = false; 
                break;
            }
        }
    } else {
        isStudent = false;
    }
    

    string tmp;
    if (isStudent) tmp = "./profile/";
    else tmp = "User/";
    tmp += username + ".txt";

    string passTmp, usernameTmp;

    ifstream ifs;
    ifs.open(tmp);
    if (!ifs.is_open()) {
        cout << "This account is not exist!!\n";
        cout << "What do you want to do now?\n";
        system("pause");
        return mainMenu();
    }

    getline(ifs, usernameTmp);
    getline(ifs, passTmp);

    if (password != passTmp) {
        cout << "You entered a wrong password!!\n";
        system("pause");
        ifs.close();
        return mainMenu();
    }

    ifs.close();

    cout << "Log in successfully !!\n\n";

    string tmpUser = username;
    unsigned int le = username.length();

    system("pause");
    if (isStudent) return profileStudent(username);
    return profile_menu(tmpUser);
}