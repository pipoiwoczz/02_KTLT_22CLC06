#include "updateStudentResult.h"

void updateStudentResultCourse(schoolYear *SY, Semester *sem, Course *course) {
    ifstream ifs;
    ofstream ofs;
    string Id, line;

    bool exist = false;
    string pathCourse = "./" + SY -> name + "/" + to_string(sem -> season) +  "/" + course -> courseID;

    ////////// CHECK WHETHER THE ID IS VALID OR NOT
    do {
        cout << "Enter a student's ID: "; cin >> Id;

        // Check if the ID is existing in the file listStud.txt of the course
        ifs.open(pathCourse + "/listStud.txt");
        while (ifs) {
            getline(ifs, line, ',');
            if (Id == line) exist = true;
            getline(ifs, line); ///// new
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

    pathCourse += "/scoreboard.txt"; // This path is used to renew the info of the scoreboard of a course
    Score *pScore = nullptr, *cur;
    exportFileInfoToLL(pScore, pathCourse); // insert data of scoreboard.txt of a course to a linked list
    cur = pScore;
    while (cur && cur -> studentID != Id) 
        cur = cur -> next; // traverse to the Node save info of the student whose score is being updating

    ////////// EDITING RESULT OF A STUDENT 
    int choice;
    string score;
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
                cout << "Enter the total mark: "; cin >> score;
                cur -> totalMark = score;
                break;
            case 2:
                cout << "Enter the final mark: "; cin >> score;
                cur -> finalMark = score;
                break;
            case 3: 
                cout << "Enter the midterm mark: "; cin >> score;
                cur -> midtermMark = score;
                break;
            case 4: 
                cout << "Enter the other mark: "; cin >> score;
                cur -> otherMark = score;
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
        if (choice == 2) break; 
        // if choice == 1, we continue the while loop
        // if choice == 2, we go to the next code segment
    } while (choice);
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
    string pathProfile = "./profile/" + Id + ".txt";
    ifs.open(pathProfile);
        for (int i=1; i<=4; i++) getline(ifs, line);
    ifs.close();

    string pathInClass = "./" + SY -> name + "/" + line + "/" + Id + "/" + course -> courseID + ".txt";
    // This path leads to the file score of student in the folder student of folder class

    cur = pScore; // Set the cur back to the pHead
    while (cur && cur -> studentID != Id) 
        cur = cur -> next; // traverse to the Node save info of the student whose score is being updating
    ofs.open(pathInClass);
        ofs << cur -> totalMark << "," << cur -> finalMark << "," << cur -> midtermMark << "," << cur -> otherMark; 
    ofs.close();
    ////////// END WRITING

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