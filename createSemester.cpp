#include "createSemester.h"
#include "login.h"
#include <sys/stat.h>
#include <direct.h>
#include <cstring>
#include "main.h"
using namespace std;

void createSemester(string username, string curSY)
{
    int season;

    cout << "Pls create a semester: " << endl;
    cout << "1. Spring \n";
    cout << "2. Summer \n";
    cout << "3. Autumn \n";
    cout << "Semester you want to create: ";

    cin >> season;

    string path = curSY + "/" + char(season + 48);

    if (_mkdir(path.c_str()) == -1) {
            cout << "This Semester has been already created!\n";
            system("pause");
            
            int move;
            cout << "Do you want to continue creating semester ?";
            cout << "\n1. Yes";
            cout << "\n2.No\n";
            cout << "Enter your move: ";
            cin >> move;

            if (move == 1)
                return createSemester(username, curSY);
            else
                return;
        }
    

    string start, end;
    cout << "Enter the start date: ";
    cin >> start;
    cout << "Enter the end date: ";
    cin >> end;

    ofstream ofs;
    ifstream ifs;
    
    ifs.open(curSY + "//semester.txt");
    ofs.open(curSY + "//tmp.txt");

    if (ifs.is_open()) {
        string tmp;

        while (getline(ifs, tmp)) 
            ofs << tmp << endl;
    }
    
    ofs << season;

    ifs.close();
    ofs.close();

    remove((curSY + "//semester.txt").c_str());
    rename((curSY + "//tmp.txt").c_str() ,(curSY + "//semester.txt").c_str());

    ofs.open(path + "//" + "infor.txt");
    ofs << season << " " << start << " " << end << endl;
    ofs.close();

}