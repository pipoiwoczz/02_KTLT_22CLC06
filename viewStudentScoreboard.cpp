#include "viewStudentScoreboard.h"

void viewStudentScoreboard(string Id) {
    string path, line, SY, curSY, Class, Semester, GPA, courseClass;
    path = "./profile/" + Id + ".txt"; // get info to open files
    ifstream ifs;
    ifs.open(path);
        getline(ifs, SY); // Username
        getline(ifs, SY); // Password
        getline(ifs, SY); // School year
        getline(ifs, Class); // Class
    ifs.close();
    ifs.open("./curTime.txt");
        getline(ifs, curSY); // current school year
        getline(ifs, Semester); // Semester
    ifs.close();

    // school year saving data of student
    path = "./" + SY + "/" + Class + "/" + Id + "/" + Semester + "_" + curSY + ".txt";
    // Open file saving list of courses in current semester
    ifs.open(path);

        getline(ifs, GPA); // GPA in this semester
        cout << "Your scoreboard of this semester:" << endl;
        cout << "--------------------" << endl;
        cout << "GPA: " << GPA << endl;
        cout << "----------" << endl;
        cout << left << setw(12) << "Course ID" << setw(30) << "Course name" << setw(8) << "Class" << setw(8) << "Credits" << setw(6) << "Total" << setw(6) << "Final" << setw(8) << "Midterm" << setw(6) << "Other" << endl;
        getline(ifs, line); // number of credits -> no use here
        while (!ifs.eof()) {
            getline(ifs, line, ','); // Get a course's ID
            getline(ifs, courseClass); // Get class name of the course
            ifstream course;
            // open file info of a course
            path = "./" + curSY + "/" + Semester + "/" + line + "/" + courseClass + "/info.txt";
            course.open(path);
                string courseName, className, numCredits;
                cout << left << setw(12) << line; // courseId is also the value of variable "line"
                getline(course, courseName); // course's ID -> don't need this information because we've already had it
                getline(course, courseName);
                cout << setw(30) << courseName; // name of course
                getline(course, className);
                cout << setw(8) << className; // name of class of the course
                getline(course, numCredits); // Get teacher's name -> don't need here
                getline(course, numCredits);
                cout << setw(8) << numCredits; // number of credits of the course
            course.close();

            // open file score of a student
            path = "./" + SY + "/" + Class + "/" + Id + "/" + line + ".txt";
            course.open(path);
                getline(course, line,',');
                cout << setw(6) << line; // Total mark
                getline(course, line,',');
                cout << setw(6) << line; // Final mark
                getline(course, line,',');
                cout << setw(8) << line; // Midterm mark
                getline(course, line);
                cout << setw(6) << line << endl; // Other mark
            course.close();
        }
        cout << "--------------------" << endl;
    ifs.close();
}

void viewStudentScoreboardChooseSem(string Id, string chosenSemester, string chosenSY) {
    string path, line, SY, Class, GPA, courseClass;
    path = "./profile/" + Id + ".txt"; // get info to open files
    ifstream ifs;
    ifs.open(path);
        getline(ifs, SY); // Username
        getline(ifs, SY); // Password
        getline(ifs, SY); // School year
        getline(ifs, Class); // Class
    ifs.close();

    // school year saving data of student
    path = "./" + SY + "/" + Class + "/" + Id + "/" + chosenSemester + "_" + chosenSY + ".txt";
    // Open file saving list of courses in current semester
    ifs.open(path);

        getline(ifs, GPA); // GPA in this semester
        getline(ifs, line); // number of credits -> no use here
        cout << "Scoreboard of semester " << chosenSemester << ", " << chosenSY << ":" << endl;
        cout << "--------------------" << endl;
        cout << "GPA: " << GPA << endl;
        cout << "----------" << endl;
        cout << left << setw(12) << "Course ID" << setw(30) << "Course name" << setw(8) << "Class" << setw(8) << "Credits" << setw(6) << "Total" << setw(6) << "Final" << setw(8) << "Midterm" << setw(6) << "Other" << endl;
        while (!ifs.eof()) {
            getline(ifs, line, ','); // Get a course's ID
            getline(ifs, courseClass); // Get class name of the course

            ifstream course;
            // open file info of a course
            path = "./" + chosenSY + "/" + chosenSemester + "/" + line + "/" + courseClass + "/info.txt";
            course.open(path);
                string courseName, className, numCredits;
                cout << left << setw(12) << line; // courseId is also the value of variable "line"
                getline(course, courseName); // course's ID -> don't need this information because we've already had it
                getline(course, courseName);
                cout << setw(30) << courseName; // name of course
                getline(course, className);
                cout << setw(8) << className; // name of class of the course
                getline(course, numCredits); // Get teacher's name -> don't need here
                getline(course, numCredits);
                cout << setw(8) << numCredits; // number of credits of the course
            course.close();

            // open file score of a student
            path = "./" + SY + "/" + Class + "/" + Id + "/" + line + ".txt";
            course.open(path);
                getline(course, line,',');
                cout << setw(6) << line; // Total mark
                getline(course, line,',');
                cout << setw(6) << line; // Final mark
                getline(course, line,',');
                cout << setw(8) << line; // Midterm mark
                getline(course, line);
                cout << setw(6) << line << endl; // Other mark
            course.close();
        }
        cout << "--------------------" << endl;
    ifs.close();
}

void viewStudentScoreboardAllCourses(string Id) {
    string path, line, SY, Class, Semester, GPA, courseClass, courseID, curSem, curSY, score;
    path = "./profile/" + Id + ".txt"; // get info to open files
    ifstream ifs, semInSchool;
    ifs.open(path);
        getline(ifs, SY); // Username
        getline(ifs, SY); // Password
        getline(ifs, SY); // School year
        getline(ifs, Class); // Class
    ifs.close();

    // school year saving data of student
    path = "./" + SY + "/" + Class + "/" + Id + "/total.txt";
    // Open file saving list of courses in current semester
    ifs.open(path); // total.txt

        getline(ifs, GPA); // GPA all semester
        getline(ifs, line); // number of credits -> no use here
        cout << "Scoreboard of all semester:" << endl;
        cout << "--------------------" << endl;
        cout << "Overall GPA: " << GPA << endl;
        cout << "----------" << endl;
        cout << left << setw(12) << "Course ID" << setw(30) << "Course name" << setw(9) << "Class" << setw(8) << "Credits" << setw(6) << "Total" << setw(6) << "Final" << setw(8) << "Midterm" << setw(6) << "Other" << endl;
        while (!ifs.eof()) {
            getline(ifs, line); // semester of a schoolYear <sem>_<SY>
            path = "./" + SY + "/" + Class + "/" + Id + "/" + line + ".txt";
            semInSchool.open(path); // <sem>_<SY>.txt
                getline(semInSchool, courseID); // GPA in this semester -> no use here
                getline(semInSchool, courseID); // total credit in this semester -> no use here
                while (!semInSchool.eof()) {
                    getline(semInSchool, courseID, ','); // Get a course's ID
                    getline(semInSchool, courseClass); // Get class name of the course
                    ifstream course;
                    // open file info of a course

                    curSem = line.substr(0, 1); // Lấy chuỗi con ở vị trí 0
                    curSY = line.substr(2); // Lấy chuỗi con từ 2 đến hết chuỗi

                    path = "./" + curSY + "/" + curSem + "/" + courseID + "/" + courseClass + "/info.txt";
                    course.open(path); // info.txt
                        string courseName, className, numCredits;
                        cout << left << setw(12) << courseID;
                        getline(course, courseName); // course's ID -> don't need this information because we've already had it
                        getline(course, courseName);
                        cout << setw(30) << courseName; // name of course
                        getline(course, className);
                        cout << setw(9) << className; // name of class of the course
                        getline(course, numCredits); // Get teacher's name -> don't need here
                        getline(course, numCredits);
                        cout << setw(8) << numCredits; // number of credits of the course
                    course.close();

                    // open file score of a student
                    path = "./" + SY + "/" + Class + "/" + Id + "/" + courseID + ".txt";
                    course.open(path); // <courseID>.txt
                        getline(course, score,',');
                        cout << setw(6) << score; // Total mark
                        getline(course, score,',');
                        cout << setw(6) << score; // Final mark
                        getline(course, score,',');
                        cout << setw(8) << score; // Midterm mark
                        getline(course, score);
                        cout << setw(6) << score << endl; // Other mark
                    course.close();
                }
            semInSchool.close();
        }
        cout << "--------------------" << endl;
    ifs.close();
}