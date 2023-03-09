#include "mainStruct.h"

void viewListClasses(SchoolYear *SchoolYear) {
    cout << "List of classes: " << endl;
    while (SchoolYear) {
        Class *Classes = SchoolYear -> classes;
        while (Classes) {
            cout << Classes -> name << endl;
            Classes = Classes -> next;
        }
        SchoolYear = SchoolYear -> next;
    }
}