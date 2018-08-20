#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<Windows.h>
using namespace std; 
#if 0
void test()
{
	static int i = 0;
	int k = i + 1;
}
int main()
{
	int i(10);
	int k = 10;
	i = 11;
	k = 11;
	OutputDebugString(L"-----------------------\n"
		L"在调试窗口输出调试信息\n"
		L"----------------------\n");
	test();
	return 0;
}
#endif
#include<iostream>
using namespace std;
#if 0
class temp
{
public: 
	temp()
	{
		/*_pDatta = new char[20];
		strcpy(_pDatta, "hello bit");*/
		i = 111;
	}
	~temp()
	{
		cout << "调用析构函数" << endl;
	}
		/*char * _pDatta;*/
	int i;
};
temp test()
{
	temp w;
	return w;
}
int main()
{
	temp ret = test();
	cout << "12345" << endl;
	temp*tp = &temp();
	int m = 1234;
	printf("%d\n",m);
	cout << ret.i<< endl;
	cout << tp->i<< endl;
	return 0;
}
#endif


//class A
//{
//	static const int a = 10;
//	//const int a;
//	//enum 
//	//{
//	//	a=10
//	//};
//	int b[a];
//public:
//	void f()
//	{
//		cout << a << endl;
//	}
//};
//int main()
//{
//	A a;
//	a.f();
//}

///////统计一个类创建了多少对象，继承体系下如何统计子类对象的个数，会不会影响父类的个数，如果消除影响呢
//class A
//{
//public:
//	A()
//	{
//		++count;
//	}
//	A(const A&a)
//	{
//		++count;
//	}
//	void fun()
//	{
//		cout << count << " " << endl;
//	}
//	~A()
//	{
//		--count;
//	}
//	static int count;
//};
//int A::count = 0;
//class B:public A
//{
//public:
//	B()
//	{
//		++this->count1;
//		--A::count;
//	}
//	B(const B&b)
//	{
//		++this->count1;
//		--A::count;
//	}
//	void fun()
//	{
//		cout << count1 << " " << endl;
//	}
//	~B()
//	{
//		--count1;
//	}
//	static int count1;
//};
//int B::count1 = 0;

//int main()
//{
//	A ar[10];
//	ar[0].fun();
//	B ar1[10];
//	ar1[0].fun();
//	ar[0].fun();
//	return 0;
//}



////////释放vector的一段空间
//#include<vector>
//int main()
//{
//	vector<int> a;
//	a.reserve(20);
//	cout << a.capacity();
//	vector<int>b;
//	a.swap(b);
//	cout << a.capacity();
//}


///////构成函数返回值是this指针，通过eax寄存器返回，有一个默认参数通过ecx传递（查看反汇编）
#include<new>
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;
class A
{
public:
	A()
	{
		a = 3;
		b = 4;
		++count;
		cout << "A construct" << endl;
	}
	A(int a1, int b1)
	{
		a = 1;
		b = 2;
		++count;
	}
	A(const A&a)
	{
		++count;
	}
	A& operator=(const A&c)
	{
		cout << "A =" << endl;
		a = c.a;
		b = c.b;
		return *this;
	}
	void __thiscall fun()
	{
		cout << count << " " << endl;
	}
	int a;
	int b;
//	char da[0];
	static int count;
};
int A::count = 0;

class B:public A
{
public:
	B()
	{
		cout << "B construct" << endl;
		++this->count1;
		--A::count;
	}
	B(const B&b)
	{
		++this->count1;
		--A::count;
	}
	B& operator=(const B& c)
	{
		cout << "A =" << endl;
		(*this) .A::operator=(c);
		return *this;
	}
	void _stdcall fun(int a ...)
	{
		cout << count1 << " " << endl;
	}
	void __cdecl  Ctest();

	~B()
	{
		--count1;
	}
	static int count1;

};
int B::count1 = 0;
extern "C"
{
	void B::Ctest()
	{
		cout << a << b << endl;
	}
}
//static void*operator new (size_t size)
//{
//	if (size == 0)
//	return ::operator new(size);
//	B*p = (B*)malloc(size);
//	return p;
//}
//static void*operator new[](size_t size)
//{
//	
//	return ::operator new(size);
//}
int main()
{
	A b(1,2);
	B c, d;
	c = d;
	b.fun();
	/*static B sa1;
	B*p = new B;
	B*p1 = new B[2];
	*p = p1[0];
	p->fun(3,1,2);
	p->A::fun();
	p->Ctest();*/
//	delete[]p;
//	delete p1 ;
	vector<int>a;
	
	//reverse(a.begin(), a.end());
	//int da= (int)(&(((B*)0)->b));

	//int a1 = 2;
	//int*p3 = &a1;
	//if (((*p3)++ == a1++))
	//	cout << "true"<< endl;
	//return 0;
}