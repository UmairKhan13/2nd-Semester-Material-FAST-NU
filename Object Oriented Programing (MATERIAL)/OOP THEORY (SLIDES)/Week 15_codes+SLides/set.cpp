#include <iostream> 
#include <set> 
#include <iterator> 
  
using namespace std; 
  
int main() 
{ 
    // empty set container 
    set <int,  <int> > gquiz1;         
  
    // insert elements in random order 
    gquiz1.insert(40); 
    gquiz1.insert(30); 
    gquiz1.insert(10); 
    gquiz1.insert(30); 
    
  
    // printing set gquiz1 
    set <int, greater <int> > :: iterator itr; 
    cout << "\nThe set gquiz1 is : "; 
    for (itr = gquiz1.begin(); itr != gquiz1.end(); ++itr) 
    { 
        cout << '\t' << *itr; 
    } 
    cout << endl; 
  
   
  
     
    // remove element with value 50 in gquiz2 
    int num; 
    num = gquiz1.erase (10); 
    cout << "\ngquiz2.erase(10) : "; 
    cout << num << " removed " ; 
    for (itr = gquiz1.begin(); itr != gquiz1.end(); ++itr) 
    { 
        cout << '\t' << *itr; 
    } 
  
    cout << endl; 
    
  
    return 0; 
  
} 
