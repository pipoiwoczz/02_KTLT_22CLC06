#include "main.h"
#include <iostream>
using namespace std;

void viewListCourses(Semester *semester) {
    cout << "List of courses: " << endl;

        Course *course = semester -> Courses;
        while (course) {
            cout << course -> courseName << endl;
            course = course -> next;
        }
    
}