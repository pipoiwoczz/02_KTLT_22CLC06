#include "main.h"
#include "studentInAClass.h"
#include "removeAStudent.h"
#include "profile.h"
#include <string>
#include <iostream>
#include <fstream>

void classMenu(Class *&pHeadClass, string nameClass, string username, schoolYear *& headSY, Semester *& headSemester, Class *& headClass)
{
    // string nameClass;

    cout << "==================\n";
    cout << "Please enter class's name: ";
    cin >> nameClass;

    while (pHeadClass && pHeadClass -> name != nameClass)
        pHeadClass = pHeadClass -> next;
    if (pHeadClass == nullptr)
    {
        cout << "You've entered a non-exist class name.\n";
        return classMenu(pHeadClass, nameClass, username, headSY, headSemester, headClass);
    }
    else
    {
        int move; 
        ifstream fin;

        cout << "1. Add students of class (by importing file)\n";
        cout << "2. View students in class\n";
        cout << "3. Add 1 student\n";
        cout << "4. Remove 1 student\n";
        cout << "0. Return to previous menu\n";
        cout << "Pls enter your move: ";
        cin >> move;
    

        while (move >= 0 && move < 5)
        {
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
                case 0:
                    return profile_menu(username, headSY, headSemester, headClass);
                    break;
                default:
                    cout << "You've entered wrong move\n";
                    cout << "Pls enter your move again: \n";
                    break;
            }
            cin >> move;
        }
    }

    
}