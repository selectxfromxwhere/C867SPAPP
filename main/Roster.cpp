#include "Roster.h"


/*create student objects using constructor to populate roster array*/
void Roster::add(
	string studentID, 
	string fName, 
	string lName, 
	string email, 
	int age, 
	double day1, 
	double day2, 
	double day3, 
	DegreeType degreeType) 
{
	/*add method does not ask for array but constructor does, create array to hold days in course*/
	double dayArray[3] = { day1, day2, day3 }; 
	studentRosterArray[++lastIndex] = new Student(studentID, fName, lName, email, age, dayArray, degreeType);
}

/*print method - all students displayed on screen*/
void Roster::printAll() 
{
	for (int i = 0; i <= Roster::lastIndex; i++) 
	{
		if (studentRosterArray[i] != nullptr)
		{
			studentRosterArray[i]->print();
		}
	}
}

/*print students that match specified degree type*/
void Roster::printByDegreeType(DegreeType degreeType) 
{
	for (int i = 0; i <= Roster::lastIndex; i++) 
	{
		if (Roster::studentRosterArray[i]->getdegreeType() == degreeType)
		{
			studentRosterArray[i]->print();
		}
	}
	cout << std::endl;
}

/*print invalid email addresses*/
void Roster::printByInvalidEmails() 
{
	bool invalidEmail = false;
	for (int i = 0; i <= Roster::lastIndex; i++) 
	{
		string studentEmail = (studentRosterArray[i]->getEmail());

		if (studentEmail.find('@') == string::npos || (studentEmail.find('.') == string::npos || (studentEmail.find(' ') != string::npos))) 
		{

			invalidEmail = true;
			cout << studentEmail << ": " << studentRosterArray[i]->getID() << std::endl;
		}
	}
	
	if (!invalidEmail) cout << "No invalid emails found." << std::endl;
}

/*print student's average days in course*/
void Roster::printAverageDaysInCourse(string studentID) 
{
	for (int i = 0; i <= Roster::lastIndex; i++)
	{
		if (studentRosterArray[i]->getID() == studentID) {

			cout << studentRosterArray[i]->getID() << ": ";
			cout << (studentRosterArray[i]->getDays()[0]
				+ studentRosterArray[i]->getDays()[1]
				+ studentRosterArray[i]->getDays()[2]) / 3.0 << std::endl;
		}
	} cout << std::endl;
}

/*remove specified student from roster*/
void Roster::removeByID(string studentID) 
{
	
	bool IDfound = false;
	for (int i = 0; i < Roster::lastIndex; i++)
	{

		if (studentRosterArray[i] != nullptr && studentRosterArray[i]->getID() == studentID)
		{
			studentRosterArray[i] = nullptr;
			IDfound = true;
			cout << "Student " << studentID << " deleted." << std::endl;
			/*Roster::lastIndex--;*/
			break;
		}
	}
		
	if (IDfound == false)
	{
		cout << "Error: student " << studentID << " not found in roster." << std::endl; 
	}
	
}

/*destructor*/
Roster::~Roster() 
{
	cout << "DESTRUCTOR HAS BEEN CALLED..." << std::endl << std::endl;
	for (int i = 0; i < numStudents; i++) 
	{
		cout << "Destroying student: " << i + 1 << std::endl;
		delete studentRosterArray[i];
		studentRosterArray[i] = nullptr;
	}
}