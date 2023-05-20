#include "createSY.h"
#include <string>
#include <fstream>
using namespace std;

bool isValidSY(string SY)
{
    ifstream ifs;
    ifs.open("SY.txt");

    string tmpSY;
    while (getline(ifs, tmpSY)) {
        if (tmpSY == SY) {
			ifs.close();
			return false;
		}
	}
    ifs.close();

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
