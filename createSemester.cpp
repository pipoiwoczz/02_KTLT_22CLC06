#include "createSemester.h"
#include <iostream>
using namespace std;

void createSemester(Semester &firstSemester)
{
    cout << "Pls create a semester: " << endl;
    cout << "1. Spring \n";
    cout << "2. Summer \n";
    cout << "3. Autumn \n";
    cin >> firstSemester.season;
    
    cout << "Enter school year of the semester: ";
    cin >> firstSemester.SY;

    cout << "Enter start date: ";
    cin >> firstSemester.startDate;

    cout << "Enter end date: ";
    cin >> firstSemester.endDate;
}