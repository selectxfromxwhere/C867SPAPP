#include "Student.h"

/*parameterless student constructor*/
Student::Student() 
{
	this->studentID = "";
	this->fName = "";
	this->lName = "";
	this->email = "";
	this->age = 0;
	for (int i = 0; i < dayArraySize; i++) this->days[i] = 0;
	this->degreeType = DegreeType::UNKNOWN;
}

/*full student constructor*/
Student::Student(string studentID, string fName, string lName, string email, int age, double days[], DegreeType degreeType)
{
	this->studentID = studentID;
	this->fName = fName;
	this->lName = lName;
	this->email = email;
	this->age = age;
	for (int i = 0; i < dayArraySize; i++) this->days[i] = days[i];
	this->degreeType = degreeType;
}

/*student getters/accessors*/
string Student::getID() { return this->studentID; }
string Student::getfName() { return this->fName; }
string Student::getlName() { return this->lName; }
string Student::getEmail() { return this->email; }
int Student::getAge() { return this->age; }
double* Student::getDays() { return this->days; }
DegreeType Student::getdegreeType() { return this->degreeType; }

/*student setters/mutators*/
void Student::setID(string studentID) { this->studentID = studentID; }
void Student::setfName(string fName) { this->fName = fName; }
void Student::setlName(string lName) { this->lName = lName; }
void Student::setEmail(string email) { this->email = email; }
void Student::setAge(int age) { this->age = age; }
void Student::setDays(double days[]) {
	/*iterate through days in course array, setting each day to an index*/
	for (int i = 0; i < dayArraySize; i++) this->days[i] = days[i];
}
void Student::setDegreeType(DegreeType degreeType) { this->degreeType = degreeType; }

/*print student's details*/
void Student::print() {
	cout << this->getID() << '\t';
	cout << this->getfName() << '\t';
	cout << this->getlName() << '\t';
	cout << this->getEmail() << '\t';
	cout << this->getAge() << '\t';
	cout << this->getDays()[0] << ', ';
	cout << this->getDays()[1] << ', ';
	cout << this->getDays()[2] << '\t';
	cout << degreeTypeStrings[this->getdegreeType()] << '\n';
}

/*student destructor*/
Student::~Student() {};
