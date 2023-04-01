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


}

void loadClass(schoolYear *&headSY, Semester *&headSemester, Class *& headClass) {
    ifstream fin;
    string classPath = headSY -> name + "//" + "class.txt";
    fin.open(classPath);

    string tmp;
    Class * ClassTmp = headClass;

    if (!fin.is_open()) {
        cout << "No class to load!!\n";
        return;
    }

    while (getline (fin, tmp)) {
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

    fin.close();
}

void loadSemester(schoolYear *&headSY, Semester *&headSemester, Class *& headClass) {
    ifstream fin;
    string path = headSY -> name + "//" + "semester.txt";
    fin.open(path);

    int tmp;
    Semester * SEtmp = headSemester;

    if (!fin.is_open()) {
        cout << "No class to load!!\n";
        return;
    }

    while (fin >> tmp) {
        if (!headClass) {
            headSemester = new Semester;
            headSemester -> season = tmp;
            SEtmp = headSemester;
        } else {
            SEtmp -> next = new Semester;
            SEtmp -> season = tmp;
            SEtmp = SEtmp -> next;
        }
    }

    SEtmp = headSemester;

    // load Semester's infor

    while (SEtmp) {
        ifstream ifs;
        string seasonPath = headSY -> name + "//" + char(SEtmp -> season + 48) + "//" + "infor.txt";

        string start, end;
        int sea;

        ifs.open(seasonPath);

        ifs >> sea >> start >> end;

        SEtmp -> season = sea;
        SEtmp -> startDate = end;
        SEtmp -> endDate = end;

        ifs.close();

        SEtmp = SEtmp -> next;
    }

    fin.close();
}
