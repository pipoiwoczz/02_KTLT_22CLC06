#include <iostream>
#include "changePassword.h"
using namespace std;

struct Class
{
    string nameClass;
    Student * pHeadStudent = nullptr;
    Class * pNextClass = nullptr;
};

void createClass(Class *& pHeadClass);

