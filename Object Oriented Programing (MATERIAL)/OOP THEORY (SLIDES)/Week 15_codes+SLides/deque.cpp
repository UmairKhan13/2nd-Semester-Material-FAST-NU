#include <iostream> 
#include <deque> 
  
using namespace std; 
  
void showdq(deque <int> g) 
{ 
    deque <int> :: iterator it; 
    for (it = g.begin(); it != g.end(); ++it) 
        cout << '\t' << *it; 
    cout << '\n'; 
} 
  
int main() 
{ 
    deque <int> dq; 
    dq.push_back(10); 
    dq.push_front(20); 
    dq.push_back(30); 
    dq.push_front(15); 
    cout << "The deque dq is : "; 
    showdq(dq); 
  
    cout << "\ndeque.size() : " << dq.size(); 
    cout << "\ndeque.max_size() : " << dq.max_size(); 
  
    cout << "\ndeque.at(2) : " << dq.at(2); 
    cout << "\ndeque.front() : " << dq.front(); 
    cout << "\ndeque.back() : " << dq.back(); 
  
    cout << "\ndeque.pop_front() : "; 
    dq.pop_front(); 
    showdq(dq); 
  
    cout << "\ndeque.pop_back() : "; 
    dq.pop_back(); 
    showdq(dq); 
   // dq.erase(10);
    //showdq(dq);
  
    return 0; 
} 
