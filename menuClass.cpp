#include "main.h"
#include "studentInAClass.h"
#include "removeAStudent.h"

void classMenu(Class * pHeadClass, string nameClass)
{
    while (pHeadClass && pHeadClass -> name != nameClass)
        pHeadClass = pHeadClass -> next;
    if (pHeadClass == nullptr)
    {
        cout << "You've entered a non-exist class name.\n";
        return;
    }
    else
    {
        int move; 

        cout << "1. Add students of class (by importing file)\n";
        cout << "2. View students in class\n";
        cout << "3. Add 1 student\n";
        cout << "4. Remove 1 student\n";
        cout << "0. Return to previous menu\n";
        cout << "Pls enter your move: ";
        cin >> move;

        while (move != 0)
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
                    // addAStudenet(pHeadClass -> Students);
                    break;
                case 4:
                    removeAStudent(pHeadClass -> Students);
                    break;
                case 0:
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