#include "viewScoreboardOfCourse.h"

void viewScoreboardOfCourse(string SY, string Sem, string curCourse) {
	string cClass, path, chosenClass;
	ifstream courseClass;
	path = "./" + SY + "/" + Sem + "/" + curCourse + "/class.txt";

	// View list of classes in a course
	courseClass.open(path);
		cout << "---------List of Class in this Course------------\n";
		while (!courseClass.eof()) {
			getline(courseClass, cClass);
			cout << cClass << endl;
		}
		cout << "---------------------------------------------------\n";
	courseClass.close();

	cout << "Enter class's name: ";
	cin >> chosenClass;

	// Check whether the input is correct or not
	bool exist = false;
	courseClass.open(path);
		while (!courseClass.eof()) {
			getline(courseClass, cClass);
			if (cClass == chosenClass) {
				exist = true;
				break;
			}
		}		
	courseClass.close();

	if (!exist) {
		cout << "You've entered an invalid class name!\n";
		cout << "Enter 0 to get back to previous menu or any key else to enter class name again\n";
		cout << "Your choice: ";
		string temp;
		cin >> temp;

		if (temp == "0") return;
		else return viewScoreboardOfCourse(SY, Sem, curCourse);
	}


    ifstream ifs;
    string out;
    ifs.open("./" + SY + "/" + Sem + "/" + curCourse + "/" + chosenClass + "/scoreboard.txt");
    if (!ifs.is_open()) {
        cout << "This course hasn't been updated scoreboard!" << endl;
        system("pause");
        return;
    }

    cout << "Course's scoreboard:" << endl;
    cout << "--------------------" << endl;
    cout << left << setw(5) << "No." << setw(10) << "ID" << setw(34) << "Name" << setw(8) << "Total" << setw(8) << "Final" << setw(8) << "Midterm" << setw(8) << "Other" << endl;
        while (!ifs.eof()) {
            getline(ifs, out, ','); // Ordinal number
            cout << left << setw(5) << out;
            getline(ifs, out, ','); // ID
            cout << left << setw(10) << out;
            getline(ifs, out, ','); // Name
            cout << left << setw(34) << out;
            getline(ifs, out, ','); // Total
            cout << left << setw(8) << out;
            getline(ifs, out, ','); // Final 
            cout << left << setw(8) << out;
            getline(ifs, out, ','); // Midterm
            cout << left << setw(8) << out;
            getline(ifs, out); // Other
            cout << left << setw(8) << out << endl;
        }
    ifs.close();
    cout << "--------------------" << endl;
}