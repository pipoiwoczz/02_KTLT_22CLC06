#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <fstream>
#include <Windows.h>
#include <stddef.h>
#include <stdio.h>
#include <conio.h>
#include <wchar.h>
#include <string>
#include <direct.h>

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77

const SMALL_RECT My_Windows = { 0, 0, 135, 33 };

enum class Color {
	black = 0,
	blue = 1,
	green = 2,
	aqua = 3,
	red = 4,
	purple = 5,
	yellow = 6,
	white = 7,
	gray = 8,
	light_blue = 9,
	light_green = 10,
	light_aqua = 11,
	light_red = 12,
	light_purple = 13,
	light_yellow = 14,
	bright_white = 15
};



using namespace std;

void textSize(int fontSize);
void textColor(int color);
void gotoxy(int x, int y);
void fixConsoleWindow();
void consoleColor();
int getKey();
void printCharacter(wstring content, COORD spot, Color textColor, Color backgroundColor, short maxlength = -1);
void printCenterCharacters(wstring content, Color textColor, Color backgroundColor, short y, SMALL_RECT box, short maxlength = -1);
void drawMenu();
string getStringInput();
void drawBox(short line);
string getSYMenuString(string username, string SY);
string getSemesterMenuString(string username, string SY, short season);
string getCourseMenuString(string username, string SY, short season, string courseID);
string getClassMenuString(string username, string SY, string classID);