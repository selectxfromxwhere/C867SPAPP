#pragma once
#include "Student.h"

class Roster
{
public:
	int lastIndex = -1;
	const static int numStudents = 5;

	/*creating array of pointers to hold students*/
	Student* studentRosterArray[numStudents] = { };

	/*setter, student data pass into add method to create student objects*/
	void add(string studentID, string fName, string lName, string email, int age, double day1, double day2, double day3, DegreeType degreeType);
	
	/*print functions for roster*/
	void printAll();
	void printByDegreeType(DegreeType degreeType);
	void printByInvalidEmails();
	void printAverageDaysInCourse(string studentID);
	void removeByID(string studentID);

	/*destructor*/
	~Roster();
};
