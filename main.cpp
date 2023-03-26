#include "mainmenu.h"
#include "main.h"
#include "loadProgress.h"
using namespace std;


int main() {
    schoolYear * headSY = nullptr;
    Semester * headSemester = nullptr;
    Class * headClass = nullptr;
    loadProgress(headSY, headSemester, headClass);
    system("pause");
    mainMenu(headSY, headSemester, headClass);

    return 0;
}