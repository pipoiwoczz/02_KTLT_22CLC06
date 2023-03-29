#include "viewScoreboardOfClass.h"

void viewScoreboardOfClass(string SY, string className, string SM) {
    string path = "./" + SY + "/" + className + "/info.txt", Id, course, curGPA, overallGPA, finalMark;
    ifstream ifs;
    ifs.open(path); // list of student in a class
    
    while (!ifs.eof()) {
        getline(ifs, Id, ',');
        cout << Id << "\t" << endl;

        path = "./" + SY + "/" + className + "/" + Id + "/" + SM + "_" +  SY + ".txt";
        ifstream studInfo;
        studInfo.open(path); // list of course that a student learn in this semester
        getline(studInfo, curGPA);

        // If a student does not learn that course, we'll have to print out what???
        while (!studInfo.eof()) {
            getline(studInfo, course);
            path = "./" + SY + "/" + className + "/" + Id + "/" + course + ".txt";
            ifstream course;
            course.open(path);
                for (int i=0; i<3; i++) getline(course, finalMark);
            course.close();
            cout << finalMark << "\t";
        }
        cout << curGPA << "\t";

        // overal GPA ???
        cout << overallGPA << "\t";
        studInfo.close();
    }

    ifs.close();
}