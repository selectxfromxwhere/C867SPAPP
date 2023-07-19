#include <iostream>
#include<sstream>
#include "Roster.h"

using namespace std;


int main()
{
    /*personal output information*/
    cout << "Scripting and Programming - Applications C867, C++, 010764049, Jessica Borsellino" << std::endl << std::endl << std::endl;

    /*program input data for students*/
    const string studentData[] =

    {
        /*student data strings*/
        "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
        "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
        "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
        "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
        "A5,Jes,Borsellino,jesborsellino@gmail.com,31,30,35,40,SOFTWARE",

    };

    const int numStudents = 5;
    
    /*create an instance of roster called classRoster*/
    Roster classRoster;

    for (int i = 0; i < sizeof(studentData) / sizeof(studentData[i]); i++) {
        string input = studentData[i];
        istringstream ss(input);
        string token;
        string InputData[9];

        int j = 0;
        while (getline(ss, token, ',')) {
            InputData[j] = token;
            j += 1;
        }

        DegreeType degreeType = UNKNOWN;

        if (InputData[8] == "SECURITY") {
            degreeType = SECURITY;
        }

        else if (InputData[8] == "NETWORK") {
            degreeType = NETWORK;
        }

        else if (InputData[8] == "SOFTWARE") {
            degreeType = SOFTWARE;
        }

        classRoster.add(InputData[0], InputData[1], InputData[2], InputData[3], std::stoi(InputData[4]), std::stod(InputData[5]), std::stod(InputData[6]), std::stod(InputData[7]), degreeType);
    }
    
    cout << "DISPLAYING ALL STUDENTS IN CLASS ROSTER:" << std::endl;
    classRoster.printAll();  
    cout << std::endl << std::endl;

    cout << "DISPLAYING STUDENTS WITH INVALID EMAIL ADDRESSES:" << std::endl;
    classRoster.printByInvalidEmails();
    cout << std::endl << std::endl;

    cout << "DISPLAYING AVERAGE DAYS IN COURSE FOR STUDENTS:" << std::endl;
    for (int i = 0; i < numStudents; i++) {
        classRoster.printAverageDaysInCourse(classRoster.studentRosterArray[i]->getID());
    }
    cout << std::endl;

    cout << "DISPLAYING STUDENTS IN THE SOFTWARE PROGRAM:" << std::endl;
    classRoster.printByDegreeType(SOFTWARE);
    cout << std::endl;

    cout << "REMOVING STUDENT A3:" << std::endl;
    classRoster.removeByID("A3");
    cout << std::endl << std::endl;

    cout << "DISPLAYING REMAINING STUDENTS IN CLASS ROSTER:" << std::endl;
    classRoster.printAll();
    cout << std::endl << std::endl;

    cout << "ATTEMPTING TO REMOVE STUDENT A3 ONCE MORE:" << std::endl;
    classRoster.removeByID("A3");
    cout << std::endl << std::endl;
    
    return 0;
}
