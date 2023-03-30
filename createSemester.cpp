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

void createSemester(string username, schoolYear *& headSY, Semester *& firstSemester, Class *& headClas)
{
    if (!firstSemester) {
        firstSemester = new Semester;
        cout << "Pls create a semester: " << endl;
        cout << "1. Spring \n";
        cout << "2. Summer \n";
        cout << "3. Autumn \n";
        cin >> firstSemester -> season;
        
        do {
            cout << "Enter school year of the semester: ";
            cin >> firstSemester -> SY;
        } while (firstSemester -> SY != headSY -> name);


        cout << "Enter start date: ";
        cin >> firstSemester -> startDate;

        cout << "Enter end date: ";
        cin >> firstSemester -> endDate;

        string path = firstSemester -> SY + "//" + char(firstSemester -> season + 48);
        string tmp;
        mkdir(path.c_str());

        ofstream ofs;
        ifstream ifs;
        ifs.open(headSY -> name + "//semester.txt");
        ofs.open(headSY -> name + "//tmp.txt");

        while (getline(ifs, tmp)) {
            ofs << tmp << endl;
        }

        ofs << firstSemester -> season << endl;

        ifs.close();
        ofs.close();

        remove((headSY -> name + "//semester.txt").c_str());
        rename((headSY -> name + "//tmp.txt").c_str() ,(headSY -> name + "//semester.txt").c_str());
        
        ofs.open(path + "//" + "infor.txt");
        ofs << firstSemester -> SY << " " << firstSemester -> season << " " << firstSemester -> startDate << " " << firstSemester -> endDate << endl;
        ofs.close();

    } else {
        Semester * tmp = firstSemester;

        while (tmp -> next) {
            tmp = tmp -> next;
        }

        tmp -> next = new Semester;
        tmp = tmp -> next;

        cout << "Pls create a semester: " << endl;
        cout << "1. Spring \n";
        cout << "2. Summer \n";
        cout << "3. Autumn \n";
        cin >> tmp -> season;
        
        cout << "Enter school year of the semester: ";
        cin >> tmp -> SY;

        cout << "Enter start date: ";
        cin >> tmp -> startDate;

        cout << "Enter end date: ";
        cin >> tmp -> endDate;

        string path = tmp -> SY + "//" + char(tmp -> season + 48);
        string temp;

        mkdir(path.c_str());

        ofstream ofs;
        ifstream ifs;
        ifs.open(headSY -> name + "//semester.txt");
        ofs.open(headSY -> name + "//tmp.txt");

        while (getline(ifs, temp)) {
            ofs << temp << endl;
        }

        ofs << tmp -> season << endl;

        ifs.close();
        ofs.close();

        remove((headSY -> name + "//semester.txt").c_str());
        rename((headSY -> name + "//tmp.txt").c_str() ,(headSY -> name + "//semester.txt").c_str());

        ofs.open(path + "//" + "infor.txt");
        ofs << tmp -> SY << " " << tmp -> season << " " << tmp -> startDate << " " << tmp -> endDate << endl;
        ofs.close();
    }


}