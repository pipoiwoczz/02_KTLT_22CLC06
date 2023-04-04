#include "createSemester.h"
#include "login.h"
#include "SYmenu.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sys/stat.h>
#include <unistd.h>
#include <cstring>
#include "main.h"
using namespace std;

void createSemester(string username, schoolYear * headSY, schoolYear * curSY)
{

    Semester * firstSemester = curSY -> Semesters;

    if (!firstSemester) {
        firstSemester = new Semester;
        
        do {
            if (firstSemester -> season > 3 || firstSemester -> season < 0) 
            {
                cout << "Please enter correct Semester!!\n";
                continue;
            }
            cout << "Pls create a semester: " << endl;
            cout << "1. Spring \n";
            cout << "2. Summer \n";
            cout << "3. Autumn \n";
            cout << "0. Exit\n";
            cin >> firstSemester -> next -> season;
        } while (firstSemester -> season > 3 || firstSemester -> season < 0);

        if (firstSemester -> season == 0) {
            delete firstSemester;
            firstSemester = nullptr;
            return ;
        }
        
        cout << "Enter start date: ";
    
        cin >> firstSemester -> startDate;

        cout << "Enter end date: ";
        cin >> firstSemester -> endDate;

        curSY -> Semesters = firstSemester;

        string path = curSY -> name + "//" + char(firstSemester -> season + 48);
        string tmp;
        if (mkdir(path.c_str()) == -1) {
            cout << "This Semester has been already exists!\n";
            system("pause");
            delete firstSemester;
            firstSemester = nullptr;
            return createSemester(username, headSY, curSY);
        }

        ofstream ofs;
        ifstream ifs;

        ifs.open(curSY -> name + "//semester.txt");
        ofs.open(curSY -> name + "//tmp.txt");

        while (getline(ifs, tmp)) {
            ofs << tmp << endl;
        }

        ofs << firstSemester -> season << endl;

        ifs.close();
        ofs.close();

        remove((curSY -> name + "//semester.txt").c_str());
        rename((curSY -> name + "//tmp.txt").c_str() ,(curSY -> name + "//semester.txt").c_str());
        
        ofs.open(path + "//" + "infor.txt");
        ofs << firstSemester -> season << " " << firstSemester -> startDate << " " << firstSemester -> endDate << endl;
        ofs.close();

    } else {
        Semester * tmp = curSY -> Semesters;

        while (tmp -> next) {
            tmp = tmp -> next;
        }

        tmp -> next = new Semester;
        // tmp = tmp -> next;
        
        do {
            if (tmp -> next -> season > 3 || tmp -> next -> season < 0) 
            {
                cout << "Please enter correct Semester!!\n";
                continue;
            }
            cout << "Pls create a semester: " << endl;
            cout << "1. Spring \n";
            cout << "2. Summer \n";
            cout << "3. Autumn \n";
            cout << "0. Exit\n";
            cin >> tmp -> next -> season;
        } while (tmp -> next -> season > 3 || tmp -> next -> season < 0);

        if (tmp -> next -> season == 0) {
            delete tmp -> next;
            tmp -> next = nullptr;
            return ;      
        }

        cout << "Enter start date: ";
        cin >> tmp -> next -> startDate;

        cout << "Enter end date: ";
        cin >> tmp -> next -> endDate;

        string path = curSY -> name + "//" + char(tmp -> next -> season + 48);
        string temp;

        if (mkdir(path.c_str()) == -1) {
            cout << "This Semester has been already exists!\n";
            system("pause");
            delete tmp -> next;
            tmp -> next = nullptr;
            return createSemester(username, headSY, curSY);
        }

        tmp = tmp -> next;

        ofstream ofs;
        ifstream ifs;
        ifs.open(curSY -> name + "//semester.txt");
        ofs.open(curSY -> name + "//tmp.txt");

        while (getline(ifs, temp)) {
            ofs << temp << endl;
        }

        ofs << tmp -> season << endl;

        ifs.close();
        ofs.close();

        remove((curSY -> name + "//semester.txt").c_str());
        rename((curSY -> name + "//tmp.txt").c_str() ,(curSY -> name + "//semester.txt").c_str());

        ofs.open(path + "//" + "infor.txt");
        ofs << tmp -> season << " " << tmp -> startDate << " " << tmp -> endDate << endl;
        ofs.close();
    }


}