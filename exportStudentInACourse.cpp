#include "exportStudentInACourse.h"

void exportStudentInACourse(string SY, string Sem, string course)   {
    // choose Course Class to view students  
	string cClass, path, chosenClass;
	ifstream courseClass;
	path = "./" + SY + "/" + Sem + "/" + course + "/class.txt";

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
		cout << "You've entered an incorrect class name!\n";
		cout << "Enter 0 to get back to previous menu or any of other keys to enter class name again\n";
		cout << "Your choice: ";
		string temp;
		cin >> temp;
    	cout << "--------------------" << endl;
        return;
	}

    string out;
    ifstream ifs;
        ifs.open("./" + SY + "/" + Sem + "/" + course + "/" + chosenClass + "/listStud.txt");
		if (ifs.is_open()) {
            ofstream ofs;
            string outputPath;

            cout << "Input path to export CSV file: ";
            cin.ignore();
            getline(cin, outputPath);

            ofs.open(outputPath);
            if (ofs)    {
                int i = 1; // Ordinal number
                ofs << course << " class " << chosenClass << endl;
                ofs << left << setw(4) << "No." << setw(10) << "ID" << "Name" << endl;
                while (!ifs.eof()) {
                    ofs << left << setw(4) << i; // Ordinal number
                    getline(ifs, out, ',');
                    ofs << setw(10) << out; // Id
                    getline(ifs, out);
                    ofs << out << endl; // Name
                    i++;
                }
		    }
        
            ofs.close();  
            }
			
		else {
			cout << "This Course Class has no students yet.\n";
            cout << "Please add students to this course class first.\n";
		}
    ifs.close();
}