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
        string path2 = "profile//";

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
			path2 += tmp[i];
			idNum += tmp[i];
		}
		string path3 = curSY -> name + "\\" + curClass -> name + "\\" + idNum;

		// create folder in SY//Class
		mkdir(path3.c_str());

        path2 += ".txt";

		// add data to profile//mssv.txt

        ofs.open(path2);
		ofs << curr -> studentId << endl << "1234" << endl;
		ofs << curSY -> name << endl;
		ofs << curClass -> name << endl;
		ofs << curr -> firstName << "," << curr -> lastName << endl;
		ofs << curr -> gender << endl;
		ofs << curr -> dateOfBirth << endl;
		ofs << curr -> socialId;
        ofs.close();

		// add data to file student.txt in folder SY//Class (only include student ID)

		path3 = curSY -> name + "\\" + curClass -> name + "\\" + "student.txt";
        ifstream ifs;

        ifs.open(path3);
        ofs.open("tmp.txt");
        if (ifs.is_open()) 
            while (getline(ifs, temp)) {
                ofs << temp << endl;
            }
		ofs << curr -> studentId;
        ifs.close();
        ofs.close();
        remove(path3.c_str());
        rename("tmp.txt", path3.c_str());
	}
	fin.close();
}

void displayListOfStudents(Student* pHead, string SY, string cl)
{
	Student* temp = pHead;

	string path = SY + "//" + cl + "//" + "student.txt";
	string tmp;
	int no = 1;

	ifstream ifs(path);

	while (temp) {
		cout << no;
		temp -> No = no;
		if (getline(ifs, tmp))
			no++;
		if (no >= 10)
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