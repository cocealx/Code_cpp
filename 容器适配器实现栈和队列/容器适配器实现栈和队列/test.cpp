#include"Seqlist.h"
#include"SList.h"
#include<string>
//template<class T, template<class>class Container>
template<class T,class Container>
class Stack
{
public:
	void Push(const T&x)
	{
		_con.PushBack(x);
	}
	void Pop(const T&x)
	{
		_con.PopBack(x);
	}
	size_t Size()
	{
		_con.Size();
	}
	bool Empty()
	{
		return _con.Empty();
	}
	void print()
	{
		_con.Print();
	}
	const T&Top()
	{
		return _con.Top();
	}
private:
	Container _con;
};
//栈的测试
void TestSeqlist()
{

	Stack<int, Seqlist<int>> tol;
	Stack<int, Seqlist<char>>temp;
	temp.Empty();
	temp.Push(1);
	temp.Push(2);
	temp.Push(3);
	temp.Push(4);

	tol.Push(1);
	tol.Push(2);
	tol.Push(3);
	tol.Push(4);
	tol.Push(5);
	tol.Push(6);
	tol.print();
	std::cout << tol.Top() << std::endl;
	if (!tol.Empty())
		std::cout << "不是空栈" << std::endl;
}
//顺序表的测试
//void TestSList()
//{
//	SList <int>s1;
//	
//	s1.PushBack(1);
//	s1.PushBack(2);
//	s1.PushBack(3);
//	s1.PushBack(4);
//	s1.Print();
//	s1.PopBack();
//	s1.PopBack();
//	s1.PopBack();
//	s1.PopBack();
//	s1.PopBack();
//	s1.Print();
//	s1.PushBack(4);
//	s1.Print();
//}

//顺序表的深拷贝和赋值运算符的重载测试
//void TestSList1()
//{
//	SList <string>s1;
//	{
//		SList<string>s2;
//
//		s1.PushBack(string("11"));
//		s1.PushBack(string("2222222222222222222222222222222222222222222222"));
//		s1.PushBack(string("33"));
//		s1.PushBack(string("44"));
//		s1.Print();
//		s2 = s1;
//		s2.Print();
//	}
//	s1.PopBack();
//	s1.PopBack();
//	s1.PopBack();
//	s1.PopBack();
//	s1.PopBack();
//	s1.Print();
//	s1.PushBack(string("44"));
//	s1.Print();
//}
//int main()
//{
////	TestSeqlist();
//	TestSList1();
//	return 0;
//}


//如果不用循环实现1+.......+n;
//class SUM
//{
//public:
//	static int addtest();
//
//};
template <int n>
 int addtest()
{
	if (n>0)
	return n+addtest<n-1>();
	return 0;
}
template<> 
int addtest<0>()
{
	return 0;
}
int add(int n)
{
	if (n > 0)
		return n + add(n - 1);
	return 0;
}
int main()
{
	cout<<add(100)<<endl;
	cout << addtest<100>() << endl;
	return 0;

}
