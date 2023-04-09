#include "studentInAClass.h"
#include "main.h"
#include <unistd.h>
#include <fstream>
#include <iomanip>
using namespace std;

void inputStudentsToClass(schoolYear *curSY, Class * curClass)
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

	Student* curr = new Student;

	while (!fin.eof()) {
		string temp;

		getline(fin, temp, ',');
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
        string path2 = "profile//" + to_string(curr->studentId) + ".txt";

		string path3 = curSY -> name + "\\" + curClass -> name + "\\" + to_string(curr->studentId);

		// create folder MSSV in SY/Class
		mkdir(path3.c_str());

		// add data to profile/mssv.txt

        ofs.open(path2);
		ofs << curr -> studentId << endl << "1234" << endl;
		ofs << curSY -> name << endl;
		ofs << curClass -> name << endl;
		ofs << 1 << endl;
		ofs << curr -> lastName << "," << curr -> firstName << endl;
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
	delete curr;
	
	fin.close();
}

void displayListOfStudents(string SY, string Class)
{
	string path = SY + "//" + Class + "//" + "student.txt";
	string tmp;
	int no = 1;

	ifstream ifs(path);

	if (!ifs.is_open()) {
		cout << "This class has no student now!!\n";
		system("pause");
		return;
	} else {
		string line;
		while (getline(ifs, line)) {
			cout << setw(3) << no ;
			no++;
			ifstream fin("profile//" + line + ".txt");
			if (fin.is_open()) {
				string tmp;
				getline(fin, tmp);
				cout << setw(10) << tmp;
				getline(fin, tmp);
				getline(fin, tmp);
				getline(fin, tmp);
				getline(fin, tmp, ',');
				string tmp2;
				getline(fin, tmp2);
				tmp2 = tmp2 + " " + tmp;
				cout << setw(20) << tmp2;
				getline(fin, tmp);
				cout << setw(9) << tmp;
				getline(fin, tmp);
				cout << setw(11) << tmp;
				getline(fin, tmp);
				cout << setw(14) << tmp << endl;
			}
			fin.close();
		}
	}
	ifs.close();
}