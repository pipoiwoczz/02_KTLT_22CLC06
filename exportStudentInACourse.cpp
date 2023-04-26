#include "exportStudentInACourse.h"

void exportStudentInACourse(string SY, string Sem, string course)   {
	string outputPath;

	cout << "Input path to export CSV file: ";
	cin.ignore();
	getline(cin, outputPath);

	ofstream ofs;
	
	ofs.open(outputPath);

	if (ofs.is_open())	{
		string path = "./" + SY + "/" + Sem + "/" + course + "/class.txt";
		string courseClass, studentID, studentName;
		ifstream ifs, Class;

		int i=1; // Ordinal number

		ifs.open(path);
			while (!ifs.eof()) {
				getline(ifs, courseClass);
				ofs << course << " class " << courseClass << endl;
				ofs << "No" << "," << "ID" << "," << "Class" << "," << "Name" << endl;

				Class.open("./" + SY + "/" + Sem + "/" + course + "/" + courseClass + "/listStud.txt");
					while (!Class.eof()) {
						getline(Class, studentID, ',');
						getline(Class, studentName);
						ofs << i << "," << studentID << "," << courseClass << "," << studentName << endl;
						i++;
					}
				Class.close();
				ofs << endl;
			}
		ifs.close();
	}	else	{
		cout << "You've entered wrong path\n";
		cout << "Please try again\n";
	}

	ofs.close();
}