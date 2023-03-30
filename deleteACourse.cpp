#include "deleteACourse.h"
#include "main.h"

void deleteACourse(Course*& pCourse)
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
			string coursePath = format("./{}", curr->courseID);
			remove_all(coursePath);
			delete curr;
			curr = prev->next;
			return;
		}
		prev = curr;
		curr = curr->next;
	}
}