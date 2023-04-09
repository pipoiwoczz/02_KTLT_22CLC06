#include "removeAStudent.h"
#include "main.h"
#include <string>
#include <direct.h>
#include <stdio.h>
using namespace std;
// #include <filesystem>
// using namespace filesystem;

void removeAStudent(schoolYear * curSY, Class * curClass)
{
	int id;
	cout << "Enter the ID of student: ";
	cin >> id;
	// if (pHead->studentId == id) {
	// 	pHead = pHead->next;
	// 	removeProfile(to_string(prev->studentId));
	// 	delete prev;
	// 	return;
	// }
	// while (prev) {
	// 	if (curr->studentId == id) {
	// 		prev->next = curr->next;
	// 		removeProfile(to_string(curr->studentId));
	// 		delete curr;
	// 		return;
	// 	}
	// 	prev = curr;
	// 	curr = curr->next;
	// }		
	string studentID = to_string(id);
	string studentFile = curSY -> name + "/" + curClass -> name + "/" + "student.txt";

	ifstream ifs(studentFile);
	bool flag;

	// check if this student isn't in this class

	if (!ifs.is_open()) {
		cout << "There is no student in this class now!\n";
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
		cout << "This student doesn't exist in this class\n";
		system("pause");
		return;
	}

	string profileSt = "profile//" + studentID + ".txt";
	cout << profileSt << endl;
	ifs.open(profileSt);

	string className, schoolYear;
	getline(ifs, schoolYear);
	getline(ifs, schoolYear);
	getline(ifs, schoolYear);
	getline(ifs, className);
	string pathStInClass = schoolYear + "//" + className + "//" + studentID;

	rmdir(pathStInClass.c_str());
	
	ifs.close();
	remove(profileSt.c_str());

	// remove student's id in file class//student.txt

	string path = schoolYear + "//" + className + "//" + "student.txt";
	string tmp;
	ofstream ofs;
	
        ifs.open(path);
        ofs.open("tmp.txt");
        if (ifs.is_open()) {
            while (getline (ifs, tmp)) {
				if (tmp != studentID)
                	ofs << tmp << endl;
            }
        }

        ofs.close();
        ifs.close();
        remove(path.c_str());
        rename("tmp.txt", path.c_str());

}