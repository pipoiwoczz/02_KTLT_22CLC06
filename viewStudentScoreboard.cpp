#define _HAS_STD_BYTE 0
#include "viewStudentScoreboard.h"
#include "gui.h"
#include "guiMenu.h"
#include "guiView.h"
using namespace std;
/*
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
        getline(course, line, ',');
        cout << setw(6) << line; // Total mark
        getline(course, line, ',');
        cout << setw(6) << line; // Final mark
        getline(course, line, ',');
        cout << setw(8) << line; // Midterm mark
        getline(course, line);
        cout << setw(6) << line << endl; // Other mark
        course.close();
    }
    cout << "--------------------" << endl;
    ifs.close();
}
*/
void viewStudentScoreboardChooseSem(string Id) {
    system("cls");
    
    printCenterCharacters(L"VIEW STUDENT'S SCOREBOARD CHOOSE SEM", Color::light_green, Color::bright_white, 3, My_Windows);

    Sleep(100);
    printCenterCharacters(wstring(Id.begin(), Id.end()), Color::light_green, Color::bright_white, 5, My_Windows);
    Sleep(200);

    string SY, Class;
    ifstream ifs;
    ifs.open("./profile/" + Id + ".txt");
    for (int i = 0; i < 3; i++) getline(ifs, SY);
    getline(ifs, Class);
    ifs.close();

    short curLine = 7;

    string sem;
    ifs.open("./" + SY + "/" + Class + "/" + Id + "/total.txt");
    getline(ifs, sem);
    getline(ifs, sem);
    while (!ifs.eof()) {
        getline(ifs, sem);
        printCenterCharacters(wstring(sem.begin(), sem.end()), Color::blue, Color::bright_white, curLine, My_Windows);
        curLine += 2;
    }
    ifs.close();
    printCenterCharacters(L"Enter The Semester Here", Color::blue, Color::bright_white, curLine, My_Windows);
    drawBox(curLine + 1);
    gotoxy(46, curLine + 2);
    string chosenSem = getStringInput();

    bool flag = false;
    ifs.open("./" + SY + "/" + Class + "/" + Id + "/total.txt");
    getline(ifs, sem);
    getline(ifs, sem);
    while (!ifs.eof()) {
        getline(ifs, sem);
        if (sem == chosenSem) {
            flag = true;
            break;
        }
    }
    ifs.close();

    if (!flag) {
        printCenterCharacters(L"YOU ENTER AN INVALIDE CHOICE", Color::red, Color::bright_white, curLine + 4, My_Windows);
        printCenterCharacters(L"PRESS any key to enter again or PRESS F1 to back to main menu", Color::green, Color::bright_white, curLine + 6, My_Windows);
        int key = getKey();
        if (key == 27)
            return mainmenuOpt();
        if (key == 59)
            return studentMenuPage(Id);
        return viewStudentScoreboardChooseSem(Id);
    }


    string path, line, GPA, courseClass;
    path = "./profile/" + Id + ".txt"; // get info to open files
    ifs.open(path);
    getline(ifs, SY); // Username
    getline(ifs, SY); // Password
    getline(ifs, SY); // School year
    getline(ifs, Class); // Class
    ifs.close();

    // school year saving data of student
    char SEM = chosenSem[0];
    string schoolyear = chosenSem.substr(2, chosenSem.length());
    path = "./" + SY + "/" + Class + "/" + Id + "/" + chosenSem + ".txt";
    // Open file saving list of courses in current semester
    ifs.open(path);

    getline(ifs, GPA); // GPA in this semester
    getline(ifs, line); // number of credits -> no use here
    printCenterCharacters(L"SCOREBOARD OF THIS SEMESTER", Color::black, Color::bright_white, curLine + 4, My_Windows);
    printCenterCharacters(L"-------------------------------------", Color::purple, Color::bright_white, curLine + 5, My_Windows);
    printCenterCharacters(L"GPA: " + wstring(GPA.begin(), GPA.end()), Color::black, Color::bright_white, curLine + 6, My_Windows);
    printCenterCharacters(L"--------------------------", Color::purple, Color::bright_white, curLine + 7, My_Windows);
    gotoxy(25, curLine + 9);
    curLine += 9;

    cout << left << setw(12) << "Course ID" << setw(30) << "Course name" << setw(8) << "Class" << setw(8) << "Credits" << setw(6) << "Total" << setw(6) << "Final" << setw(8) << "Midterm" << setw(6) << "Other" << endl;
    while (!ifs.eof()) {
        gotoxy(25, curLine + 2);

        getline(ifs, line, ','); // Get a course's ID
        getline(ifs, courseClass); // Get class name of the course

        ifstream course;
        // open file info of a course
        path = "./" + SY + "/" + SEM + "/" + line + "/" + courseClass + "/info.txt";
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
        getline(course, line, ',');
        cout << setw(6) << line; // Total mark
        getline(course, line, ',');
        cout << setw(6) << line; // Final mark
        getline(course, line, ',');
        cout << setw(8) << line; // Midterm mark
        getline(course, line);
        cout << setw(6) << line << endl; // Other mark
        course.close();
        curLine++;
    }
    printCenterCharacters(L"-------------------------------------", Color::purple, Color::bright_white, curLine + 3, My_Windows);
    ifs.close();

    printCenterCharacters(L"PRESS F1 to View Scoreboard Of All Semester", Color::purple, Color::bright_white, curLine + 5, My_Windows);
    printCenterCharacters(L"PRESS any key else to back to previous menu", Color::purple, Color::bright_white, curLine + 7, My_Windows);

    int key = getKey();
    if (key == 27)
        return mainmenuOpt();
    if (key == 59) {
        viewStudentScoreboardAllCourses(Id);
    }
    return studentMenuPage(Id);
    
}

void viewStudentScoreboardAllCourses(string Id) {
    system("cls");
    wstring tmp[3];
   
    printCenterCharacters(L"VIEW STUDENT'S SCOREBOARD ALL COURSE", Color::light_green, Color::bright_white, 3, My_Windows);

    Sleep(100);
    printCenterCharacters(wstring(Id.begin(), Id.end()), Color::light_green, Color::bright_white, 5, My_Windows);
    Sleep(200);


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
    printCenterCharacters(L"SCOREBOARD OF ALL SEMESTER", Color::blue, Color::bright_white, 7, My_Windows);
    printCenterCharacters(L"-------------------------------------", Color::purple, Color::bright_white, 8, My_Windows);
    printCenterCharacters(L"OVERALL GPA: " + wstring(GPA.begin(), GPA.end()), Color::blue, Color::bright_white, 9, My_Windows);
    printCenterCharacters(L"---------------------", Color::purple, Color::bright_white, 10, My_Windows);
    gotoxy(25, 12);

    short curLine = 12;

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

            gotoxy(25, curLine + 2);

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
            getline(course, score, ',');
            cout << setw(6) << score; // Total mark
            getline(course, score, ',');
            cout << setw(6) << score; // Final mark
            getline(course, score, ',');
            cout << setw(8) << score; // Midterm mark
            getline(course, score);
            cout << setw(6) << score << endl; // Other mark
            course.close();
            curLine++;
        }
        semInSchool.close();
    }
    printCenterCharacters(L"-------------------------------------", Color::purple, Color::bright_white, curLine + 3, My_Windows);
    ifs.close();

    printCenterCharacters(L"PRESS F1 to View Scoreboard Of A Semester", Color::purple, Color::bright_white, curLine + 5, My_Windows);
    printCenterCharacters(L"PRESS any key else to back to previous menu", Color::purple, Color::bright_white, curLine + 7, My_Windows);

    int key = getKey();
    if (key == 27)
        return mainmenuOpt();
    if (key == 59) {
        viewStudentScoreboardChooseSem(Id);
    }
    return studentMenuPage(Id);
}