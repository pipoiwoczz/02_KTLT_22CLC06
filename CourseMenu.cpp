#include "CourseMenu.h"
#include "inputStudentsToCourse.h"
#include "main.h"
#include "SEmenu.h"
#include "updateCourseInfor.h"
#include "viewStudentInACourse.h"
#include "importCourseScoreboard.h"
#include <string>
using namespace std;

void courseMenu(string username, schoolYear * headSY, schoolYear * curSY, int choice, Semester * curSE, Course *& curCour) {

    system("cls");
    cout << "Course Menu: " << curCour -> courseID << endl;
    cout << "1. Upload a list of students\n";
    cout << "2. Add a student to a course\n";
    cout << "3. Remove a student from a course\n";
    cout << "4. View list of Students in course\n";
    cout << "5. Import ScoreBoard of students\n";
    cout << "6. View the Scoreboard of the course\n";
    cout << "7. Update a student's result\n";
    cout << "0. Back to previous menu\n";
    
    int move;
    do {
        cout << "=============================\n";
        cout << "Enter your move: ";
        cin >> move;

        switch (move) {
            case 1: 
                inputStudentsToCourse(curSY, curSE, curCour);
                break;
            case 2:
                cout << "ADd a student to course\n";
                break;
            case 3:
                
                break;
            case 4: 
                viewStudentInACourse(curSY, curSE, curCour);
                break;
            case 5:
                inputStudentScore();
                break;
            case 0:
                return SEMenu(username, headSY, curSY, choice);
                break;
        }
        system("pause");
        return courseMenu(username, headSY, curSY, choice, curSE, curCour);
    } while (move < 0 || move > 4);
}