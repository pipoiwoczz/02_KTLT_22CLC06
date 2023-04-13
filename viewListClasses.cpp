#include "viewListClasses.h"

void viewListClasses() {
    string classes, schoolYear;
    bool thereIsAClass = false;
    cout << "--------------------" << endl;
    cout << "List of classes in the system: " << endl;
    cout << "----------" << endl;
    ifstream ifs, year;
    ifs.open("./SY.txt");
        while (!ifs.eof()) {
            getline(ifs, schoolYear);
            year.open("./" + schoolYear + "/class.txt");
                if (year.is_open()) {
                    while (!year.eof()) {
                        thereIsAClass = true;
                        getline(year, classes);
                        cout << classes << endl;
                    }
                }
            year.close();
        }
    ifs.close();
    if (!thereIsAClass) cout << "There's no class in the system!" << endl;
    cout << "----------" << endl;
}