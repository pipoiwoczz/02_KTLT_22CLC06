#include "removeAStudent.h"

void removeAStudent(string nameSY, string nameClass)
{
	int id;
	cout << "Enter the ID of student: ";
	cin >> id;
	
	string studentID = to_string(id);
	string path_SY_Class_student = nameSY + "/" + nameClass + "/" + "student.txt";

	ifstream ifs(path_SY_Class_student);
	bool flag;

	// check if this student isn't in this class

	if (!ifs.is_open()) {
		cout << "There is no student in this class now!\n";
		cout << "Please input students to this class first!\n";
		system("pause");
		return;
	} else {
		string tmp;
		while (getline (ifs, tmp)) {
			if (tmp == studentID) {
				flag = true;
				break;
			}
			flag = false;
		}
	}

	ifs.close();

	if (flag == false) {
		cout << "The student doesn't exist in this class\n";
		cout << "\nDo you want to remove another student in this class?";
		cout << "\n1. Yes";
		cout << "\n2. No\n";

		int move;
		
		do	{
			cout << "Please choose your move: ";
			cin >> move;

			switch (move)	{
				case 1: 
					return removeAStudent(nameSY, nameClass);
				case 2: 
					return;
				default:	
					cout << "You've entered wrong choice";
					cout << "\nPlease try again";
					cout << endl;
			}	
		}	while (move != 1 && move != 2);
	}

	string path_SY_Class_MSSV = nameSY + "//" + nameClass + "//" + studentID;

	// 	remove folder in SY/class/mssv
	_rmdir(path_SY_Class_MSSV.c_str());

	string path_Pro5_MSSV = "profile/" + studentID + ".txt";	

	//	remove profile/mssv.txt 
	remove(path_Pro5_MSSV.c_str());

	// remove student's id in file class//student.txt

	string tmp;
	ofstream ofs;
	
	ifs.open(path_SY_Class_student);
	ofs.open("tmp.txt");
	if (ifs.is_open()) {
		while (getline (ifs, tmp)) {
			if (tmp != studentID)
				ofs << tmp << endl;
		}
	}

	ofs.close();
	ifs.close();
	remove(path_SY_Class_student.c_str());
	rename("tmp.txt", path_SY_Class_student.c_str());
}