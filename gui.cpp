#include "gui.h"
#include "guiMenu.h"

void textColor(int color) {
    HANDLE mau;
    mau = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(mau, color);
}

void gotoxy(int x, int y) {
    static HANDLE h = NULL;
    if (!h)
        h = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD c = { x, y };
    SetConsoleCursorPosition(h, c);
}

void fixConsoleWindow() {
    system("color f0");
    ShowWindow(GetConsoleWindow(), SW_MAXIMIZE);
    HWND consoleWindow = GetConsoleWindow();
    LONG style = GetWindowLong(consoleWindow, GWL_STYLE);
    style = style & ~(WS_MAXIMIZEBOX) & ~(WS_THICKFRAME);
    SetWindowLong(consoleWindow, GWL_STYLE, style);
}

void consoleColor() {
    HANDLE console_color;
    console_color = GetStdHandle(
        STD_OUTPUT_HANDLE);
}

void textSize(int fontSize) {
    CONSOLE_FONT_INFOEX cfi;
    cfi.cbSize = sizeof(cfi);
    cfi.nFont = 0;
    cfi.dwFontSize.X = 0;
    cfi.dwFontSize.Y = fontSize;
    cfi.FontFamily = FF_DONTCARE;
    cfi.FontWeight = FW_NORMAL;
    wcscpy(cfi.FaceName, L"Consolas");
    SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);
}

int getKey() {
    int ch = _getch();
    if (ch == 0 || ch == 224) {
        int temp = _getch();
        return temp;
    }
}

void printCharacter(wstring content, COORD spot, Color textColor, Color backgroundColor, short maxlength) {
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    DWORD Written;
    
    int color = int(textColor) + int(backgroundColor) * 16;
    

    if (maxlength == -1) {
        //content = content.substr(0, maxlength) + L"...";
    }

    for (int i = 0; i < content.length(); i++) {
        FillConsoleOutputAttribute(hOut, color, 1, spot, &Written);
        FillConsoleOutputCharacterW(hOut, content[i], 1, spot, &Written);
        spot.X++;
    }
}

void printCenterCharacters(wstring content, Color textColor, Color backgroundColor, short y, SMALL_RECT box, short maxlength) {
    short centerX = (short(box.Left) + short(box.Right)) / 2 - content.length() / 2;

    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    DWORD Written;

    int color = int(textColor) + int(backgroundColor) * 16;

    if (maxlength == -1) {
        //content = content.substr(0, maxlength) + L"...";
    }

    for (int i = 0; i < content.length(); i++) {
        FillConsoleOutputAttribute(hOut, color, 1, { centerX, y }, &Written);
        FillConsoleOutputCharacterW(hOut, content[i], 1, { centerX, y }, &Written);
        centerX++;
    }
}

void drawMenu() {
    wstring temp[6];
    temp[0] = L"███╗░░░███╗░█████╗░██╗███╗░░██╗    ███╗░░░███╗███████╗███╗░░██╗██╗░░░██╗";
    temp[1] = L"████╗░████║██╔══██╗██║████╗░██║    ████╗░████║██╔════╝████╗░██║██║░░░██║";
    temp[2] = L"██╔████╔██║███████║██║██╔██╗██║    ██╔████╔██║█████╗░░██╔██╗██║██║░░░██║";
    temp[3] = L"██║╚██╔╝██║██╔══██║██║██║╚████║    ██║╚██╔╝██║██╔══╝░░██║╚████║██║░░░██║";
    temp[4] = L"██║░╚═╝░██║██║░░██║██║██║░╚███║    ██║░╚═╝░██║███████╗██║░╚███║╚██████╔╝";
    temp[5] = L"╚═╝░░░░░╚═╝╚═╝░░╚═╝╚═╝╚═╝░░╚══╝    ╚═╝░░░░░╚═╝╚══════╝╚═╝░░╚══╝░╚═════╝░";
    for (int i = 2; i < 7; i++) {
        printCenterCharacters(temp[i-2], Color::black, Color::bright_white, i, My_Windows);
        Sleep(100);
    }
    Sleep(200);
}


void drawBox(short line) {
    wstring temp[3];
    temp[0] = L"┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓";
    temp[1] = L"┃                                          ┃";
    temp[2] = L"┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛";

    for (int i = 0; i < 3; i++) {
        printCenterCharacters(temp[i], Color::black, Color::bright_white, i + line, My_Windows);
    }
}

string getStringInput() {
    string temp;
	int ch;
    int maxlength = 24;
    int length = 0;
    while (1) {
		ch = getKey();
        if (ch == 27) {
            //mainmenuOpt();
            return "ESC";
        }
        if (ch == 13 ) {
			return temp;
		}
        if (ch == 8) {
            if (temp.length() > 0) {
				temp.pop_back();
				cout << "\b \b";
                length--;
			}
		}
        else 
			if (length < maxlength) {
				temp += ch;
				cout << (char)ch;
				length++;
            }
            else {
                cout << (char)ch;
                cout << "\b \b";
            }
		
	}
}

string getCourseInfor() {
    string temp;
    int ch;
    short maxlength = 30;
    int length = 0;
    while (1) {
        ch = getKey();
        if (ch == 27) {
           // mainmenuOpt();
            return "ESC";
        }
        if (ch == 13) {
            return temp;
        }
        if (ch == 59) {
            return "next";
        }
        if (ch == 8) {
            if (temp.length() > 0) {
                temp.pop_back();
                cout << "\b \b";
                length--;
            }
        }
        else
            if (length < maxlength) {
                temp += ch;
                cout << (char)ch;
                length++;
            }
            else {
                cout << (char)ch;
                cout << "\b \b";
            }

    }
}

string getMenuString() {
    string temp;
    int ch;
    short maxlength = 30;
    int length = 0;
    while (1) {
        ch = getKey();
        if (ch == 27) {
            //mainmenuOpt();
            return "ESC";
        }
        if (ch == 13) {
            return temp;
        }
        if (ch == 59) {
             //SYMenuPage(username, SY);
             return "F1";
        }
        if (ch == 8) {
            if (temp.length() > 0) {
                temp.pop_back();
                cout << "\b \b";
                length--;
            }
        }
        else
            if (length < maxlength) {
                temp += ch;
                cout << (char)ch;
                length++;
            }
            else {
                cout << (char)ch;
                cout << "\b \b";
            }

    }
}
