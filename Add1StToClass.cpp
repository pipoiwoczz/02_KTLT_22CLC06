#include "main.h"
#include <iostream>
#include <fstream>
using namespace std;

void add1StToClass(Student *& headStudent) {
    Student * tmp = headStudent;
    int no = 1;
    if (!headStudent) {
        headStudent = new Student;
        headStudent -> No = no;
        cout << "Enter student's ID: ";
        cin >> headStudent -> studentId;
        cout << "Enter student's first name: ";
        cin >> headStudent -> firstName;
        cout << "Enter student's last name: ";
        cin >> headStudent -> lastName;
        cout << "Enter student's gender: ";
        cin >> headStudent -> gender;
        cout << "Enter student's birthday: ";
        cin >> headStudent -> dateOfBirth;
        cout << "Enter student's social ID: ";
        cin >> headStudent -> socialId;
    } else {
        no++;
        while (tmp -> next) {
            tmp = tmp -> next;
            no++;
        }
        tmp -> next = new Student;
        tmp = tmp -> next;
        tmp -> No = no;
        cout << "Enter student's ID: ";
        cin >> tmp -> studentId;
        cout << "Enter student's first name: ";
        cin >> tmp -> firstName;
        cout << "Enter student's last name: ";
        cin >> tmp -> lastName;
        cout << "Enter student's gender: ";
        cin >> tmp -> gender;
        cout << "Enter student's birthday: ";
        cin >> tmp -> dateOfBirth;
        cout << "Enter student's social ID: ";
        cin >> tmp -> socialId;
    }
}