// QUESTION 1 : HOSPITAL MANAGEMENT SYSTEM

#include <iostream>

using namespace std;

int staffIndex = 0;
int bedIndex = 0;
int doctorIndex = 0;
int patientIndex = 0;

class Bed {
	string ward;
	int number;
	bool occupied;
public:
	friend class Patient;
	Bed() {}
	Bed (string ward, int number, bool occupied)
		: ward(ward)
		, number(number)
		, occupied(occupied)
	{}
	void report() const {
		cout << "Ward name: " << ward << endl;
		cout << "Bed number: " << number << endl;
		cout << "Occupied: " << occupied << endl;
	}
} beds[100];

class Employee {
	string name;
public:
	friend class Patient;
	
	Employee()
	{}
	Employee(string name)
		: name(name)
	{}
};

class Doctor : public Employee {
	string username, password;
public:
	Doctor()
	{}
	Doctor(string name) :
		Employee(name)
	{}
	void setUsername(string user) { username = user; }
	void setPassword(string pass) { password = pass; }
} doctors[100];

class Patient {
	bool deleted = false;
	int id;
	string name;
	Doctor *d;
	Bed *b;
public:
	Patient()
	{}
	Patient(string name)
		: name(name)
	{}
	Patient(string name, int id, Doctor *d, Bed *b)
		: name(name)
		, id(id)
		, d(d)
		, b(b)
	{}
	void report() const {
		if (deleted) {
			cout << "Patient deleted" << endl;
			return;
		}
		cout << "Patient ID: " << id << endl;
		cout << "Patient name: " << name << endl;
		cout << "Ward name: " << b -> ward << endl;
		cout << "Bed number: " << b -> number << endl;
		cout << "Doctor name: " << d -> name << endl;
	}
	void remove() {
		id = 0;
		deleted = true;
	}
	void setDoctor(Doctor *d) {
		this -> d = d;
	}
	void setID(int ID) { this -> id = id; }
	string getName() const { return this -> name; }
} patients[100];



class Staff : public Employee {
	
public:
	Staff()
	{}
	Staff(string name)
		: Employee(name)
	{}
	void addPatient(string name) {
		patients[patientIndex] = {name};
		cout << "Patient " << name << " added at index: " << patientIndex << endl;
		patientIndex++;
	}
	void addDoctor(string name) {
		doctors[doctorIndex] = {name};
		cout << "Doctor " << name << " added at index: " << doctorIndex << endl;
		doctorIndex++;
	};
	void assignID(Patient &p, int id) {
		p.setID(id);
		cout << "Assigned ID #" << id << " to patient " << p.getName() << endl;
	}
	void assignLoginCredentials(Doctor &d, string user, string pass) {
		d.setUsername(user);
		d.setPassword(pass);
		cout << "Assigned username and password" << endl;
	}
	void assignDoctor(Patient &p, Doctor &d) {
		p.setDoctor(&d);
	}
	void deletePatient(Patient &p) { p.remove();}
	void addBed(string ward, int number, bool occupied) {
		beds[bedIndex] = {ward, number, occupied};
		bedIndex++;
		cout << "Bed added" << endl;
	}
} staff[100];

class Admin : public Employee {
	
public:
	
	void addStaff(string name) {
		staff[staffIndex] = {name};
		cout << "Staff " << name << " added at index: " << staffIndex << endl;
		staffIndex++;
	}
};

int main() {
	Admin a;
	
	a.addStaff("Efshal"); // Registration requirement 3
	Staff Efshal = staff[0]; // can add multiple staffs with unique indices
	
	Efshal.addPatient("Areeb"); // Registration requirement 1
	Patient dheeraj = patients[0]; // can add multiple patients with unique indices
		
	Efshal.addDoctor("Zain"); // Registration requirement 2
	
	Efshal.assignID(dheeraj, 1337); // Registration requirement 4
	
	Doctor SirZain("Sir Zain");
	Efshal.assignLoginCredentials(SirZain, "zain", "fast1234"); // Registration requirement 5
	
	Efshal.assignDoctor(dheeraj, SirZain); // Check In requirement 1
	// can assign multiple doctors with unique indices
	
	Efshal.deletePatient(dheeraj); // Check In requirement 2
	
	Efshal.addBed("East Wing Ward", 12, true); // Check In Requirement 3
	// can add multiple beds with unique indices
	
	cout << endl << "Reports: " << endl;
	
	Patient p("Umair", 100, &SirZain, &beds[0]);
	p.report(); // Reports Requirement 1
	
	cout << endl;
	
	beds[0].report(); // Reports Requirement 2
}


