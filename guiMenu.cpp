#pragma once
#include "guiMenu.h"
#include "createSY.h"
#include "guiView.h"
#include "guiAddnRemove.h"

void mainmenuOpt() {
    system("cls");
    drawMenu();

    short line = 1;
    printCenterCharacters(L"LOG IN", Color::blue, Color::bright_white, 11, My_Windows);
    printCenterCharacters(L"REGISTER", Color::blue, Color::bright_white, 13, My_Windows);
    printCenterCharacters(L"EXIT", Color::blue, Color::bright_white, 15, My_Windows);

    while (1) {
        if (line == 1) {
            printCenterCharacters(L">> LOG IN << ", Color::red, Color::bright_white, 11, My_Windows);
            printCenterCharacters(L"   REGISTER   ", Color::blue, Color::bright_white, 13, My_Windows);
            printCenterCharacters(L"   EXIT   ", Color::blue, Color::bright_white, 15, My_Windows);
        }
        if (line == 2) {
            printCenterCharacters(L"   LOG IN   ", Color::blue , Color::bright_white, 11, My_Windows);
            printCenterCharacters(L">> REGISTER <<", Color::red, Color::bright_white, 13, My_Windows);
            printCenterCharacters(L"   EXIT   ", Color::blue, Color::bright_white, 15, My_Windows);
        }
        if (line == 3) {
            printCenterCharacters(L"   LOG IN   ", Color::blue, Color::bright_white, 11, My_Windows);
            printCenterCharacters(L"   REGISTER   ", Color::blue, Color::bright_white, 13, My_Windows);
            printCenterCharacters(L">> EXIT <<", Color::red, Color::bright_white, 15, My_Windows);
        }

        int check = getKey();
        switch (check) {
        case 72:
            if (line == 1) {
                line = 3;
            }
            else line -= 1;
            break;
        case 80:
            if (line == 3) {
                line = 1;
            }
            else line += 1;
            break;
        case 13:
            if (line == 1) return LoginPage();
            if (line == 2) return RegisterPage();
            if (line == 3) return;
            break;
        }
    }
}


void LoginPage() {
    system("cls");
    wstring temp[3];
    temp[0] = L"▒█░░░ ▒█▀▀▀█ ▒█▀▀█    ▀█▀ ▒█▄░▒█";
    temp[1] = L"▒█░░░ ▒█░░▒█ ▒█░▄▄    ▒█░ ▒█▒█▒█";
    temp[2] = L"▒█▄▄█ ▒█▄▄▄█ ▒█▄▄█    ▄█▄ ▒█░░▀█";
    for (int i = 0; i < 3; i++) {
        printCenterCharacters(temp[i], Color::black, Color::bright_white, i + 2, My_Windows);
        Sleep(80);
    }

    Sleep(150);
    printCharacter(L"Username", { 45, 9 }, Color::blue, Color::bright_white);
    drawBox(10);
    printCharacter(L"Password", { 45, 15 }, Color::blue, Color::bright_white);
    drawBox(16);
    printCenterCharacters(L"Press ESC to back to previous menu", Color::red, Color::bright_white, 20, My_Windows);

    gotoxy(46, 11);
    string username;
    username = getStringInput();
    gotoxy(46, 17);
    string password;
    password = getStringInput();

    bool isStudent = true;
    if (username.length() == 8) {
        for (char c : username) {
            if (!isdigit(c)) {
                isStudent = false;
                break;
            }
        }
    }
    else {
        isStudent = false;
    }


    string tmp;
    if (isStudent) tmp = "./profile/";
    else tmp = "User/";
    tmp += username + ".txt";

    string passTmp, usernameTmp;

    ifstream ifs;
    ifs.open(tmp);
    if (!ifs.is_open()) {
        printCenterCharacters(L"THIS ACCOUNT DOESN'T EXIST", Color::red, Color::bright_white, 22, My_Windows);
        printCenterCharacters(L"Press anykey to continue...", Color::purple, Color::bright_white, 0, My_Windows);
        getKey();
        return mainmenuOpt();
    }

    getline(ifs, usernameTmp);
    getline(ifs, passTmp);

    if (password != passTmp) {
        printCenterCharacters(L"You entered a wrong password", Color::red, Color::bright_white, 22, My_Windows);
        printCenterCharacters(L"Press anykey to continue...", Color::purple, Color::bright_white, 0, My_Windows);
        getKey();
        ifs.close();
        return LoginPage();
    }

    ifs.close();

    printCenterCharacters(L"LOG IN SUCCESSFULLY", Color::green, Color::bright_white, 22, My_Windows);
    printCenterCharacters(L"Press anykey to continue...", Color::purple, Color::bright_white, 0, My_Windows);
    getKey();
    if (isStudent) return studentMenuPage(username);
	else return ProfileMenuPage(username);

    return;
}


void RegisterPage() {
    system("cls");
    wstring temp[3];
    temp[0] = L"▒█▀▀█ ▒█▀▀▀ ▒█▀▀█ ▀█▀ ▒█▀▀▀█ ▀▀█▀▀ ▒█▀▀▀ ▒█▀▀█";
    temp[1] = L"▒█▄▄▀ ▒█▀▀▀ ▒█░▄▄ ▒█░ ░▀▀▀▄▄ ░▒█░░ ▒█▀▀▀ ▒█▄▄▀";
    temp[2] = L"▒█░▒█ ▒█▄▄▄ ▒█▄▄█ ▄█▄ ▒█▄▄▄█ ░▒█░░ ▒█▄▄▄ ▒█░▒█";

    for (int i = 0; i < 3; i++) {
        printCenterCharacters(temp[i], Color::black, Color::bright_white, i + 2, My_Windows);
        Sleep(80);
    }

    Sleep(150);
    printCharacter(L"Username", { 45, 9 }, Color::blue, Color::bright_white);
    drawBox(10);
    printCharacter(L"Password", { 45, 15 }, Color::blue, Color::bright_white);
    drawBox(16);
    printCharacter(L"Teacher Key", { 45, 21 }, Color::blue, Color::bright_white);
    drawBox(22);
    printCenterCharacters(L"Press ESC to back to previous menu", Color::red, Color::bright_white, 0, My_Windows);

    gotoxy(46, 11);
    string username;
    username = getStringInput();
    gotoxy(46, 17);
    string password;
    password = getStringInput();
    gotoxy(46, 23);
    string teacherKey;
    teacherKey = getStringInput();

    ifstream fin;
    ofstream fout;
    fin.open("User\\" + username + ".txt");
    if (fin.is_open()) {
        fin.close();
        printCenterCharacters(L"This account existed", Color::red, Color::bright_white, 26, My_Windows);
        printCenterCharacters(L"Press anykey to continue...", Color::purple, Color::bright_white, 0, My_Windows);
        getKey();
        return RegisterPage();
    }
    else {
        if (teacherKey != "CS101") {
            printCenterCharacters(L"You've entered an invalid teacher key", Color::red, Color::bright_white, 26, My_Windows);
            printCenterCharacters(L"Press anykey to continue...", Color::purple, Color::bright_white, 0, My_Windows);
            getKey();
            return RegisterPage();
        }
        else {
            _mkdir("./User");
            fout.open("./User\\" + username + ".txt");
            if (!fout.is_open()) {
                printCenterCharacters(L"Cann't Create File", Color::green, Color::bright_white, 26, My_Windows);
                printCenterCharacters(L"Press anykey to continue...", Color::purple, Color::bright_white, 0, My_Windows);
                getKey();
                return mainmenuOpt();
            }
            fout << username << endl;
            fout << password << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;
            fout.close();
            printCenterCharacters(L"Register Successfully", Color::green, Color::bright_white, 26, My_Windows);
            printCenterCharacters(L"Press anykey to continue...", Color::green, Color::bright_white, 28, My_Windows);
            getKey();
            return mainmenuOpt();
        }
    }
}

void ProfileMenuPage(string username) {
    system("cls");
    wstring temp[3];
    temp[0] = L"░█▀▀█ ░█▀▀█ ░█▀▀▀█ ░█▀▀▀ ▀█▀ ░█─── ░█▀▀▀    ░█▀▄▀█ ░█▀▀▀ ░█▄─░█ ░█─░█";
    temp[1] = L"░█▄▄█ ░█▄▄▀ ░█──░█ ░█▀▀▀ ░█─ ░█─── ░█▀▀▀    ░█░█░█ ░█▀▀▀ ░█░█░█ ░█─░█";
    temp[2] = L"░█─── ░█─░█ ░█▄▄▄█ ░█─── ▄█▄ ░█▄▄█ ░█▄▄▄    ░█──░█ ░█▄▄▄ ░█──▀█ ─▀▄▄▀";

    for (int i = 0; i < 3; i++) {
        printCenterCharacters(temp[i], Color::black, Color::bright_white, i + 2, My_Windows);
        Sleep(80);
    }

    Sleep(150);

    short line = 1;
    int ch = 1;
    printCenterCharacters(L"   VIEW PROFILE   ", Color::blue, Color::bright_white, 10, My_Windows);
    printCenterCharacters(L"   CHANGE PROFILE   ", Color::blue, Color::bright_white, 12, My_Windows);
    printCenterCharacters(L"   CREATE NEW SCHOOL YEAR   ", Color::blue, Color::bright_white, 14, My_Windows);
    printCenterCharacters(L"   VIEW AVAILABLE SCHOOL YEAR   ", Color::blue, Color::bright_white, 16, My_Windows);
    printCenterCharacters(L"   CHOOSE SCHOOLYEAR   ", Color::blue, Color::bright_white, 18, My_Windows);

    while (1) {
        if (line == 1) {
            printCenterCharacters(L">> VIEW PROFILE <<", Color::red, Color::bright_white, 10, My_Windows);
            printCenterCharacters(L"   CHANGE PROFILE   ", Color::blue, Color::bright_white, 12, My_Windows);
            printCenterCharacters(L"   CREATE NEW SCHOOL YEAR   ", Color::blue, Color::bright_white, 14, My_Windows);
            printCenterCharacters(L"   VIEW AVAILABLE SCHOOL YEAR   ", Color::blue, Color::bright_white, 16, My_Windows);
            printCenterCharacters(L"   CHOOSE SCHOOLYEAR   ", Color::blue, Color::bright_white, 18, My_Windows);
            printCenterCharacters(L"   BACK TO PREVIOUS MENU   ", Color::blue, Color::bright_white, 20, My_Windows);
        }
        if (line == 2) {
            printCenterCharacters(L"   VIEW PROFILE   ", Color::blue, Color::bright_white, 10, My_Windows);
            printCenterCharacters(L">> CHANGE PROFILE <<", Color::red, Color::bright_white, 12, My_Windows);
            printCenterCharacters(L"   CREATE NEW SCHOOL YEAR   ", Color::blue, Color::bright_white, 14, My_Windows);
            printCenterCharacters(L"   VIEW AVAILABLE SCHOOL YEAR   ", Color::blue, Color::bright_white, 16, My_Windows);
            printCenterCharacters(L"   CHOOSE SCHOOLYEAR   ", Color::blue, Color::bright_white, 18, My_Windows);
            printCenterCharacters(L"   BACK TO PREVIOUS MENU  ", Color::blue, Color::bright_white, 20, My_Windows);
        }
        if (line == 3) {
            printCenterCharacters(L"   VIEW PROFILE   ", Color::blue, Color::bright_white, 10, My_Windows);
            printCenterCharacters(L"   CHANGE PROFILE   ", Color::blue, Color::bright_white, 12, My_Windows);
            printCenterCharacters(L">> CREATE NEW SCHOOL YEAR <<", Color::red, Color::bright_white, 14, My_Windows);
            printCenterCharacters(L"   VIEW AVAILABLE SCHOOL YEAR   ", Color::blue, Color::bright_white, 16, My_Windows);
            printCenterCharacters(L"   CHOOSE SCHOOLYEAR   ", Color::blue, Color::bright_white, 18, My_Windows);
            printCenterCharacters(L"   BACK TO PREVIOUS MENU   ", Color::blue, Color::bright_white, 20, My_Windows);
        }
        if (line == 4) {
            printCenterCharacters(L"   VIEW PROFILE   ", Color::blue, Color::bright_white, 10, My_Windows);
            printCenterCharacters(L"   CHANGE PROFILE   ", Color::blue, Color::bright_white, 12, My_Windows);
            printCenterCharacters(L"   CREATE NEW SCHOOL YEAR   ", Color::blue, Color::bright_white, 14, My_Windows);
            printCenterCharacters(L">> VIEW AVAILABLE SCHOOL YEAR <<", Color::red, Color::bright_white, 16, My_Windows);
            printCenterCharacters(L"   CHOOSE SCHOOLYEAR   ", Color::blue, Color::bright_white, 18, My_Windows);
            printCenterCharacters(L"   BACK TO PREVIOUS MENU   ", Color::blue, Color::bright_white, 20, My_Windows);
        }
        if (line == 5) {
            printCenterCharacters(L"   VIEW PROFILE   ", Color::blue, Color::bright_white, 10, My_Windows);
            printCenterCharacters(L"   CHANGE PROFILE   ", Color::blue, Color::bright_white, 12, My_Windows);
            printCenterCharacters(L"   CREATE NEW SCHOOL YEAR   ", Color::blue, Color::bright_white, 14, My_Windows);
            printCenterCharacters(L"   VIEW AVAILABLE SCHOOL YEAR   ", Color::blue, Color::bright_white, 16, My_Windows);
            printCenterCharacters(L">> CHOOSE SCHOOLYEAR <<", Color::red, Color::bright_white, 18, My_Windows);
            printCenterCharacters(L"   BACK TO PREVIOUS MENU   ", Color::blue, Color::bright_white, 20, My_Windows);
        }
        if (line == 6) {
            printCenterCharacters(L"   VIEW PROFILE   ", Color::blue, Color::bright_white, 10, My_Windows);
            printCenterCharacters(L"   CHANGE PROFILE   ", Color::blue, Color::bright_white, 12, My_Windows);
            printCenterCharacters(L"   CREATE NEW SCHOOL YEAR   ", Color::blue, Color::bright_white, 14, My_Windows);
            printCenterCharacters(L"   VIEW AVAILABLE SCHOOL YEAR   ", Color::blue, Color::bright_white, 16, My_Windows);
            printCenterCharacters(L"   CHOOSE SCHOOLYEAR   ", Color::blue, Color::bright_white, 18, My_Windows);
            printCenterCharacters(L">> BACK TO PREVIOUS MENU <<", Color::red, Color::bright_white, 20, My_Windows);
        }

        int check = getKey();
        switch (check) {
        case 72:
            if (line == 1) {
                line = 6;
            }
            else line -= 1;
            break;
        case 80:
            if (line == 6) {
                line = 1;
            }
            else line += 1;
            break;
        case 13:
            if (line == 1) return ProfilePage(username);
            if (line == 2) return changeProfilePage(username);
            if (line == 3) return createSYPage(username);
            if (line == 4) return viewSchoolYear(username);
            if (line == 5) return chooseSchoolYear(username);
            if (line == 6) return mainmenuOpt();
            break;
        }
    }
}

void ProfilePage(string username) {
    system("cls");
    wstring temp[3];
    temp[0] = L"░█▀▀█ ░█▀▀█ ░█▀▀▀█ ░█▀▀▀ ▀█▀ ░█─── ░█▀▀▀    ░█▀▀█ ─█▀▀█ ░█▀▀█ ░█▀▀▀";
    temp[1] = L"░█▄▄█ ░█▄▄▀ ░█──░█ ░█▀▀▀ ░█─ ░█─── ░█▀▀▀    ░█▄▄█ ░█▄▄█ ░█─▄▄ ░█▀▀▀";
    temp[2] = L"░█─── ░█─░█ ░█▄▄▄█ ░█─── ▄█▄ ░█▄▄█ ░█▄▄▄    ░█─── ░█─░█ ░█▄▄█ ░█▄▄▄";
    for (int i = 0; i < 3; i++) {
        printCenterCharacters(temp[i], Color::black, Color::bright_white, i + 2, My_Windows);
        Sleep(80);
    }
    Sleep(150);

    string tmp;
    string filename = "./User\\" + username + ".txt";
    ifstream ifs;

    ifs.open(filename, ios::in);
    if (!ifs.is_open()) {
        cout << "SOME THING WRONG \n\n\n";
        printCenterCharacters(L"Press anykey to continue...", Color::purple, Color::bright_white, 0, My_Windows);
        getKey();
        return ProfileMenuPage(username);
    }
    getline(ifs, tmp);
    printCharacter(L"Uername: " + wstring(tmp.begin(), tmp.end()), { 20, 7 }, Color::black, Color::bright_white);
    getline(ifs, tmp);
    printCharacter(L"Password: " + wstring(tmp.begin(), tmp.end()), { 20, 9 }, Color::black, Color::bright_white);
    getline(ifs, tmp);

    if (!getline(ifs, tmp)) {
        printCharacter(L"Teacher ID: None", {20, 11}, Color::black, Color::bright_white);
        printCharacter(L"First Name: None", {20, 13}, Color::black, Color::bright_white);
        printCharacter(L"Last Name: None", { 20, 15 }, Color::black, Color::bright_white);
        printCharacter(L"Gender: None", { 20, 17 }, Color::black, Color::bright_white);
        printCharacter(L"Date Of Birth: None", { 20, 19 }, Color::black, Color::bright_white);
        printCharacter(L"Social ID: None", { 20, 21 }, Color::black, Color::bright_white);
        ifs.close();
        printCenterCharacters(L"Press anykey to continue...", Color::purple, Color::bright_white, 0, My_Windows);
        getKey();
        ProfileMenuPage(username);
        return;
    }

    printCharacter(L"Teacher ID: " + wstring(tmp.begin(), tmp.end()), { 20, 11 }, Color::black, Color::bright_white);

    getline(ifs, tmp);
    printCharacter(L"First Name: " + wstring(tmp.begin(), tmp.end()), { 20, 13 }, Color::black, Color::bright_white);

    getline(ifs, tmp);
    printCharacter(L"Last Name: " + wstring(tmp.begin(), tmp.end()), { 20, 15 }, Color::black, Color::bright_white);

    getline(ifs, tmp);
    printCharacter(L"Gender: "  + wstring(tmp.begin(), tmp.end()), { 20, 17 }, Color::black, Color::bright_white);

    getline(ifs, tmp);
    printCharacter(L"Date Of Birth: " + wstring(tmp.begin(), tmp.end()), { 20, 19 }, Color::black, Color::bright_white);

    getline(ifs, tmp);
    printCharacter(L"Social ID: " + wstring(tmp.begin(), tmp.end()), { 20, 21 }, Color::black, Color::bright_white);

    ifs.close();

    printCenterCharacters(L"PRESS ANY KEY TO GET BACK TO PREVIOUS MENU", Color::green, Color::bright_white, 24, My_Windows);
    printCenterCharacters(L"Press anykey to continue...", Color::purple, Color::bright_white, 0, My_Windows);
    getKey();
    ProfileMenuPage(username);
}

void changeProfilePage(string username) {
    system("cls");
    wstring temp[2];
    temp[0] = L"█▀▀ █▀▄ █ ▀█▀   █▀█ █▀█ █▀█ █▀▀ █ █░░ █▀▀   █▀█ ▄▀█ █▀▀ █▀▀";
    temp[1] = L"██▄ █▄▀ █ ░█░   █▀▀ █▀▄ █▄█ █▀░ █ █▄▄ ██▄   █▀▀ █▀█ █▄█ ██▄";
    printCharacter(L"Press F1 to back to previous menu", { short(My_Windows.Right - 34), 0 }, Color::black, Color::bright_white);
    for (int i = 0; i < 2; i++) {
		printCenterCharacters(temp[i], Color::black, Color::bright_white, i + 2, My_Windows);
	}

    string username1, password1, firstname1, lastname1, gender1, dateofbirth1, socialid1, teacherID1;
    ifstream fin("User\\" + username + ".txt");
    if (fin.is_open()) {
		getline(fin, username1);
		getline(fin, password1);
        getline(fin, teacherID1);
        getline(fin, teacherID1);
		getline(fin, firstname1);
		getline(fin, lastname1);
		getline(fin, gender1);
		getline(fin, dateofbirth1);
		getline(fin, socialid1);
        fin.close();
	}

    printCharacter(L"Password: " , {45, 7}, Color::blue, Color::bright_white);
    printCharacter(L"" + wstring(password1.begin(), password1.end()), { 45+11, 7 }, Color::gray, Color::bright_white);
    drawBox(8);
    printCharacter(L"Teacher ID: " ,  { 45, 11 }, Color::blue, Color::bright_white);
    printCharacter(L"" + wstring(teacherID1.begin(), teacherID1.end()), { 45+13, 11 }, Color::gray, Color::bright_white);
    drawBox(12);
    printCharacter(L"First Name: " , { 45, 15 }, Color::blue, Color::bright_white);
    printCharacter(L"" + wstring(firstname1.begin(), firstname1.end()), { 45+13, 15 }, Color::gray, Color::bright_white);
    drawBox(16);
    printCharacter(L"Last Name: " , { 45, 19 }, Color::blue, Color::bright_white);
    printCharacter(L"" + wstring(lastname1.begin(), lastname1.end()), { 45+12, 19 }, Color::gray, Color::bright_white);
    drawBox(20);
    printCharacter(L"Gender: " , { 45, 23 }, Color::blue, Color::bright_white);
    printCharacter(L"" + wstring(gender1.begin(), gender1.end()), { 45+9, 23 }, Color::gray, Color::bright_white);
    drawBox(24);
    printCharacter(L"Date Of Birth: " , { 45, 27 }, Color::blue, Color::bright_white);
    printCharacter(L"" + wstring(dateofbirth1.begin(), dateofbirth1.end()), { 45+16, 27 }, Color::gray, Color::bright_white);
    drawBox(28);
    printCharacter(L"Social ID: " , { 45, 31 }, Color::blue, Color::bright_white);
    printCharacter(L"" + wstring(socialid1.begin(), socialid1.end()), { 45 + 12, 31 }, Color::gray, Color::bright_white);
    drawBox(32);
    printCenterCharacters(L"Press ESC to back to main menu", Color::red, Color::bright_white, 36, My_Windows);
    int key = getKey();
    if (key == 27)
        return mainmenuOpt();

    if (key == 59)
        return ProfileMenuPage(username);

    gotoxy(46, 9);
    password1 = getStringInput();
    gotoxy(46, 13);
    teacherID1 = getStringInput();
    gotoxy(46, 17);
    firstname1 = getStringInput();
    gotoxy(46, 21);
    lastname1 = getStringInput();
    gotoxy(46, 25);
    gender1 = getStringInput();
    gotoxy(46, 29);
    dateofbirth1 = getStringInput();
    gotoxy(46, 33);
    socialid1 = getStringInput();

    string filename = "User\\" + username + ".txt";
    ofstream ofs;
    ifstream ifs;
    ifs.open(filename);
    string tmp;
    getline(ifs, tmp); // username
    getline(ifs, tmp); // password
    if (password1 == "") {
		password1 = tmp;
	}
    getline(ifs, tmp);
    getline(ifs, tmp); // teacherID
    if (teacherID1 == "") {
        teacherID1 = tmp;
    }
    getline(ifs, tmp);
    if (firstname1 == "") {
        firstname1 = tmp;
	}
    getline(ifs, tmp);
    if (lastname1 == "") {
		lastname1 = tmp;
    }
    getline(ifs, tmp);
    if (gender1 == "") {
        gender1 = tmp;
    }
    getline(ifs, tmp);
    if (dateofbirth1 == "") {
		dateofbirth1 = tmp;
	}
    getline(ifs, tmp);
    if (socialid1 == "") {
		socialid1 = tmp;
	}
    ifs.close();
    ofs.open(filename);
    ofs << username << endl;
    ofs << password1 << endl << endl;
    ofs << teacherID1 << endl;
    ofs << firstname1 << endl;
    ofs << lastname1 << endl;
    ofs << gender1 << endl;
    ofs << dateofbirth1 << endl;
    ofs << socialid1 << endl;
    ofs.close();   

    gotoxy(0, 0);
    printCenterCharacters(L"Update Successfully", Color::green, Color::bright_white, 35, My_Windows);
    printCenterCharacters(L"Press anykey to continue...", Color::purple, Color::bright_white, 0, My_Windows);
    getKey();

    return ProfilePage(username);
}

void SYMenuPage(string username, string SY) {
    system("cls");
    wstring temp[3];
    temp[0] = L"█▀▀▀█ ░█▀▀█ ░█─░█ ░█▀▀▀█ ░█▀▀▀█ ░█───    ░█──░█ ░█▀▀▀ ─█▀▀█ ░█▀▀█    ░█▀▄▀█ ░█▀▀▀ ░█▄─░█ ░█─░█";
    temp[1] = L"▀▀▀▄▄ ░█─── ░█▀▀█ ░█──░█ ░█──░█ ░█───    ░█▄▄▄█ ░█▀▀▀ ░█▄▄█ ░█▄▄▀    ░█░█░█ ░█▀▀▀ ░█░█░█ ░█─░█";
    temp[2] = L"█▄▄▄█ ░█▄▄█ ░█─░█ ░█▄▄▄█ ░█▄▄▄█ ░█▄▄█    ──░█── ░█▄▄▄ ░█─░█ ░█─░█    ░█──░█ ░█▄▄▄ ░█──▀█ ─▀▄▄▀";
    for (int i = 0; i < 3; i++) {
		printCenterCharacters(temp[i], Color::black, Color::bright_white, i + 2, My_Windows);
        Sleep(100);
	}
    Sleep(150);

    short line = 1;
    printCharacter(L"Press ESC to back to main menu", { 0, 0 }, Color::black, Color::bright_white);
    printCharacter(L"Press F1 to back to previous menu", { short(My_Windows.Right - 34), 0}, Color::black, Color::bright_white);
    printCenterCharacters(L"   CREATE SEMESTER   ", Color::blue, Color::bright_white, 10, My_Windows);
    printCenterCharacters(L"   VIEW AND CHOOSE AVAILABLE SEMESTER   ", Color::blue, Color::bright_white, 12, My_Windows);
    printCenterCharacters(L"   CREATE CLASS   ", Color::blue, Color::bright_white, 14, My_Windows);
    printCenterCharacters(L"   VIEW AND CHOOSE AVAILABLE CLASS   ", Color::blue, Color::bright_white, 16, My_Windows);
    int key = getKey();
    if (key == 27) {
        return mainmenuOpt();
    }
    if (key == 59) {
		return ProfileMenuPage(username);
	}
    while (1) {
        if (line == 1) {
            printCenterCharacters(L">> CREATE SEMESTER <<", Color::light_red, Color::bright_white, 10, My_Windows);
            printCenterCharacters(L"   VIEW AND CHOOSE AVAILABLE SEMESTER   ", Color::blue, Color::bright_white, 12, My_Windows);
            printCenterCharacters(L"   CREATE CLASS   ", Color::blue, Color::bright_white, 14, My_Windows);
            printCenterCharacters(L"   VIEW AND CHOOSE AVAILABLE CLASS   ", Color::blue, Color::bright_white, 16, My_Windows);
        }
        if (line == 2) {
            printCenterCharacters(L"   CREATE SEMESTER   ", Color::blue, Color::bright_white, 10, My_Windows);
            printCenterCharacters(L"   CREATE CLASS   ", Color::blue, Color::bright_white, 14, My_Windows);
            printCenterCharacters(L"   VIEW AND CHOOSE AVAILABLE CLASS   ", Color::blue, Color::bright_white, 16, My_Windows);
            printCenterCharacters(L">> VIEW AND CHOOSE AVAILABLE SEMESTER <<", Color::light_red, Color::bright_white, 12, My_Windows);
		}
        if (line == 3) {
            printCenterCharacters(L"   CREATE SEMESTER   ", Color::blue, Color::bright_white, 10, My_Windows);
            printCenterCharacters(L"   VIEW AND CHOOSE AVAILABLE SEMESTER   ", Color::blue, Color::bright_white, 12, My_Windows);
            printCenterCharacters(L"   VIEW AND CHOOSE AVAILABLE CLASS   ", Color::blue, Color::bright_white, 16, My_Windows);
			printCenterCharacters(L">> CREATE CLASS <<", Color::light_red, Color::bright_white, 14, My_Windows);
        }
        if (line == 4) {
            printCenterCharacters(L"   CREATE SEMESTER   ", Color::blue, Color::bright_white, 10, My_Windows);
            printCenterCharacters(L"   VIEW AND CHOOSE AVAILABLE SEMESTER   ", Color::blue, Color::bright_white, 12, My_Windows);
            printCenterCharacters(L"   CREATE CLASS   ", Color::blue, Color::bright_white, 14, My_Windows);
			printCenterCharacters(L">> VIEW AND CHOOSE AVAILABLE CLASS <<", Color::light_red, Color::bright_white, 16, My_Windows);
		}

        key = getKey();
        if (key == 27) {
            return mainmenuOpt();
        }
        if (key == 59) {
            return ProfileMenuPage(username);
        }
        if (key == 72) {
            if (line == 1) {
				line = 4;
			}
            else {
				line--;
			}
		}
        if (key == 80) {
            if (line == 4) {
                line = 1;
            }
            else {
				line++;
            }
        }
        if (key == 13) {
            if (line == 1) {
				return CreateSemesterPage(username, SY);
			}
            if (line == 2) {
				return viewAndChooseSemesterPage(username, SY);
			}
            if (line == 3) {
				return CreateClassPage(username, SY);
			}
            if (line == 4) {
				return viewAndChooseClassPage(username, SY);
			}
		}
    }
}

void ClassMenuPage(string username, string SY, string classID) {
    system("cls");
    wstring temp[3];
    temp[0] = L"▒█▀▀█ ▒█░░░ ░█▀▀█ ▒█▀▀▀█ ▒█▀▀▀█     ▒█▀▄▀█ ▒█▀▀▀ ▒█▄░▒█ ▒█░▒█";
    temp[1] = L"▒█░░░ ▒█░░░ ▒█▄▄█ ░▀▀▀▄▄ ░▀▀▀▄▄     ▒█▒█▒█ ▒█▀▀▀ ▒█▒█▒█ ▒█░▒█";
    temp[2] = L"▒█▄▄█ ▒█▄▄█ ▒█░▒█ ▒█▄▄▄█ ▒█▄▄▄█     ▒█░░▒█ ▒█▄▄▄ ▒█░░▀█ ░▀▄▄▀";
    for (int i = 0; i < 3; i++) {
		printCenterCharacters(temp[i], Color::black, Color::bright_white, i + 2, My_Windows);
		Sleep(100);
	}
    printCenterCharacters(L"<<<< CLASS " + wstring(classID.begin(), classID.end()) + L" >>>>", Color::light_green, Color::bright_white, 5, My_Windows);
    Sleep(200);

    short line = 1;
    printCharacter(L"Press ESC to back to main menu", { 0, 0 }, Color::black, Color::bright_white);
    printCharacter(L"Press F1 to back to previous menu", { short(My_Windows.Right - 34), 0}, Color::black, Color::bright_white);
    printCenterCharacters(L"   IMPORT STUDENT LIST   ", Color::blue, Color::bright_white, 10, My_Windows);
    printCenterCharacters(L"   VIEW SCOREBOARD   ", Color::blue, Color::bright_white, 12, My_Windows);
    printCenterCharacters(L"   VIEW STUDENTS LIST   ", Color::blue, Color::bright_white, 14, My_Windows);
    printCenterCharacters(L"   ADD A STUDENT   ", Color::blue, Color::bright_white, 16, My_Windows);
    printCenterCharacters(L"   REMOVE A STUDENT   ", Color::blue, Color::bright_white, 18, My_Windows);

    int key = getKey();

    if (key == 27) {
		return mainmenuOpt();
	}
    if (key == 59) {
        return SYMenuPage(username, SY);
    }

    while (true) {
        if (line == 1) {
            printCenterCharacters(L">> IMPORT STUDENT LIST <<", Color::red, Color::bright_white, 10, My_Windows);
            printCenterCharacters(L"   VIEW SCOREBOARD   ", Color::blue, Color::bright_white, 12, My_Windows);
            printCenterCharacters(L"   VIEW STUDENTS LIST   ", Color::blue, Color::bright_white, 14, My_Windows);
            printCenterCharacters(L"   ADD A STUDENT   ", Color::blue, Color::bright_white, 16, My_Windows);
            printCenterCharacters(L"   REMOVE A STUDENT   ", Color::blue, Color::bright_white, 18, My_Windows);
        }
        if (line == 2) {
            printCenterCharacters(L"   IMPORT STUDENT LIST   ", Color::blue, Color::bright_white, 10, My_Windows);
            printCenterCharacters(L">> VIEW SCOREBOARD <<", Color::red, Color::bright_white, 12, My_Windows);
            printCenterCharacters(L"   VIEW STUDENTS LIST   ", Color::blue, Color::bright_white, 14, My_Windows);
            printCenterCharacters(L"   ADD A STUDENT   ", Color::blue, Color::bright_white, 16, My_Windows);
            printCenterCharacters(L"   REMOVE A STUDENT   ", Color::blue, Color::bright_white, 18, My_Windows);
        }
        if (line == 3) {
            printCenterCharacters(L"   IMPORT STUDENT LIST   ", Color::blue, Color::bright_white, 10, My_Windows);
            printCenterCharacters(L"   VIEW SCOREBOARD   ", Color::blue, Color::bright_white, 12, My_Windows);
            printCenterCharacters(L">> VIEW STUDENTS LIST <<", Color::red, Color::bright_white, 14, My_Windows);
            printCenterCharacters(L"   ADD A STUDENT   ", Color::blue, Color::bright_white, 16, My_Windows);
            printCenterCharacters(L"   REMOVE A STUDENT   ", Color::blue, Color::bright_white, 18, My_Windows);
        }
        if (line == 4) {
            printCenterCharacters(L"   IMPORT STUDENT LIST   ", Color::blue, Color::bright_white, 10, My_Windows);
            printCenterCharacters(L"   VIEW SCOREBOARD   ", Color::blue, Color::bright_white, 12, My_Windows);
            printCenterCharacters(L"   VIEW STUDENTS LIST   ", Color::blue, Color::bright_white, 14, My_Windows);
            printCenterCharacters(L">> ADD A STUDENT <<", Color::red, Color::bright_white, 16, My_Windows);
            printCenterCharacters(L"   REMOVE A STUDENT   ", Color::blue, Color::bright_white, 18, My_Windows);
        }
        if (line == 5) {
            printCenterCharacters(L"   IMPORT STUDENT LIST   ", Color::blue, Color::bright_white, 10, My_Windows);
            printCenterCharacters(L"   VIEW SCOREBOARD   ", Color::blue, Color::bright_white, 12, My_Windows);
            printCenterCharacters(L"   VIEW STUDENTS LIST   ", Color::blue, Color::bright_white, 14, My_Windows);
            printCenterCharacters(L"   ADD A STUDENT   ", Color::blue, Color::bright_white, 16, My_Windows);
            printCenterCharacters(L">> REMOVE A STUDENT <<", Color::red, Color::bright_white, 18, My_Windows);
        }

        key = getKey();
        if (key == 27) {
			return mainmenuOpt();
		}
        if (key == 59) {
			return SYMenuPage(username, SY);
		}
        if (key == 72) {
            if (line == 1) {
				line = 5;
			}
            else {
				line--;
			}
        }
        if (key == 80) {
            if (line == 5) {
                line = 1;
            }
            else {
                line++;
            }
        }
        if (key == 13) {
            if (line == 1) {
                return importStudentsListInClass(username, SY, classID);
            }
            if (line == 2) {
				return viewScoreboard(username, SY, classID);
			}
            if (line == 3) {
                return viewListOfStudentsInClass(username, SY, classID);
            }
            if (line == 4) {
                return addAStudentToClass(username, SY, classID);
            }
            if (line == 5) {
				return removeAStudentInClass(username, SY, classID);
			}
        }
    }
}

void SemesterMenuPage(string username, string SY, short season) {
    system("cls");
    wstring temp[3];
    temp[0] = L"░█▀▀▀█ ░█▀▀▀ ░█▀▄▀█ ░█▀▀▀ ░█▀▀▀█ ▀▀█▀▀ ░█▀▀▀ ░█▀▀█    ░█▀▄▀█ ░█▀▀▀ ░█▄─░█ ░█─░█";
    temp[1] = L"─▀▀▀▄▄ ░█▀▀▀ ░█░█░█ ░█▀▀▀ ─▀▀▀▄▄ ─░█── ░█▀▀▀ ░█▄▄▀    ░█░█░█ ░█▀▀▀ ░█░█░█ ░█─░█";
    temp[2] = L"░█▄▄▄█ ░█▄▄▄ ░█──░█ ░█▄▄▄ ░█▄▄▄█ ─░█── ░█▄▄▄ ░█─░█    ░█──░█ ░█▄▄▄ ░█──▀█ ─▀▄▄▀";
    for (int i = 0; i < 3; i++) {
        printCenterCharacters(temp[i], Color::light_aqua, Color::bright_white, i + 2, My_Windows);
        Sleep(100);
    }
    if (season == 1)
        printCenterCharacters(L"<<<<SPRING>>>>", Color::light_green , Color::bright_white, 5, My_Windows);
    if (season == 2)
        printCenterCharacters(L"<<<<SUMMER>>>>", Color::light_green, Color::bright_white, 5, My_Windows);
    if (season == 3)
        printCenterCharacters(L"<<<<AUTUMN>>>>", Color::light_green, Color::bright_white, 5, My_Windows);
    Sleep(200);

    printCharacter(L"Press ESC to back to main menu", { 0, 0 }, Color::black, Color::bright_white);
    cout << season << endl;
    printCharacter(L"Press F1 to back to previous menu", { short(My_Windows.Right - 34), 0}, Color::black, Color::bright_white);

    printCenterCharacters(L"   ADD A COURSE   ", Color::blue, Color::bright_white, 10, My_Windows);
    printCenterCharacters(L"   VIEW AND CHOOSE A COURSE   ", Color::blue, Color::bright_white, 12, My_Windows);
    printCenterCharacters(L"   REMOVE A COURSE   ", Color::blue, Color::bright_white, 14, My_Windows);
    printCenterCharacters(L"   UPDATE A COURSE   ", Color::blue, Color::bright_white, 16, My_Windows);

    int key = getKey();
    if (key == 27)
        return mainmenuOpt();
    if (key == 59)
        return SYMenuPage(username, SY);
    
    short line = 1;

    while (true) {
        if (line == 1) {
            printCenterCharacters(L">> ADD A COURSE <<", Color::light_red, Color::bright_white, 10, My_Windows);
            printCenterCharacters(L"   VIEW AND CHOOSE A COURSE   ", Color::blue, Color::bright_white, 12, My_Windows);
            printCenterCharacters(L"   REMOVE A COURSE   ", Color::blue, Color::bright_white, 14, My_Windows);
            printCenterCharacters(L"   UPDATE A COURSE   ", Color::blue, Color::bright_white, 16, My_Windows);
        }
        if (line == 2) {
            printCenterCharacters(L"   ADD A COURSE   ", Color::blue, Color::bright_white, 10, My_Windows);
            printCenterCharacters(L">> VIEW AND CHOOSE A COURSE <<", Color::light_red, Color::bright_white, 12, My_Windows);
            printCenterCharacters(L"   REMOVE A COURSE   ", Color::blue, Color::bright_white, 14, My_Windows);
            printCenterCharacters(L"   UPDATE A COURSE   ", Color::blue, Color::bright_white, 16, My_Windows);
        }
        if (line == 3) {
            printCenterCharacters(L"   ADD A COURSE   ", Color::blue, Color::bright_white, 10, My_Windows);
            printCenterCharacters(L"   VIEW AND CHOOSE A COURSE   ", Color::blue, Color::bright_white, 12, My_Windows);
            printCenterCharacters(L">> REMOVE A COURSE <<", Color::light_red, Color::bright_white, 14, My_Windows);
            printCenterCharacters(L"   UPDATE A COURSE   ", Color::blue, Color::bright_white, 16, My_Windows);
        }
        if (line == 4) {
            printCenterCharacters(L"   ADD A COURSE   ", Color::blue, Color::bright_white, 10, My_Windows);
            printCenterCharacters(L"   VIEW AND CHOOSE A COURSE   ", Color::blue, Color::bright_white, 12, My_Windows);
            printCenterCharacters(L"   REMOVE A COURSE   ", Color::blue, Color::bright_white, 14, My_Windows);
            printCenterCharacters(L">> UPDATE A COURSE <<", Color::light_red, Color::bright_white, 16, My_Windows);
        }
    
        key = getKey();

        if (key == 72) {
            if (line == 1)
                line = 4;
            else
                line--;
        } 
        if (key == 80)
            if (line == 4)
                line = 1;
            else line++;
        if (key == 27)
            return mainmenuOpt();
        if (key == 59)
            return SYMenuPage(username, SY);
        if (key == 13) {
            if (line == 1)
                return CreateACourse(username, SY, season);
            if (line == 2)
                return viewAndChooseCourse(username, SY, season);
            if (line == 3)
                return removeACourse(username, SY, season);
            if (line == 4)
                return UpdateCourseInfor(username, SY, season);

        }
    }
}

void CourseMenuPage(string username, string SY, short season, string courseID) {
    system("cls");
    wstring temp[3];
    temp[0] = L"▒█▀▀█ ▒█▀▀▀█ ▒█░▒█ ▒█▀▀█ ▒█▀▀▀█ ▒█▀▀▀    ▒█▀▄▀█ ░█▀▀█ ▒█▄░▒█ ░█▀▀█ ▒█▀▀█ ▒█▀▀▀ ▒█▀▄▀█ ▒█▀▀▀ ▒█▄░▒█ ▀▀█▀▀";
    temp[1] = L"▒█░░░ ▒█░░▒█ ▒█░▒█ ▒█▄▄▀ ░▀▀▀▄▄ ▒█▀▀▀    ▒█▒█▒█ ▒█▄▄█ ▒█▒█▒█ ▒█▄▄█ ▒█░▄▄ ▒█▀▀▀ ▒█▒█▒█ ▒█▀▀▀ ▒█▒█▒█ ░▒█░░";
    temp[2] = L"▒█▄▄█ ▒█▄▄▄█ ░▀▄▄▀ ▒█░▒█ ▒█▄▄▄█ ▒█▄▄▄    ▒█░░▒█ ▒█░▒█ ▒█░░▀█ ▒█░▒█ ▒█▄▄█ ▒█▄▄▄ ▒█░░▒█ ▒█▄▄▄ ▒█░░▀█ ░▒█░░";
    for (int i = 0; i < 3; i++) {
		printCenterCharacters(temp[i], Color::light_red, Color::bright_white, 2 + i, My_Windows);
        Sleep(100);
    }
    printCenterCharacters(L"<<<" + wstring(courseID.begin(), courseID.end()) + L">>>", Color::light_blue, Color::bright_white, 5, My_Windows);
    Sleep(200);
    printCharacter(L"Press ESC to back to main menu", {0, 0}, Color::black, Color::bright_white);
    printCharacter(L"Press F1 to back to previous menu", { short(My_Windows.Right - 34), 0}, Color::black, Color::bright_white);
    printCenterCharacters(L"   VIEW COURSE INFORMATION   ", Color::blue, Color::bright_white, 8, My_Windows);
    printCenterCharacters(L"   VIEW LIST OF STUDENTS   ", Color::blue, Color::bright_white, 10, My_Windows);
    printCenterCharacters(L"   ADD A COURSE CLASS   ", Color::blue, Color::bright_white, 12, My_Windows);
    printCenterCharacters(L"   CHOOSE A COURSE CLASS   ", Color::blue, Color::bright_white, 14, My_Windows);
    printCenterCharacters(L"   VIEW SCOREBOARD OF THIS COURSE   ", Color::blue, Color::bright_white, 16, My_Windows);
    printCenterCharacters(L"   EXPORT THIS COURSE'S SCOREBOARD   ", Color::blue, Color::bright_white, 18, My_Windows);
    printCenterCharacters(L"   UPDATE A STUDENT RESULT   ", Color::blue, Color::bright_white, 20, My_Windows);

    int key = getKey();
    if (key == 27)
        return mainmenuOpt();
    if (key == 59)
        return SemesterMenuPage(username, SY, season);

    short line = 1;

    while (true) {
        if (line == 1) {
            printCenterCharacters(L"<< VIEW COURSE INFORMATION >>", Color::light_red, Color::bright_white, 8, My_Windows);
            printCenterCharacters(L"   VIEW LIST OF STUDENTS   ", Color::blue, Color::bright_white, 10, My_Windows);
            printCenterCharacters(L"   ADD A COURSE CLASS   ", Color::blue, Color::bright_white, 12, My_Windows);
            printCenterCharacters(L"   CHOOSE A COURSE CLASS   ", Color::blue, Color::bright_white, 14, My_Windows);
            printCenterCharacters(L"   VIEW SCOREBOARD OF THIS COURSE   ", Color::blue, Color::bright_white, 16, My_Windows);
            printCenterCharacters(L"   EXPORT THIS COURSE'S SCOREBOARD   ", Color::blue, Color::bright_white, 18, My_Windows);
            printCenterCharacters(L"   UPDATE A STUDENT RESULT   ", Color::blue, Color::bright_white, 20, My_Windows);
        }
        if (line == 2) {
            printCenterCharacters(L"   VIEW COURSE INFORMATION   ", Color::blue, Color::bright_white, 8, My_Windows);
            printCenterCharacters(L"<< VIEW LIST OF STUDENTS >>", Color::light_red, Color::bright_white, 10, My_Windows);
            printCenterCharacters(L"   ADD A COURSE CLASS   ", Color::blue, Color::bright_white, 12, My_Windows);
            printCenterCharacters(L"   CHOOSE A COURSE CLASS   ", Color::blue, Color::bright_white, 14, My_Windows);
            printCenterCharacters(L"   VIEW SCOREBOARD OF THIS COURSE   ", Color::blue, Color::bright_white, 16, My_Windows);
            printCenterCharacters(L"   EXPORT THIS COURSE'S SCOREBOARD   ", Color::blue, Color::bright_white, 18, My_Windows);
            printCenterCharacters(L"   UPDATE A STUDENT RESULT   ", Color::blue, Color::bright_white, 20, My_Windows);
        }
        if (line == 3) {
            printCenterCharacters(L"   VIEW COURSE INFORMATION   ", Color::blue, Color::bright_white, 8, My_Windows);
            printCenterCharacters(L"   VIEW LIST OF STUDENTS   ", Color::blue, Color::bright_white, 10, My_Windows);
            printCenterCharacters(L"<< ADD A COURSE CLASS >>", Color::light_red, Color::bright_white, 12, My_Windows);
            printCenterCharacters(L"   CHOOSE A COURSE CLASS   ", Color::blue, Color::bright_white, 14, My_Windows);
            printCenterCharacters(L"   VIEW SCOREBOARD OF THIS COURSE   ", Color::blue, Color::bright_white, 16, My_Windows);
            printCenterCharacters(L"   EXPORT THIS COURSE'S SCOREBOARD   ", Color::blue, Color::bright_white, 18, My_Windows);
            printCenterCharacters(L"   UPDATE A STUDENT RESULT   ", Color::blue, Color::bright_white, 20, My_Windows);
        }
        if (line == 4) {
            printCenterCharacters(L"   VIEW COURSE INFORMATION   ", Color::blue, Color::bright_white, 8, My_Windows);
            printCenterCharacters(L"   VIEW LIST OF STUDENTS   ", Color::blue, Color::bright_white, 10, My_Windows);
            printCenterCharacters(L"   ADD A COURSE CLASS   ", Color::blue, Color::bright_white, 12, My_Windows);
            printCenterCharacters(L"<< CHOOSE A COURSE CLASS >>", Color::light_red, Color::bright_white, 14, My_Windows);
            printCenterCharacters(L"   VIEW SCOREBOARD OF THIS COURSE   ", Color::blue, Color::bright_white, 16, My_Windows);
            printCenterCharacters(L"   EXPORT THIS COURSE'S SCOREBOARD   ", Color::blue, Color::bright_white, 18, My_Windows);
            printCenterCharacters(L"   UPDATE A STUDENT RESULT   ", Color::blue, Color::bright_white, 20, My_Windows);
        }
        if (line == 5) {
            printCenterCharacters(L"   VIEW COURSE INFORMATION   ", Color::blue, Color::bright_white, 8, My_Windows);
            printCenterCharacters(L"   VIEW LIST OF STUDENTS   ", Color::blue, Color::bright_white, 10, My_Windows);
            printCenterCharacters(L"   ADD A COURSE CLASS   ", Color::blue, Color::bright_white, 12, My_Windows);
            printCenterCharacters(L"   CHOOSE A COURSE CLASS   ", Color::blue, Color::bright_white, 14, My_Windows);
            printCenterCharacters(L"<< VIEW SCOREBOARD OF THIS COURSE >>", Color::light_red, Color::bright_white, 16, My_Windows);
            printCenterCharacters(L"   EXPORT THIS COURSE'S SCOREBOARD   ", Color::blue, Color::bright_white, 18, My_Windows);
            printCenterCharacters(L"   UPDATE A STUDENT RESULT   ", Color::blue, Color::bright_white, 20, My_Windows);
        }
        if (line == 6) {
            printCenterCharacters(L"   VIEW COURSE INFORMATION   ", Color::blue, Color::bright_white, 8, My_Windows);
            printCenterCharacters(L"   VIEW LIST OF STUDENTS   ", Color::blue, Color::bright_white, 10, My_Windows);
            printCenterCharacters(L"   ADD A COURSE CLASS   ", Color::blue, Color::bright_white, 12, My_Windows);
            printCenterCharacters(L"   CHOOSE A COURSE CLASS   ", Color::blue, Color::bright_white, 14, My_Windows);
            printCenterCharacters(L"   VIEW SCOREBOARD OF THIS COURSE   ", Color::blue, Color::bright_white, 16, My_Windows);
            printCenterCharacters(L"<< EXPORT THIS COURSE'S SCOREBOARD >>", Color::light_red, Color::bright_white, 18, My_Windows);
            printCenterCharacters(L"   UPDATE A STUDENT RESULT   ", Color::blue, Color::bright_white, 20, My_Windows);
        }
        if (line == 7) {
            printCenterCharacters(L"   VIEW COURSE INFORMATION   ", Color::blue, Color::bright_white, 8, My_Windows);
            printCenterCharacters(L"   VIEW LIST OF STUDENTS   ", Color::blue, Color::bright_white, 10, My_Windows);
            printCenterCharacters(L"   ADD A COURSE CLASS   ", Color::blue, Color::bright_white, 12, My_Windows);
            printCenterCharacters(L"   CHOOSE A COURSE CLASS   ", Color::blue, Color::bright_white, 14, My_Windows);
            printCenterCharacters(L"   VIEW SCOREBOARD OF THIS COURSE   ", Color::blue, Color::bright_white, 16, My_Windows);
            printCenterCharacters(L"   EXPORT THIS COURSE'S SCOREBOARD   ", Color::blue, Color::bright_white, 18, My_Windows);
            printCenterCharacters(L"<< UPDATE A STUDENT RESULT >>", Color::light_red, Color::bright_white, 20, My_Windows);
        }

        key = getKey();

        if (key == 27)
            return mainmenuOpt();
        if (key == 59)
            return SemesterMenuPage(username, SY, season);
        if (key == 72) {
			if (line == 1)
				line = 7;
			else
				line--;
		}
        if (key == 80) {
            if (line == 7)
				line = 1;
			else
				line++;
        }
        if (key == 13) {
            if (line == 1)
                return viewCourseInformation(username, SY, season, courseID);
            if (line == 2)
                return viewListOfStudentInACourse(username, SY, season, courseID);
            if (line == 3)
                return addACourseClass(username, SY, season, courseID);
            if (line == 4)
                return viewAndChooseCourseClass(username, SY, season, courseID);
            if (line == 5)
                return viewScoreboardOfACourse(username, SY, season, courseID);
            if (line == 6)
                return exportListStudentToFile(username, SY, season, courseID);
            if (line == 7)
                return UpdateAStudentResult(username, SY, season, courseID);
        }
    }
}

void CourseClassMenuPage(string username, string SY, short season, string courseID, string classID) {
    system("cls");
    wstring temp[3];
    temp[0] = L"░█▀▀█ ░█▀▀▀█ ░█─░█ ░█▀▀█ ░█▀▀▀█ ░█▀▀▀    ░█▀▀█ ░█─── ─█▀▀█ ░█▀▀▀█ ░█▀▀▀█    ░█▀▄▀█ ░█▀▀▀ ░█▄─░█ ░█─░█";
    temp[1] = L"░█─── ░█──░█ ░█─░█ ░█▄▄▀ ─▀▀▀▄▄ ░█▀▀▀    ░█─── ░█─── ░█▄▄█ ─▀▀▀▄▄ ─▀▀▀▄▄    ░█░█░█ ░█▀▀▀ ░█░█░█ ░█─░█";
    temp[2] = L"░█▄▄█ ░█▄▄▄█ ─▀▄▄▀ ░█─░█ ░█▄▄▄█ ░█▄▄▄    ░█▄▄█ ░█▄▄█ ░█─░█ ░█▄▄▄█ ░█▄▄▄█    ░█──░█ ░█▄▄▄ ░█──▀█ ─▀▄▄▀";
    for(int i = 0; i < 3; i++)
    {
        printCenterCharacters(temp[i], Color::red, Color::bright_white, 2 + i, My_Windows);
        Sleep(100);
    }
    printCenterCharacters(wstring(classID.begin(), classID.end()), Color::light_red, Color::bright_white, 6, My_Windows);
    Sleep(200);
    printCharacter(L"Press ESC to back to main menu", { 0, 0 }, Color::black, Color::bright_white);
    printCharacter(L"Press F1 to back to previous menu", { short(My_Windows.Right - 34), 0 }, Color::black, Color::bright_white);
    printCenterCharacters(L"   IMPORT STUDENTS   ", Color::blue, Color::bright_white, 8, My_Windows);
    printCenterCharacters(L"   ADD A STUDENT   ", Color::blue, Color::bright_white, 10, My_Windows);
    printCenterCharacters(L"   REMOVE A STUDENT   ", Color::blue, Color::bright_white, 12, My_Windows);
    printCenterCharacters(L"   IMPORT SCOREBOARD   ", Color::blue, Color::bright_white, 14, My_Windows);
    printCenterCharacters(L"   VIEW SCOREBOARD   ", Color::blue, Color::bright_white, 16, My_Windows);

    int key = getKey();
    if (key == 27)
        return mainmenuOpt();
    if (key == 59)
        return CourseMenuPage(username, SY, season, courseID);

    short line = 1;

    while (true) {
        if (line == 1) {
            printCenterCharacters(L"<< IMPORT STUDENTS >>", Color::light_red, Color::bright_white, 8, My_Windows);
            printCenterCharacters(L"   ADD A STUDENT   ", Color::blue, Color::bright_white, 10, My_Windows);
            printCenterCharacters(L"   REMOVE A STUDENT   ", Color::blue, Color::bright_white, 12, My_Windows);
            printCenterCharacters(L"   IMPORT SCOREBOARD   ", Color::blue, Color::bright_white, 14, My_Windows);
            printCenterCharacters(L"   VIEW SCOREBOARD   ", Color::blue, Color::bright_white, 16, My_Windows);
        }
        if (line == 2) {
            printCenterCharacters(L"   IMPORT STUDENTS   ", Color::blue, Color::bright_white, 8, My_Windows);
            printCenterCharacters(L"<< ADD A STUDENT >>", Color::light_red, Color::bright_white, 10, My_Windows);
            printCenterCharacters(L"   REMOVE A STUDENT   ", Color::blue, Color::bright_white, 12, My_Windows);
            printCenterCharacters(L"   IMPORT SCOREBOARD   ", Color::blue, Color::bright_white, 14, My_Windows);
            printCenterCharacters(L"   VIEW SCOREBOARD   ", Color::blue, Color::bright_white, 16, My_Windows);
        }
        if (line == 3) {
            printCenterCharacters(L"   IMPORT STUDENTS   ", Color::blue, Color::bright_white, 8, My_Windows);
            printCenterCharacters(L"   ADD A STUDENT   ", Color::blue, Color::bright_white, 10, My_Windows);
            printCenterCharacters(L"<< REMOVE A STUDENT >>", Color::light_red, Color::bright_white, 12, My_Windows);
            printCenterCharacters(L"   IMPORT SCOREBOARD   ", Color::blue, Color::bright_white, 14, My_Windows);
            printCenterCharacters(L"   VIEW SCOREBOARD   ", Color::blue, Color::bright_white, 16, My_Windows);
        }
        if (line == 4) {
            printCenterCharacters(L"   IMPORT STUDENTS   ", Color::blue, Color::bright_white, 8, My_Windows);
            printCenterCharacters(L"   ADD A STUDENT   ", Color::blue, Color::bright_white, 10, My_Windows);
            printCenterCharacters(L"   REMOVE A STUDENT   ", Color::blue, Color::bright_white, 12, My_Windows);
            printCenterCharacters(L"<< IMPORT SCOREBOARD >>", Color::light_red, Color::bright_white, 14, My_Windows);
            printCenterCharacters(L"   VIEW SCOREBOARD   ", Color::blue, Color::bright_white, 16, My_Windows);
        }
        if (line == 5) {
            printCenterCharacters(L"   IMPORT STUDENTS   ", Color::blue, Color::bright_white, 8, My_Windows);
            printCenterCharacters(L"   ADD A STUDENT   ", Color::blue, Color::bright_white, 10, My_Windows);
            printCenterCharacters(L"   REMOVE A STUDENT   ", Color::blue, Color::bright_white, 12, My_Windows);
            printCenterCharacters(L"   IMPORT SCOREBOARD   ", Color::blue, Color::bright_white, 14, My_Windows);
            printCenterCharacters(L"<< VIEW SCOREBOARD >>", Color::light_red, Color::bright_white, 16, My_Windows);
        }

        int key = getKey();
        if (key == 27)
            return mainmenuOpt();
        if (key == 59)
            return CourseMenuPage(username, SY, season, courseID);
        if (key == 72) {
			if (line == 1)
				line = 5;
			else
				line--;
		}
        if (key == 80) {
            if (line == 5)
				line = 1;
			else
				line++;
        }
        if (key == 13) {
            if (line == 1)
                return importStudentToCourseClass(username, SY, season, courseID, classID);
            if (line == 2)
                return addAStudentToCourseClass(username, SY, season, courseID, classID);
            if (line == 3)
                return removeAStudentInCourseClass(username, SY, season, courseID, classID);
            if (line == 4)
                return importScoreboardToCourseClass(username, SY, season, courseID, classID);
            if (line == 5)
                return viewScoreboardOfACourseClass(username, SY, season, courseID, classID);
        }
    }
}

void studentMenuPage(string username) {
    system("cls"); 
    wstring temp[3];
    temp[0] = L"▒█▀▀▀█ ▀▀█▀▀ ▒█░▒█ ▒█▀▀▄ ▒█▀▀▀ ▒█▄░▒█ ▀▀█▀▀ 　 ▒█▀▄▀█ ▒█▀▀▀ ▒█▄░▒█ ▒█░▒█";
    temp[1] = L"░▀▀▀▄▄ ░▒█░░ ▒█░▒█ ▒█░▒█ ▒█▀▀▀ ▒█▒█▒█ ░▒█░░ 　 ▒█▒█▒█ ▒█▀▀▀ ▒█▒█▒█ ▒█░▒█";
    temp[2] = L"▒█▄▄▄█ ░▒█░░ ░▀▄▄▀ ▒█▄▄▀ ▒█▄▄▄ ▒█░░▀█ ░▒█░░ 　 ▒█░░▒█ ▒█▄▄▄ ▒█░░▀█ ░▀▄▄▀";
    for (int i = 0; i < 3; i++)
    {
        printCenterCharacters(temp[i], Color::red, Color::bright_white, 2 + i, My_Windows);
        Sleep(100);
    }
    printCenterCharacters(wstring(username.begin(), username.end()), Color::light_red, Color::bright_white, 6, My_Windows);
    Sleep(200);
    printCharacter(L"Press ESC to back to main menu", { 0, 0 }, Color::black, Color::bright_white);
    printCenterCharacters(L"   VIEW PROFILE   ", Color::blue, Color::bright_white, 8, My_Windows);
    printCenterCharacters(L"   CHANGE PROFILE   ", Color::blue, Color::bright_white, 10, My_Windows);
    printCenterCharacters(L"   VIEW COURSE IN THIS SEMESTER   ", Color::blue, Color::bright_white, 12, My_Windows);
    printCenterCharacters(L"   VIEW SCOREBOARD   ", Color::blue, Color::bright_white, 14, My_Windows);

    int key = getKey();
    if (key == 27)
        return mainmenuOpt();

    short line = 1;

    while (true) {
        if (line == 1) {
            printCenterCharacters(L">> VIEW PROFILE <<", Color::light_red, Color::bright_white, 8, My_Windows);
            printCenterCharacters(L"   CHANGE PROFILE   ", Color::blue, Color::bright_white, 10, My_Windows);
            printCenterCharacters(L"   VIEW COURSE IN THIS SEMESTER   ", Color::blue, Color::bright_white, 12, My_Windows);
            printCenterCharacters(L"   VIEW SCOREBOARD   ", Color::blue, Color::bright_white, 14, My_Windows);
        }
        if (line == 2) {
            printCenterCharacters(L"   VIEW PROFILE   ", Color::blue, Color::bright_white, 8, My_Windows);
            printCenterCharacters(L">> CHANGE PROFILE <<", Color::light_red, Color::bright_white, 10, My_Windows);
            printCenterCharacters(L"   VIEW COURSE IN THIS SEMESTER   ", Color::blue, Color::bright_white, 12, My_Windows);
            printCenterCharacters(L"   VIEW SCOREBOARD   ", Color::blue, Color::bright_white, 14, My_Windows);
        }
        if (line == 3) {
            printCenterCharacters(L"   VIEW PROFILE   ", Color::blue, Color::bright_white, 8, My_Windows);
            printCenterCharacters(L"   CHANGE PROFILE   ", Color::blue, Color::bright_white, 10, My_Windows);
            printCenterCharacters(L">> VIEW COURSE IN THIS SEMESTER <<", Color::light_red, Color::bright_white, 12, My_Windows);
            printCenterCharacters(L"   VIEW SCOREBOARD   ", Color::blue, Color::bright_white, 14, My_Windows);
        }
        if (line == 4) {
            printCenterCharacters(L"   VIEW PROFILE   ", Color::blue, Color::bright_white, 8, My_Windows);
            printCenterCharacters(L"   CHANGE PROFILE   ", Color::blue, Color::bright_white, 10, My_Windows);
            printCenterCharacters(L"   VIEW COURSE IN THIS SEMESTER   ", Color::blue, Color::bright_white, 12, My_Windows);
            printCenterCharacters(L">> VIEW SCOREBOARD <<", Color::light_red, Color::bright_white, 14, My_Windows);
        }

        key = getKey();
        if (key == 27)
            return mainmenuOpt();
        if (key == 72) {
            if (line == 1)
                line = 4;
            else
                line--;
        }
        if (key == 80) {
            if (line == 4)
                line = 1;
            else
                line++;
        }
        if (key == 13) {
            if (line == 1)
                return viewStudentProfile(username);
            if (line == 2)
                return changeStudentInfo(username);
            if (line == 3)
                return viewListCousres(username);
            if (line == 4)
                return viewStudentScoreboard(username);
        }
    }
}