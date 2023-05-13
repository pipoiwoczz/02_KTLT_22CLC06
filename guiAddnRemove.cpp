#include "guiAddnRemove.h"
#include "gui.h"
#include "main.h"
#include "updateGPA.h"
#include <filesystem>
using namespace filesystem;

void importStudentsListInClass(string username, string SY, string classID) {
	system("cls");
	printCharacter(L"Press ESC to back to main menu", {0, 0}, Color::black, Color::bright_white);
	printCenterCharacters(L"<<<< CLASS " + wstring(classID.begin(), classID.end()) + L" >>>>", Color::light_green, Color::bright_white, 2, My_Windows);
	
	printCharacter(L"Input the path here: ", {45, 7}, Color::aqua, Color::bright_white);
	gotoxy(45 + 22, 7);
	string path = getStringInput();
	if (path == "ESC") {
		return mainmenuOpt();
	}

	ifstream ifs(path);
	if (!ifs.is_open()) {
		printCharacter(L"Press F1 to back to previous menu", { short(My_Windows.Right - 34), 0}, Color::black, Color::bright_white);
		printCenterCharacters(L"THIS PATH DOESN'T EXIST", Color::red, Color::bright_white, 10, My_Windows);
		printCenterCharacters(L"PLEASE ENTER AGAIN", Color::red, Color::bright_white, 12, My_Windows);
		printCenterCharacters(L"Press any key to enter again...", Color::green, Color::bright_white, 0, My_Windows);
		int key = getKey();
		if (key == 27) {
			return mainmenuOpt();
		} 
		if (key == 59) {
			return ClassMenuPage(username, SY, classID);
		}
		return importStudentsListInClass(username, SY, classID);
	}
	else {
		_mkdir("profile");
		while (!ifs.eof()) {
			string temp;
			Student tmp;

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
			string path_Pro5_MSSV = "./profile/" + to_string(tmp.studentId) + ".txt";

			string path_SY_Class_MSSV ="./" + SY + "/" + classID + "/" + to_string(tmp.studentId);

			// create folder MSSV in SY/Class
			_mkdir(path_SY_Class_MSSV.c_str());

			// add data to profile/mssv.txt
			// Still deciding how to output in4 of student to file 

			ofs.open(path_Pro5_MSSV);
			ofs << tmp.studentId << endl << "1234" << endl;
			ofs << SY << endl;
			ofs << classID << endl;
			ofs << tmp.lastName << "," << tmp.firstName << endl;
			ofs << tmp.gender << endl;
			ofs << tmp.dateOfBirth << endl;
			ofs << tmp.socialId;
			ofs.close();

			// add data to file student.txt in folder SY//Class (only include student ID)

			path_SY_Class_MSSV ="./" + SY + "/" + classID + "/" + "student.txt";
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
		printCenterCharacters(L"PRESS ANY KEY TO BACK TO PREVIOUS MENU", Color::green, Color::bright_white, 14, My_Windows);
		printCenterCharacters(L"IMPORT SUCCESSFULLY", Color::green, Color::bright_white, 12, My_Windows);
		int key = getKey();
		if (key == 27)
			return mainmenuOpt();
		return ClassMenuPage(username, SY, classID);
	}
}

void addAStudentToClass(string username, string SY, string classID) {
	system("cls");
	printCharacter(L"Press ESC to back to main menu", { 0, 0 }, Color::black, Color::bright_white);
	printCharacter(L"Press F1 to back to previous menu", { short(My_Windows.Right - 34), 0}, Color::black, Color::bright_white);
	printCenterCharacters(L"<<<< CLASS " + wstring(classID.begin(), classID.end()) + L" >>>>", Color::light_green, Color::bright_white, 2, My_Windows);
	printCenterCharacters(L"INPUT  NEW STUDENT'S INFORMATION", Color::light_green, Color::bright_white, 4, My_Windows);

	Student stu;
	printCharacter(L"Input new student's ID here: ", { 45, 6 }, Color::blue, Color::bright_white);
	gotoxy(45 + 30, 6);
	string ID = getMenuString();
	if (ID == "ESC") {
		return mainmenuOpt();
	}
	if (ID == "F1") {
		return ClassMenuPage(username, SY, classID);
	}

	printCharacter(L"Input new student's first name here: ", { 45, 8 }, Color::blue, Color::bright_white);
	gotoxy(45 + 38, 8);
	string fName = getMenuString();
	if (fName == "ESC") {
		return mainmenuOpt();
	}
	if (fName == "F1") {
		return ClassMenuPage(username, SY, classID);
	}

	printCharacter(L"Input new student's last name here: ", { 45, 10 }, Color::blue, Color::bright_white);
	gotoxy(45 + 37, 10);
	string lName = getMenuString();
	if (lName == "ESC") {
		return mainmenuOpt();
	}
	if (lName == "F1") {
		return ClassMenuPage(username, SY, classID);
	}

	printCharacter(L"Input new student's gender here: ", { 45, 12 }, Color::blue, Color::bright_white);
	gotoxy(45 + 34, 12);
	string gender = getMenuString();
	if (gender == "ESC")
		return mainmenuOpt();
	if (gender == "F1")
		return ClassMenuPage(username, SY, classID);

	printCharacter(L"Input new student's date of birth here: ", { 45, 14 }, Color::blue, Color::bright_white);
	gotoxy(45 + 41, 14);
	string dob = getMenuString();
	if (dob == "ESC")
		return mainmenuOpt();
	if (dob == "F1")
		return ClassMenuPage(username, SY, classID);

	printCharacter(L"Input new student's social ID here: ", { 45, 16 }, Color::blue, Color::bright_white);
	gotoxy(45 + 37, 16);
	string socialID = getMenuString();
	if (socialID == "ESC")
		return mainmenuOpt();
	if (socialID == "F1")
		return ClassMenuPage(username, SY, classID);

	_mkdir("profile");
	string path = "./profile/" + ID + ".txt";
	ifstream ifs(path);
	if (ifs.is_open()) {
		ifs.close();
		printCharacter(L"Press F1 to back to previous menu", { short(My_Windows.Right - 34), 0 }, Color::black, Color::bright_white);
		printCenterCharacters(L"THIS STUDENT HAS ALREADY EXIST", Color::red, Color::bright_white, 19, My_Windows);
		printCenterCharacters(L"Press any key to enter again", Color::red, Color::bright_white, 21, My_Windows);
		int key = getKey();
		if (key == 27)
			return mainmenuOpt();
		if (key == 59)
			return ClassMenuPage(username, SY, classID);
		return addAStudentToClass(username, SY, classID);
	}
	else {
		_mkdir((SY + "/" + classID + "/" + ID).c_str());
		ofstream ofs(path);
		ofs << ID << endl << 1234 << endl << SY << endl << classID << endl << fName << "," << lName << endl << gender << endl << dob << endl << socialID;
		ofs.close();
		ifs.open(SY + "/" + classID + "/student.txt");
		if (ifs.is_open() && !ifs.eof()) {
			ifs.close();
			ofs.open(SY + "/" + classID + "/student.txt", ios::app);
			ofs << endl << ID;
			ofs.close();
		}
		else {
			ofs.open(SY + "/" + classID + "/student.txt");
			ofs << ID;
			ofs.close();
		}
		printCenterCharacters(L"CONGRATULATION! You added successfully", Color::green, Color::bright_white, 19, My_Windows);
		printCenterCharacters(L"Press any key to enter again or Press F1 to add one more student", Color::green, Color::bright_white, 21, My_Windows);
		int key = getKey();
		if (key == 27)
			return mainmenuOpt();
		if (key == 59)
			return addAStudentToClass(username, SY, classID);
		return ClassMenuPage(username, SY, classID);

	}
}

void removeAStudentInClass(string username, string SY, string classID) {
	system("cls");
	printCharacter(L"Press ESC to back to main menu", { 0, 0 }, Color::black, Color::bright_white);
	printCenterCharacters(L"<<<< CLASS " + wstring(classID.begin(), classID.end()) + L" >>>>", Color::light_green, Color::bright_white, 2, My_Windows);
	printCharacter(L"Enter Student's ID you want to remove here: ", {45, 5}, Color::blue, Color::bright_white);

	gotoxy(45 + 45, 5);
	string ID = getStringInput();
	if (ID == "ESC")
		return mainmenuOpt();

	string listStClass = "./" + SY + "/" + classID + "/student.txt";
	ifstream ifs;
	bool flag = false;
	ifs.open("profile/" + ID + ".txt");
	if (!ifs.is_open()) {
		printCharacter(L"Press F1 to back to previous menu", { short(My_Windows.Right - 34), 0 }, Color::black, Color::bright_white);
		printCenterCharacters(L"THIS STUDENT HASN'T ALREADY EXIST", Color::red, Color::bright_white, 8, My_Windows);
		printCenterCharacters(L"Press any key to enter again", Color::red, Color::bright_white, 10, My_Windows);
		int key = getKey();
		if (key == 27)
			return mainmenuOpt();
		if (key == 59)
			return ClassMenuPage(username, SY, classID);
		return removeAStudentInClass(username, SY, classID);
	}
	ifs.close();
	ifs.open(listStClass);
	if (!ifs.is_open() || ifs.eof()) {
		ifs.close();
		printCenterCharacters(L"THIS CLASS HAS NO STUDENTS YET", Color::red, Color::bright_white, 8, My_Windows);
		printCenterCharacters(L"Press any key to back to previous menu", Color::red, Color::bright_white, 10, My_Windows);
		int key = getKey();
		if (key == 27)
			return mainmenuOpt();
		return ClassMenuPage(username, SY, classID);
	}
	else {
		string temp;
		while (getline(ifs, temp)) {
			if (temp == ID) {
				flag = true;
				break;
			}
		}
		ifs.close();
	}

	if (flag == false) {
		printCenterCharacters(L"THIS STUDENT IS NOT A STUDENT IN THIS CLASS", Color::red, Color::bright_white, 8, My_Windows);
		printCenterCharacters(L"Press any key to enter again or Press F1 back to previous menu", Color::red, Color::bright_white, 10, My_Windows);
		int key = getKey();
		if (key == 27) {
			return mainmenuOpt();
		}
		if (key == 59)
			return ClassMenuPage(username, SY, classID);
		return removeAStudentInClass(username, SY, classID);
	}
	else {

		string path_SY_Class_MSSV = SY + "//" + classID + "//" + ID;

		// 	remove folder in SY/class/mssv
		_rmdir(path_SY_Class_MSSV.c_str());

		string path_Pro5_MSSV = "profile/" + ID + ".txt";

		//	remove profile/mssv.txt 
		remove(path_Pro5_MSSV.c_str());

		// remove student's id in file class//student.txt

		string tmp;
		ofstream ofs;

		ifs.open("./" + SY + "/" + classID + "/student.txt");
		ofs.open("tmp.txt");
		if (ifs.is_open()) {
			while (getline(ifs, tmp)) {
				if (tmp != ID) {
					ofs << tmp;
					if (!ifs.eof())
						ofs << endl;
				}
			}
		}

		ofs.close();
		ifs.close();
		remove(("./" + SY + "/" + classID + "/student.txt").c_str());
		rename("tmp.txt", ("./" + SY + "/" + classID + "/student.txt").c_str());

		printCenterCharacters(L"CONGRATULATION!! YOU REMOVE THIS STUDENT SUCCESSFULLY", Color::red, Color::bright_white, 8, My_Windows);
		printCenterCharacters(L"Press any key to back to previous menu or Press F1 to remove 1 more student", Color::red, Color::bright_white, 10, My_Windows);
		int key = getKey();
		if (key == 27)
			return mainmenuOpt();
		if (key == 59)
			return removeAStudentInClass(username, SY, classID);
		return ClassMenuPage(username, SY, classID);

	}
}

void removeACourse(string username, string SY, short season) {
	system("cls");
	printCharacter(L"Press ESC to back to main menu", { 0, 0 }, Color::black, Color::bright_white);
	printCenterCharacters(L"<<<<DELETE A COURSE>>>>", Color::green, Color::bright_white, 2, My_Windows);
	if (season == 1) {
		printCenterCharacters(L"<<Spring>>", Color::light_aqua, Color::bright_white, 3, My_Windows);
	}
	if (season == 2) 
		printCenterCharacters(L"<<Summer>>", Color::light_aqua, Color::bright_white, 3, My_Windows);
	if (season == 3)
		printCenterCharacters(L"<<Autumn>>", Color::light_aqua, Color::bright_white, 3, My_Windows);

	string path = SY + "//" + to_string(season) + "/" + "course.txt";
	string tmp;
	int no = 1;
	ifstream ifs((path).c_str());
	short line = 8;
	if (!ifs.is_open() || ifs.eof()) {
		ifs.close();
		printCenterCharacters(L"----------------------THIS SEMESTER HAS NO COURSE------------------------", Color::purple, Color::bright_white, 5, My_Windows);
		printCenterCharacters(L"Press any key to back to previous menu", Color::green, Color::bright_white, 0, My_Windows);
		int key = getKey();
		if (key == 27)
			return mainmenuOpt();
		return SemesterMenuPage(username, SY, season);
	}
	else {
		printCenterCharacters(L"----------------------List of Courses------------------------", Color::purple, Color::bright_white, 5, My_Windows);
		while (getline(ifs, tmp)) {
			printCenterCharacters(wstring(tmp.begin(), tmp.end()), Color::purple, Color::bright_white, line, My_Windows);
			line += 2;
		}
		ifs.close();
		printCharacter(L"Enter your choice here: ", { 45, short(line + 3) }, Color::blue, Color::bright_white);
		gotoxy(45 + 25, line + 3);
		string course = getStringInput();
		if (course == "ESC")
			return mainmenuOpt();
		bool flag = false;
		ifs.open(path);
		while (getline(ifs, tmp)) {
			if (tmp == course) {
				flag = true;
				break;
			}
		}
		ifs.close();
		if (!flag) {
			printCenterCharacters(L"----------------------THIS COURSE DOES NOT EXIST------------------------", Color::purple, Color::bright_white, line + 5, My_Windows);
			printCenterCharacters(L"Press any key to enter again or press F1 to back to previous menu", Color::red, Color::bright_white, line + 7, My_Windows);
			int key = getKey();
			if (key == 27)
				return mainmenuOpt();
			if (key == 59)
				return SemesterMenuPage(username, SY, season);
			return removeACourse(username, SY, season);
		}
		else {
			printCenterCharacters(L"----------------------ARE YOU SURE TO DELETE THIS COURSE------------------------", Color::purple, Color::bright_white, line + 5, My_Windows);
			printCenterCharacters(L"Press any key to delete this Course or Press F1 to back to previous menu", Color::green, Color::bright_white, line + 7, My_Windows);
			int key = getKey();
			if (key == 27)
				return mainmenuOpt();
			if (key == 59)
				return SemesterMenuPage(username, SY, season);

			string classPath = SY + "//" + to_string(season) + "//" + course + "//";

			ofstream ofs;

			remove_all(SY + "//" + to_string(season) + "//" + course);

			// delete courseID in file course.txt in folder Season
			ifs.open((SY + "//" + to_string(season) + "//" + "course.txt").c_str());
			ofs.open("tmp.txt");

			if (ifs.is_open()) {
				string temp;
				while (getline(ifs, temp)) {
					if (temp == course);
					else ofs << temp << endl;
				}
			}

			ifs.close();
			ofs.close();

			remove((SY + "//" + to_string(season) + "//" + "course.txt").c_str());
			rename("tmp.txt", (SY + "//" + to_string(season) + "//" + "course.txt").c_str());

			printCenterCharacters(L"DELETE SUCCESSFULLY", Color::green, Color::bright_white, line + 9, My_Windows);
			printCenterCharacters(L"Press any key to back to previous menu or Press F1 to back to remove 1 more Course", Color::green, Color::bright_white, line + 7, My_Windows);
			key = getKey();
			if (key == 27)
				return mainmenuOpt();
			if (key == 59)
				return removeACourse(username, SY, season);
			return SemesterMenuPage(username, SY, season);
		}
	}
}

void UpdateCourseInfor(string username, string SY, short season) {
	system("cls");
	printCharacter(L"Press ESC to back to main menu", { 0, 0 }, Color::black, Color::bright_white);
	printCharacter(L"Press F1 to exit updating menu", { short(My_Windows.Right - 34), 0}, Color::black, Color::bright_white);
	printCenterCharacters(L"<<<<UPDATE COURSE INFORMATION>>>>", Color::green, Color::bright_white, 2, My_Windows);
	if (season == 1) {
		printCenterCharacters(L"<<Spring>>", Color::light_aqua, Color::bright_white, 3, My_Windows);
	}
	if (season == 2)
		printCenterCharacters(L"<<Summer>>", Color::light_aqua, Color::bright_white, 3, My_Windows);
	if (season == 3)
		printCenterCharacters(L"<<Autumn>>", Color::light_aqua, Color::bright_white, 3, My_Windows);

	string path = SY + "//" + to_string(season) + "/" + "course.txt";
	string tmp;
	int no = 1;
	ifstream ifs((path).c_str());
	short line = 8;
	if (!ifs.is_open() || ifs.eof()) {
		ifs.close();
		printCenterCharacters(L"----------------------THIS SEMESTER HAS NO COURSE------------------------", Color::purple, Color::bright_white, 5, My_Windows);
		printCenterCharacters(L"Press any key to back to previous menu", Color::green, Color::bright_white, 0, My_Windows);
		int key = getKey();
		if (key == 27)
			return mainmenuOpt();
		return SemesterMenuPage(username, SY, season);
	}
	else {
		printCenterCharacters(L"----------------------List of Courses------------------------", Color::purple, Color::bright_white, 5, My_Windows);
		while (getline(ifs, tmp)) {
			printCenterCharacters(wstring(tmp.begin(), tmp.end()), Color::purple, Color::bright_white, line, My_Windows);
			line += 2;
		}
		ifs.close();
		printCharacter(L"Enter your choice here: ", { 45, short(line + 3) }, Color::blue, Color::bright_white);
		gotoxy(45 + 25, line + 3);
		string course = getStringInput();
		if (course == "ESC")
			return mainmenuOpt();
		bool flag = false;
		ifs.open(path);
		while (getline(ifs, tmp)) {
			if (tmp == course) {
				flag = true;
				break;
			}
		}
		ifs.close();
		if (!flag) {
			printCenterCharacters(L"----------------------THIS COURSE DOES NOT EXIST------------------------", Color::purple, Color::bright_white, line + 5, My_Windows);
			printCenterCharacters(L"Press any key to enter again or press F1 to back to previous menu", Color::red, Color::bright_white, line + 7, My_Windows);
			int key = getKey();
			if (key == 27)
				return mainmenuOpt();
			if (key == 59)
				return SemesterMenuPage(username, SY, season);
			return UpdateCourseInfor(username, SY, season);
		}
		else {

			// getCourseInfo
			string course_infor_path = SY + "/" + to_string(season) + "/" + course + "/info.txt";
			string courseID, courseName, courseCre;
			ifstream fin(course_infor_path);
			if (fin.is_open()) {
				getline(fin, courseID);
				getline(fin, courseName);
				getline(fin, courseCre);
			}
			else {
				cout << "Can not open file" << endl;
			}
			fin.close();

			// print course info
			printCenterCharacters(L"You can press enter to skip this status", Color::purple, Color::bright_white, line + 6, My_Windows);
			printCenterCharacters(L"----------------------EDIT COURSE INFORMATION------------------------", Color::purple, Color::bright_white, line + 5, My_Windows);
			printCharacter(L"Course ID: ", { 45, short(line + 8) }, Color::blue, Color::bright_white);
			printCharacter(wstring(courseID.begin(), courseID.end()), { 45 + 12, short(line + 8) }, Color::gray, Color::bright_white);
			drawBox(line + 9);
			printCharacter(L"Course Name: ", { 45, short(line +12) }, Color::blue, Color::bright_white);
			printCharacter(L"" + wstring(courseName.begin(), courseName.end()), { 45 + 14, short(line + 12) }, Color::gray, Color::bright_white);
			drawBox(line + 13);
			printCharacter(L"Course Credits: ", { 45, short(16 + line) }, Color::blue, Color::bright_white);
			printCharacter(L"" + wstring(courseCre.begin(), courseCre.end()), { 45 + 17, short(line + 16) }, Color::gray, Color::bright_white);
			drawBox(line + 17);

			// get New infor
			string newCourseID, newCourseName, newCourseCre;

			gotoxy(46, line + 10);
			newCourseID = getMenuString();
			if (newCourseID == "ESC")
				return mainmenuOpt();
			if (newCourseID == "F1")
				return SemesterMenuPage(username, SY, season);
			gotoxy(46, line + 14);
			newCourseName = getMenuString();
			if (newCourseName == "ESC")
				return mainmenuOpt();
			if (newCourseName == "F1")
				return SemesterMenuPage(username, SY, season);
			gotoxy(46, line + 18);
			newCourseCre = getMenuString();
			if (newCourseCre == "ESC")
				return mainmenuOpt();
			if (newCourseCre == "F1")
				return SemesterMenuPage(username, SY, season);


			// update this course in course.txt
			string path = "./" + SY + "/" + to_string(season) + "/" + course + "/class.txt";
			string coursePath = "./" + SY + "/" + to_string(season) + "/course.txt";
			ofstream ofs;
			ifs.open(coursePath);
			if (ifs.is_open()) {
				string tmp;
				ofs.open("./" + SY + "/" + to_string(season) + "/tmp.txt");
				while (getline(ifs, tmp)) {
					if (newCourseID != "" && newCourseID != "next" && tmp == courseID)
						ofs << newCourseID;
					else
						ofs << tmp;
					if (!ifs.eof())
						ofs << endl;
				}
				ifs.close();
				ofs.close();
			}
			// update courseID/info.txt
			ifs.open(course_infor_path);
			ofs.open("tmp.txt");
			getline(ifs, tmp);
			if (tmp != "" && tmp != "\n")
				if (newCourseID != "")
					ofs << newCourseID << endl;
				else
					ofs << tmp << endl;
			getline(ifs, tmp);
			if (tmp != "" && tmp != "\n")
				if (newCourseName != "")
					ofs << newCourseName << endl;
				else
					ofs << tmp << endl;
			getline(ifs, tmp);
			if (tmp != "" && tmp != "\n")
				if (newCourseCre != "")
					ofs << newCourseCre;
				else
					ofs << tmp;
			ifs.close();
			ofs.close();
			remove(course_infor_path.c_str());
			rename("tmp.txt", course_infor_path.c_str());
			

			// update course info of all classés
			ifs.open(path);
			string className, teacherName, credits, numberOfStudent, dayOfWeek, session;
			if (ifs.is_open()) {
				string tmp;
				while (getline(ifs, tmp)) {
					string infoPath = "./" + SY + "/" + to_string(season) + "/" + courseID + "/" + tmp + "/info.txt";

					// get info of course class
					fin.open(infoPath);
					getline(fin, tmp);
					getline(fin, courseName);
					getline(fin, className);
					getline(fin, teacherName);
					getline(fin, credits);
					getline(fin, numberOfStudent);
					getline(fin, dayOfWeek);
					getline(fin, session);
					fin.close();

					ofs.open(infoPath);
					if (newCourseID != "")
						ofs << newCourseID << endl;
					else
						ofs << courseID << endl;

					if (newCourseName != "")
						ofs << newCourseName << endl;
					else
						ofs << courseName << endl;

					ofs << className << endl;
					ofs << teacherName << endl;

					if (newCourseCre != "")
						ofs << newCourseCre << endl;
					else
						ofs << credits << endl;

					ofs << numberOfStudent << endl;
					ofs << dayOfWeek << endl;;
					ofs << session;
					ofs.close();
				}
			}

				ifs.close();
				
			if (newCourseID != "0") {
				int res1 = rename(("./" + SY + "/" + to_string(season) + "/" + courseID).c_str(), ("./" + SY + "/" + to_string(season) + "/" + newCourseID).c_str());
				remove(coursePath.c_str());
				int res2 = rename(("./" + SY + "/" + to_string(season) + "/tmp.txt").c_str(), coursePath.c_str());
				courseID = newCourseID;
			};

			printCenterCharacters(L"EDIT SUCCESFULLY", Color::green, Color::bright_white, line + 20, My_Windows);
			printCenterCharacters(L"Press any key to back to previous menu or Press F1 to edit 1 more Course ", Color::red, Color::bright_white, line + 21, My_Windows);
			int key = getKey();
			if (key == 27)
				return mainmenuOpt();
			if (key == 59)
				return UpdateCourseInfor(username, SY, season);
			return SemesterMenuPage(username, SY , season);
		
		}
	}
}


void addACourseClass(string username, string SY, short season, string courseID) {
	system("cls");
	printCharacter(L"Press ESC to back to main menu", { 0, 0 }, Color::black, Color::bright_white);
	printCharacter(L"Press F1 to back to previous menu", { short(My_Windows.Right - 34), 0}, Color::black, Color::bright_white);
	printCenterCharacters(L"ADD COURSE CLASS", Color::purple, Color::bright_white, 3, My_Windows);
	printCenterCharacters(wstring(courseID.begin(), courseID.end()), Color::light_purple, Color::bright_white, 4, My_Windows);

	// get course info
	string path = SY + "/" + to_string(season) + "/" + courseID + "/info.txt";
	string courseName, courseCre, tmp;
	ifstream ifs(path);
	getline(ifs, courseName);
	getline(ifs, courseName);
	getline(ifs, courseCre);
	ifs.close();

	string className, teacherName, numberOfStudent, dayOfWeek, session;
	
	printCharacter(L"Class Name", {45, 6}, Color::blue, Color::bright_white);
	drawBox(7);
	gotoxy(46, 8);
	className = getMenuString();
	if (className == "ESC")
		return mainmenuOpt();
	if (className == "F1")
		return CourseMenuPage(username, SY, season, courseID);
	
	printCharacter(L"Teacher Name", { 45, 10 }, Color::blue, Color::bright_white);
	drawBox(11);
	gotoxy(46, 12);
	teacherName = getMenuString();
	if (teacherName == "ESC")
		return mainmenuOpt();
	if (teacherName == "F1")
		return CourseMenuPage(username, SY, season, courseID);

	printCharacter(L"Number Of Max Student", { 45, 14 }, Color::blue, Color::bright_white);
	drawBox(15);
	gotoxy(46, 16);
	numberOfStudent = getMenuString();
	if (numberOfStudent == "ESC")
		return mainmenuOpt();
	if (numberOfStudent == "F1")
		return CourseMenuPage(username, SY, season, courseID);

	printCharacter(L"Day Of Week", { 45, 18 }, Color::blue, Color::bright_white);
	drawBox(19);
	gotoxy(46, 20);
	dayOfWeek = getMenuString();
	if (dayOfWeek == "ESC")
		return mainmenuOpt();
	if (dayOfWeek == "F1")
		return CourseMenuPage(username, SY, season, courseID);
	printCharacter(L"Session", { 45, 22 }, Color::blue, Color::bright_white);
	drawBox(23);
	gotoxy(46, 24);
	session = getMenuString();
	if (session == "ESC")
		return mainmenuOpt();
	if (session == "F1")
		return CourseMenuPage(username, SY, season, courseID);

	if (className == "" || teacherName == "" || numberOfStudent == "" || dayOfWeek == "" || session == "") {
		printCenterCharacters(L"ANY INFORMATION IS NOT FULFILL YET", Color::red, Color::bright_white, 27, My_Windows);
		printCenterCharacters(L"Press any key to enter again or Press F1 to back to previous menu", Color::red, Color::bright_white, 28, My_Windows);
		int key = getKey();
		if (key == 27)
			return mainmenuOpt();
		if (key == 59)
			return CourseMenuPage(username, SY, season, courseID);
		return addACourseClass(username, SY, season, courseID);
	}
	else {
		// add information to class.txt
		ofstream ofs;
		string classPath = SY + "/" + to_string(season) + "/" + courseID + "/class.txt";
		ifs.open(classPath);
		if (ifs.is_open() && !ifs.eof()) {
			ifs.close();
			ofs.open(classPath, ios::app);
			ofs << endl << className;
			ofs.close();
		}
		else {
			ifs.close();
			ofs.open(classPath);
			ofs << className;
			ofs.close();
		}

		// create info.txt in course class
		_mkdir((SY + "/" + to_string(season) + "/" + courseID + "/" + className).c_str());
		ofs.open((SY + "/" + to_string(season) + "/" + courseID + "/" + className + "/info.txt"));
		ofs << courseID << endl << courseName << endl << className << endl << teacherName << endl << courseCre << endl << numberOfStudent << endl << dayOfWeek << endl << session;
		ofs.close();

		printCenterCharacters(L"COURSE CLASS CREATED SUCCESSFULLY", Color::red, Color::bright_white, 27, My_Windows);
		printCenterCharacters(L"Press any key to enter again or Press F1 to back to previous menu", Color::red, Color::bright_white, 28, My_Windows);
		int key = getKey();
		if (key == 27)
			return mainmenuOpt();
		if (key == 59)
			return CourseMenuPage(username, SY, season, courseID);
		return addACourseClass(username, SY, season, courseID);
	}
}

void exportFileInfoToLL(Score*& head, string path) {
	ifstream fin;
	string No, id, fName, lName, total, final, midterm, other;
	fin.open(path);
	while (!fin.eof()) {
		Score* temp = new Score;
		getline(fin, No, ',');
		temp->No = No;
		if (fin.eof()) {
			delete temp;
			break;
		}
		getline(fin, id, ',');
		temp->studentID = id;
		getline(fin, lName, ',');
		getline(fin, fName, ',');
		temp->fullName = lName+","+fName;
		getline(fin, total, ',');
		temp->totalMark = total;
		getline(fin, final, ',');
		temp->finalMark = final;
		getline(fin, midterm, ',');
		temp->midtermMark = midterm;
		getline(fin, other);
		temp->otherMark = other;

		temp->next = head;
		head = temp;
	}
	fin.close();
}

void deleteLLScore(Score*& head) {
	Score* temp = head;
	while (head) {
		head = head->next;
		delete temp;
		temp = head;
	}
}

void reverseList(Score*& pHead) {
	Score* curA = nullptr, * curB = nullptr;
	while (pHead && pHead->next) {
		curB = pHead->next;
		pHead->next = curA;
		curA = pHead;
		pHead = curB;
	}
	if (pHead) pHead->next = curA;
}

void UpdateAStudentResult(string username, string SY, short season, string courseID) {
	system("cls");

	string sy;
	ifstream scy("SY.txt");
	getline(scy, sy);
	scy.close();

	ifstream ifs, thisCourse;
	ofstream ofs;
	string Id, line, Class, courseClass;
	string pathCourse = "./" + SY + "/" + to_string(season) + "/" + courseID;

	printCharacter(L"Press ESC to back to main menu", { 0, 0 }, Color::black, Color::bright_white);
	printCharacter(L"Press F1 to back to previous menu", { short(My_Windows.Right - 34), 0}, Color::black, Color::bright_white);
	printCenterCharacters(L"EDIT A STUDENT RESULT", Color::aqua, Color::bright_white, 3, My_Windows);
	printCenterCharacters(L"Course " + wstring(courseID.begin(), courseID.end()), Color::light_green, Color::bright_white, 4, My_Windows);

	printCharacter(L"Enter student ID here: ", { 50, 6 }, Color::blue, Color::bright_white);
	gotoxy(50 + 24, 6);
	Id = getMenuString();
	if (Id == "ESC") 
		return mainmenuOpt();
	if (Id == "F1")
		return CourseMenuPage(username, SY, season, courseID);

	bool exist = false;

	ifs.open("./profile/" + Id + ".txt");

	if (ifs.is_open()) {
		getline(ifs, Class); // student id
		getline(ifs, Class); // password
		getline(ifs, Class);
		getline(ifs, Class);

		// Check if the ID is existing in the file listStud.txt of the course
		thisCourse.open("./" + sy + "/" + Class + "/" + Id + "/" + to_string(season) + "_" + SY + ".txt");
		if (thisCourse.is_open()) {
			getline(thisCourse, courseClass); // GPA in this sem
			getline(thisCourse, courseClass); // credit in this sem
			while (getline(thisCourse, courseClass, ',') && courseClass != courseID) // course id
				getline(thisCourse, courseClass); 
			getline(thisCourse, courseClass); // course clasS
		}
		thisCourse.close();
		thisCourse.open(pathCourse + "/" + courseClass + "/listStud.txt");
		if (thisCourse.is_open()) {
			while (!thisCourse.eof()) {
				getline(thisCourse, line, ','); // student ID
				if (Id == line) {
					exist = true;
					break;
				} 
				getline(thisCourse, line); // Student name
			}
		}
		thisCourse.close();
	}
	ifs.close();

	if (!exist) {
		printCenterCharacters(L"THIS STUDENT IS NOT A STUDENT OF THIS COURSE", Color::red, Color::bright_white, 8, My_Windows);
		printCenterCharacters(L"Press any key to enter again or Press F1 to back to previous menu", Color::red, Color::bright_white, 9, My_Windows);
		int key = getKey();
		if (key == 27)
			return mainmenuOpt();
		if (key == 59)
			return CourseMenuPage(username, SY, season, courseID);
		return UpdateAStudentResult(username, SY, season, courseID);
	} 

	pathCourse += "/" + courseClass + "/scoreboard.txt"; // This path is used to renew the info of the scoreboard of a course
	Score* pScore = nullptr, * cur;
	exportFileInfoToLL(pScore, pathCourse); // insert data of scoreboard.txt of a course to a linked list
	cur = pScore;
	while (cur && cur->studentID != Id)
		cur = cur->next; // traverse to the Node save info of the student whose score is being updating

	////////// EDITING RESULT OF A STUDENT 
	int choice;
	string oldTotal, total, finalM, midterm, other;
	oldTotal = cur->totalMark;
	total = cur->totalMark;
	finalM = cur->finalMark;
	midterm = cur->midtermMark;
	other = cur->otherMark;

	printCenterCharacters(L"Press enter to skip this mark", Color::red, Color::bright_white, 8, My_Windows);

	printCharacter(L"Enter total mark: ", { 45, 10 }, Color::blue, Color::bright_white);
	gotoxy(45 + 19, 10);
	cur->totalMark = getStringInput();
	if (cur->totalMark == "ESC") {
		deleteLLScore(pScore);
		return mainmenuOpt();
	}
	printCharacter(L"Enter final mark: ", { 45, 12 }, Color::blue, Color::bright_white);
	gotoxy(45 + 19, 12);
	cur->finalMark = getStringInput();
	if (cur->finalMark == "ESC") {
		deleteLLScore(pScore);
		return mainmenuOpt();
	}
	printCharacter(L"Enter midterm mark: ", { 45, 14 }, Color::blue, Color::bright_white);
	gotoxy(45 + 21, 14);
	cur->midtermMark = getStringInput();
	if (cur->midtermMark == "ESC") {
		deleteLLScore(pScore);
		return mainmenuOpt();
	}
	printCharacter(L"Enter other mark: ", { 45, 16 }, Color::blue, Color::bright_white);
	gotoxy(45 + 19, 16);
	cur->otherMark = getStringInput();
	if (cur->otherMark == "ESC") {
		deleteLLScore(pScore);
		return mainmenuOpt();
	}

	if (cur->totalMark != "")
		total = cur->totalMark;
	else {
		cur->totalMark = total;
	}
	if (cur->finalMark != "")
		finalM = cur->finalMark;
	else {
		cur->finalMark = finalM;
	}
	if (cur->midtermMark != "")
		midterm = cur->midtermMark;
	else {
		cur->midtermMark = midterm;
	}
	if (cur->otherMark != "")
		other = cur->otherMark;
	else {
		cur->otherMark = other;
	}

	reverseList(pScore);
	////////// NOW REWRITE THE DATA TO THE SCOREBOARD FILE
	ofs.open(pathCourse);
	cur = pScore;
	while (cur) {
		ofs << cur->No << ",";
		ofs << cur->studentID << ",";
		ofs << cur->fullName << ",";
		ofs << cur->totalMark << ",";
		ofs << cur->finalMark << ",";
		ofs << cur->midtermMark << ",";
		ofs << cur->otherMark;
		if (cur->next) ofs << endl;
		cur = cur->next;
	}
	ofs.close();
	////////// END WRITING

	////////// REWRITE THE DATA TO THE SCORE FILE OF FOLDER STUDENT IN FOLDER CLASS
	// Read the info of the class that the student belongs to

	string pathInClass = "./" + sy + "/" + Class + "/" + Id + "/" + courseID + ".txt";
	// This path leads to the file score of student in the folder student of folder class

	// cur = pScore; // Set the cur back to the pHead
	// while (cur && cur -> studentID != Id) 
	//     cur = cur -> next; // traverse to the Node save info of the student whose score is being updating

	ofs.open(pathInClass);
	// ofs << cur -> totalMark << "," << cur -> finalMark << "," << cur -> midtermMark << "," << cur -> otherMark; 
	ofs << total << "," << finalM << "," << midterm << "," << other;
	ofs.close();
	////////// END WRITING

	if (oldTotal != total) updateGPA(Id, SY, to_string(season));
	deleteLLScore(pScore);

	printCenterCharacters(L"UPDATE SUCCESSFULLY", Color::green, Color::bright_white, 19, My_Windows);
	printCenterCharacters(L"Press any key to back to previous menu or F1 to edit 1 more", Color::green, Color::bright_white, 21, My_Windows);
	int key = getKey();
	if (key == 27)
		return mainmenuOpt();
	if (key == 59)
		return UpdateAStudentResult(username, SY, season, courseID);
	return CourseMenuPage(username, SY, season, courseID);
}

void importStudentToCourseClass(string username, string SY, short season, string courseID, string className) {
	system("cls");
	printCharacter(L"Press ESC to back to main menu", { 0, 0 }, Color::black, Color::bright_white);
	printCenterCharacters(L"<<<< CLASS " + wstring(className.begin(), className.end()) + L" >>>>", Color::light_green, Color::bright_white, 2, My_Windows);

	printCharacter(L"Input the path here: ", { 45, 7 }, Color::aqua, Color::bright_white);
	gotoxy(45 + 22, 7);
	string path = getStringInput();
	if (path == "ESC") return mainmenuOpt();
	ifstream fin(path);
	if (!fin.is_open() || fin.eof()) {
		fin.close();
		printCharacter(L"Press F1 to back to previous menu", { short(My_Windows.Right - 34), 0 }, Color::black, Color::bright_white);
		printCenterCharacters(L"THIS PATH DOESN'T EXIST", Color::red, Color::bright_white, 10, My_Windows);
		printCenterCharacters(L"PLEASE ENTER AGAIN", Color::red, Color::bright_white, 12, My_Windows);
		printCenterCharacters(L"Press any key to enter again or Press F1 to back to previous menu", Color::green, Color::bright_white, 0, My_Windows);
		int key = getKey();
		if (key == 27) {
			return mainmenuOpt();
		}
		if (key == 59) {
			return CourseMenuPage(username, SY, season, courseID);
		}
		return importStudentToCourseClass(username, SY, season, courseID, className);
	}
		
	string stId, fName, lName, temp;

	short line = 6;

	while (!fin.eof()) {

		string tmp;
		getline(fin, tmp, ',');
		stId = tmp;
		getline(fin, tmp, ',');
		fName = tmp;
		getline(fin, tmp);
		lName = tmp;

		ifstream ifs;
		ofstream ofs;

		string profilePathCheck = "./profile/" + (stId) + ".txt";
		ifs.open(profilePathCheck);
		if (!ifs.is_open()) {
			printCenterCharacters(wstring(stId.begin(), stId.end()) + L" is not a student in this schoolyear", Color::light_red, Color::bright_white, line, My_Windows);
			printCenterCharacters(L"Press any key to continue", Color::green, Color::bright_white, line + 1, My_Windows);
			line++;
			continue;
		}
		else {
			ifs.close();

			string sy;
			ifs.open("SY.txt");
			getline(ifs, sy);
			ifs.close();

			string curSY;
			short curSeason;

			ifstream course, student;
			student.open("./profile/" + stId + ".txt");
			string classID;
			for (int i = 0; i < 4; i++) {
				getline(student, classID);
			}
			student.close();
			course.open("./" + sy + "/" + classID + "/" + stId + "/courses.txt");
			if (course.is_open()) {
				course >> curSY >> curSeason;
				if (curSY != SY || curSeason != season) {
					course.close();
					ofstream fout("./" + sy + "/" + classID + "/" + stId + "/courses.txt");
					fout << SY << endl << season << endl << courseID << "," << className;
					fout.close();
				}
				else {
					course.close();
					ofstream fout("./" + sy + "/" + classID + "/" + stId + "/courses.txt", ios::app);
					fout << endl << courseID << "," << className;
					fout.close();
				}
			}
			else {
				course.close();
				ofstream fout("./" + sy + "/" + classID + "/" + stId + "/courses.txt");
				fout << season << endl << SY << endl << courseID << "," << className;
				fout.close();
			}

		}

		string path = "./" + SY + "/" + char(season + 48) + "/" + courseID + "/" + className + "/" + "listStud.txt";


		ifs.open(path);
		ofs.open("tmp.txt");
		if (ifs.is_open())
			while (getline(ifs, temp)) {
				ofs << temp << endl;
			}
		ofs << stId << "," << fName << " " << lName;
		ifs.close();
		ofs.close();
		remove(path.c_str());
		rename("tmp.txt", path.c_str());
	}
	fin.close();


	printCenterCharacters(L"IMPORT SUCCESSFULLY", Color::green, Color::bright_white, line + 2, My_Windows);
	printCenterCharacters(L"Press any to back to previous menu", Color::green, Color::bright_white, line + 3, My_Windows);
	int key = getKey();
	if (key == 27)
		return mainmenuOpt();
	return CourseClassMenuPage(username, SY, season, courseID, className);
}

void addAStudentToCourseClass(string username, string SY, short season, string courseID, string className) {
	string ID, fName, lName;
	ifstream ifs;
	ofstream ofs;
	system("cls");
	printCharacter(L"Press ESC to back to main menu", { 0, 0 }, Color::black, Color::bright_white);
	printCenterCharacters(L"ADD A STUDENT PAGE", Color::aqua, Color::bright_white, 4, My_Windows);
	printCenterCharacters(L"Class " + wstring(className.begin(), className.end()), Color::light_green, Color::bright_white, 5, My_Windows);
	printCenterCharacters(L"===================Please enter student infomation here===================", Color::light_red, Color::bright_white, 7, My_Windows);

	printCharacter(L"Student ID", { 45, 9 }, Color::blue, Color::bright_white);
	drawBox(10);
	gotoxy(46, 11);
	ID = getStringInput();
	if (ID == "ESC")
		return mainmenuOpt();

	string profilePathCheck = "profile/" + ID + ".txt";
	ifs.open(profilePathCheck);
	if (!ifs.is_open()) {
		printCenterCharacters(L"THIS STUDENT IS NOT EXIST IN THIS YEAR", Color::red, Color::bright_white, 13, My_Windows);
		printCenterCharacters(L"Press any key to enter again or Press F1 to back to previous menu", Color::green, Color::bright_white, 15, My_Windows);
		int key = getKey();
		if (key == 27)
			return mainmenuOpt();
		if (key == 59)
			return CourseClassMenuPage(username, SY, season, courseID, className);
		return addAStudentToCourseClass(username, SY, season, courseID, className);
	}
	else {
		ifs.close();

		string sy;
		ifs.open("SY.txt");
		getline(ifs, sy);
		ifs.close();

		string curSY;
		short curSeason;

		ifstream course, student;
		student.open("./profile/" + ID + ".txt");
		string classID;
		for (int i = 0; i < 4; i++) {
			getline(student, classID);
		}
		student.close();
		course.open("./" + sy + "/" + classID + "/" + ID + "/courses.txt");
		if (course.is_open()) {
			course >> curSY >> curSeason;
			if (curSY != SY || curSeason != season) {
				course.close();
				ofstream fout("./" + sy + "/" + classID + "/" + ID + "/courses.txt");
				fout << SY << endl << season << endl << courseID << "," << className;
				fout.close();
			}
			else {
				course.close();
				ofstream fout("./" + sy + "/" + classID + "/" + ID + "/courses.txt", ios::app);
				fout << endl << courseID << "," << className;
				fout.close();
			}
		}
		else {
			course.close();
			ofstream fout("./" + sy + "/" + classID + "/" + ID + "/courses.txt");
			fout << SY << endl << season << endl << courseID << "," << className;
			fout.close();
		}
	}

	printCharacter(L"First Name", { 45, 13 }, Color::blue, Color::bright_white);
	drawBox(14);
	gotoxy(46, 15);
	fName = getStringInput();
	if (fName == "ESC")
		return mainmenuOpt();

	printCharacter(L"Last Name", { 45, 17 }, Color::blue, Color::bright_white);
	drawBox(18);
	gotoxy(46, 19);
	lName = getStringInput();
	if (lName == "ESC")
		return mainmenuOpt();

	string path = SY + "/" + to_string(season) + "/" + courseID + "//" + className + "/" + "listStud.txt";
	string infoStudent = ID + "," + lName +" " + fName;
	int flag = 0;

	ifs.open(path);
	ofs.open(SY + "/" + to_string(season) + "/" + courseID + "/" + "tmp.txt");

	if (ifs.is_open()) {
		string tmp;
		while (getline(ifs, tmp)) {
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

	if (flag == 1) {
		remove((SY + "/" + to_string(season) + "/" + courseID + "/" + "tmp.txt").c_str());

		printCenterCharacters(L"THIS STUDENT IS ALREADY IN THIS COURSE CLASS", Color::red, Color::bright_white, 13, My_Windows);
		printCenterCharacters(L"Press any key to enter again or Press F1 to back to previous menu", Color::green, Color::bright_white, 15, My_Windows);
		int key = getKey();
		if (key == 27)
			return mainmenuOpt();
		if (key == 59)
			return CourseClassMenuPage(username, SY, season, courseID, className);
		return addAStudentToCourseClass(username, SY, season, courseID, className);

	}
	else {
		remove(path.c_str());
		int res = rename((SY + "/" + to_string(season) + "/" + courseID + "/" + "tmp.txt").c_str(), path.c_str());

		printCenterCharacters(L"ADDED SUCCESSFULLY", Color::green, Color::bright_white, 13, My_Windows);
		printCenterCharacters(L"Press any key to back to previous menu or Press F1 to enter again", Color::green, Color::bright_white, 15, My_Windows);
		int key = getKey();
		if (key == 27)
			return mainmenuOpt();
		if (key == 59)
			return addAStudentToCourseClass(username, SY, season, courseID, className);
		return CourseClassMenuPage(username, SY, season, courseID, className);
	}
}

void removeAStudentInCourseClass(string username, string SY, short season, string courseID, string className) {
	system("cls");
	printCharacter(L"Press ESC to back to main menu", { 0, 0 }, Color::black, Color::bright_white);
	printCenterCharacters(L"<<<< CLASS " + wstring(className.begin(), className.end()) + L" >>>>", Color::light_green, Color::bright_white, 2, My_Windows);
	printCharacter(L"Enter Student's ID you want to remove here: ", { 45, 5 }, Color::blue, Color::bright_white);

	gotoxy(45 + 45, 5);
	string ID = getStringInput();
	if (ID == "ESC")
		return mainmenuOpt();

	string listStClass = "./" + SY + "/" +to_string(season) + "/" + courseID + "/" + className + "/listStud.txt";
	ifstream ifs;
	bool flag = false;
	ifs.open("profile/" + ID + ".txt");
	if (!ifs.is_open()) {
		printCenterCharacters(L"THIS STUDENT HASN'T ALREADY EXIST", Color::red, Color::bright_white, 8, My_Windows);
		printCenterCharacters(L"Press any key to enter again or F1 to back to previous menu", Color::red, Color::bright_white, 10, My_Windows);
		int key = getKey();
		if (key == 27)
			return mainmenuOpt();
		if (key == 59)
			return CourseClassMenuPage(username, SY, season, courseID, className);
		return removeAStudentInCourseClass(username, SY, season, courseID, className);
	}
	ifs.close();
	ifs.open(listStClass);
	if (!ifs.is_open() || ifs.eof()) {
		ifs.close();
		printCenterCharacters(L"THIS CLASS HAS NO STUDENTS YET", Color::red, Color::bright_white, 8, My_Windows);
		printCenterCharacters(L"Press any key to back to previous menu", Color::red, Color::bright_white, 10, My_Windows);
		int key = getKey();
		if (key == 27)
			return mainmenuOpt();
		return CourseClassMenuPage(username, SY, season, courseID, className);
	}
	else {
		string temp;
		ofstream ofs("tmp.txt");
		while (getline(ifs, temp, ',')) {
			if (temp == ID) {
				flag = true;
				getline(ifs, temp);
				continue;
			}
			ofs << temp << ",";
			getline(ifs, temp);
			ofs << temp << endl;
		}
		ofs.close();
		ifs.close();
	}

	if (!flag) {
		printCenterCharacters(L"THIS STUDENT IS NOT EXIST IN THIS CLASS", Color::red, Color::bright_white, 8, My_Windows);
		printCenterCharacters(L"Press any key to enter again or F1 to back to previous menu", Color::red, Color::bright_white, 10, My_Windows);
		int key = getKey();
		if (key == 27)
			return mainmenuOpt();
		if (key == 59)
			return CourseClassMenuPage(username, SY, season, courseID, className);
		return removeAStudentInCourseClass(username, SY, season, courseID, className);
	} 

	remove(listStClass.c_str());
	int res = rename("tmp.txt", listStClass.c_str());

	printCenterCharacters(L"REMOVE SUCCESSFULLY", Color::green, Color::bright_white, 8, My_Windows);
	printCenterCharacters(L"Press any to back to previous menu", Color::green, Color::bright_white, 10, My_Windows);
	int key = getKey();
	if (key == 27)
		return mainmenuOpt();
	return CourseClassMenuPage(username, SY, season, courseID, className);
}

int getCourseCredit(string curSY, string season, string courseID) {
	string courseCre;
	ifstream ifs;
	ofstream ofs;

	string coursePath = "./" + curSY + "/" + season + "/" + courseID + "/class.txt";
	string coureClass;

	ifs.open(coursePath);
	if (ifs.is_open())
		getline(ifs, coureClass);
	ifs.close();

	string courseClassPath = "./" + curSY + "/" + season + "/" + courseID + "/" + coureClass + "/info.txt";
	ifs.open(courseClassPath);
	if (ifs.is_open()) {
		string tmp;
		getline(ifs, tmp); // course ID 
		getline(ifs, tmp); // course Name;
		getline(ifs, tmp); // class Name
		getline(ifs, tmp); // teachername
		getline(ifs, courseCre); // course credit
	}
	ifs.close();

	return stoi(courseCre);
}

string searchStudent(string studentID)
{
	string pathProfile = "./profile/" + studentID + ".txt";
	ifstream ifs(pathProfile);
	string className;
	for (int i = 0; i < 4; i++)
		getline(ifs, className);
	ifs.close();
	return className;
}


void importScoreboardToCourseClass(string username, string SY, short season, string courseID, string classID) {
	system("cls");
	printCharacter(L"Press ESC to back to main menu", { 0, 0 }, Color::black, Color::bright_white);
	printCenterCharacters(L"<<<< CLASS " + wstring(classID.begin(), classID.end()) + L" >>>>", Color::light_green, Color::bright_white, 2, My_Windows);
	printCenterCharacters(wstring(courseID.begin(), courseID.end()), Color::light_aqua, Color::bright_white, 3, My_Windows);

	ifstream ifs;
	string listStud = "./" + SY + "/" + char(season + 48) + "/" + courseID + "/" + classID + "/listStud.txt";
	ifs.open(listStud);
	if (!ifs.is_open() || ifs.eof()) {
		printCenterCharacters(L"THIS CLASS HAS NO StUDENTS", Color::red, Color::bright_white, 6, My_Windows);
		printCenterCharacters(L"PLEASE ADD STUDENTS FIRST", Color::red, Color::bright_white, 8, My_Windows);
		printCenterCharacters(L"Press any key to to back to previous menu", Color::green, Color::bright_white, 10, My_Windows);
		int key = getKey();
		if (key == 27) {
			return mainmenuOpt();
		}
		return CourseClassMenuPage(username, SY, season, courseID, classID);

	}
	ifs.close();

	printCharacter(L"Input the path here: ", { 45, 7 }, Color::aqua, Color::bright_white);
	gotoxy(45 + 22, 7);
	string path = getStringInput();
	if (path == "ESC") {
		return mainmenuOpt();
	}


	ifstream fin(path);
	if (!fin.is_open()) {
		printCenterCharacters(L"THIS PATH DOESN'T EXIST", Color::red, Color::bright_white, 10, My_Windows);
		printCenterCharacters(L"PLEASE ENTER AGAIN", Color::red, Color::bright_white, 12, My_Windows);
		printCenterCharacters(L"Press any key to enter again or Press F1 to back to previous menu", Color::green, Color::bright_white, 14, My_Windows);
		int key = getKey();
		if (key == 27) {
			return mainmenuOpt();
		}
		if (key == 59) {
			return CourseClassMenuPage(username, SY, season, courseID, classID);
		}
		return importScoreboardToCourseClass(username, SY, season, courseID, classID);
	}

	string sy;
	ifs.open("./SY.txt");
	getline(ifs, sy);
	ifs.close();

	string classPath = "./" + sy + "/" + char(season + 48) + "/" + courseID + "/class.txt";
	string courseTotal;
	int courseCre = getCourseCredit(SY, to_string(season), courseID); // get course credits
	ofstream ofs;
	string temp, stID, Class;
	while (!fin.eof()) {
		getline(fin, temp, ','); // no
		getline(fin, stID, ','); // studentid
		Class = searchStudent(stID);
		string stScore = "./" + sy + "/" + Class + "/" + stID + "/" + courseID + ".txt";

		ofstream fout(stScore);
		for (int i = 0; i < 2; i++) {
			getline(fin, temp, ','); // get first name and last name
		}

		getline(fin, courseTotal, ',');			// get course total
		fout << courseTotal << ",";
		getline(fin, temp);
		fout << temp;
		fout.close();

		string total = "./" + sy + "/" + Class + "/" + stID + "/total.txt";
		string sesy = "./" + sy + "/" + Class + "/" + stID + "/" + to_string(season) + "_" + SY + ".txt";

		// CHECK IF This se-sy is exist or not
		bool flag = false;
		ifs.open(sesy);
		if (ifs.is_open()) {
			int seCre;
			float seGPA;
			ifs >> seGPA;
			ifs >> seCre;
			seGPA *= seCre * 1.0;
			seCre += courseCre;
			seGPA = (seGPA + courseCre * stof(courseTotal)) / seCre * 1.0;
			ofs.open("./" + sy + "/" + Class + "/" + stID + "/tmp.txt");
			if (ofs.is_open()) {
				ofs << seGPA << endl;
				ofs << seCre;
				string temp;
				while (getline(ifs, temp))
					if (temp != "\n" && temp != "" && temp != " ")
						ofs << endl << temp;
				ofs << endl << courseID << "," << classID;
			}
			ofs.close();
			ifs.close();

			remove(sesy.c_str());
			rename(("./" + sy + "/" + Class + "/" + stID + "/tmp.txt").c_str(), sesy.c_str());
		}
		else {
			ofs.open(sesy);
			ofs << courseTotal << endl << courseCre << endl << courseID << "," << classID;
			ofs.close();
			flag = true;
		}
		ifs.close();

		ifs.open(total); // open total.txt
		if (!ifs.is_open()) { // if there is no file total.txt before 
			ofs.open(total);
			ofs << courseTotal << endl;
			ofs << courseCre;
			if (flag == true)
				ofs << endl << to_string(season) + "_" + SY;
			ofs.close();
		}
		else { // if this is exist before, updating this file
			int totalCredits;
			float GPA;
			ifs >> GPA;
			ifs >> totalCredits;
			GPA *= totalCredits;
			totalCredits += courseCre;
			GPA = (GPA + courseCre * stof(courseTotal)) / totalCredits;
			ofs.open("tmp.txt");
			if (ofs.is_open()) {
				ofs << GPA << endl;
				ofs << totalCredits;
				string temp;
				while (getline(ifs, temp))
					if (temp != "\n" && temp != "" && temp != " ")
						ofs << endl << temp;
				if (flag == true)
					ofs << endl << to_string(season) + "_" + SY;
			}
			ofs.close();
			ifs.close();

			remove(total.c_str());
			rename("tmp.txt", total.c_str());
		}
		ifs.close();
	}
	fin.close();

	string scoreboardPath = "./" + SY + "/" + to_string(season) + "/" + courseID + "/" + classID + "/" + "scoreboard.txt";

	ofs.open(scoreboardPath);
	fin.open(path);
	while (getline(fin, temp)) {
		if (!fin.eof())
			ofs << temp << endl;
	}
	fin.close();
	ofs.close();

	printCenterCharacters(L"IMPORT SCOREBOARD SUCCESSFULLY", Color::green, Color::bright_white, 10, My_Windows);
	printCenterCharacters(L"PRESS ANY KEY TO BACK TO PREVIOUS MENU", Color::green, Color::bright_white, 12, My_Windows);
	int key = getKey();
	if (key == 27)
		return mainmenuOpt();
	return CourseClassMenuPage(username , SY, season, courseID, classID);
}