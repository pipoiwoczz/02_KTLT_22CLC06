#include "importCourseScoreboard.h"
#include "main.h"
#include <iostream>
using namespace std;

void inputStudentScore(Grade*& studentGrade, ifstream& fin)
{
	string s;
	getline(fin, s, ',');
	studentGrade->totalMark = stof(s);
	getline(fin, s, ',');
	studentGrade->finalMark = stof(s);
	getline(fin, s, ',');
	studentGrade->midtermMark = stof(s);
	getline(fin, s, ',');
	studentGrade->otherMark = stof(s);
}

void importScoreBoard(Course*& pCourse, Class*& pHeadClass)
{
	Course* curr = pCourse;
	ifstream fin;
	string path, temp, tempClassName;
	int tempStudentID;
	string courseid;
	
	cout << "Enter the course ID: ";
	cin >> courseid;
	while (pCourse) {
		if (pCourse->courseID == courseid) {
			cin.ignore();
			cout << "Enter the path of the score board: ";
			getline(cin, path);
			fin.open(path);

			if (!fin.is_open()) {
				cout << "The file doesn't exist.";
				return;
			}
			while (!fin.eof()) {
				getline(fin, temp);
				tempClassName = temp;
				
				Class* currClass = pHeadClass;
				while (currClass) {
					if (currClass->name == tempClassName) {
						Student* currStudent = currClass->Students;
						while (currStudent) {
							Grade* currGrade = currStudent->pHeadGrade;
							while (currGrade) {
								if (currGrade->courseID == courseid) {
									inputStudentScore(currGrade, fin);
									currGrade->courseGPA = pCourse->credits * currGrade->totalMark;
									break;
								}
								currGrade = currGrade->next;
							}
							currStudent = currStudent->next;
						}
					}
					currClass = currClass->next;
				}
			}
		}
	}
}