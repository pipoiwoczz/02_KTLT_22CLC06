#include "createClasses.h"
#include "login.h"
#include "main.h"
#include <cstring>
#include <string>
#include <fstream>
#include <unistd.h>
using namespace std;

void createClass(string username, string nameSY)
{
    string nameClass;

    cin.ignore();
    cout << "Pls enter name of class: ";
    getline(cin, nameClass);

    string path = nameSY + "\\" + nameClass;

    if (mkdir(path.c_str()) == -1)  {
        cout << "This class has already been created\n";
        cout << "Do you want to create another class? \n";
        cout << "1. Yes\n";
        cout << "2. No \n";
        int move;
        cout << "Choose your move: ";
        cin >> move;
        if (move == 1)  
            createClass(username, nameSY);
        else
            return;
    } else {
        ifstream ifs;
        ofstream ofs;

        string sy = nameSY + "//";

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
    }
}