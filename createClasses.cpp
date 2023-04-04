#include "createClasses.h"
#include "login.h"
#include <cstring>
#include <string>
#include <fstream>
#include <unistd.h>

void createClass(schoolYear *& curSY)
{
    string nameClass;

    cin.ignore();
    cout << "Pls enter name of class: ";
    getline(cin, nameClass);

    string path = curSY -> name + "\\" + nameClass;

    if (mkdir(path.c_str()) == -1)  {
        cout << "This class has already been created\n";
        cout << "Do you want to continue creating class? \n";
        cout << "1. Yes\n";
        cout << "2. No \n";
        int move;
        cout << "Choose your move: ";
        cin >> move;
        if (move == 1)  
            createClass(curSY);
        else
            return;
    }
    else    {
        ifstream ifs;
        ofstream ofs;

        string sy = curSY -> name + "//";

        ifs.open(sy + "class.txt");
        ofs.open(sy + "tmp.txt");

        if (ifs.is_open())
            while (!ifs.eof())  {
                string tmp;
                getline(ifs, tmp);
                ofs << tmp << endl;
            }        

        ofs << nameClass;

        ifs.close();
        ofs.close();
        remove((sy + "class.txt").c_str());
        rename((sy + "tmp.txt").c_str(), (sy + "class.txt").c_str());

        Class * tmpClass = curSY -> Classes;

        curSY -> Classes = new Class;
        curSY -> Classes -> name = nameClass;
        curSY -> Classes -> next = tmpClass;
    }
}