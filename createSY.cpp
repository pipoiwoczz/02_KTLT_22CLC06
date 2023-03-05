#include "createSY.h"
#include <iostream>
using namespace std;

bool isValidSY(string SY)
{
    string year1, year2;
    int idx = 0;

    while ('0' <= SY[idx] && SY[idx] <= '9')
    {
        year1 += SY[idx];
        idx++;
    }

    if (SY[idx] != '-')
        return false;

    idx++;
    while ('0' <= SY[idx] && SY[idx] <= '9')
    {
        year2 += SY[idx];
        idx++;
    }

    if (idx != SY.length() - 1)
        return false;
    
    if ((stoi(year2) - stoi(year1)) != 1)
        return false;
    
    return true;
}

void createSY(schoolYear * pArrSY, int &n)
{
    string SY;

    cout << "Pls enter the school year : ";
    cin >> SY;

    if (isValidSY(SY) == true)
    {
        schoolYear * pTemp = new schoolYear [n];

        n++;
        for (int i = 0; i < n - 1; i++)
            pTemp[i] = pArrSY[i];
        pTemp[n - 1].nameSY = SY;
        return;
    }
    else
    {
        cout << "You've entered wrong school year : " << endl;
        
        int move;
        cout <<"1. Continue creating a new school year\n";
        cout << "2. Exit\n";
        cout << "-------------------------------------";
        cout << "Enter your move : ";
        cin >> move;

        if (move == 1)
            createSY(pArrSY, n);
        else
            return;
    }
}