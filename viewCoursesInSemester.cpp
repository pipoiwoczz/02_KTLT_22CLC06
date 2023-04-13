#include "viewCoursesInSemester.h"

void viewListCoursesInSem(string SY, string semester) {
    cout << "List of courses in this semester: " << endl;
    cout << "----------" << endl;
    string course;
    ifstream ifs;
    ifs.open("./" + SY + "/" + semester + "/course.txt");
        if (!ifs.is_open()) {
            cout << "There's no course in this semester" << endl;
        } else {
            while (!ifs.eof()) {
                getline(ifs, course);
                cout << course << endl;
            }
        }
    ifs.close();
    cout << "----------" << endl;
}