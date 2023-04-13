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

void SYMenu(string username, string curSY) {

    system("cls");
    cout << "\tSchool Year Menu: " << curSY << endl;
    cout << "1. Create Semester\n";
    cout << "2. View available Semester\n";
    cout << "3. Choose available Semester\n";
    cout << "4. Create Class\n";
    cout << "5. View available Class\n";
    cout << "6. Choose available Class\n";
    cout << "0. Back to previous menu\n";

    int move;

    cout << "======================\n";
    do {
        cout << "Enter your move: ";
        cin >> move;
    }
    while (move > 6 || move < 0);

    switch (move) {
        case 1: {
            createSemester(username, curSY);
            return SYMenu(username, curSY);
            break;
        }           // done case 1

        case 2: {
            ifstream ifs;
            ifs.open(curSY + "/semester.txt");

            if (!ifs.is_open()) {
                cout << "There is no Semester created yet";
                cout << "Please create Semesters first!\n";
            } else {    
                string tmp;
                while (getline (ifs, tmp)) {
                    if (tmp == "1") cout << "Spring\n";
                    if (tmp == "2") cout << "Summer\n" ;
                    if (tmp == "3") cout << "Autumn\n";
                }
                ifs.close();
            }

            system("pause");
            return SYMenu(username, curSY);
        }           // done case 2

        case 3: {
            int i = 1; 
            ifstream ifs;
            ifs.open(curSY + "/semester.txt");
            if (!ifs.is_open()) {
                cout << "There is no Semester created yet";
                cout << "Please create Semesters first!\n";
                return SYMenu(username, curSY);
            } else {    
                string tmp;
                while (getline (ifs, tmp)) {
                    cout << i;
                    if (tmp == "1") cout << ". Spring\n";
                    if (tmp == "2") cout << ". Summer\n" ;
                    if (tmp == "3") cout << ". Autumn\n";
                    i++;
                }
                ifs.close();
            
            }

            int choice;
            do {
                cout << "==================\n";
                cout << "Enter your move: ";
                cin >> choice;
                if (choice >= i || choice < 1)  {
                    cout << "You've entered wrong choice.\n";
                    cout << "Please try again.\n";
                }
            } while (choice >= i || choice < 1);

            ofstream ofs;

            //  Modify curTime.txt
            ofs.open("curTime.txt");
            ofs << curSY << endl << choice;         
            ofs.close();

            return SEMenu(username,curSY, choice);
        }

        case 4:
            createClass(username, curSY);
            system("pause");
            SYMenu(username, curSY);
            break;

        case 5: {
            ifstream ifs;
            string path_SY_classtxt = curSY + "/" + "class.txt";

            ifs.open(path_SY_classtxt.c_str());
    
            if (!ifs.is_open()) {
                cout << "There is no class now!!\n";
                cout << "Please create classes first!!\n";
                
                ifs.close();
                return SYMenu(username, curSY);
            }

            cout << "Current available school year: \n";
            
            string tmp;

            while (getline(ifs, tmp))   
                cout << tmp << endl;
            
            ifs.close();
            return SYMenu(username, curSY);
        }

        case 6: {
            ifstream ifs;
            string path_SY_classtxt = curSY + "/" + "class.txt";

            ifs.open(path_SY_classtxt.c_str());
    
            if (!ifs.is_open()) {
                cout << "There is no class now!!\n";
                cout << "Please create classes first!!\n";
                
                ifs.close();
                return SYMenu(username, curSY);
            }

            cout << "Current available school year: \n";
            
            string tmp;

            while (getline(ifs, tmp))   
                cout << tmp << endl;
            

            string nameClass;

            cout << "==================\n";
            cout << "Please enter class's name: ";
            cin >> nameClass;

            
            int flag = 0;

            while (getline(ifs, tmp))   {
                if (tmp == nameClass)   {
                    flag == 1;
                    break;
                }
            }

            if (flag == 0)  {
                ifs.close();

                cout << "You've entered a non-existed class name.\n";
                cout << "Please press enter to return to the current school year menu.\n";
                system("pause");
                return SYMenu(username, curSY);
            }

            return classMenu(username, curSY, nameClass);
            }
        case 0:
            return profile_menu(username);
            break;
        }   
}
