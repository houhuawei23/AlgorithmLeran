e in vector?
```cpp
std::vector<int> v = {1, 2, 3};
int key = 6;

std::count(v.begin(), v.end(), key); // return count
std::find(v.begin(), v.end(), key) != v.end(); // return iter

std::find_if(v.begin(), v.end(), [](auto e){ return e == 5;})
```

vector copy:

```cpp
// Initializing vector with values  
vector<int> vect1{1, 2, 3, 4};  

// Declaring new vector  
vector<int> vect2;  

// Using assignment operator to copy one vector to other  
vect2 = vect1;  

// Declaring new vector and copying element of old vector  
// constructor method, Deep copy  
vector<int> vect2(vect1);  

#include<algorithm> // for copy() and assign()  
#include<iterator> // for back_inserter  

// Copying vector by copy function  
copy(vect1.begin(), vect1.end(), back_inserter(vect2));  

// Copying vector by assign function  
vect2.assign(vect1.begin(), vect1.end());  
```