#include "main.h"   
#include "loadProgress.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void loadProgress(schoolYear *&headSY, Semester *&headSemester, Class *& headClass) {

    string tmp;
    ifstream fin;

    // load SY

    schoolYear *SYtmp;

    fin.open("SY.txt");
    
    if (!fin.is_open()) {
        cout << "No progress to load!!\n";
        return;
    } else {
        while (getline(fin, tmp)) {
            if (!headSY) {
                headSY = new schoolYear;
                headSY -> name = tmp;
                SYtmp = headSY;
            } else {
                SYtmp -> next = new schoolYear;
                SYtmp -> name = tmp;
                SYtmp = SYtmp -> next;
            }
        }
    }

    fin.close();


    // load Class naem

    Class *ClassTmp;
    fin.open("class.txt");

    if (!fin.is_open()) {
        cout << "No class to load!!\n";
        return;
    } else {
        while (getline(fin, tmp)) {
            if (!headClass) {
                headClass = new Class;
                headClass -> name = tmp;
                ClassTmp = headClass;
            } else {
                ClassTmp -> next = new Class;
                ClassTmp -> name = tmp;
                ClassTmp = ClassTmp -> next;
            }
        }
    }

    fin.close();

    // load Semester name

    Semester *semesterTmp;
    fin.open("class.txt");

    if (!fin.is_open()) {
        cout << "No class to load!!\n";
        return;
    } else {
        while (getline(fin, tmp)) {
            if (!headClass) {
                headClass = new Class;
                headClass -> name = tmp;
                ClassTmp = headClass;
            } else {
                ClassTmp -> next = new Class;
                ClassTmp -> name = tmp;
                ClassTmp = ClassTmp -> next;
            }
        }
    }

    fin.close();

    

}