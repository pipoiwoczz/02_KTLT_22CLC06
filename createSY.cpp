#include "createSY.h"
#include <iostream>
#include "login.h"
#include <cstring>
#include <string>
#include <fstream>
#include <direct.h>
using namespace std;

bool isValidSY(string SY)
{
    string year1, year2;
    int idx = 0;

    while (SY[idx] <= '9' && SY[idx] >= '0')   {
        year1 += SY[idx];
        ++idx;
    }

    if (SY[idx] != '-')
        return false;
    
    ++idx;

    while (SY[idx] <= '9' && SY[idx] >= '0')   {
        year2 += SY[idx];
        ++idx;
    }

    if (stoi(year2) - stoi(year1) == 1) 
        return true;

    return false;
}

bool existedSY(string SY)    {
    ifstream ifs;

    ifs.open("SY.txt");
    string tmpSY;
    
    if (ifs.is_open()) {
        while (getline(ifs, tmpSY))  {
            if (tmpSY == SY)    {
                ifs.close();
                return true;
            }
        }
    }

    ifs.close();
    return false;
}

void insertSYAtBeginning(schoolYear *& pHeadSY, string nameSY)
{
    schoolYear * pTemp = pHeadSY;

    pHeadSY = new schoolYear;
    pHeadSY -> name = nameSY;
    pHeadSY -> next = pTemp;
}

void createSY()
{
    string SY;

    cout << "Pls enter the school year : ";
    cin >> SY;

    if (isValidSY(SY) == true && existedSY(SY) == false)
    {
        // insertSYAtBeginning(headSY, SY); // no more LL
        ofstream ofs;
        ifstream ifs;
        string tmp;
        ifs.open("SY.txt");
        ofs.open("tmp.txt");
        if (ifs.is_open()) {
            while (getline (ifs, tmp)) {
                ofs << tmp << endl;
            }
        }
        
        ofs << SY << endl;
        ofs.close();
        ifs.close();
        remove("SY.txt");
        rename("tmp.txt", "SY.txt");
        _mkdir(SY.c_str());

        
    }
    else
    {
        if (isValidSY(SY) == false)
            cout << "You've entered wrong school year : " << endl;
        else
            cout << "You've entered an existed school year. \n";
        
        int move;
        cout << "1. Continue creating a new school year\n";
        cout << "2. Exit\n";
        cout << "-------------------------------------\n";
        cout << "Enter your move : ";
        cin >> move;

        if (move == 1)
            createSY();
        else
            return;
    }
}