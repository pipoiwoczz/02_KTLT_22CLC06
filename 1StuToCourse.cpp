#include "1StuToCourse.h"
#include "main.h"
#include <fstream>
#include <iostream>
using namespace std;

void add1StudentToCourse(schoolYear * curSY, Semester * curSE, Course * curCourse)  {
    cout << "==========Pls enter the information of the Student==========";

    string id, firstName, lastName;

    cout << "\nStudent ID: ";
    getline(cin, id);

    cin.ignore();
    cout << "Enter student's last name: ";
    getline(cin, lastName);

    cin.ignore();
    cout << "Enter student's first name: ";
    getline(cin, firstName);
    
    

    string path = curSY -> name + "/" + to_string(curSE -> season) + "/" + curCourse -> courseID + "/" + "listStud.txt";
    string infoStudent = id + "," + lastName + " " + firstName; 
    int flag = 0;

    ifstream ifs;
    ofstream ofs;

    ifs.open(path);
    ofs.open(curSY -> name + "/" + to_string(curSE -> season) + "/" + curCourse -> courseID + "/" + "tmp.txt");

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
    ifs.close();
    ofs.close();

    if (flag == 1)  {
        remove((curSY -> name + "/" + to_string(curSE -> season) + "/" + curCourse -> courseID + "/" + "tmp.txt").c_str());

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
        }   while (move != 1 && move != 2);
    } else    {
        remove(path.c_str());
        rename((curSY -> name + "/" + to_string(curSE -> season) + "/" + curCourse -> courseID + "/" + "tmp.txt").c_str(), path.c_str());
        
        Student * tail = curCourse -> students;

        if (tail == nullptr)    {
            tail = new Student;
            curCourse -> students = tail;
        }    
        else    {
            while (tail -> next)    
                tail = tail -> next;
            tail -> next = nullptr;
            tail -> next = new Student;
            tail = tail -> next;
        }

        tail -> studentId = id;
        tail -> lastName = lastName;
        tail -> firstName = firstName;
    }
}