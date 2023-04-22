#include "copyScoreboard.h"

void copyScoreboard(schoolYear* currYear, Semester* currSem, Course* currCourse, string pathScoreboard)
{
	string pathCourse = "./" + currYear->name + "/" + to_string(currSem->season) + "/" + currCourse->courseID + "/scoreboard.txt";
	ofstream ofs(pathCourse);
	ifstream ifs(pathScoreboard);

	while (!ifs.eof()) {
		string temp;
		getline(ifs, temp);
		ofs << temp << endl;
	}

	ofs.close();
	ifs.close();
}