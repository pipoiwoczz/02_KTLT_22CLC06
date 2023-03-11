#include "main.h"

void viewListCourses(Semester *semester) {
    cout << "List of courses: " << endl;
    while (semester) {
        Course *course = semester -> course;
        while (course) {
            cout << course -> name << endl;
            course = course -> next;
        }
        semester = semester -> next;
    }
}