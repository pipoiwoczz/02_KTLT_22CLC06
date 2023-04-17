#include "studentInAClass.h"
#include "main.h"
#include <fstream>
#include <iomanip>
using namespace std;


// 	Undicided how to set up profile/mssv.txt
void inputStudentsToClass(string nameSY, string nameClass)
{
	_mkdir("profile");

	ifstream ifs;
	string fileInput;

	cout << "Enter the path of a CSV file containing students: ";
	cin >> fileInput;
	ifs.open(fileInput);

	if (!ifs.is_open()) {
		ifs.close();
		cout << "The file doesn't exist.";
		cout << "\nDo you want to continue adding students of class (by importing file)?";
		cout << "\n1. Yes";
		cout << "\n2. No\n";

		int move;
		
		do	{
			cout << "Please choose your move: ";
			cin >> move;

			switch (move)	{
				case 1: 
					return inputStudentsToClass(nameSY, nameClass);
				case 2: return;
				default:	
					cout << "You've entered wrong choice";
					cout << "\nPlease try again";
					cout << endl;
			}	
		}	while (move != 1 && move != 2);
	}

	Student tmp;

	while (!ifs.eof()) {
		string temp;

		getline(ifs, temp, ',');

		getline(ifs, temp, ',');
		tmp.studentId = stoi(temp);
		getline(ifs, temp, ',');
		tmp.firstName = temp;
		getline(ifs, temp, ',');
		tmp.lastName = temp;
		getline(ifs, temp, ',');
		tmp.gender = temp;
		getline(ifs, temp, ',');
		tmp.dateOfBirth = temp;
		getline(ifs, temp, '\n');
		tmp.socialId = temp;

        ofstream ofs;
        string path_Pro5_MSSV = "profile/" + to_string(tmp.studentId) + ".txt";

		string path_SY_Class_MSSV = nameSY + "/" + nameClass + "/" + to_string(tmp.studentId);

		// create folder MSSV in SY/Class
		_mkdir(path_SY_Class_MSSV.c_str());

		// add data to profile/mssv.txt
		// Still deciding how to output in4 of student to file 

        ofs.open(path_Pro5_MSSV);
		ofs << tmp.studentId << endl << "1234" << endl;
		ofs << nameSY << endl;
		ofs << nameClass << endl;
		ofs << tmp.lastName << "," << tmp.firstName << endl;
		ofs << tmp.gender << endl;
		ofs << tmp.dateOfBirth << endl;
		ofs << tmp.socialId;
        ofs.close();

		// add data to file student.txt in folder SY//Class (only include student ID)

		path_SY_Class_MSSV = nameSY + "/" + nameClass + "/" + "student.txt";
        ifstream fin;

        fin.open(path_SY_Class_MSSV);
        ofs.open("tmp.txt");
        if (fin.is_open()) 
            while (getline(fin, temp, '\n')) {
                ofs << temp << endl;
            }
		ofs << tmp.studentId;
        fin.close();
        ofs.close();
        remove(path_SY_Class_MSSV.c_str());
        rename("tmp.txt", path_SY_Class_MSSV.c_str());

	}
	
	ifs.close();
}

void displayListOfStudents(string nameSY, string nameClass)
{
	string path = nameSY + "//" + nameClass + "//" + "student.txt";
	string tmp;
	int no = 1;

	ifstream ifs((path).c_str());

	if (!ifs.is_open()) {
		cout << "This class has no student now!!\n";
		system("pause");
		return;
	} else {
		cout << "\n----------------------List of Students------------------------\n";
		cout << left << setw(3) << "No" << setw(10) << "MSSV" << setw(34) << "Full Name" << setw(9) << "Gender" << setw(13) << "DoB" << setw(14) << "Social ID" << endl << endl;
		string mssv;
		while (getline(ifs, mssv)) {
			cout << setw(3) << no;
			++no;
			ifstream fin(("profile//" + mssv + ".txt").c_str());
			if (fin.is_open()) {
				string tmp;
				getline(fin, tmp);
				cout << left << setw(10) << tmp;
				getline(fin, tmp);
				getline(fin, tmp);
				getline(fin, tmp);
				getline(fin, tmp, ',');
				string tmp2;
				getline(fin, tmp2);
				tmp2 = tmp2 + " " + tmp;
				cout << setw(34) << tmp2;
				getline(fin, tmp);
				cout << setw(9) << tmp;
				getline(fin, tmp);
				cout << setw(13) << tmp;
				getline(fin, tmp);
				cout << setw(14) << tmp << endl;
			}
			fin.close();
		}
	}
	ifs.close();
}