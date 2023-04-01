#include "viewStudentScoreboard.h"

void viewStudentScoreboard(string Id) {
    string path, line, SY, Class;
    path = "./" + Id + "_SV.txt";
    ifstream ifs;
    ifs.open(path);
        getline(ifs, SY);
        getline(ifs, Class);
    ifs.close();

    path = "./" + SY + "/" + Class + "/" + Id + "/info.txt";
    ifs.open(path);

    cout << "Courses you will study in this semester: " << endl;
    // The number of execution based on the info of a student
    // for (int i=0; i<4; i++) getline(ifs, line);   // Maybe don't need this line
    while (!ifs.eof()) {
        getline(ifs, line);
        ifstream course;
        // open file info of a course
        path = "./" + SY + "/" + Class + "/" + Id + "/info.txt";
        course.open(path);

        course.close();

        // open file score of a student
        path = "./" + SY + "/" + Class + "/" + Id + "/info.txt";
        course.open(path);

        course.close();
    }

    ifs.close();
}