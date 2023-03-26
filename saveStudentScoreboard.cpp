#include "saveStudentScoreboard.h"

string searchStudentInClass(Class* pClass, string studentID)
{
	while (pClass) {
		while (pClass->Students) {
			if (pClass->Students->studentId == stoi(studentID))
				return pClass->name;
			pClass->Students = pClass->Students->next;
		}
		pClass = pClass->next;
	}
}

void saveStudentScoreboard(Class* pClass, string pathOfScoreboard, string courseName)
{
	ifstream fin(pathOfScoreboard);
	string temp, No;

	while (!fin.eof()) {
		getline(fin, No, ',');
		getline(fin, temp, ',');
		string className = searchStudentInClass(pClass, temp);
		path folder = format("{}/scoreboard/{}_courseName.txt", className, temp);
		ofstream fout(folder);
		fout << No << "," << temp << ",";
		getline(fin, temp, ',');
		fout << temp << ",";
		getline(fin, temp, ',');
		fout << temp << ",";
		getline(fin, temp, ',');
		fout << temp << ",";
		getline(fin, temp, ',');
		fout << temp << ",";
		getline(fin, temp, ',');
		fout << temp << endl;
		fout.close();
	}
	fin.close();
}