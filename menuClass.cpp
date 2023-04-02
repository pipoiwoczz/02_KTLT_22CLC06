#include "main.h"
#include "studentInAClass.h"
#include "removeAStudent.h"
#include "Add1StToClass.h"
#include "SYmenu.h"
#include "profile.h"
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

void classMenu(Class *&pHeadClass, string nameClass, string username, schoolYear *& headSY, Semester *& headSemester, Class *& headClass, schoolYear *& curSY)
{
    Class *curClass = pHeadClass;

    while (curClass -> name != nameClass) {
        curClass = curClass -> next;
    }
        system("cls");
        int move; 
        ifstream fin;

        cout << "1. Add students of class (by importing file)\n";
        cout << "2. View students in class\n";
        cout << "3. Add 1 student\n";
        cout << "4. Remove 1 student\n";
        cout << "0. Return to previous menu\n";
        cout << "=========================\n";
        
        do {
            cout << "Pls enter your move: ";
            cin >> move;      
            switch (move)
            {
                case 1:
                    inputStudentsToClass(curClass -> Students, curSY, curClass);
                    system("pause");
                    classMenu(pHeadClass, nameClass, username, headSY, headSemester, headClass, curSY);
                    break;
                case 2: 
                    displayListOfStudents(curClass -> Students);
                    system("pause");
                    classMenu(pHeadClass, nameClass, username, headSY, headSemester, headClass, curSY);
                    break;
                case 3:
                    add1StToClass(curClass -> Students, curSY, curClass);
                    system("pause");
                    classMenu(pHeadClass, nameClass, username, headSY, headSemester, headClass, curSY);
                    break;
                case 4:
                    removeAStudent(curClass -> Students);
                    system("pause");
                    classMenu(pHeadClass, nameClass, username, headSY, headSemester, headClass, curSY);
                    break;
                case 0:
                    return SYMenu(username, curSY, headSemester, headClass, headSY);
                    break;
                default:
                    cout << "You've entered wrong move\n";
                    cout << "Pls enter your move again: \n";
                    break;
            }              
        } while (move < 0 || move > 5);
}