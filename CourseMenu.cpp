#include "CourseMenu.h"

void courseMenu(string username, string curSY, int season, string courseID) {

    system("cls");
    cout << "Course Menu: " << courseID << endl;
    cout << "1. Upload a list of students\n";
    cout << "2. Add a student to a course\n";
    cout << "3. Remove a student from a course\n";
    cout << "4. View list of Students in a course class\n";
    cout << "5. Import ScoreBoard of students\n";
    cout << "6. View the Scoreboard of a course class\n";
    cout << "7. Update a student's result\n";
    cout << "8. View list of Students in course \n";
    cout << "9. View the Scoreboard of this course\n";
    cout << "0. Back to previous menu\n";
    
    int move;
    do {
        cout << "=============================\n";
        cout << "Enter your move: ";
        cin >> move;

        switch (move) {
            case 1: 
                inputStudentsToCourse(curSY, season, courseID);
                break;
            case 2:
                add1StudentToCourse(curSY, season, courseID);
                break;
            case 3:
                removeAStudentInCourse(curSY, season, courseID);
                break;
            case 4: 
                viewStudentInACourseClass(curSY, to_string(season), courseID);
                break;
            case 5:
                saveStudentScoreboard(curSY, season, courseID);
                break;
            case 6:
                viewScoreboardOfCourse(curSY, to_string(season), courseID);
                break;
            case 7:
                updateStudentResultCourse(curSY, season, courseID);
                break;
            case 8:
                studentInACourse(curSY , to_string(season), courseID);
                break;
            case 9:
                viewScoreboardOfCourse(curSY, to_string(season), courseID);
                break;
            case 0:
                return SEMenu(username, curSY, season);
                break;
        }
        system("pause");
        return courseMenu(username, curSY, season, courseID);
    } while (move < 0 || move > 4);
}