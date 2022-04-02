#include <iostream> 
#include <iterator> 
#include <map> 
  
using namespace std; 
  
int main() 
{ 
  
    // empty map container 
    map<int, int> mp; 
  
    // insert elements in random order 
    mp.insert(pair<int, int>(1, 22)); 
    mp.insert(pair<int, int>(2, 30)); 
    mp.insert(pair<int, int>(3, 60)); 
    mp.insert(pair<int, int>(4, 20)); 
    mp.insert(pair<int, int>(5, 50)); 
    mp.insert(pair<int, int>(6, 50)); 
    mp.insert(pair<int, int>(7, 10)); 
  
    // printing map gquiz1 
    map<int, int>::iterator itr; 
    cout << "\nThe map  is : \n"; 
    cout << "\tKEY\tELEMENT\n"; 
    for (itr = mp.begin(); itr != mp.end(); ++itr) { 
        cout << '\t' << itr->first 
             << '\t' << itr->second << '\n'; 
    } 
    cout << endl; 

//     remove all elements up to  element with key=3 in map 
    cout << "\nMap after removal of"
            " elements less than key=3 : \n"; 
    cout << "\tKEY\tELEMENT\n"; 
    mp.erase(mp.begin(), mp.find(3)); 
    for (itr = mp.begin(); itr != mp.end(); ++itr) { 
        cout << '\t' << itr->first 
             << '\t' << itr->second << '\n'; 
    } 
  
//     remove all elements with key = 4 
    int num; 
    num =mp.erase(4); 
    cout << "\nmp.erase(4) : "; 
    cout << num << " removed \n"; 
    cout << "\tKEY\tELEMENT\n"; 
    for (itr = mp.begin(); itr != mp.end(); ++itr) { 
        cout << '\t' << itr->first 
             << '\t' << itr->second << '\n'; 
    } 
  
    cout << endl; 
//  
} 
