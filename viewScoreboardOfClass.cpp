#include "viewScoreboardOfClass.h"

/*
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

void viewClassScoreboard(string username, string SY, string className) {
    cout << "----------" << endl;
    cout << "Class: " << className << endl;
    cout << "----------" << endl;

    ifstream ifs, student;
    string course, ID, name, total, final, GPA, curSem, curSY;

    ifs.open("./" + SY + "/" + className + "/student.txt");
        // Check if this file have nothing or does not exist
        if (ifs.eof() || !ifs.is_open()) {
            cout << "This class haven't had any student yet" << endl; 
            cout << "--------------------" << endl;
            return;
        }
    ifs.close();

    ifs.open("./curTime.txt");
        getline(ifs, curSY); // Current year
        getline(ifs, curSem); // Current Semester
    ifs.close();

    courseInThisSem *head = nullptr; // This linked list is used to 
    // Open the file contain list of student's ID in a class
    ifs.open("./" + SY + "/" + className + "/student.txt");
        while (!ifs.eof()) {
            getline(ifs, ID); // Student's ID
            // Open the file saving courses that a student will learn in this semester
            student.open("./" + SY + "/" + className + "/" + ID + "/" + curSem + "_" + curSY + ".txt"); // <sem>_<SY>.txt
                if (student.is_open()) { // if this student does not learn in this sem -> do not do this code segment
                    getline(student, course); // GPA in this semester -> no need here
                    getline(student, course); // credit -> no need either
                    while (!student.eof()) {
                        getline(student, course,','); // get a course's ID
                        if (!checkExist(head, course)) insertCourseAtBegin(head, course);
                        getline(student, course); // class of the course -> no need here
                    }
                }
            student.close();
        }
    ifs.close();

    // Now we have the linked list of courses
    // Print out first line to the screen
    cout << left << setw(34) << "Name"; // the name of the column that represents student's name
    courseInThisSem *cur = head; // A temp pointer used to traverse
    while (cur) {
        cout << setw(10) << cur -> ID; // course ID
        cur = cur -> next;
    }
    cout << setw(5) << "GPA" << setw(12) << "Overall GPA" << endl;

    // 2nd, 3rd, 4th, ... line
    ifs.open("./" + SY + "/" + className + "/student.txt");
        // Check if this file have nothing or does not exist
        while (!ifs.eof()) {
            getline(ifs, ID); // Student's ID
            student.open("./profile/" + ID + ".txt");
                for (int i=0; i<5; i++) getline(student, name);
                cout << left << setw(34) << name; // Prints out student name
            student.close();

            cur = head; // refresh the "cur" variable
            while (cur) {
                student.open("./" + SY + "/" + className + "/" + ID + "/" + cur -> ID + ".txt");
                    // If this student does not enroll in this course, print out x
                    if (!student.is_open()) cout << setw(10) << "x";
                    else {
                        getline(student, total, ',');
                        getline(student, final, ',');
                        cout << setw(10) << final; // Final mark
                    }
                student.close();

                cur = cur -> next;
            }
            
            student.open("./" + SY + "/" + className + "/" + ID + "/" + curSem + "_" + curSY + ".txt");
                getline(student, GPA);
                if (!student.is_open()) cout << setw(5) << 0;
                else cout << setw(5) << GPA; // GPA in this sem
            student.close();

            student.open("./" + SY + "/" + className + "/" + ID + "/total.txt");
                getline(student, GPA);
                if (!student.is_open()) cout << setw(12) << 0 << endl;
                else cout << setw(12) << GPA << endl; // OVerall GPA
            student.close();
        }
    ifs.close();    
    cout << "--------------------" << endl;

    deleteCourseLL(head); // Delete linked list
    return;
}

void deleteCourseLL(courseInThisSem* &head) {
    courseInThisSem *temp = head;
    while (head) {
        head = head -> next;
        delete temp;
        temp = head;
    }
}
*/