#include "main.h"

void viewListCourses(SchoolYear *schoolYear) {
    cout << "List of courses: " << endl;
    while (schoolYear) {
        Semester *semester = schoolYear -> semester;
        while (semester) {
            Course *course = semester -> course;
            while (course) {
                cout << course -> name << endl;
                course = course -> next;
            }
            semester = semester -> next;
        }
        schoolYear = schoolYear -> next;
    }
}