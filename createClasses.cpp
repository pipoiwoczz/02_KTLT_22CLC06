#include "createSY.h"
#include <iostream>
using namespace std;


void createClass(Class *& pHeadClass)
{
    string nameClass;

    cout << "Pls enter name of class: ";
    getline(cin, nameClass);
    
    if (pHeadClass == nullptr)
    {
        pHeadClass = new Class;
        pHeadClass -> nameClass = nameClass;
    }
    else
    {
        Class * pCur = pHeadClass;

        while (pCur -> pNextClass != nullptr)
        {
            pCur = pCur -> pNextClass;
        }

        pCur -> pNext = new Class;
        pCur -> pNextClass -> nameClass = nameClass;
    }
}