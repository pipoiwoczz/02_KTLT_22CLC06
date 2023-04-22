#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include "createStudentAcc.h"

void createStudentAccount(Student * pHeadStudent) {
    string folder = "User\\", filename = "";
    ofstream ofs;
    int ID = pHeadStudent -> studentId;
    char strID[33];
    _itoa(ID, strID, 15);
    while (pHeadStudent != nullptr) {
        filename = folder + string(strID) + ".txt";
        ofs.open(filename);

        ofs << ID << endl;
        ofs << "123" << endl;
        ofs << ID << endl;
        ofs << pHeadStudent -> firstName << endl;
        ofs << pHeadStudent -> lastName << endl;
        ofs << pHeadStudent -> gender << endl;
        ofs << pHeadStudent -> dateOfBirth << endl;
        ofs << pHeadStudent -> socialId << endl;

        ofs.close();

        pHeadStudent = pHeadStudent -> next;
    }
}