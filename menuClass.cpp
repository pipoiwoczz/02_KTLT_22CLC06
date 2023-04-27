#include "menuClass.h"

void classMenu(string username, string nameSY, string nameClass)
{
    system("cls");
    ifstream fin;

    cout << "\tClass Menu: " << nameClass << endl;
    cout << "1. Add students of class (by importing file)\n";
    cout << "2. View students in class\n";
    cout << "3. Add 1 student\n";
    cout << "4. Remove 1 student\n";
    cout << "5. View Scoreboard of this class\n";
    cout << "0. Return to previous menu\n";
    cout << "=========================\n";
    
    int move;
    do {
        cout << "Pls enter your move: ";
        cin >> move;      
        switch (move)
        {
            case 1:
                inputStudentsToClass(nameSY, nameClass);             
                break;
            case 2: 
                displayListOfStudents(nameSY, nameClass);
                break;
            case 3:
                add1StToClass(nameSY, nameClass);
                break;
            case 4:
                removeAStudent(nameSY, nameClass);
                break;
            case 5:
                //viewClassScoreboard(nameSY, nameClass);
                break;
            case 0:
                return SYMenu(username, nameSY);
                break;
            default:
                cout << "You've entered wrong move\n";
                cout << "Pls enter your move again: \n";
                break;
        }  
        system("pause");
        return classMenu(username, nameSY, nameClass);            
    } while (move < 0 || move > 5);
}