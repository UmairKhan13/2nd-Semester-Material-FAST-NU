// QUESTION 1
#include <iostream>
using namespace std;

class Address {
	string name;
	string address;
	string city;
	string state;
	string zip;
	
public:
	Address() {}
	Address(string name, string address, string city, string state, string zip) :
		name (name),
		address(address),
		city(city),
		state(state),
		zip(zip)
 	{}
};

class Package {
	const Address sender; // encapsulated the data members into Address class
	const Address recipient;
	double weight, cost;
	
public:
	Package () : sender(), recipient() {}
	Package (
		string sName,
		string sAddress,
		string sCity,
		string sState,
		string sZip,
		string rName,
		string rAddress,
		string rCity,
		string rState,
		string rZip,
		double weight,
		double cost) :
			sender (sName, sAddress, sCity, sState, sZip),
			recipient(rName, rAddress, rCity, rState, rZip),
			weight(weight < 0 ? 0 : weight), // input validation
			cost(cost < 0 ? 0 : cost) // input validation
		{}
		
	virtual double calculateCost() { return weight * cost; }
	
	double getWeight() const { return this -> weight; }
};

class TwoDayPackage : public Package {
	double flatFee;
	
public:
	TwoDayPackage() {}
	TwoDayPackage (
		string sName,
		string sAddress,
		string sCity,
		string sState,
		string sZip,
		string rName,
		string rAddress,
		string rCity,
		string rState,
		string rZip,
		double weight,
		double cost,
		double flatFee) :
			Package (sName, sAddress, sCity, sState, sZip, 
					rName, rAddress, rCity, rState, rZip, 
					weight, cost),
			flatFee(flatFee)
		{}
		
	double calculateCost() {
		return Package::calculateCost() + flatFee;
	}
};

class OvernightPackage : public Package {
	double feePerOunce;
	
public:
	OvernightPackage() {}
	OvernightPackage (
		string sName,
		string sAddress,
		string sCity,
		string sState,
		string sZip,
		string rName,
		string rAddress,
		string rCity,
		string rState,
		string rZip,
		double weight,
		double cost,
		double feePerOunce) :
			Package (sName, sAddress, sCity, sState, sZip, 
					rName, rAddress, rCity, rState, rZip, 
					weight, cost),
			feePerOunce(feePerOunce)
		{}
		
	double calculateCost() {
		return Package::calculateCost() + Package::getWeight() * feePerOunce;
	}
};

int main() {
	Package p("Aneeb", "16 Almayo Crescent", "Toronto", "ON", "M9V2L4",
			  "Umair", "Street #9 North Naizmabad", "Karachi", "Sindh", "L396X2",
			  2.5, 25.15
			  );
	TwoDayPackage tdp("Maaz", "12 Brownridge Crescent", "Toronto", "ON", "M9V4M5",
			  "Burney", "Gulshan Chowrangi", "Karachi", "Sindh", "N8J7A0",
			  3.75, 25.15, 20
			  );
	OvernightPackage op("Ansari", "140 Wendell Avenue", "Toronto", "ON", "M9V8X2",
			  "Sir Zain", "FAST NUCES", "Karachi", "Sindh", "J9A7J1",
			  1.25, 25.15, 7.5
			  );
	cout << p.calculateCost() << endl;
	cout << tdp.calculateCost() << endl;
	cout << op.calculateCost() << endl;
	
}
