#include "addACourse"

void addACourse(Course*& pHead)
{
	pHead = new Course;
	cout << "CourseID: ";
	cin >> pHead->courseID;
	cout << "Course name: ";
	cin >> pHead->courseName;
	cout << "Class name: ";
	cin >> pHead->className;
	cout << "The number of credits: ";
	cin >> pHead->credits;
	cout << "The maximum number of students in the course: ";
	cin >> pHead->maxStudents;
	cout << "Day of week: ";
	cin >> pHead->dayOfWeek;
	cout << "The session performed on: ";
	cin >> pHead->session;
}