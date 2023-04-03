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
    
    if (fin.is_open())  {
        while (getline(fin, tmp)) {
                /*headSY = new schoolYear;
                headSY -> name = tmp;
                SYtmp = headSY;

                loadClass(headSY, headSemester, headClass);
                loadSemester(headSY, headSemester, headClass);
            } else {
                SYtmp -> next = new schoolYear;
                SYtmp -> name = tmp;
                SYtmp = SYtmp -> next;

                loadClass(SYtmp, headSemester, headClass);
                loadSemester(headSY, headSemester, headClass); */

                schoolYear * tmpSY = headSY;
                headSY = new schoolYear;
                headSY -> name = tmp;
                headSY -> next = tmpSY;
                loadClass(headSY);
                loadSemester(headSY);
        }
    }

    fin.close();

}

void loadClass(schoolYear * headSY) {
    ifstream fin;
    string classPath = headSY -> name + "/" + "class.txt";
    fin.open(classPath);

    
    if (fin.is_open())  {
        Class * headClass = nullptr;
        string tmp;

        while (getline (fin, tmp))  {
            Class * tmpClass = headClass;

            headClass = new Class;
            headClass -> name = tmp;
            headClass -> next = tmpClass;
        }   

        headSY -> Classes = headClass;
    }
        
    fin.close();
}

void loadSemester(schoolYear * headSY) {
    ifstream fin;
    string path = headSY -> name + "/" + "semester.txt";
    fin.open(path);

    if (!fin.is_open()) 
        return;

    Semester * headSE = nullptr;
    int tmp;

    while (fin >> tmp)  {
        Semester * tmpSE = headSE;

        headSE = new Semester;
        headSE -> season = tmp;
        headSE -> next = tmpSE;

        string semesterIn4 = headSY -> name + "/" + char(tmp + 48) + "/" + "infor.txt";

        ifstream ifs;
        ifs.open(semesterIn4);

        if (ifs.is_open())  {
            int sea;
            string start, end;
            
            ifs >> sea >> start >> end;

            headSE -> startDate = start;
            headSE -> endDate = end;
        }

        ifs.close();
    }

    headSY -> Semesters = headSE;

    fin.close();
}
