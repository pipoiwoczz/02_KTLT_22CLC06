#include "exportStudentInACourse.h"

void exportStudentInACourse(string SY, string Sem, string course)   {
	string outputPath;

	cout << "Input path: ";
	cin.ignore();
	getline(cin, outputPath);

	ofstream ofs;

	ofs.open(outputPath);

	if (ofs.is_open())	{
		string path; 
		ifstream courseClass;

		path = "./" + SY + "/" + Sem + "/" + course + "/class.txt";
		
		string cClass;
		courseClass.open(path);
			while (!courseClass.eof()) {
				getline(courseClass, cClass);
				ofs << course << " class " << cClass << endl;

				ifstream ifs;
				ifs.open("./" + SY + "/" + Sem + "/" + course + "/" + cClass + "/scoreboard.txt");
					if (ifs.is_open())	{
						ofs << "No" << "," << "ID" << ",";
						ofs << "Last name" << "," << "First Name" << ",";
						ofs << "Total" << "," << "Final" << "," << "Midterm" << "," << "Other" << endl;
						while (!ifs.eof()) {
							string tmp;

							getline(ifs, tmp, ','); // Ordinal number
							ofs << left << tmp << ",";
							getline(ifs, tmp, ','); // ID
							ofs << left << tmp << ",";
							getline(ifs, tmp, ','); // Last Name
							ofs << tmp << ",";
							getline(ifs, tmp, ','); // First Name
							ofs << tmp << ",";
							getline(ifs, tmp, ','); // Total
							ofs << tmp << ",";
							getline(ifs, tmp, ','); // Final 
							ofs << tmp << ",";
							getline(ifs, tmp, ','); // Midterm
							ofs << tmp << ",";
							getline(ifs, tmp); // Other
							ofs << tmp << endl;
						}
					}
					else	{
						ofs << "This class doesn't have a scoreboard yet.\n";
						ofs << "Please import a scoreboard first.\n";
					}

				ifs.close();
			}
		courseClass.close();
	} else	{
		cout << "You've entered wrong path.\n";
		cout << "Please try again.\n";
	}
    
	ofs.close();
}