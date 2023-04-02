#include "updateGPA.h"

void updateGPA(string ID) {
    ifstream ifs, course, curSem;
    string line, SY, Class, Sem;

    string GPA, thisTermCredit, courseCredit, totalCredit;
    float floatGPA = 0;
    ifs.open("./profile/" + ID + ".txt");
        getline(ifs, line);
        getline(ifs, line);
        getline(ifs, SY);
        getline(ifs, Class);
        getline(ifs, Sem);
    ifs.close();

    line = "./" + SY + "/" + Class + "/" + ID + "/" + Sem + "_" + SY + ".txt";
    ifs.open(line);
        getline(ifs, GPA);
        getline(ifs, thisTermCredit);
        while (!ifs.eof()) {
            getline(ifs, line); // line's value is course's ID now
            // Get the number of credit of a course
            course.open("./" + SY + "/" + Sem + "/" + line + "/info.txt");
                for (int i=0; i<5; i++) getline(course, courseCredit); ///// course
            course.close();

            // Get the infomation of total mark in folder <courseID>.txt
            course.open("./" + SY + "/" + Class + "/" + ID + "/" + line + ".txt");
                getline(course, line, ','); // Total mark
            course.close();
            floatGPA += stof(line) * stoi(courseCredit); // Sum of GPA
        }
        floatGPA /= stoi(thisTermCredit);
    ifs.close();
    
    stringstream ss;
    ss << fixed << setprecision(1) << floatGPA; // round to the first decimal place
    string formattedGPA = ss.str();

    // SAVE DATA TO EXIST FILE OR A NEW FILE?
    ///// WORKING WITH FILE IN C LANGUAGE
    char path[256];
    sprintf(path, "./%s/%s/%s/%s_%s.txt", SY.c_str(), Class.c_str(), ID.c_str(), Sem.c_str(), SY.c_str());
    FILE *file = fopen(path, "r+");
        fputs(formattedGPA.c_str(), file);
    fclose(file);
    // EDIT GPA IN FILE SEMESTER AND FILE TOTAL.TXT

    sprintf(path, "./%s/%s/%s/total.txt", SY.c_str(), Class.c_str(), ID.c_str()); // Combine strings into a path
    ifs.open("./" + SY + "/" + Class + "/" + ID + "/total.txt");

    floatGPA = 0; // RESET FLOATGPA
    if (!ifs.is_open()) cout << "Hi" << endl;
        getline(ifs, line);
        getline(ifs, totalCredit); // total credit of that student
        while (!ifs.eof()) {
            getline(ifs, line); // line = <sem>_<SY>
            curSem.open("./" + SY + "/" + Class + "/" + ID + "/" + line + ".txt");
                getline(curSem, GPA);
                getline(curSem, thisTermCredit);
            curSem.close();
            floatGPA += stof(GPA) * stoi(thisTermCredit);
        }
        floatGPA /= stoi(totalCredit);
    ifs.close();
    
    stringstream anotherGPA;
    anotherGPA << fixed << setprecision(1) << floatGPA; // round to the first decimal place
    formattedGPA = anotherGPA.str();

    file = fopen(path, "r+");
        fputs(formattedGPA.c_str(), file);
    fclose(file);
    
}