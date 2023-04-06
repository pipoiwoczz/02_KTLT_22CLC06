#include "1StuToCourse.h"

void add1StudentToCourse(schoolYear * curSY, Semester * curSE, Course * curCourse)  {
    Student * tmpStudent;

    cout << "==========Pls enter the information of the Student==========";

    cout << "\nStudent ID: ";
    cin >> tmpStudent -> studentId;
    cin.ignore();
    cout << "Enter student's first name: ";
    getline(cin , tmpStudent -> firstName);
    cin.ignore();
    cout << "Enter student's last name: ";
    getline(cin , tmpStudent -> lastName);

    string path = curSY -> name + "/" + curSE -> season + "/" + curCourse -> name + "listStud.txt";
    string infoStudent = tmpStudent -> studentId + "," + tmpStudent -> lastName + " " + tmpStudent -> firstName; 
    int flag = 0;

    ifstream ifs;
    ofstream ofs;

    ifs.open(path);
    ofs.open(curSY -> name + "/" + curSE -> season + "/" + curCourse -> name + "tmp.txt");

    if (ifs.is_open())  {
        string tmp;
        while (getline(ifs, tmp))   {
            if (tmp == infoStudent) {
                flag = 1;
                break;
            }

            ofs << tmp << endl;
        }
    }

    ofs << infoStudent;
    ifs.close;
    ofs.close;

    if (flag == 1)  {
        delete tmpStudent;

        remove((curSY -> name + "/" + curSE -> season + "/" + curCourse -> name + "tmp.txt").c_str());

        cout << "Student has already been in the course...";
        cout << "\nDo you want to continue adding 1 student to this course?";

        int move;
        cout << "\n1. Yes";
        cout << "\n2. No";

        do {
            cout << "\nEnter your choice: ";
            cin >> move;

            switch (move)   {
                case 1: 
                    return add1StudentToCourse(curSY, curSE, curCourse);
                case 2:
                    return;
                default:
                    cout << "Wrong choice. Pls try again.";
                    break;
            }
        }   while (move != 1 && move != 2)
    } else    {
        remove(path);
        rename((curSY -> name + "/" + curSE -> season + "/" + curCourse -> name + "tmp.txt").c_str(), path.c_str());
        
        Student * tail = curCourse -> students;

        if (tail == nullptr)    {
            curCourse -> students = new Student;
            curCourse -> students = tmpStudent;
        }
        else    {
            while (tail -> next)
                tail = tail -> next;
            
            tail -> next = tmpStudent;
        }
        
        delete tmpStudent;
    }
}