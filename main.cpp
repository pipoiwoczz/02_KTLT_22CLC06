#include "mainmenu.h"
#include "main.h"
using namespace std;

schoolYear *SchoolYear = nullptr;

int main() {
    schoolYear * headSY = nullptr;
    Semester * headSemester = nullptr;
    Class * headClass = nullptr;

    mainMenu(headSY, headSemester, headClass);

    return 0;
}