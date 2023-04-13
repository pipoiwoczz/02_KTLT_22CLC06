#include "main.h"
#include "updateGPA.h"

struct Score {
    string No, studentID, fullName, totalMark, finalMark, midtermMark, otherMark;
    Score* next = nullptr;
};

void updateStudentResultCourse(string curSY, int season, string courseID);
void exportFileInfoToLL(Score* &head, string path);
void deleteLLScore(Score* &head);
void reverseList(Score* &pHead);