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

    while (headSY) {
        schoolYear * tmp = headSY;
        headSY = headSY -> next;
        delete tmp;
    }

    while (headSemester) {
        Semester * tmp = headSemester;
        headSemester = headSemester -> next;
        delete tmp;
    }

    while (headClass) {
        Class * tmp = headClass;
        headClass = headClass -> next;
        delete tmp;
    }

    return 0;
}