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

void SEMenu(string username, string curSY, int season) {


    system("cls");
    cout << "\tSemester Menu: ";
    if (season == 1) cout << "Spring\n";
    if (season == 2) cout << "Summer\n";
    if (season == 3) cout << "Autumn\n";

    cout << "1. Add a course\n";
    // cout << "2. Upload a list of students\n";
    cout << "2. View list of courses\n";
    cout << "3. Choose a course in this Semester\n";
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
            case 1: {
                addACourse(curSY, season); 
            }
                break;
            case 2: {
                string path = curSY + "//" + to_string(season) + "//course.txt";
                ifstream ifs;
                ifs.open(path);
                if (!ifs.is_open()) {
                    cout << "There is no course created yet\n";
                    cout << "Please create a course first\n";
                } else {
                    string tmp;
                    while (getline (ifs, tmp)) 
                        cout << tmp << endl;
                    ifs.close();
                }
            }
                break;
            case 3: {

                cout << "===================================\n";
                cout << "\t\tCourse\n";

                string path = curSY + "//" + to_string(season) + "//course.txt";
                ifstream ifs;
                ifs.open(path);
                if (!ifs.is_open()) {
                    cout << "There is no course created yet\n";
                    cout << "Please create a course first\n";
                } else {
                    string tmp;
                    while (getline (ifs, tmp)) 
                        cout << tmp << endl;
                    ifs.close();
                }

                string courseID;
                
                
                do {
                    
                    cout << "======================================\n";
                    cout << "Please enter your Course ID: ";
                    cin >> courseID;
                    ifs.open(path);
                    bool flag = false;
                    if (!ifs.is_open()) {
                        cout << "There is no course created yet\n";
                        cout << "Please create a course first\n";
                    } else {
                        string tmp;
                        while (getline (ifs, tmp)) 
                            if (tmp == courseID) {
                                ifs.close();
                                return courseMenu(username, curSY, season, courseID);
                            }
                        ifs.close();
                        cout << "You've enterd an invalid Course ID, Please enter again\n"; 
                        cout << "Please enter again\n";
                    }
                } while (1);
            }
                break;

            case 4: {
                cout << "===================================\n";
                cout << "\t\tCourse\n";

                string path = curSY + "//" + to_string(season) + "//course.txt";
                ifstream ifs;
                ifs.open(path);
                if (!ifs.is_open()) {
                    cout << "There is no course created yet\n";
                    cout << "Please create a course first\n";
                    break;
                } else {
                    string tmp;
                    while (getline (ifs, tmp)) 
                        cout << tmp << endl;
                    ifs.close();
                }

                string courseID;
               
                

                ifs.open(path);
                bool flag = false;;
                do {
                    cout << "======================================\n";
                    cout << "Please enter your Course ID: ";
                    cin >> courseID;
                    if (!ifs.is_open()) {
                        cout << "There is no course created yet\n";
                        cout << "Please create a course first\n";
                    } else {
                        string tmp;
                        while (getline (ifs, tmp)) 
                            if (tmp == courseID) {
                                ifs.close();
                                deleteACourse(curSY, season, courseID);
                                flag = true;
                        }
                        ifs.close();
                        if (!flag) cout << "You've enterd an invalid Course ID, Please enter again\n";
                    }
                } while (1);
            }
                break;
            case 5: {
                cout << "===================================\n";
                cout << "\t\tCourse\n";

                string path = curSY + "//" + to_string(season) + "//course.txt";
                ifstream ifs;
                ifs.open(path);
                if (!ifs.is_open()) {
                    cout << "There is no course created yet\n";
                    cout << "Please create a course first\n";
                    return;
                } else {
                    string tmp;
                    while (getline (ifs, tmp)) 
                        cout << tmp << endl;
                    ifs.close();
                }

                string courseID;
                
                
                bool flag = false;
                ifs.open(path);
                do {
                    cout << "======================================\n";
                    cout << "Please enter your Course ID: ";
                    
                    cin >> courseID;

                    if (!ifs.is_open()) {
                        cout << "There is no course created yet\n";
                        cout << "Please create a course first\n";
                    } else {
                        string tmp;
                        while (getline (ifs, tmp)) 
                            if (tmp == courseID) {
                                ifs.close();
                                flag = true;
                                updateCourseInfor(curSY, season, courseID);
                        }
                        ifs.close();
                        if (!flag)   cout << "You've enterd an invalid Course ID, Please enter again\n";
                        
                    }
                } while (!flag);
            }
                break;
            case 0:{
                return SYMenu(username, curSY);
            }
            break;
        }
        system("pause");
        return SEMenu(username, curSY, season);
    } while (move < 0 || move > 4);
}