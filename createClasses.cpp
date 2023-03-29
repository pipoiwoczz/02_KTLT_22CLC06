#include "createClasses.h"
#include "login.h"
#include <cstring>
#include <string>
#include <fstream>

void createClass(Class *& pHeadClass)
{
    string nameClass;

    cin.ignore();
    cout << "Pls enter name of class: ";
    getline(cin, nameClass);
    
    char *nameTmp = new char [nameClass.length() + 1];
    strcpy(nameTmp, nameClass.std::string::c_str());

    if (pHeadClass == nullptr)
    {
        pHeadClass = new Class;
        pHeadClass -> name = nameClass;
    }
    else
    {
        Class * pCur = pHeadClass;

        while (pCur -> next != nullptr)
        {
            pCur = pCur -> next;
        }

        pCur -> next = new Class;
        pCur -> next -> name = nameClass;
    }

    createFolder(nameTmp);

    ifstream ifs;
    ofstream ofs;
    ifs.open("class.txt");
    ofs.open("tmp.txt");

    string tmp;
    while (getline(ifs, tmp)) {
        ofs << tmp << endl;
    }


    ofs << nameClass;


    ifs.close();
    ofs.close();

    remove("class.txt");
    rename("tmp.txt", "class.txt");
}