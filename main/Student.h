#pragma once
#include <iostream>
#include <iomanip>
#include "Degreetype.h">

using std::string;
using std::cout;

class Student
{
public:
	const static int dayArraySize = 3;

	/*parameterless student object constructor*/
	Student();

	/*student object constructor*/
	Student(string studentID, string fName, string lName, string email, int age, double days[], DegreeType degreeType);
	
	/*student destructor*/
	~Student();

	/*getters/accessors*/
	string getID();
	string getfName();
	string getlName();
	string getEmail();
	int getAge();
	double* getDays();
	DegreeType getdegreeType();

	/*setters/mutators*/
	void setID(string ID);
	void setfName(string fName);
	void setlName(string lName);
	void setEmail(string email);
	void setAge(int age);
	void setDays(double days[]);
	void setDegreeType(DegreeType degreeType);

	/*print this student's specific data*/
	void print(); 



private:
	string studentID;
	string fName;
	string lName;
	string email;
	int age;
	double days[dayArraySize];
	DegreeType degreeType;
};

