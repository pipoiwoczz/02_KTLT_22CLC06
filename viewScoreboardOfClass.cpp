#include "viewScoreboardOfClass.h"

bool checkExist(courseInThisSem *head, string value) {
    while (head) {
        if (head -> ID == value) return true;
        head = head -> next;
    }
    return false;
}

void insertCourseAtBegin(courseInThisSem* &head, string value) {
    courseInThisSem *temp = new courseInThisSem;
    temp -> ID = value;
    temp -> next = head;
    head = temp;
}

void viewClassScoreboard(schoolYear *SY, Class *className) {
    ifstream ifs, student;
    string sem, course, ID, name, total, final, GPA;
    ifs.open("./SY.txt");
        getline(ifs, sem); // Semester
    ifs.close();

    courseInThisSem *head = nullptr; // This linked list is used to 
    // Open the file contain list of student's ID in a class
    ifs.open("./" + SY -> name + "/" + className -> name + "/student.txt");
        while (!ifs.eof()) {
            getline(ifs, ID); // Student's ID
            // Open the file saving courses that a student will learn in this semester
            student.open("./" + SY -> name + "/" + className -> name + "/" + ID + "/" + sem + "_" + SY -> name + ".txt"); // <sem>_<SY>.txt
                getline(student, course); // GPA in this semester -> no need here
                getline(student, course); // credit -> no need either
                while (!student.eof()) {
                    getline(student, course,','); // get a course's ID
                    if (!checkExist(head, course)) insertCourseAtBegin(head, course);
                    getline(student, course); // class of the course -> no need here
                }
            student.close();
        }
    ifs.close();

    // Now we have the linked list of courses
    // Print out first line to the screen
    cout << className -> name << endl;
    cout << "----------" << endl;
    cout << left << setw(34) << "Name"; // the name of the column that represents student's name
    courseInThisSem *cur = head; // A temp pointer used to traverse
    while (cur) {
        cout << setw(10) << cur -> ID; // course ID
        cur = cur -> next;
    }
    cout << setw(5) << "GPA" << setw(12) << "Overall GPA" << endl;

    // 2nd, 3rd, 4th, ... line
    ifs.open("./" + SY -> name + "/" + className -> name + "/student.txt");
        while (!ifs.eof()) {
            getline(ifs, ID); // Student's ID
            student.open("./profile/" + ID + ".txt");
                for (int i=0; i<5; i++) getline(student, name);
                cout << left << setw(34) << name; // Prints out student name
            student.close();

            cur = head; // refresh the "cur" variable
            while (cur) {
                student.open("./" + SY -> name + "/" + className -> name + "/" + ID + "/" + cur -> ID + ".txt");
                    // If this student does not enroll in this course, print out x
                    if (!student.is_open()) cout << setw(10) << "x";
                    getline(student, total, ',');
                    getline(student, final, ',');
                student.close();
                cout << setw(10) << final; // Final mark

                cur = cur -> next;
            }
            
            student.open("./" + SY -> name + "/" + className -> name + "/" + ID + "/" + sem + "_" + SY -> name + ".txt");
                getline(student, GPA);
                cout << setw(5) << GPA; // GPA in this sem
            student.close();

            student.open("./" + SY -> name + "/" + className -> name + "/" + ID + "/total.txt");
                getline(student, GPA);
                cout << setw(12) << GPA << endl; // OVerall GPA
            student.close();
        }
    ifs.close();    
    cout << "--------------------" << endl;

    deleteCourseLL(head); // Delete linked list
}

void deleteCourseLL(courseInThisSem* &head) {
    courseInThisSem *temp = head;
    while (head) {
        head = head -> next;
        delete temp;
        temp = head;
    }
}