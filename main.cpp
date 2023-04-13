

#include "mainmenu.h"
#include "main.h"
#include "loadProgress.h"
using namespace std;


int main() {
    schoolYear * headSY = nullptr;


    loadProgress(headSY);
    system("pause");

    mainMenu();

    while (headSY) {
        schoolYear * tmp = headSY;
        headSY = headSY -> next;
        delete tmp;
    }

    return 0;
}