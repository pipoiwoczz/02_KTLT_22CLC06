#include "createSemester.h"
#include <iostream>
using namespace std;

void createSemester(Semester &s)
{
    int course;
    cin >> course;

    cout << "1: Spring\n";
    cout << "2: Summer\n";
    cout << "3: Autumn\n";
    cout << "Pls create a semester: " << endl;
    cin >> course;

    if (course == 1)
        s.pS1Courses = new Course;
    else if (course == 2)
        s.pS2Courses = new Course;
         else
            s.pS3Courses = new Course;
}