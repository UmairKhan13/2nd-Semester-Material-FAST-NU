//============================================================================
// Name        : Vectors.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include <algorithm>
#include <iostream>
#include <vector>
#include <numeric>
using namespace std;


int main() {
	vector <int> v(7,1);
	cout<<"Size:"<<v.size()<<endl;
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(7);
	v.push_back(5);

	vector <int>::const_iterator ptr;
	cout<<"THe capacity:"<<v.capacity()<<endl;
	for(ptr=v.begin();ptr!=v.end();ptr++)
	{
		cout<<*ptr<<" ";
	}
	cout<<endl;
	v[0]=9;
	v.push_back(v[0]);
	v.push_back(v[1]);
	ptr=v.begin();

    //v.insert(ptr+1,4);
    cout<<v.at(2)<<endl;
    for(ptr=v.begin();ptr!=v.end();ptr++)
    	{
    		cout<<*ptr<<" ";
    	}

    cout<<endl;
    //int i=sizeof(v)/sizeof(v[0]);
    sort(v.begin(),v.end());
    ///cout<<v.max_size()<<endl;
    for(ptr=v.begin();ptr!=v.end();ptr++)
        	{
        		cout<<*ptr<<" ";
        	}
    cout<<endl;
    ptr=min_element(v.begin(),v.end());
        cout<<"MIn Element"<<*ptr<<endl;
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	cout<<"Num of 9:"<<count(v.begin(),v.end(),9)<<endl;
    cout<<"Sum of first 4:"<<accumulate(v.begin(),v.begin()+4,0);
	return 0;
}
