#include "viewCoursesStudent.h"

// This function uses <iomanip> library
// Uses the setw function inside this library
// setw is used to set the width of a column in a table
// left is to align all items to the left of the column
void viewCoursesStudent(string Id) {
    string path, line, SY, Class, courseClass, Sem, curSY;
    // Path leads to the file student info in folder profile
    path = "./profile/" + Id + ".txt"; // Get SY and Class
    ifstream ifs, Course;
    ifs.open(path);
        getline(ifs, SY); // username
        getline(ifs, SY); // password
        getline(ifs, SY); // school year
        getline(ifs, Class); // class name
    ifs.close();
    ifs.open("./curTime.txt");
        getline(ifs, curSY); // get the current year
        getline(ifs, Sem); // get the current semester
    ifs.close();

    path = "./" + SY + "/" + Class + "/" + Id + "/" + Sem + "_" + curSY + ".txt"; // Get info of courses leaning in this sem
    ifs.open(path);
        if (!ifs.is_open()) {
            cout << "There's no course in this semester" << endl;
            return;
        }
        cout << "Courses you will study in this semester: " << endl;
        cout << "--------------------" << endl;
        getline(ifs, line); // GPA -> no need here
        getline(ifs, line); // credit -> no need either

        int i = 1; // This variable is used to represent ordinal number, add up to 1 when there's a new member printing out
        string CourseID, CourseName, CourseClass, Teacher, Credit, DayOfWeek, Session;
        cout << left << setw(5) << "No." << setw(12) << "Course ID" << setw(30) << "Course name" << setw(8) << "Credit" << setw(10) << "Class" << setw(14) << "Session" << "   " << "Teacher" << endl;
        while (!ifs.eof()) {
            getline(ifs, line,','); // Read courseID
            getline(ifs, courseClass); // Read class name in the course
            Course.open("./" + SY + "/" + Sem + "/" + line + "/" + courseClass + "/info.txt");
                getline(Course, CourseID);
                getline(Course, CourseName);
                getline(Course, CourseClass);
                getline(Course, Teacher);
                getline(Course, Credit);
                getline(Course, DayOfWeek); // max student -> no need either
                getline(Course, DayOfWeek);
                getline(Course, Session);
            Course.close();
            cout << left << setw(5) << i << setw(12) << CourseID << setw(30) << CourseName << setw(8) << Credit << setw(10) << CourseClass << setw(4) << DayOfWeek << setw(10) << Session << "   " << Teacher << endl;
            i++;
        }
        cout << "--------------------" << endl;
    ifs.close();
}