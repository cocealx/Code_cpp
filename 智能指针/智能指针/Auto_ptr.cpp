//#define _CRT_SECURE_NO_WARNINGS 1
//#include<iostream>
//using namespace std;
///*
//template<class T>
//class Auto_Ptr
//{
//public:
//	typedef Auto_Ptr<T> Auto_Ptr;
//	Auto_Ptr(const T&Ptr = NULL):_Ptr(Ptr)
//	{}
//	Auto_Ptr(Auto_Ptr&ptr) :_Ptr(ptr._Ptr)
//	{
//		ptr._Ptr = NULL;
//	}
//	Auto_Ptr&operator=(Auto_Ptr&ptr)
//	{
//		if (this == &ptr)
//			return *this;
//		if (_Ptr)
//			delete _Ptr;
//		_Ptr = ptr._Ptr;
//		ptr._Ptr = NULL;
//
//	}
//	T&operator*()
//	{
//		return *(_Ptr);
//	}
//	T*operator->()
//	{
//		return _Ptr;
//	}
//	~Auto_Ptr()
//	{
//	   if (_Ptr)
//	      delete _Ptr;
//	}
//private:
//	T*_Ptr;
//};
//*/
//template<class T>
//class Auto_Ptr
//{
//public:
//	Auto_Ptr( T*Ptr = NULL) :_Ptr(Ptr),flag(true)
//	{}
//	Auto_Ptr(const Auto_Ptr&ptr) :_Ptr(ptr._Ptr), flag(true)
//	{
//		ptr.flag = false;
//	}
//	Auto_Ptr&operator=(const Auto_Ptr&ptr)
//	{
//		if (this == &ptr)
//			return *this;
//		if (flag&& _Ptr)
//			delete _Ptr;
//		_Ptr = ptr._Ptr;
//		ptr.flag = false;
//		flag = true;
//	}
//	T&operator*()
//	{
//		return *(_Ptr);
//	}
//	T*operator->()
//	{
//		return _Ptr;
//	}
//	~Auto_Ptr()
//	{
//		if (_Ptr)
//			delete _Ptr;
//	}
//private:
//	T* _Ptr;
//	mutable bool flag;
//};
//
//int main()
//{
//	Auto_Ptr<int> p1(new int);
//}	


#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<memory>
using namespace std;
template<class T>
struct Node
{
	Node(T data = T()) :_data(data)
	{
	}
	~Node()
	{
		cout << "Call ~Node()" << endl;
	}
	weak_ptr<Node> Pnext;
	weak_ptr<Node> Ppre;
	T _data;
};
void testShared_Ptr()
{
	shared_ptr<Node<int>>sp1(new Node<int>(1));
	shared_ptr<Node<int>>sp2(new Node<int>(2));
	cout << sp1.use_count() << endl;
	cout << sp2.use_count() << endl;
	sp1->Pnext = sp2;
	sp2->Ppre = sp1;
	cout << sp1.use_count() << endl;
	cout << sp2.use_count() << endl;
}
int main()
{
	testShared_Ptr();
	cout << "testShared_pte()函数运行结束"<<endl;
	return 0;
}
