// Question 2
#include <iostream>
using namespace std;

class Supervisor {
	string name;
	string area;
public:
	Supervisor () {}
	Supervisor (string name) :
		name(name),
		area("")
	{}
	string getArea() { return this -> area; }
	void setArea(string area) { this -> area = area; }
	string getName() { return this -> name; }
};

class Project {
	Supervisor *supervisor;
	int projID;
	
public:
	int juryMarks, supervisorMarks, totalMarks;
	static int projCount;
	Project(int projID, int juryMarks, int supervisorMarks) :
		projID(projID),
		juryMarks(juryMarks),
		supervisorMarks(supervisorMarks)
	{ projCount++; }
	void setSupervisor (Supervisor *s) { supervisor = s; }
	virtual int getMarks() { 
		cout << juryMarks + supervisorMarks;
	}
};

class CSProject : public Project {
public:
	CSProject(int projID, int juryMarks, int supervisorMarks, Supervisor &s) :
		Project(projID, 
			juryMarks > 60 ? 60 : juryMarks, //input validation
			supervisorMarks > 40 ? 40 : supervisorMarks) { 
			totalMarks = juryMarks + supervisorMarks;
			if (s.getArea() == "") s.setArea("CS");
			if (s.getArea() == "EE") {
				cout << s.getName() << " is already assigned to EE projects!" << endl;
			}
			setSupervisor(&s);
		}
		
	int getMarks() {
		cout << totalMarks << "/100 ";
		if (totalMarks < 50)
			cout << "You failed!" << endl;
		else cout << "You passed!" << endl;
	}
};

class EEProject : public Project {
public:
	EEProject(int projID, int juryMarks, int supervisorMarks, Supervisor &s) :
		Project(projID,
			juryMarks > 95 ? 95 : juryMarks, 
			supervisorMarks > 25 ? 25 : supervisorMarks) { 
			totalMarks = juryMarks + supervisorMarks;
			if (s.getArea() == "") s.setArea("EE");
			if (s.getArea() == "CS") {
				cout << s.getName() << " is already assigned to CS projects!" << endl;
				return;
			}
			setSupervisor(&s);
		}
	int getMarks() {
		cout << totalMarks << "/120 ";
		if (((float)totalMarks / 120 * 100) < 50)
			cout << "You failed!" << endl;
		else cout << "You passed!" << endl;
	}
};

int Project::projCount = 0;

int main() {
	Supervisor cs("Sir Shahzad"), ee("Sir Zain");
	CSProject p1(1234, 40, 30, cs);
	EEProject p2(1251, 78, 17, ee);
	CSProject p3(3124, 31, 26, ee); // will print error
	EEProject p4(3124, 31, 26, ee); // will work because Sir Zain can take multiple EE projects
	p1.getMarks();
	p2.getMarks();
	p4.getMarks();
}
