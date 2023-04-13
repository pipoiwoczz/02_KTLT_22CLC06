#include "viewListCourses.h"

void insertCourseBeg(listCourse* &course, string ID) {
    listCourse *temp = new listCourse;
    temp -> ID = ID;
    temp -> next = course;
    course = temp;
}

void insertCourse(listCourse* &Course, string ID) {
    listCourse *dummy = new listCourse; // dummy node
    dummy -> next = Course;
    Course = dummy;
    listCourse *cur = Course;
    bool finishFunc = false;
    while (cur && cur -> next) {
        if ((cur -> next -> ID).compare(ID) == 0) {
            finishFunc = true;
            break;
        }
        else if ((cur -> next -> ID).compare(ID) > 0) {
            insertCourseBeg(cur -> next, ID);
            finishFunc = true;
            break;
        }
        cur = cur -> next;
    }
    if (!finishFunc) {
        cur -> next = new listCourse;
        cur -> next -> ID = ID;
    }
    Course = Course -> next;
    delete dummy; // dummy node
}

void viewListCourses() {
    cout << "--------------------" << endl;
    cout << "List of all courses in the system: " << endl;
    cout << "----------" << endl;
    string SY, thisCourse;
    ifstream year, sem;
    listCourse *course = nullptr;
    year.open("./SY.txt");
        while (!year.eof()) {
            getline(year, SY);
            for (int i=1; i<4; i++) { // semester 1 to 3
                sem.open("./" + SY + "/" + to_string(i) + "/course.txt");
                    if (sem.is_open()) {
                        while (!sem.eof()) {
                            getline(sem, thisCourse); // get a course's id
                            insertCourse(course, thisCourse); // insert to linked list
                        }
                    }
                sem.close();
            }
        }
    year.close();

    listCourse *cur = course;
    while (cur) {
        cout << cur -> ID << endl;
        cur = cur -> next;
    }
    if (course == nullptr) cout << "There's no course in the system!" << endl;
    cout << "----------" << endl;

    deleteLLCourse(course);
}

void deleteLLCourse(listCourse* &course) {
    while (course) {
        listCourse *temp = course;
        course = course -> next;
        delete temp;
    }
}

void viewCourseClass(string courseID) { // courseID is the ID of the course that user wants to view list of class of it
    cout << "--------------------" << endl;
    cout << "List of classes of course " << courseID << ":" << endl;
    cout << "----------" << endl;
    string SY, thisClass, path;
    ifstream year, courseClass;
    listCourse *course = nullptr;
    bool thereIsACoure = false;
    year.open("./SY.txt");
        while (!year.eof()) {
            getline(year, SY);
            for (int i=1; i<4; i++) { // semester 1 to 3
                path = "./" + SY + "/" + to_string(i) + "/" + courseID + "/class.txt";
                courseClass.open(path);
                    if (courseClass.is_open()) {
                        while (!courseClass.eof()) {
                            thereIsACoure = true;
                            getline(courseClass, thisClass); // get a class's name
                            insertCourse(course, thisClass); // insert to linked list
                        }
                    }
                courseClass.close();
            }
        }
    year.close();

    listCourse *cur = course;
    while (cur) {
        cout << cur -> ID << endl; // Print out to the screen
        cur = cur -> next;
    }
    if (!thereIsACoure) cout << "There's no class in this course!" << endl;
    cout << "----------" << endl;

    deleteLLCourse(course);    
}