#include "main.h"
#include "studentInAClass.h"
#include "removeAStudent.h"
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

        int move; 
        ifstream fin;

        cout << "1. Add students of class (by importing file)\n";
        cout << "2. View students in class\n";
        cout << "3. Add 1 student\n";
        cout << "4. Remove 1 student\n";
        cout << "5. View list of students in the class\n";
        cout << "0. Return to previous menu\n";
        
        do {
            cout << "Pls enter your move: ";
            cin >> move;      
            switch (move)
            {
                case 1:
                    inputStudentsToClass(pHeadClass -> Students);
                    break;
                case 2: 
                    displayListOfStudents(pHeadClass -> Students);
                    break;
                case 3:
                    addAStudent(pHeadClass -> Students, fin);
                    break;
                case 4:
                    removeAStudent(pHeadClass -> Students);
                    break;
                case 5:
                    displayListOfStudents(pHeadClass -> Students);
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