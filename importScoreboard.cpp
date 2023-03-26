#include "importScoreboard.h"

void importScoreBoard(Course* pCourse)
{
	string folderCourse = to_string(pCourse->courseID) + "_course";
	string scoreboard = "scoreboard";
	path folder = folderCourse;
	path folderScoreboard = folder / scoreboard;

	if (!exists(folderScoreboard)) {
		bool res = create_directory(folderScoreboard);
		if (!res) {
			cout << "Error: Unable to create directory!" << endl;
			return;
		}
	}

	string pathOfScoreboard;
	ifstream fin;
	cout << "Enter the path of the scoreboard: ";
	cin >> pathOfScoreboard;
	fin.open(pathOfScoreboard);

	while (!fin.eof()) {
		string temp, No;
		getline(fin, No, ',');
		getline(fin, temp, ',');
		path scoreSt = folderScoreboard / format("{}.txt", temp);
		ofstream fout(scoreSt);
		fout << No << "," << temp << ",";
		getline(fin, temp, ',');
		fout << temp << ",";
		getline(fin, temp, ',');
		fout << temp << ",";
		getline(fin, temp, ',');
		fout << temp << ",";
		getline(fin, temp, ',');
		fout << temp << ",";
		getline(fin, temp);
		fout << temp;
		fout.close();
	}
	fin.close();
}