#include "viewStudentInACourse.h"
using namespace std;

void viewStudentInACourse(schoolYear *SY, Semester *Sem, Course *course) {
    string out;
    ifstream ifs;
        ifs.open("./" + SY -> name + "/" + to_string(Sem -> season) + "/" + course -> courseID + "/listStud.txt");
        int i = 1; // Ordinal number
        cout << "Student in this course: "<< endl;
        cout << "--------------------" << endl;
        cout << left << setw(5) << "No." << setw(12) << "ID" << "Name" << endl;
        while (!ifs.eof()) {
            cout << left << setw(5) << i; // Ordinal number
            getline(ifs, out, ',');
            cout << setw(12) << out; // Id
            getline(ifs, out);
            cout << out << endl; // Name
            i++;
        }
        cout << "--------------------" << endl;
    ifs.close();
}