#include "Add1StToClass.h"

// Undecided how to set up profile/mssv.txt
void add1StToClass(string nameSY, string nameClass) {
    Student stu;
    int no = 1;

    cout << "Enter student's ID: ";
    cin >> stu.studentId;
    cout << "Enter student's first name: ";
    cin.ignore();
    getline(cin , stu.firstName);
    cout << "Enter student's last name: ";
    getline(cin , stu.lastName);
    cout << "Enter student's gender: ";
    cin >> stu.gender;
    cout << "Enter student's birthday: ";
    cin >> stu.dateOfBirth;
    cout << "Enter student's social ID: ";
    cin >> stu.socialId;

    _mkdir("profile");
    string path_Pro5_MSSV = "profile//" + to_string(stu.studentId) + ".txt";

    ifstream fin(path_Pro5_MSSV);
    if (fin.is_open()) {
        cout << "This student has already exist in this schoolyear\n";
        system("pause");

        cout << "Do you want to continue adding 1 student to this class?";
        cout << "\n1.Yes";
        cout << "\n2.No\n";

        int move;
		
		do	{
			cout << "Please choose your move: ";
			cin >> move;

			switch (move)	{
				case 1: 
					return add1StToClass(nameSY, nameClass);
				case 2: 
                    return;
				default:	
					cout << "You've entered wrong choice";
					cout << "\nPlease try again";
					cout << endl;
			}	
		}	while (move != 1 && move != 2);
    } else {

        // crete file profile/MSSV.txt
        ofstream out(path_Pro5_MSSV);
        out << stu.studentId << endl << "1234\n";
        out << nameSY << endl;
        out << nameClass << endl;
        out << stu.lastName << "," << stu.firstName << endl;
        out << stu.gender << endl;
        out << stu.dateOfBirth << endl;
        out << stu.socialId;
        out.close();
    }

    _mkdir((nameSY + "//" + nameClass + "//" + to_string(stu.studentId)).c_str());

    string stPath = nameSY + "//" + nameClass + "//" + "student.txt";
    ifstream ifs(stPath);
    ofstream ofs("tmp.txt");
    if (ifs.is_open()) {
        string tmp;
        while (getline(ifs, tmp)) {
            ofs << tmp << endl;
            if (tmp == to_string(stu.studentId)) {
                cout << "This student has aldready exists\n\n";
                ofs.close();
                remove("tmp.txt");
                ifs.close();
                system("pause");
                return add1StToClass(nameSY, nameClass);
            }
        }
        ofs <<stu.studentId;
    } else {
        ofs <<stu.studentId;
    }

    ifs.close();
    ofs.close();

    remove(stPath.c_str());
    rename("tmp.txt", stPath.c_str());
    
}