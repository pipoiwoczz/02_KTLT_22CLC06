#include "deleteACourse.h"
#include "main.h"
#include <stdio.h>
#include <fstream>
#include <string>
#include <filesystem>
using namespace std;
namespace fs = filesystem;

void deleteACourse(schoolYear *year, Semester *sem, Course*& pCourse)
{
	Course* curr, * prev;
	int courseid;
	cout << "Enter the course ID needed to delete: ";
	cin >> courseid;
	if (pCourse->courseID == courseid) {
		curr = pCourse;
		pCourse = pCourse->next;
		delete curr;
		return;
	}
	curr = pCourse->next;
	prev = pCourse;
	while (curr) {
		if (curr->courseID == courseid) {
			prev->next = curr->next;
			string coursePath = "./" + year->name + "/" + to_string(sem->season) + "/" + to_string(curr->courseID);
			fs::remove_all(coursePath);
			delete curr;
			curr = prev->next;
			return;
		}
		prev = curr;
		curr = curr->next;
	}
}