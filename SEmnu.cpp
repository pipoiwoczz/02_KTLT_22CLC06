#include "main.h"
#include "addACourse.h"
#include "updateCourseInfor.h"
#include "viewListCourses.h"
#include "removeAStudent.h"
#include "deleteACourse.h"
#include "profile.h"
#include "inputStudentsToCourse.h"
#include "CourseMenu.h"
#include "SYmenu.h"
#include <iostream>
#include <fstream>
using namespace std;

void SEMenu(string username, schoolYear * headSY, schoolYear * curSY, int choice) {
    Semester *cur = curSY -> Semesters;

    while (cur && cur -> season != choice)
        cur = cur -> next;

    system("cls");
    cout << "\tSemester Menu: ";
    if (cur -> season == 1) cout << "Spring\n";
    if (cur -> season == 2) cout << "Summer\n";
    if (cur -> season == 3) cout << "Autumn\n";

    cout << "1. Add a course\n";
    // cout << "2. Upload a list of students\n";
    cout << "2. View list of courses\n";
    cout << "3. Choose a course\n";
    // cout << "5. Add a student to a course\n";
    // cout << "6. Remove a student from a course\n";
    cout << "4. Delete a course\n";
    cout << "5. Update course information\n";
    cout << "0. Back to previous menu\n";

    int move;
    do {
        cout << "=============================\n";
        cout << "Enter your move: ";
        cin >> move;

        switch (move) {
            case 1: 
                addACourse(curSY, cur, cur -> Courses);
                break;
            case 2:
                viewListCourses(cur);
                break;
            case 3:
                Course *curCour = cur -> Courses;
                cout << "===================================\n";
                cout << "\t\tCourse\n";
                if (!curCour) {
                    cout << "There is no Course now\n";
                    break;
                } else {
                    while (curCour) {
                        cout << curCour -> courseID << endl;
                        curCour = curCour -> next;
                    }
                }
                curCour = cur -> Courses;
                do {
                    if (!curCour) {
                        cout << "You've enterd an invalid Course ID, Please enter again\n";
                    }
                    curCour = cur -> Courses;

                    cout << "======================================\n";
                    cout << "Enter your course: ";
                    string courID;
                    cin >> courID;
                    while (curCour && curCour -> courseID != courID)   
                        curCour = curCour -> next;
                    if (curCour) {
                        return courseMenu(username , headSY, curSY, choice, cur, curCour);
                    } else {
                        continue;
                    }
                } while (1);
                break;
            case 4: 
                deleteACourse(curSY, cur, cur -> Courses);
                break;
            case 5:
                updateCourseInfor(curSY, cur, cur -> Courses);
                break;
            case 0:
                SYMenu(username, headSY, curSY);
                break;
        }
        system("pause");
        return SEMenu(username, headSY, curSY, choice);
    } while (move < 0 || move > 4);
}