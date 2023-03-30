#include "main.h"
#include "addACourse.h"
#include "updateCourseInfor.h"
#include "viewListCourses.h"
#include "removeAStudent.h"
#include "deleteACourse.h"
#include "inputStudentsToCourse.h"
#include <iostream>
#include <fstream>
using namespace std;

void SEMenu(string username, schoolYear *& headSY, Semester *& headSemester, Class *& headClass, int choice) {
    Semester *cur = headSemester;
    if (choice == 2) {
        cur = cur -> next;
    } 
    if (choice == 3) {
        cur = cur -> next -> next;
    }

    system("cls");
    cout << "Semester Menu: ";
    if (cur -> season == 1) cout << "Spring\n";
    if (cur -> season == 2) cout << "Summer\n";
    if (cur -> season == 3) cout << "Autumn\n";

    cout << "1. Add a course\n";
    cout << "2. Upload a list of students\n";
    cout << "3. View list of courses\n";
    cout << "4. Update course information\n";
    cout << "5. Add a student to a course\n";
    cout << "6. Remove a student from a course\n";
    cout << "7. Delete a course\n";

    int move;
    do {
        cout << "=============================\n";
        cout << "Your move is: ";
        cin >> move;

        switch (move) {
            case 1: 
                addACourse(cur -> Courses);
                break;
            case 2:
                inputStudentsToCourse(cur -> Courses);
                break;
            case 3:
                viewListCourses(cur);
                break;
            case 4:
                updateCourseInfor(cur -> Courses);
                break;
            case 5:
                // in
                break;
            case 6:
                break;
            case 7: 
                break;
            case 0:
                break;
        }
    } while (move < 0 || move > 7);
}