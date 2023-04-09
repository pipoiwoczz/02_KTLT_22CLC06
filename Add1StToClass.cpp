#include "main.h"
#include <string>
#include <cstring>
#include <stdlib.h>
#include <unistd.h>
#include <iostream>
#include <fstream>
using namespace std;

void add1StToClass(Student *& headStudent, schoolYear * curSY, Class * curClass) {
    Student * student = new Student;
    int no = 1;

    cout << "Enter student's ID: ";
        cin >> student -> studentId;
        cin.ignore();
        cout << "Enter student's first name: ";
        getline(cin , student -> firstName);
        cin.ignore();
        cout << "Enter student's last name: ";
        getline(cin , student -> lastName);
        cout << "Enter student's gender: ";
        cin >> student -> gender;
        cout << "Enter student's birthday: ";
        cin >> student -> dateOfBirth;
        cout << "Enter student's social ID: ";
        cin >> student -> socialId;

    string profilePath = "profile//" + to_string(student -> studentId) + ".txt";
    mkdir("profile");
    ifstream fin(profilePath);
    if (fin.is_open()) {
        cout << "This student has already exist in this schoolyear\n";
        delete student;
        system("pause");
        return add1StToClass(headStudent, curSY, curClass);
    } else {
        ofstream out(profilePath);
        out << student -> studentId << endl << "1234\n";
        out << curSY -> name << endl;
        out << curClass -> name << endl;
        out << 1 << endl;
        out << student -> lastName << "," << student -> firstName << endl;
        out << student -> gender << endl;
        out << student -> dateOfBirth << endl;
        out << student -> socialId;
        out.close();
    }

    mkdir((curSY -> name + "//" + curClass -> name + "//" + to_string(student -> studentId)).c_str());

    string stPath = curSY -> name + "//" + curClass -> name + "//" + "student.txt";
    ifstream ifs(stPath);
    ofstream ofs("tmp.txt");
    if (ifs.is_open()) {
        string tmp;
        while (getline(ifs, tmp)) {
            ofs << tmp << endl;
            if (tmp == to_string(student -> studentId)) {
                cout << "This student has aldready exists\n\n";
                ofs.close();
                remove("tmp.txt");
                ifs.close();
                delete student;
                system("pause");
                return add1StToClass(headStudent, curSY, curClass);
            }
        }
        ofs <<student -> studentId;
    } else {
        ofs <<student -> studentId;
    }

    delete student;
    ifs.close();
    ofs.close();

    remove(stPath.c_str());
    rename("tmp.txt", stPath.c_str());
    
}