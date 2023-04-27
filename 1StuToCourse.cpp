#include "1StuToCourse.h"

void add1StudentToCourse(string curSY, int season, string courseID)  {
    string classPath = curSY + "//" + char(season + 48) + "//" + courseID + "//" + "class.txt";
	ifstream ifs;
	ofstream ofs;

	cout << "---------List of Class in this Course------------\n";
	ifs.open(classPath);
	if (ifs.is_open()) {
		string tmp;
		while (getline(ifs, tmp)) {
			cout << tmp << endl;
		}
		ifs.close();
	} else {
		cout << "This course has now class\n";
		return;
	}
	cout << "---------------------------------------------------\n";

	string className;
	cout << "Enter class's name: ";
	cin >> className;
    
    bool check = false;;
	ifs.open(classPath);
	if (ifs.is_open()) {
		string tmp;
		while (getline(ifs, tmp)) {
			if (tmp == className) check = true;
		}
	}

	if (!check) {
		ifs.close();
		cout << "You enter invalid class name!\n";
		cout << "Input 0 to get back to previous menu or anything to enter class name again\n";
		string temp;
		cin >> temp;
		if (temp == "0") {
			return;
		} else {
			return add1StudentToCourse(curSY, season, courseID);
		}
	}
	ifs.close();

    cout << "==========Pls enter the information of the Student==========";

    string firstName, lastName;
    int id;

    cout << "\nStudent ID: ";
    cin >> id;

    cout << "Enter student's last name: ";
    cin.ignore();
    getline(cin, lastName);

    cout << "Enter student's first name: ";
    cin >> firstName;
    
    string profilePathCheck = "profile/" + to_string(id) + ".txt";
    ifs.open(profilePathCheck);
    if (!ifs.is_open()) {
        cout << "This student isn't a student in this schoolyear\n";
        cout << "Please enter again\n";
        system("pause");
        return add1StudentToCourse(curSY, season, courseID);
    }
    else {
        ifs.close();
    }
        

    string path = curSY + "/" + to_string(season) + "/" +  courseID + "//" + className +  "/" + "listStud.txt";
    string infoStudent = to_string(id) + "," + lastName + " " + firstName; 
    int flag = 0;

    ifs.open(path);
    ofs.open(curSY + "/" + to_string(season) + "/" + courseID + "/" + "tmp.txt");

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
        remove((curSY + "/" + to_string(season) + "/" +  courseID + "/" + "tmp.txt").c_str());

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
                    return add1StudentToCourse(curSY, season, courseID);
                case 2:
                    return;
                default:
                    cout << "Wrong choice. Pls try again.";
                    break;
            }
        }   while (move != 1 && move != 2);
    } else {
        remove(path.c_str());
        int res = rename((curSY + "/" + to_string(season) + "/" + courseID + "/" + "tmp.txt").c_str(), path.c_str());
    }
}