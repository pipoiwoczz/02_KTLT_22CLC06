#include "viewCoursesStudent.h"

// View list of courses that a student will learn in a semester
// Need to fix the path of the files
void viewCoursesStudent(string Id) {
    string path, line, SY, Class;
    path = "./" + Id + "_SV.txt";
    ifstream ifs;
    ifs.open(path);
        getline(ifs, SY);
        getline(ifs, Class);
    ifs.close();

    ifstream ifs;
    path = "./" + SY + "/" + Class + "/" + Id + "/info.txt";
    ifs.open(path);

    cout << "Courses you will study in this semester: " << endl;
    // The number of execution based on the info of a student
    // for (int i=0; i<4; i++) getline(ifs, line);   // Maybe don't need this line
    while (!ifs.eof()) {
        getline(ifs, line);
        cout << line << endl;
    }

    ifs.close();
}