#include "CourseMenu.h"
#include "inputStudentsToCourse.h"
#include "main.h"
#include "SEmenu.h"
#include "updateCourseInfor.h"
#include "viewScoreboardOfCourse.h"
#include "updateStudentResult.h"
#include "viewStudentInACourse.h"
#include "1StuToCourse.h"
#include "removeAStudentInCourse.h"
#include "saveStudentScoreboard.h"
#include <string>
using namespace std;

void courseMenu(string username, schoolYear * headSY, schoolYear * curSY, int choice, Semester * curSE, Course *& curCour) {

    system("cls");
    cout << "Course Menu: " << curCour -> courseID << endl;
    cout << "1. Upload a list of students\n";
    cout << "2. Add a student to a course\n";
    cout << "3. Remove a student from a course\n";
    cout << "4. View list of Students in a course class\n";
    cout << "5. Import ScoreBoard of students\n";
    cout << "6. View the Scoreboard of a course class\n";
    cout << "7. Update a student's result\n";
    cout << "8. View list of Students in course \n";
    cout << "9. View the Scoreboard of the course\n";
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
                add1StudentToCourse(curSY, curSE, curCour);
                break;
            case 3:
                removeAStudentInCourse(curSY, curSE, curCour);
                break;
            case 4: 
                viewStudentInACourseClass(curSY, curSE, curCour);
                break;
            case 5:
                saveStudentScoreboard(curSY, curSE, curCour);
                break;
            case 6:
                viewScoreboardOfCourse(curSY, curSE, curCour);
                break;
            case 7:
                updateStudentResultCourse(curSY, curSE, curCour);
                break;
            case 8:
                studentInACourse(curSY, curSE, curCour);
                break;
            case 9:
                break;
            case 0:
                return SEMenu(username, headSY, curSY, choice);
                break;
        }
        system("pause");
        return courseMenu(username, headSY, curSY, choice, curSE, curCour);
    } while (move < 0 || move > 4);
}