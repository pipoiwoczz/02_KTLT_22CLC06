#include "createSemester.h"
#include "login.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sys/stat.h>
#include <unistd.h>
#include <cstring>
#include "main.h"
using namespace std;

void createSemester(string username, schoolYear * curSY)
{
    int season;

    cout << "Pls create a semester: " << endl;
    cout << "1. Spring \n";
    cout << "2. Summer \n";
    cout << "3. Autumn \n";

    cin >> season;

    string path = curSY -> name + "/" + char(season + 48) + "_" + curSY -> name + ".txt";

    if (mkdir(path.c_str()) == -1) {
            cout << "This Semester has been already created!\n";
            system("pause");
            
            int move;
            cout << "Do you want to continue creating semester ?";
            cout << "\n1. Yes";
            cout << "\n2.No";

            if (move == 1)
                return createSemester(username, curSY);
            else
                return;
        }
    
    Semester * headSE = curSY -> Semesters;
    Semester * tmp = headSE;

    headSE = new Semester;
    headSE ->next = tmp;
    headSE ->season = season;

    cout << "Enter start date: ";
    cin >> headSE -> startDate;

    cout << "Enter end date: ";
    cin >> headSE -> endDate;

    curSY -> Semesters = headSE;

    ofstream ofs;
    ifstream ifs;
    
    ifs.open(curSY -> name + "//semester.txt");
    ofs.open(curSY -> name + "//tmp.txt");

    if (ifs.is_open()) {
        string tmp;

        while (getline(ifs, tmp)) 
            ofs << tmp << endl;
    }
    
    ofs << season;

    ifs.close();
    ofs.close();

    remove((curSY -> name + "//semester.txt").c_str());
    rename((curSY -> name + "//tmp.txt").c_str() ,(curSY -> name + "//semester.txt").c_str());

    ofs.open(path + "//" + "infor.txt");
    ofs << season << " " << headSE -> startDate << " " << headSE -> endDate << endl;
    ofs.close();

}