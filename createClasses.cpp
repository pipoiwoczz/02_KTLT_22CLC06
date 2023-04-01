#include "createClasses.h"
#include "login.h"
#include <cstring>
#include <string>
#include <fstream>
#include <unistd.h>

void createClass(Class *& headClass, string SY)
{
    string nameClass;

    cin.ignore();
    cout << "Pls enter name of class: ";
    getline(cin, nameClass);

    Class * tmpClass = headClass;

    headClass = new Class;
    headClass -> name = nameClass;
    headClass -> next = tmpClass;

    string path = SY + "\\" + nameClass;

    if (mkdir(path.c_str()) == -1)  {
        cout << "This class has already been created\n";
        cout << "Do you want to continue creating class? \n";
        cout << "1. Yes\n";
        cout << "2. No \n";
        int move;
        cout << "Choose your move: ";
        cin >> move;
        if (move == 1)  
            createClass(headClass, SY);
        else
            return;
    }
    else    {
        ifstream ifs;
        ofstream ofs;

        ifs.open("class.txt");
        ofs.open("tmp.txt");

        while (!ifs.eof())  {
            string tmp;
            getline(ifs, tmp);
            ofs << tmp << endl;
        }        

        ofs << nameClass << endl;

        ifs.close();
        ofs.close();
        remove("class.txt");
        rename("tmp.txt", "class.txt");
    }
}