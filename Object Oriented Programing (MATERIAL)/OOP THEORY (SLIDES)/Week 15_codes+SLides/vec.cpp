#include <iostream>
#include <vector>               
using namespace std;
 
int main() {
   vector<int> vec; 
   int i;
   cout << "vector size = " << vec.size() << endl;
  for(i = 0; i < 5; i++) {
      vec.push_back(i);
   }
   cout << "extended vector size = " << vec.size() << endl;

   // access 5 values from the vector
   for(i = 0; i < 5; i++) {
      cout << "value of vec [" << i << "] = " << vec[i] << endl;
   }
vec.pop_back();
cout<< "extended vector size = " << vec.size() << endl;

   // use iterator to access the values
   vector<int>::iterator v = vec.begin();
   while( v != vec.end()) {
      cout << "value of v = " << *v << endl;
      v++;
   }

//   return 0;
}
