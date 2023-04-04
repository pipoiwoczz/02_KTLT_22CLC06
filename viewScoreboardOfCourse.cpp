#include "viewScoreboardOfCourse.h"
#include "main.h"
#include <iostream>
using namespace std;

void viewScoreboardOfCourse(schoolYear *SY, Semester *Sem, Course *course) {
    ifstream ifs;
    string out;
    ifs.open("./" + SY -> name + "/" + to_string(Sem -> season) + "/" + course -> courseID + "/scoreboard.txt");
    cout << "Course's scoreboard:" << endl;
    cout << "--------------------" << endl;
    cout << left << setw(5) << "No." << setw(10) << "ID" << setw(34) << "Name" << setw(8) << "Total" << setw(8) << "Final" << setw(8) << "Midterm" << setw(8) << "Other" << endl;
    while (!ifs.eof()) {
        getline(ifs, out, ','); // Ordinal number
        cout << left << setw(5) << out;
        getline(ifs, out, ','); // ID
        cout << left << setw(10) << out;
        getline(ifs, out, ','); // Name
        cout << left << setw(34) << out;
        getline(ifs, out, ','); // Total
        cout << left << setw(8) << out;
        getline(ifs, out, ','); // Final 
        cout << left << setw(8) << out;
        getline(ifs, out, ','); // Midterm
        cout << left << setw(8) << out;
        getline(ifs, out); // Other
        cout << left << setw(8) << out << endl;
    }
    ifs.close();
    cout << "--------------------" << endl;
}