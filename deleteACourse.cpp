#include "deleteACourse.h"

void deleteACourse(Course*& pHead)
{
	Course* curr, * prev;
	int courseid;
	cout << "Enter the course ID needed to delete: ";
	cin >> courseid;
	if (pHead->courseID == courseid) {
		curr = pHead;
		pHead = pHead->next;
		delete curr;
		return;
	}
	curr = pHead->next;
	prev = pHead;
	while (curr) {
		if (curr->courseID == courseid) {
			prev->next = curr->next;
			delete curr;
			curr = prev->next;
			return;
		}
		prev = curr;
		curr = curr->next;
	}
}