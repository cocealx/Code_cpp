//#define _CRT_SECURE_NO_WARNINGS 1
//#include<iostream>
//#include<iomanip>
//#include<string>
//using namespace std;
//class Time 
//{
//public:
//	//无参构造函数
//	Time()
//	{
//		sec = 0;
//		minute = 0;
//		hour = 0;
//	}
//	//带参构造函数 用参数的初始化表对数据成员初始化
//	Time(int h, int m, int s) :sec(s), minute(m), hour(h){}
//	//全缺省参数构造函数,如果有全缺省参数构造函数，则不能重载其他构造函数
//	//Time(int h = 0, int m = 0, int s = 0) :hour(h), minute(m), sec(s){};
//	void set_time();
//	void show_time();
//private:
//	int sec;
//	int minute;
//	int hour;
//};
//void Time::set_time()
//{
//	cout << "输入时间" << endl;
//	cin >> hour >> minute >> sec;
//}
//void Time::show_time()
//{
//	cout << hour << ":" << minute << ":" << sec << endl;
//}
//class  Student
//{
//private:
//	char name[20];
//	int number;
//	float score;
//public:
//	
//	Student(char na[], int num, float sc) :number(num), score(sc){ strcpy(name, na); }
//	Student()
//	{
//		strcpy(name, "0");
//		number = 0;
//		score = 0.0f;
//	}
//	void show();
//};
//void Student::show()
//{
//	
//	cout << name << setw(6) << number << setw(6) << score << endl;
//}
//int main()
//{
//	//Time time1, time2{11,59,59};
//	////time1.set_time();
//	//time1.show_time();	
//	//time2.show_time();
//	//Student stu1, stu2{ "xiaowang", 25, 89.5 };
//	//stu1.show();
//	//stu2.show();
//	////引用练习
//	int arr[2] = { 0 };
//	int(&arr1)[2] = arr;
//	arr1[0] = 1;
//	arr1[1] = 2;
//	getchar();
//	return 0;
//}								
////总结：1.一个类可以有多个构造函数，但只能有一个默认构造函数
////2.一个类如果定义全缺省参数的构造函数，则不能再重载构造函数
////3.当数据成员有数组时，不能在参数初始化表中对其初始化
//#include<iostream>
//class Base
//{
//public:
///*	Base(int a0) :_a0(a0)
//	{
//
//	}*/
//	int _a0;
//private:
//
//};
//class B1 :virtual public Base
//{
//public:
//	int _a1;
//};
//class B2 :virtual public Base
//{
//public:
//	int _a2;
//};
//class Derive :public B1,public B2
//{
//public:
//	Derive()
//	{
//		std::cout<<1<<std::endl;
//	}
//	int _a4;
//private:
//	
//};
//int main()
//{
//	Derive D;
//	D._a4 = 0;
//	D._a2 = 1;
//	D._a1 = 2;
//	D.B1::_a0 = 4;
//	return 0;
//}
//#include<iostream>
//using namespace std;
//int main()
//{
//
//	int a = 5;
//	int&b = a;
//	int *ptr1 = &a;
//	int*ptr = &b;
//	b = 10;
//	return 0;
//
//}
//#include<iostream>
//using namespace std;
//class Base
//{
//public:
//	Base() :_a1(1){};
//	//virtual ~Base(){};
//	void fun()
//	{
//		cout << "base" << endl;
//	}
//
//private:
//	int _a1;
//
//};
//class Divered :public Base
//{
//public:
//	Divered() :Base(), _b1(0){};
//	//virtual ~Divered(){};
//	virtual void fun()
//	{
//		cout << "Divered" << endl;
//	}
//
//private:
//	int _b1;
//};
// int main()
//{
//	Divered*d1 = new Divered;
//	Base*d2 = d1;
//	 d2->fun();
//	 delete d2;
//	 return 0;
//}
//


//设计一个类不能被继承
//#include<iostream>
//using namespace std;
//class assist
//{
//	friend class Dirved;
//private:
//	assist()
//	{
//
//	}
//	~assist()
//	{
//
//	}
//
//};
//class Dirved : virtual public assist
//{
//public:
//	Dirved()
//	{
//		cout << "Dirved()" << endl;
//	}
//private:
//	int _a0;
//	int _a1;
//};
//class son :public Dirved
//{
//public:
//	int _a3;
//};
//int main()
//{
//	Dirved d1;
//	//son s1;
//	return 0;
//}

//#include<iostream>
//using  namespace std;
//class Scoped
//{
//public:
//	Scoped() :_a0(1), _a1(2)
//	{
//		cout << "hehe" << endl;
//	}
//private:
//	Scoped(Scoped&);
//	Scoped& operator=(Scoped&);
//	int _a0;
//	int _a1;
//};
//int main()
//{
//	Scoped s1;
//	//Scoped s2(s1);
//	Scoped s2;
//	//s2 = s1;
//} 
//#include<iostream>
//using namespace std;
//class oneobject
//{
//public:
//	static oneobject*Getobject()
//	{
//		if (count==0)
//		return new oneobject();
//		return NULL;
//	}
//	~oneobject()
//	{
//		--count;
//	}
//private:
//	oneobject() :_a0(1), _a1(2)
//	{
//		++count;
//	}
//	int _a0;
//	int _a1;
//	static int count;
//	
//};
//int oneobject::count = 0;
////重点
//#include<iostream>
//using namespace std;
//class A
//{
//public:
//	A()
//	{
//		m_a = 1; m_b = 2;
//	}
//	 void fun()
//	{
//		cout << m_a << " " << m_b << endl;
//	}
//private:
//	int m_a;
//	int m_b;
//};
//class B:public A
//{
//public:
//	B()
//	{
//		m_c = 3;
//	}
//	/*virtual*/ void fun()
//	{
//		cout << m_c << endl;
//		*((&m_c)+4) = 10;
//	
//	}
//private:
//	int m_c;
//};
//int main()
//{
//	A a;
//	B*pb = (B*)(&a);
//	pb->fun();
//	return 0;
//}
#include<iostream>
#include<malloc.h>
using namespace std;
//int main()
//{
//	int *p = (int*)malloc(8);
//	int *p1 = new int[2];
//	int *p3 = new int(1);
//	p[5]  = 5;
//	p1[5] = 10;
//	p3[3] = 10;
//	free(p);
//	delete[]p1;
//	delete p3;
//	return 0;
//}
//int main()
//{
//	int i ;
//	for (i=0;i<10;++i)
//	{
//		cout << "1" << endl;
//	}
//	for (;;)
//	{
//		cout << "1" << endl;
//	}
//	while (1)
//	{
//		cout << "1" << endl;
//		++i;
//	}
//	do
//	{
//		cout << "1" << endl;
//		++i;
//	} while (1);
//	return 0;
//}
//#include<iostream>
//using namespace std;
//class data
//{
//public :
//	data() :_a(1), _b(2)
//	{
//
//	}
//	int _a;
//	int _b;
//};
//void test(data temp)
//{
//	data t1 = temp;
//}
//int main()
//{
//	data temp;
//	temp._a = 10;
//	temp._b = 0;
//	int i = 10;
//	int j = 0;
//	int arr[10] = { 0 };
//	test(temp);
//	return 0;
//
//}

//void Swap(int &left, int &right)
//{ 
//	int temp = left;   
//	left = right; 
//	right = temp;
//}
//int main() 
//{  
//	int iNum = 10; 
//	int *pNum = NULL;   
//
//	Swap(iNum, *pNum);   
//
//	return 0;
//}


#include<iostream>
#include<stack>
#include<assert.h>
using namespace std;
template<class T>
struct element
{
	element(const T&_data):data(_data),count(1)
	{}
	T data;
	int count;
};
template<class T>
class MinStack
{
public:
	MinStack()
	{

	}
	bool Push(const T&data)
	{
		element<T> el(data);
		s.push(data);
		if (!min_s.empty())
		{
			element<T> &temp = min_s.top();
			if (temp.data >data)
			{
				min_s.push(el);
			}
			else if (temp.data == data)
			{
				++temp.count;
			}
		}
		else
		{
			min_s.push(el);
			return true;
		}
		return true;
	}
	bool Pop()
	{
		if (!s.empty())
		{
			const T& temp_s = s.top();
			element<T>&temp_min = min_s.top();
			s.pop();
			if (temp_s == temp_min.data)
			{
				if (temp_min.count == 1)
					min_s.pop();
				else
					--temp_min.count;
			}
			return true;
		}
		return false;
	}
	T&Min()
	{
		if (!min_s.empty())
		{
			return min_s.top().data;
		}
		assert(0);
	}
private:
	stack<T> s;
	stack<element<T>> min_s;
};
int main()
{
	int array[] = { 4, 2, 9, 7, 4, 3, 1, 1, 2, 4, 5 };
	MinStack<int>s1;
	for (int i = 0; i < sizeof(array) / sizeof(array[0]); ++i)
	{
		s1.Push(array[i]);
		cout << s1.Min() << " ";

	}
	cout << endl;
	for (int i = 0; i < sizeof(array) / sizeof(array[0])-1; ++i)
	{
		s1.Pop();
		cout << s1.Min() << " ";
	}
	cout << endl;
	return 0;
}