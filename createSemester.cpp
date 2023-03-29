#include "createSemester.h"
#include <iostream>
#include "main.h"
using namespace std;

void createSemester(Semester *& firstSemester)
{
    if (!firstSemester) {
        firstSemester = new Semester;
        cout << "Pls create a semester: " << endl;
        cout << "1. Spring \n";
        cout << "2. Summer \n";
        cout << "3. Autumn \n";
        cin >> firstSemester -> season;
        
        cout << "Enter school year of the semester: ";
        cin >> firstSemester -> SY;

        cout << "Enter start date: ";
        cin >> firstSemester -> startDate;

        cout << "Enter end date: ";
        cin >> firstSemester -> endDate;
    } else {
        Semester * tmp = firstSemester;
        while (tmp -> next) {
            tmp = tmp -> next;
        }
        tmp -> next = new Semester;
        tmp = tmp -> next;
        cout << "Pls create a semester: " << endl;
        cout << "1. Spring \n";
        cout << "2. Summer \n";
        cout << "3. Autumn \n";
        cin >> tmp -> season;
        
        cout << "Enter school year of the semester: ";
        cin >> tmp -> SY;

        cout << "Enter start date: ";
        cin >> tmp -> startDate;

        cout << "Enter end date: ";
        cin >> tmp -> endDate;
    }


}