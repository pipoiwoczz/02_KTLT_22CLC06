#include "viewScoreboardOfCourse.h"

void viewScoreboardOfCourse(string SY, string Sem, string curCourse) {
	string path; 
	ifstream courseClass;

	path = "./" + SY + "/" + Sem + "/" + curCourse + "/class.txt";

	// View list of classes in a course
	string cClass, chosenClass;
	courseClass.open(path);
		while (!courseClass.eof()) {
			getline(courseClass, cClass);
			cout << "Class " << cClass << endl;

			ifstream ifs;
			ifs.open("./" + SY + "/" + Sem + "/" + curCourse + "/" + cClass + "/scoreboard.txt");
				if (ifs.is_open())	{
					cout << "\t" << left << setw(5) << "No" << setw(10) << "ID";
					cout << left << setw(22) << "Last name" << setw(12) << "First Name";
					cout << left << setw(8) << "Total" << setw(8) << "Final" << setw(8) << "Midterm" << setw(8) << "Other" << endl;
					while (!ifs.eof()) {
						string tmp;

						getline(ifs, tmp, ','); // Ordinal number
						cout << "\t" << left << setw(5) << tmp;
						getline(ifs, tmp, ','); // ID
						cout << left << setw(10) << tmp;
						getline(ifs, tmp, ','); // Last Name
						cout << left << setw(22) << tmp;
						getline(ifs, tmp, ','); // First Name
						cout << left << setw(12) << tmp;
						getline(ifs, tmp, ','); // Total
						cout << left << setw(8) << tmp;
						getline(ifs, tmp, ','); // Final 
						cout << left << setw(8) << tmp;
						getline(ifs, tmp, ','); // Midterm
						cout << left << setw(8) << tmp;
						getline(ifs, tmp); // Other
						cout << left << setw(8) << tmp << endl;
					}
				}
				else	{
					cout << "\tThis class doesn't have a scoreboard yet.";
					cout << "\n\tPlease import a scoreboard first.\n";
				}

			ifs.close();
		}
	courseClass.close();
}