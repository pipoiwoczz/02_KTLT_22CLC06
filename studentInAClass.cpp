#include "studentInAClass.h"
#include "main.h"
#include <unistd.h>
#include <fstream>

void inputStudentsToClass(Student*& pHead, schoolYear *curSY, Class * curClass)
{
	int no = 1;
	ifstream fin;
	string path, temp;
	cout << "Enter the path of a CSV file containing students: ";
	cin >> path;
	fin.open(path);

	if (!fin.is_open()) {
		cout << "The file doesn't exist.";
		return;
	}

	Student* curr = pHead;

	while (!fin.eof()) {
		if (!pHead) {
			pHead = new Student;
			curr = pHead;
		}
		else {
			no++;
			while (curr -> next) {
				curr = curr -> next;
				no++;
			}
			curr->next = new Student;
			curr = curr->next;
		}
		string temp;

		getline(fin, temp, ',');
		curr->No = no;
		getline(fin, temp, ',');
		curr->studentId = stoi(temp);
		getline(fin, temp, ',');
		curr->firstName = temp;
		getline(fin, temp, ',');
		curr->lastName = temp;
		getline(fin, temp, ',');
		curr->gender = temp;
		getline(fin, temp, ',');
		curr->dateOfBirth = temp;
		getline(fin, temp);
		curr->socialId = temp;

		mkdir("profile");
        ofstream ofs;
        string path = "profile//";

        int n = curr -> studentId;

		char tmp[100] = "";
		string idNum;
		int cnt = 0;
        while (n != 0) {
            tmp[cnt] = char(n % 10 + 48);
            n /= 10;
			cnt++;
        }

		for (int i = cnt - 1; i >= 0; i--) {
			path += tmp[i];
			idNum += tmp[i];
		}
		string path2 = curSY -> name + "\\" + curClass -> name + "\\" + idNum;
		mkdir(path2.c_str());

        path += ".txt";

        ofs.open(path);
        ofs << curr -> No << "," << curr -> studentId << "," << curr -> firstName << "," << curr -> lastName << "," << curr -> gender << "," << curr -> dateOfBirth << "," << curr -> socialId << endl;
        ofs.close();
	}
	fin.close();
}

void displayListOfStudents(Student* pHead)
{
	Student* temp = pHead;

	while (temp) {
		cout << temp->No;
		if (temp->No >= 10)
			cout << " ";
		cout << "  ";
		cout << temp->studentId << "  ";
		cout << temp->firstName << " " << temp->lastName << "  ";
		cout << temp->gender << "  ";
		cout << temp->dateOfBirth << "  ";
		cout << temp->socialId << endl;
		temp = temp->next;
	}
}