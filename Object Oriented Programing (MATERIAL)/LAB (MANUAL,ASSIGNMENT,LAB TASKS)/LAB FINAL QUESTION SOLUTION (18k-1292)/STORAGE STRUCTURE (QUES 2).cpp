// QUES 2: STORAGE STRUCTURE

#include <iostream>

using namespace std;

template<typename T>
class StorageStructure {
	T list[100], *head, *tail;
	int size;
public:
	StorageStructure(T initial) : size(1) {
		head = &list[0];
		tail = &list[0];
		list[0] = initial;
	}
	
	void sing() {
		for (int i = size; i > 0; i--)
			cout << list[i - 1] << endl;
		cout << "HEAD: " << *head << endl;
		cout << "TAIL: " << *tail << endl;
	}
	
	void insert(T toInsert) {
		tail++;
		for (int i = size; i > 0; i--)
			list[i] = list[i - 1];
		list[0] = toInsert;
		size++;
	}
	
	int read() {
	    T toFind;
	    cout << "ENTER VALUE TO SEARCH = ";
	    cin >> toFind;
		for (int i = 0; i < size; i++)
			if (list[i] == toFind) 
            {
            cout<< endl<<toFind<<" found at position =  "<<i+1<<endl;
			break;
		    }
	}
	
		
	void split() {
		int half = size % 2 ? (size - 1) / 2 : size / 2;
		StorageStructure<int> first(list[0]);
		StorageStructure<int> second(list[half]);
		for (int i = 1; i < half; i++) {
			first.insert(list[i]);
		}
		for (int i = half + 1; i < size; i++) {
			second.insert(list[i]);
		}
		// printing splits to confirm output:
		first.sing();
		cout << endl;
		second.sing();
	}
};

int main() {
	StorageStructure<int> list(1);
	list.insert(2);
	list.insert(3);
	list.insert(4);
	list.insert(5);
	list.insert(6);
	list.insert(7);
	list.insert(8);
	list.split();
	list.read();
}
