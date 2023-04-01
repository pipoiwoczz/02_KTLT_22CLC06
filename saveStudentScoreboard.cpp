#include "saveStudentScoreboard.h"

string searchStudent(string studentID)
{
	string pathProfile = "./profile/" + studentID + ".txt";
	ifstream ifs(pathProfile);
	string className;
	for (int i = 0; i < 4; i++)
		getline(ifs, className);
	return className;
}

void saveStudentScoreboard(schoolYear *year, string pathOfScoreboard, string courseID)
{
	ifstream fin(pathOfScoreboard);
	string temp;

	while (!fin.eof()) {
		getline(fin, temp, ','); // no
		getline(fin, temp, ','); // studentid
		string className = searchStudent(temp);
		string folder = "./" + year->name + "/" + className + "/" + temp + "/" + courseID + ".txt";
		
		ofstream fout(folder);
		getline(fin, temp, ',');
		for (int i = 0; i < 3; i++) {
			getline(fin, temp, ',');
			fout << temp << ",";
		}
		getline(fin, temp);
		fout << temp;
		fout.close();
	}
	fin.close();
}