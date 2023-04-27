#include "gui.h"
#include "guiMenu.h"
#include "guiView.h"
#include "guiAddnRemove.h"
int main() {
	system("cls");
	textSize(24);
	fixConsoleWindow();

	//viewCourseInformation("khoa", "2022-2023", 1, "CSS101");
	//viewAndChooseCourseClass("khoa", "2022-2023", 1, "CSS101");
	mainmenuOpt();
	return 1;
}