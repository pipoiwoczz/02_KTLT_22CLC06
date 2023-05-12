#include "guiCreate.h"
#include "createSY.h"


void createSYPage(string username) {
    system("cls");
    wstring temp = L"CREATE SCHOOL YEAR PAGE";
    printCenterCharacters(temp, Color::black, Color::bright_white, 2, My_Windows);
    printCharacter(L"PRESS ESC to back to main menu", { 0,0 }, Color::black, Color::bright_white);
    printCharacter(L"Press F1 to back to previous menu", { short(My_Windows.Right - 34), 0}, Color::black, Color::bright_white);

    string SY;
    ofstream ofs;
    ifstream ifs("SY.txt");
    if (!ifs.is_open() || ifs.eof()) {
        ifs.close();
        printCenterCharacters(L"There is no School Year", Color::light_purple, Color::bright_white, 4, My_Windows);
        printCharacter(L"Input school year now", { 45, 7 }, Color::blue, Color::bright_white);
        drawBox(8);
        gotoxy(46, 9);
        SY = getMenuString();
        if (SY == "ESC") {
            return mainmenuOpt();
		}
        if (SY == "F1") {
            return ProfileMenuPage(username);
		}
        if (!isValidSY(SY)) {
            printCharacter(L"You've entered invalid School year", { 45, 7 }, Color::red, Color::bright_white);
            printCenterCharacters(L"Press any key to continue...", Color::red, Color::bright_white, 9, My_Windows);
            getKey();
            createSYPage(username);
        }
        ofs.open("SY.txt");
        ofs << SY;
        ofs.close();
        _mkdir(SY.c_str());
    }
    else {
        int i = 4;
        printCenterCharacters(L"Available School Year", Color::purple, Color::bright_white, i, My_Windows);
        while (getline(ifs, SY)) {
            printCenterCharacters(wstring(SY.begin(), SY.end()), Color::black, Color::bright_white, i + 2, My_Windows);
            i = i + 2;
        }
        ifs.close();
        printCharacter(L"Input school year now", { 45, short(i + 3) }, Color::blue, Color::bright_white);
        drawBox(i + 4);
        gotoxy(46, i + 5);
        SY = getMenuString();
        if (SY == "ESC") {
			return mainmenuOpt();
        }
        if (SY == "F1")
            return ProfileMenuPage(username);

        if (!isValidSY(SY)) {
            printCenterCharacters(L"You've entered invalid School year", Color::red, Color::bright_white, i + 8, My_Windows);
            printCenterCharacters(L"Press any key to continue...", Color::purple, Color::bright_white, i + 10, My_Windows);
            getKey();
            createSYPage(username);
        }
        ofs.open("SY.txt", ios::app);
        ofs << endl << SY;
        ofs.close();
        _mkdir(SY.c_str());
    }

    ofs.open("curTime.txt");
    ofs << SY << endl << 1;
    ofs.close();

    printCenterCharacters(L"Press any key to continue...", Color::purple, Color::bright_white, 7, My_Windows);
    getKey();
    return ProfileMenuPage(username);
}

void CreateSemesterPage(string username, string SY) {
    system("cls");
    printCenterCharacters(L"CREATE SEMESTER PAGE", Color::light_red, Color::bright_white, 2, My_Windows);
    short idx = 5;

    printCenterCharacters(L"Choose Semester Here", Color::light_red, Color::bright_white, idx, My_Windows);
    idx += 2;
    int line = 1;

    printCharacter(L"Press ESC to back to main menu", { 0, 0 }, Color::black, Color::bright_white);
    printCharacter(L"Press F1 to back to previous menu", { short(My_Windows.Right - 34), 0 }, Color::black, Color::bright_white);
    printCenterCharacters(L"   Spring   ", Color::black, Color::bright_white, idx, My_Windows);
    printCenterCharacters(L"   Summer   ", Color::black, Color::bright_white, idx + 2, My_Windows);
    printCenterCharacters(L"   Autumn   ", Color::black, Color::bright_white, idx + 4, My_Windows);

    int key = getKey();
    if (key == 27) {
        return mainmenuOpt();
    }
    if (key == 59) {
        return SYMenuPage(username, SY);
    }

    while (true) {

        if (line == 1) {
            printCenterCharacters(L">> Spring <<", Color::light_blue, Color::bright_white, idx, My_Windows);
            printCenterCharacters(L"   Summer   ", Color::black, Color::bright_white, idx + 2, My_Windows);
            printCenterCharacters(L"   Autumn   ", Color::black, Color::bright_white, idx + 4, My_Windows);
        }
        if (line == 2) {
            printCenterCharacters(L"   Spring   ", Color::black, Color::bright_white, idx, My_Windows);
            printCenterCharacters(L">> Summer <<", Color::light_blue, Color::bright_white, idx + 2, My_Windows);
            printCenterCharacters(L"   Autumn   ", Color::black, Color::bright_white, idx + 4, My_Windows);
        }
        if (line == 3) {
            printCenterCharacters(L"   Spring   ", Color::black, Color::bright_white, idx, My_Windows);
            printCenterCharacters(L"   Summer   ", Color::black, Color::bright_white, idx + 2, My_Windows);
            printCenterCharacters(L">> Autumn <<", Color::light_blue, Color::bright_white, idx + 4, My_Windows);
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
				line = 3;
			}
            else {
				line--;
			}
        }
        if (key == 80) {
            if (line == 3) {
                line = 1;
            }
            else {
                line++;
            }
        }
        if (key == 13) {
            if (_mkdir((SY + "/" + to_string(line)).c_str()) == 0) {
                printCenterCharacters(L"Create Semester Successfully", Color::light_green, Color::bright_white, idx + 6, My_Windows);
                printCharacter(L"Start date", { 45, short(idx + 8) }, Color::blue, Color::bright_white);
                drawBox(idx + 9);
                string startdate;
                gotoxy(46, idx + 10);
                startdate = getStringInput();
                if (startdate == "ESC") {
					return mainmenuOpt();
				}
                printCharacter(L"End date", { 45, short(idx + 13) }, Color::blue, Color::bright_white);
                drawBox(idx + 14);
                string enddate;
                gotoxy(46, idx + 15);
                enddate = getStringInput();
                if (enddate == "ESC") {
                    return mainmenuOpt();
                }
                ofstream ofs((SY + "/" + to_string(line) + "/info.txt").c_str());
                ofs << line << " " << startdate << " " << enddate;
                ofs.close();
                printCenterCharacters(L"Press any key to modify this semester...", Color::purple, Color::bright_white, 0, My_Windows);
                key = getKey();
                if (key == 27) {
                    return mainmenuOpt();
                }
                if (key == 59) {
                    return SYMenuPage(username, SY);
                }
                //return SemesterMenuPage();
                return SYMenuPage(username, SY);

            }
            else {
                printCenterCharacters(L"Create Semester Failed", Color::red, Color::bright_white, idx + 6, My_Windows);
                printCenterCharacters(L"Press any key to choose again...", Color::purple, Color::bright_white, 0, My_Windows);
                key = getKey();
                if (key == 27) {
                    return mainmenuOpt();
                }
                if (key == 59) {
                    return SYMenuPage(username, SY);
                }
                return CreateSemesterPage(username, SY);
            }
        }        
    }
}

void CreateClassPage(string username, string SY) {
    system("cls");
    wstring temp = L"CREATE CLASS PAGE";
    printCenterCharacters(temp, Color::black, Color::bright_white, 2, My_Windows);

    printCharacter(L"Press ESC to back to main menu", { 0, 0 }, Color::black, Color::bright_white);
    printCharacter(L"Press F1 to back to previous menu", { short(My_Windows.Right - 34), 0 }, Color::black, Color::bright_white);

    printCharacter(L"Class ID: ", { 45, 5 }, Color::blue, Color::bright_white);
    drawBox(6);
    string classID;
    gotoxy(46, 7);

    int key = getKey();
    if (key == 27)
        return mainmenuOpt();
    if (key == 59)
        return SYMenuPage(username, SY);

    classID = getStringInput();
    if (classID == "ESC")
		return mainmenuOpt();

    string path = SY + "/" + classID;
    if (_mkdir(path.c_str()) == 0) {
        //printCharacter(L"Press F1 to back to previous menu", { short(My_Windows.Right - 34), 0}, Color::black, Color::bright_white);
        
        printCenterCharacters(L"Create Class Successfully", Color::light_green, Color::bright_white, 9, My_Windows);
        printCenterCharacters(L"Press any key to modify this class...", Color::purple, Color::bright_white, 0, My_Windows);

        ifstream ifs;
        ifs.open(SY + "/" + "class.txt");
        if (!ifs.is_open() || ifs.eof()) {
            ifs.close();
            ofstream ofs(SY + "/class.txt");
            ofs << classID;
            ofs.close();
        }
        else {
            ifs.close();
            ofstream ofs(SY + "/class.txt", ios::app);
            ofs << endl << classID;
            ofs.close();
        }

        int key = getKey();
        if (key == 27) {
			return mainmenuOpt();
		}
        if (key == 59) {
			return SYMenuPage(username, SY);
		}
        return ClassMenuPage(username, SY, classID);
    }
    else {
        printCenterCharacters(L"Create Class Failed", Color::red, Color::bright_white, 8, My_Windows);
        printCharacter(L"Press F1 to back to previous menu", { short(My_Windows.Right - 34), 0 }, Color::black, Color::bright_white);
		printCenterCharacters(L"Press any key to choose again...", Color::purple, Color::bright_white, 0, My_Windows);
		int key = getKey();
        if (key == 27) {
			return mainmenuOpt();
		}
        if (key == 59) {
			return SYMenuPage(username, SY);
		}
		return CreateClassPage(username, SY);
    }
    
}

void CreateACourse(string username, string SY, short season) {
    system("cls");
    wstring temp = L"CREATE COURSE PAGE";
    printCharacter(L"Press ESC to back to main menu", { 0, 0 }, Color::black, Color::bright_white);
    printCharacter(L"Press F1 to back to previous menu", { short(My_Windows.Right - 34), 0 }, Color::black, Color::bright_white);

    printCenterCharacters(temp, Color::aqua, Color::bright_white, 2, My_Windows);
    if (season == 1)
        printCenterCharacters(L"<<<<SPRING>>>>", Color::green, Color::bright_white, 3, My_Windows);
    if (season == 2)
        printCenterCharacters(L"<<<<SUMMER>>>>", Color::green, Color::bright_white, 3, My_Windows);
    if (season == 3)
        printCenterCharacters(L"<<<<AUTUMN>>>>", Color::green, Color::bright_white, 3, My_Windows);

    string path_course = SY + "/" + to_string(season) + "/course.txt";

    printCharacter(L"Enter Course ID here: ", { 45, 6 }, Color::blue, Color::bright_white);
    gotoxy(45 + 23, 6);

    string courseID = getMenuString();
    if (courseID == "ESC")
		return mainmenuOpt();
    if (courseID == "F1")
        return SemesterMenuPage(username, SY, season);
    printCharacter(L"Enter Course Name here: ", { 45, 8 }, Color::blue, Color::bright_white);
    gotoxy(45 + 25, 8);
    string courseName = getMenuString();
    if (courseName == "ESC")
        return mainmenuOpt();
    if (courseName == "F1")
        return SemesterMenuPage(username, SY, season);

    printCharacter(L"Enter Course Credits here: ", { 45, 10 }, Color::blue, Color::bright_white);
    gotoxy(45 + 28, 10);
    string courseCredit = getMenuString();
    if (courseCredit == "ESC")
		return mainmenuOpt();
    if (courseCredit == "F1")
		return SemesterMenuPage(username, SY, season);
    int courseCre = stoi(courseCredit);

    if (_mkdir((SY + "/" + to_string(season) + "/" + courseID).c_str()) == -1) {
        printCenterCharacters(L"THIS COURSE HAS ALREADY EXIST", Color::red, Color::bright_white, 8, My_Windows);
        printCenterCharacters(L"Press any key to enter again or Press F1 to back to previous menu", Color::red, Color::bright_white, 10, My_Windows);
        int key = getKey();
        if (key == 27)
            return mainmenuOpt();
        if (key == 59)
            return SemesterMenuPage(username, SY, season);
        return CreateACourse(username, SY, season);
    }

    // add to course.txt
    string path = SY + "/" + to_string(season) + "/course.txt";
    ifstream ifs;
    ofstream ofs;
    ifs.open(path);
    if (!ifs.is_open() || ifs.eof()) {
        ifs.close();
        ofs.open(path);
        ofs << courseID;
        ofs.close();
    }
    else {
        ifs.close();
        ofs.open(path, ios::app);
        ofs << endl << courseID;
        ofs.close();
    }

    //create info.txt of a course
    ofs.open(SY + "/" + to_string(season) + "/" + courseID + "/info.txt");
    ofs << courseID << "\n" << courseName << "\n" << courseCre;
    ofs.close();

    printCenterCharacters(L"CREATE COURSE SUCCESSFULLY", Color::green, Color::bright_white, 13, My_Windows);
    printCenterCharacters(L"Press any key to back to previous menu or Press F1 to back to create 1 more", Color::green, Color::bright_white, 15, My_Windows);
    int key = getKey();
    if (key == 27)
        return mainmenuOpt();
    if (key == 59)
        return CreateACourse(username, SY, season);
    return SemesterMenuPage(username, SY, season);
}