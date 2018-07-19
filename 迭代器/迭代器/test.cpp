#include"List.h"
#include<vector>
#include<list>



void testlist()
{
    list<int>ls1;
	ls1.push_back(1);
	ls1.push_back(2);
	ls1.push_back(3);
	ls1.push_back(4);
	ls1.push_back(5);
	ls1.push_back(6);
	/*ls1.insert(1)*/
	//Myprintf(ls1);
	const list<int>ls2(6, 6);
	//Myprintf(ls2);
}

void testvector()
{
	vector<int> arry;
	arry.push_back(1);
	arry.push_back(1);
	arry.push_back(1);
	arry.push_back(1);
	arry.push_back(1);
}
template<class T>
void Myprintf(const T&s1)
{
	MYList<int>::ConstIterator t1 = s1.Begin();
	while (t1 != s1.End())
	{
		/**t1 = 1;*/
		cout << *t1 << " ";
		++t1;
	}
	cout << endl;
}
struct AA
{
	AA(int a1 = int(), int a2 = int()) :_a1(a1), _a2(a2)
	{
	}
	int _a1;
	int _a2;
};
void testMYlist()
{

	MYList<int>s1;
	s1.Pushback(1);
	s1.Pushback(2);
	s1.Pushback(3);
	s1.Pushback(4);
	Myprintf(s1);


	MYList<AA>s2;
	MYList<AA>::Iterator t2 = s2.Begin();
	cout << t2->_a1 << endl;
	cout << t2->_a2 << endl;
	if (t2 != s2.End())
		cout << "12222213" << endl;
//	//Pushback和Popback的测试。
//	MYList<int>s3;
//	s3.Pushback(1);
//	s3.Pushback(2);
//	s3.Pushback(3);
//	s3.Pushback(4);
//
//	s3.PopBack();
//	Myprintf(s3);
//	s3.PopBack();
//	Myprintf(s3);
//	s3.PopBack();
//	Myprintf(s3);
//	s3.PopBack();
//	Myprintf(s3);
////	s3.PopBack();
//	//测试PushFront和PopFront
//	s3.PushFront(4);
//	s3.PushFront(3);
//	s3.PushFront(2);
//	s3.PushFront(1);
//	Myprintf(s3);
//	s3.PopFront();
//	Myprintf(s3);
//	s3.PopFront();
//	Myprintf(s3);
//	s3.PopFront();
//	Myprintf(s3);
//	s3.PopFront();
//	Myprintf(s3);
//	//s3.PopFront();
//	//	Insert函数和Erase函数的测试
//	s3.Pushback(1);
//	s3.Pushback(2);
//	s3.Pushback(3);
//	s3.Pushback(4);
//	Myprintf(s3);
//	s3.Insert(s3.Find(1), 0);
//	s3.Insert(s3.Find(2), 0);
//	s3.Insert(s3.Find(3), 0);
//	s3.Insert(s3.Find(4), 0);
//	Myprintf(s3);
//	s3.Erase(s3.Find(0));
//	s3.Erase(s3.Find(0));
//	s3.Erase(s3.Find(0));
//	s3.Erase(s3.Find(0));
//	s3.Erase(s3.Find(4));
//	Myprintf(s3);
	//MYList<int> s4;
	//s4.Pushback(1);
	//s4.Pushback(2);
	//s4.Pushback(3);
	//s4.Pushback(4);
	//Myprintf(s4);
	//MYList<int>::Iterator t4 = s4.Begin();
	//while (t4 != s4.End())
	//{
	//	if (*t4 % 2 == 0)
	//	{
	//		s4.Erase(s4.Find(*t4));
	//	}
	//	++t4;
	//}
	//Myprintf(s4);
}
int main()
{

	//testlist();
	MYList<int>s1;
	testMYlist();
	return 0;
}

	