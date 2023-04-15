#include "updateStudentResult.h"

void updateStudentResultCourse(string curSY, int season, string course) {
    ifstream ifs, thisCourse;
    ofstream ofs;
    string Id, line, Class, SY, courseClass;

    bool exist = false;
    string pathCourse = "./" + curSY  + "/" + to_string(season) +  "/" + course ;

    ////////// CHECK WHETHER THE ID IS VALID OR NOT
    do {
        cout << "Enter a student's ID: "; cin >> Id;

        ifs.open("./profile/" + Id + ".txt");
            if (ifs.is_open()) {
                getline(ifs, SY); // school year
                getline(ifs, SY); // password
                getline(ifs, SY);
                getline(ifs, Class);

                // Check if the ID is existing in the file listStud.txt of the course
                thisCourse.open("./" + SY + "/" + Class + "/" + Id + "/" + to_string(season) + "_" + curSY + ".txt");
                    if (thisCourse.is_open()) {
                        getline(thisCourse, courseClass); // GPA in this sem
                        getline(thisCourse, courseClass); // credit in this sem
                        getline(thisCourse, courseClass,','); // course id
                        getline(thisCourse, courseClass); // course class
                    }
                thisCourse.close();
                thisCourse.open(pathCourse + "/" + courseClass + "/listStud.txt");
                    if (thisCourse.is_open()) {
                        while (!thisCourse.eof()) {
                            getline(thisCourse, line, ','); // student ID
                            if (Id == line) exist = true;
                            getline(thisCourse, line); // Student name
                        }
                    }
                thisCourse.close();
            }
        ifs.close();

        if (!exist) {
            cout << "---------------" << endl;
            cout << "You've entered a wrong student's ID." << endl;
            cout << "This ID may not exist or does not in this course." << endl;
            cout << "What do you want to do?" << endl;
            cout << "1. Exit updating" << endl;
            cout << "2. Continue updating and enter another ID" << endl;
            int choice;
            cout << "Your choice is: "; cin >> choice;
            cout << "---------------" << endl;
            if (choice == 1) return; // Exit the function
            // Cause we have nothing to do in case 1 so we just basically exit the function
        }
    } while (!exist);
    ////////// END CHECKING

    pathCourse += "/" + courseClass + "/scoreboard.txt"; // This path is used to renew the info of the scoreboard of a course
    Score *pScore = nullptr, *cur;
    exportFileInfoToLL(pScore, pathCourse); // insert data of scoreboard.txt of a course to a linked list
    cur = pScore;
    while (cur && cur -> studentID != Id) 
        cur = cur -> next; // traverse to the Node save info of the student whose score is being updating

    ////////// EDITING RESULT OF A STUDENT 
    int choice;
    string oldTotal, total, finalM, midterm, other;
    oldTotal = cur -> totalMark;
    total = oldTotal;
    finalM = cur -> finalMark;
    midterm = cur -> midtermMark;
    other = cur -> otherMark;

    do {
        cout << "---------------" << endl;
        cout << "Which score do you want to update?" << endl;
        cout << "1. Total Mark" << endl;
        cout << "2. Final Mark" << endl;
        cout << "3. Midterm Mark" << endl;
        cout << "4. Other Mark" << endl;
        cout << "5. Exit updating" << endl;

        cout << "Your choice is: "; cin >> choice;
        cout << "---------------" << endl;
        switch (choice) {
            case 1: 
                // NEED THIS CASE, BECAUSE WE DON'T KNOW WHICH SCORE TAKE HOW MUCH PERCENTAGE IN TOTAL
                cout << "Enter the total mark: "; cin >> total;
                cur -> totalMark = total;
                break;
            case 2:
                cout << "Enter the final mark: "; cin >> finalM;
                cur -> finalMark = finalM;
                break;
            case 3: 
                cout << "Enter the midterm mark: "; cin >> midterm;
                cur -> midtermMark = midterm;
                break;
            case 4: 
                cout << "Enter the other mark: "; cin >> other;
                cur -> otherMark = other;
                break;
            default:
                return;
        }
        cout << "---------------" << endl;
        cout << "Successfully updated result." << endl;
        cout << "What do you want to do next?" << endl;
        cout << "1. Continue updating this student's result" << endl;
        cout << "2. Exit updating" << endl;

        cout << "Your choice: "; cin >> choice;
        cout << "---------------" << endl;
        if (choice == 2) {
            cout << "Exiting..." << endl;
            break; 
        }
        if (choice != 1 && choice != 2) {
            cout << "Invalid choice, please enter a valid choice" << endl;
        }
        // if choice == 1, we continue the while loop
        // if choice == 2, we go to the next code segment
    } while (choice != 2);
    ////////// FINISH EDITING RESULT
    
    // NEED TO REVERSE LL //////////////////////////////////////////////
    reverseList(pScore);
    ////////// NOW REWRITE THE DATA TO THE SCOREBOARD FILE
    ofs.open(pathCourse);
    cur = pScore;
    while (cur) {
        ofs << cur -> No << ",";
        ofs << cur -> studentID << ",";
        ofs << cur -> fullName << ",";
        ofs << cur -> totalMark << ",";
        ofs << cur -> finalMark << ",";
        ofs << cur -> midtermMark << ",";
        ofs << cur -> otherMark;
        if (cur -> next) ofs << endl;
        cur = cur -> next;
    }
    ofs.close();
    ////////// END WRITING

    ////////// REWRITE THE DATA TO THE SCORE FILE OF FOLDER STUDENT IN FOLDER CLASS
    // Read the info of the class that the student belongs to

    string pathInClass = "./" + curSY  + "/" + Class + "/" + Id + "/" + course  + ".txt";
    // This path leads to the file score of student in the folder student of folder class

    // cur = pScore; // Set the cur back to the pHead
    // while (cur && cur -> studentID != Id) 
    //     cur = cur -> next; // traverse to the Node save info of the student whose score is being updating

    ofs.open(pathInClass);
        // ofs << cur -> totalMark << "," << cur -> finalMark << "," << cur -> midtermMark << "," << cur -> otherMark; 
        ofs << total << "," << finalM << "," << midterm << "," << other; 
    ofs.close();
    ////////// END WRITING
    
    if (oldTotal != total) updateGPA(Id);
    deleteLLScore(pScore);
}

void exportFileInfoToLL(Score* &head, string path) {
    ifstream fin;
    string No, id, name, total, final, midterm, other;
    fin.open(path);
    while (!fin.eof()) {
        Score *temp = new Score;
        getline(fin, No, ',');
        temp -> No = No;
        getline(fin, id, ',');
        temp -> studentID = id;
        getline(fin, name, ',');
        temp -> fullName = name;
        getline(fin, total, ',');
        temp -> totalMark = total;
        getline(fin, final, ',');
        temp -> finalMark = final;
        getline(fin, midterm, ',');
        temp -> midtermMark = midterm;
        getline(fin, other);
        temp -> otherMark = other;

        temp -> next = head;
        head = temp;
    }
    fin.close();
}

void deleteLLScore(Score* &head) {
    Score *temp = head;
    while (head) {
        head = head -> next;
        delete temp;
        temp = head;
    } 
}

void reverseList(Score* &pHead) {
    Score *curA = nullptr, *curB = nullptr;
    while (pHead && pHead -> next) {
        curB = pHead -> next;
        pHead -> next = curA;
        curA = pHead;
        pHead = curB;
    }
    if (pHead) pHead -> next = curA;
}