# Low Level I/O
* High Speed
#High level I/O
* Formatted I/O
* Bytes are grouped into meaningful unit
# Portion of I/O class Hierarchy
```
				ios
	/					\
istream				ostream
	/		\		/		\
ifstream	iostream	ofstream
				I
			fstream
```
* 크게 그림을 그려라!

# Class ios_base
* I/O stream
	* a sequence of bytes
* direct or indirect base class for all stanard I/O class
```c++
ios_base::fmtflags old_flags = 
	cout.flags(ios_base::left
					| ios_base::hex
					| ios_base::showpoint
					| ios_base::uppercase
					|	ios_base::fixed );
```

# Operator Overloading
* operator void*() const;
* bool operator!() const;
* etc

# Class istream
* derived from basic_ios
* Methods for input operations
	* read, get, getline, peek, ...

# Class ostream

# Class istream

# Class Manipulators
* Manipulator
* a function that either directly or indirectly modifies a stream
* Manipulator without arguments
	* endl

# File I/O classes
* File I/O
* ofstream