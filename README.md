# gittest2

My test repository on GitHub

I love :coffee: :pizza:, and :dancer:.
탬플릿(Template)
	function template:
	
```c++
int Add(int a, int b)
{
	return a+b;
}

template <typename T>
T Add(T a, T b)
{
	return a+b;
}

class template:
class Data
{
	T data;
public:
	Data (T d) {data=d;}
	void SetData(T d)
	{ data = d; }
	T GetData() {
	return data;
	}
}
```
- Template instanciation : 사용할 당시에 객체/함수를 생성
- function이나 class를 정의할 때 특정 data type 을 사용하는 대신 generic type을 사용할 수 있다.
- function template나 class template는 여러 가지 data type에 대해서 function 정의나 class 정의를 생성할 수 있다.	
-	template는 처리 algorithm은 동일하고 처리할 값의 data type이 다양할 때 유용하게 사용할 수 있다.
	
#Class template의 정의

```c++
template <typename generic_type_name, ...> class class_name
{
	//Member func, var
};
```
	
* class tmeplate의 멤버 function의 정의

```C++
template <typename generic_type_name, ...>
ReturnType ClassTemplateName<parameter>::MemberFunctionName(argument list)
{
	//implement
}
```
	
	E.g. Stack Class
	
```C++
	template <typename T=int, int sz=0>
	class Stack
	{
	protected:
		int m_size;
		int m_top;
		T * m_buffer;
	public:
		Stack(int size=sz)
		{
			m_size = size;
			m_top = -1;
			m_buffer = new T[m_size];
		}
		~Stack()
		{...}
		Stack(const Stack & s)
		{...}
		bool Push( T value ){...}
		bool Pop(T& value) {...}
		etc.
	}
```
	
	Class Template의 instantiation
	명시적으로 template의 parameter를 지정해야 한다.
	객체를 생성할 때 template의 parameter 지정
```C++
		Stack<int> s1(10);
		Stack<string> s2(5);
		Stack<double, 10> s3;
```
	객체를 생성하지는 않지만 객체에 대한 포인터나 레퍼런스를 정의하면서 template의 parameter 지정
```C++
		Stack<char, 10> *pStack = NULL;
```
	typedef 문으로 class template의 별명을 지정하면서 template의 parameter 지정
```C++
		typedef Stack<Point> PointStack;
		PointStack s4(20);
```

	Template의 우수성
		
#STL(Standard Template Library)
- 표준 C++이 제공하는 template 기반 라이브러리
-	STL container와 STL algorithm으로 구성된다.
-	STL container
	-	일종의 컬렉션 class
		-	같은 종류의 데이터의 모임
		-	같은 data type 의 데이터를 저장하고 읽어오기 위한 자료 구조 클래스
	-	일반적으로 많이 사용하는 vector, list, stack, etc
-	STL algorithm
	-	자주 사용하는 유용한 algorithm을 function template으로 정의
	-	프로그램 개발 시 많이 사용되는 copy, sort, search, etc
			
#STL Container의 종류
1. 순차 container(sequence container)
	- 데이터를 순차적으로 저장하는 가장 일반적인 container
	- 삽입된 데이터를 저장할 때 별도의 제약을 갖지 않음
	- 시퀀스 contianer의 임의의 위치에 원소를 삽입/삭제 가능
	- vector, list, queue
2. 연관 container(associative container)
	- 데이터를 무조건 저장하는 것이 아닌 뭐시가저시기
		
#iterator class
- STL container는 공통적으로 iterator class를 제공한다.
	- iterator 는 반복자라고도 하는데, STL container의 원소에 접근하는 포인터와 비슷한 역할을 제공
	- STL container의 특정 원소를 가리키며 ++ 연산자를 이용해서 다음 원소를 가리킬 수 도 있고, * 연산자를 이용해서 특정 원소에 접근할 수도 있다.
- STL container는 공통적으로 첫 번째 원소를 가리키는 iterator를 리턴하는 begin function과 마지막 원소를 가리키는 iterator를 리턴하는 end function을 제공

example:

```c++
list<Shape*>::iterator it;
for(it=list1.begin(); it!=list1.end();++it)
	( *it )->draw();
```

#STL algorithm
- STL이 제공하는 algorithm
- STL algorithm 사용 예
'''C++
int arr[10] = {90, 432,3,3,4 , 44, 4,2,5, 34, 5,23};

#Generic Programming
- Data가 보관되는 형식과 data를 처리하는 algorithm을 분리하여 서로 **독립적으로** **관리**할 수 있는 프로그래밍 방식
- Generic Programming 에서는 데이터가 보관되는 형식과 관계없이 동일한 방법으로 처리할 수 있는 algorithm을 구현하는 것이 목표
- Generic Programming의 장점
	- 데이터의 형식과 데이터의 처리 algorithm을 분리함으로써 확장성을 가질 수 있다.
