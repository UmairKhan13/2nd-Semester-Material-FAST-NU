#include <iostream>
#include <string.h>

using namespace std;

int main() {
	char types[8][4] = {"O-", "O+", "A-", "A+", "B-", "B+", "AB-", "AB+"};
	int compatibility[8][8] = {
		{1, 0, 0, 0, 0, 0, 0, 0},
		{1, 1, 0 ,0, 0, 0, 0, 0},
		{1, 0, 1, 0, 0, 0, 0, 0},
		{1, 1, 1, 1, 0, 0, 0, 0},
		{1, 0, 0, 0, 1, 0, 0, 0},
		{1, 1, 0, 0, 1, 1, 0, 0},
		{1, 0, 1, 0, 1, 0, 1, 0},
		{1, 1, 1, 1, 1, 1, 1, 1}	
	};
	char c;
	bool found;
	string type;
	int index;
	do {
		cout << "Enter blood type (case-sensitive): ";
		cin >> type;
		for (int i = 0; i < 8; i++) {
			if (!strcmp(types[i], type.data())) {
				found = true;
				index = i;
				break;
			}
		} 
		if (!found) cout << "Invalid blood type!" << endl;
		else {
			cout << "Can receive from: ";
			for (int i = 0; i < 8; i++) {
				if (compatibility[index][i] == 1) {
					cout << types[i] << ", ";
				}
			} cout << endl;
			cout << "Can donate to: ";
			for (int i = 0; i < 8; i++) {
				if (compatibility[i][index] == 1) {
					cout << types[i] << ", ";
				}
			} cout << endl;
		}
		cout << "Do you want to continue for another value (y/n)?";
		cin >> c;
	} while (c == 'Y' || c == 'y');
}
