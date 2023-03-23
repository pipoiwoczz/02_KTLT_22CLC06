#include "viewStudentInACourse.h"
#include <iostream>
#include <string>
#include "main.h"
using namespace std;

void viewStudentInACourse(string s, string course) {
    ifstream ifs;
    s = s + course + ".txt";
    string out;
    ifs.open(s);
    while (ifs) {
        getline(ifs, out, ',');
        cout << out << " ";
        getline(ifs, out);
        cout << out << endl;
    }
    ifs.close();
}