#include "viewScoreboardOfCourse.h"

void viewScoreboardOfCourse(string s, string course) {
    ifstream ifs;
    s = s + course + "_scoreboard.txt";
    string out;
    ifs.open(s);
    cout << "No\tId\tName\t\t\tMidterm\tFinal\tOther\tTotal" << endl;
    while (ifs) {
        getline(ifs, out, ',');
        cout << out << "\t";
        getline(ifs, out, ',');
        cout << out << "\t";
        getline(ifs, out, ',');
        cout << out << "\t";
        getline(ifs, out, ',');
        cout << out << "\t";
        getline(ifs, out, ',');
        cout << out << "\t";
        getline(ifs, out, ',');
        cout << out << "\t";
        getline(ifs, out);
        cout << out << endl;
    }
    ifs.close();
}