#include "viewCoursesInSemester.h"
#include "main.h"

void viewListCoursesInSem(Semester *semester) {
    cout << "List of courses in this semester: " << endl;
    Course *course = semester -> Courses;
    while (course) {
        cout << course -> courseName << endl;
        course = course -> next;
    }
}