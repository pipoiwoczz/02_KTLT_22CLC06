#include "main.h"
#include <string>
#include <cstring>
#include <stdlib.h>
#include <unistd.h>
#include <iostream>
#include <fstream>
using namespace std;

void add1StToClass(Student *& headStudent, schoolYear * curSY, Class * curClass) {
    Student * tmp = headStudent;
    int no = 1;

    if (!headStudent) {
        headStudent = new Student;
        headStudent -> No = no;
        cout << "Enter student's ID: ";
        cin >> headStudent -> studentId;
        cin.ignore();
        cout << "Enter student's first name: ";
        getline(cin , headStudent -> firstName);
        cin.ignore();
        cout << "Enter student's last name: ";
        getline(cin , headStudent -> lastName);
        cout << "Enter student's gender: ";
        cin >> headStudent -> gender;
        cout << "Enter student's birthday: ";
        cin >> headStudent -> dateOfBirth;
        cout << "Enter student's social ID: ";
        cin >> headStudent -> socialId;

        mkdir("profile");

        ofstream ofs;
        string path = "profile//";
        int n = headStudent -> studentId;

        char tmp2[100] = "";
        string idNum;
		int cnt = 0;
        while (n != 0) {
            tmp2[cnt] = char(n % 10 + 48);
            n /= 10;
			cnt++;
        }

		for (int i = cnt - 1; i >= 0; i--) {
			path += tmp2[i];
        	idNum += tmp2[i];
		}

		string path2 = curSY -> name + "\\" + curClass -> name + "\\" + idNum;
		mkdir(path2.c_str());

        path += ".txt";

        ofs.open(path);
        ofs << headStudent -> No << "," << headStudent -> studentId << "," << headStudent -> firstName << "," << headStudent -> lastName << "," << headStudent -> gender << "," << headStudent -> dateOfBirth << "," << headStudent->socialId << endl;
        ofs.close();
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
        cin.ignore();
        cout << "Enter student's first name: ";
        getline(cin , tmp -> firstName);
        cin.ignore();
        cout << "Enter student's last name: ";
        getline(cin , tmp -> lastName);
        cout << "Enter student's gender: ";
        cin >> tmp -> gender;
        cout << "Enter student's birthday: ";
        cin >> tmp -> dateOfBirth;
        cout << "Enter student's social ID: ";
        cin >> tmp -> socialId;

        mkdir("profile");
        
        ofstream ofs;
        string path = "profile//";
        int n = tmp -> studentId;

        char tmp2[100] = "";
        string idNum;
		int cnt = 0;
        while (n != 0) {
            tmp2[cnt] = char(n % 10 + 48);
            n /= 10;
			cnt++;
        }

		for (int i = cnt - 1; i >= 0; i--) {
			path += tmp2[i];
        	idNum += tmp2[i];
		}

		string path2 = curSY -> name + "\\" + curClass -> name + "\\" + idNum;
		mkdir(path2.c_str());

        path += ".txt";

        ofs.open(path);
        ofs << tmp -> No << "," << tmp -> studentId << "," << tmp -> firstName << "," << tmp -> lastName << "," << tmp -> gender << "," << tmp -> dateOfBirth << "," << tmp->socialId << endl;
        ofs.close();
        }
}