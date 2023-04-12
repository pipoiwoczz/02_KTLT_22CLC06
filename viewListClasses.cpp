#include "viewListClasses.h"

void viewListClasses() {
    string classes, schoolYear;
    cout << "List of classes: " << endl;
    ifstream ifs, year;
    ifs.open("./SY.txt");
        while (!ifs.eof()) {
            getline(ifs, schoolYear);
            year.open("./" + schoolYear + "/class.txt");
                while (!year.eof()) {
                    getline(year, classes);
                    cout << classes << endl;
                }
            year.close();
        }
    ifs.close();
}