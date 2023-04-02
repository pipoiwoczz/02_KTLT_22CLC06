#include "removeAStudent.h"
#include "main.h"

void removeAStudent(Student*& pHead)
{
	Student* curr = pHead->next;
	Student* prev = pHead;
	int id;
	cout << "Enter the ID of student: ";
	cin >> id;
	if (pHead->studentId == id) {
		pHead = pHead->next;
		delete prev;
		return;
	}
	while (prev) {
		if (curr->studentId == id) {
			prev->next = curr->next;
			delete curr;
			return;
		}
		prev = curr;
		curr = curr->next;
	}		
}