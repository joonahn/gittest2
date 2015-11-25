# Generic Programming

* Paradigm of generic programming
	* Decide which algorithms you want
	* Parameterize them so that they work for a variety of suitable types and data structures
* Example
	* sorting, search
	* array, linked list
	* int, string

# Template basics

```c++
class St {
	int data;
	public:
	St(int a);
	void outs() {
		cout<<data<<endl;
	}
};

St::St(int a) : data(a){}

int main() {
	St S1(5)
	S1.outs();
	return 0;
}
```

ㅎㅇ

```c++
#include <iostream>
template <class T> class St {
	T data;
public:
	St(T a);
	void outs() {cout<<data<<endl;}
}
template <class T> St<T>st(T a) : data(a){}

int main()
{
	St<int> s(5);
	St<float> fs(6.5);
	St(<string> sts("test");
	
	s.outs();
	fs.outs();
	sts.outs();
	
	return 0;
}
```

#Template
* Template can have multiple arguments
#Template Instantiations
* To use a template class, specify a data type in angle brackets

```c++
Array <int> a1(100);
a1[3] = 30;
Array <double> a2(20);
a2[0] = 3.14;
Array <string> a3(40);
a3[30] = "test";
cout<<""<<endl;
(...)
```
#Template Class in Parameter List
#Function Style Parameters
* Template class can have prarameters that are not class praramenters

```c++
//We can use literal as template parameter
Array <Student, 50> cs232;
Array <int, 100> a1;
```

#Function Templates
* Function overloading
	* similar operations with different data types and (maybe) different logics
* Function template
	* same logic and operation for differrent data types
	* sorting, searching, etc
#Sample Application
* Template stack class

```c++
//김영신 멍청이
#include <iostream>
#include <string>
//#define NDEBUG
#include <cassert>
using namespace std;
template < class T >
class Stack {
public:
	enum { DefaultStack = 50, EmptyStack = -1 };
	//뭐시기저시기
	
}

//Function here

template <class T>
Stack < T > :: push(const T & e) {
	//조건 체크
	assert( !full() );
	if( !full() )
		elements[ ++top ] = e;
	else
		msg( "stack full!" );
}
```

#Standard Template Library
* Standard Template Library (STL)
	* many reusable components
	* defined in the std namespace
* Breif history
	* developed at HP
	* result of research on generic programming
	* accepted as an addition to std c++ in 1995

#Three basic components
* Container
	* an obj that holds another obj
	* vector, stack, deque, list, set, map ...
* Algorithm
	* functions for processing container's elements
	* copy, sort, search, merge, permute, ...
* Iterator
	* mechanism for accesing the objects in a container

#Basic sequential container
* Vector : 사용자가 배열과는 달리 Array의 크기를 신경쓰지 않아도 되는타입

```c++
int main()
{
	vector<int>nums;
	nums.insert(nums.begin(), -999);
	nums.insert(nums.end, 57);
	nums.erase(nums.begin());
	for(i = 0; i< nums.size();i++)
		cout<<nums[i]<<endl;
	return 0;
}
```
* Iterator

```c++
#include <iostream>
#include <string>
#include <list>
void dump(list<string> &m)
{
	list<string>::const_iterator it;
	it = m.begin();
	while(it!=m.end())
	{
		cout<<*it<<endl;
	}
}
```

#Efficiency of vector, deque & list
* [] is overloaded for vectors and deques, but not for lsits
* Efficiency of vectors, deques, and lists are different according to operators

#Basic Associative Containers
* Associative containers
	* set: collection of zero or more non-duplicate unordered elements (keys)
	* map : (key, value) pair
	*multimap : 중복 허용

```c++
#include <map>
int main() {
	map<string, string> m;
	m["afd"] = "CSE";
	m["fajie"] = "CSE";
	...
}
```

#Container Adaptors
* Container Adaptors
	* A container adaptor adapts ....

#Algorithms
* sort 같은거 있음

```c++
sort(it.begin(), it.end(), comp);
```
