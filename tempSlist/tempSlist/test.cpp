#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include"Vector.h"
#include"String.h"
#include"List.h"
#include"Container.h"
using namespace std;
void testint()
{
	Vector<int>v1;
	v1.PushBack(1);
	v1.PushBack(2);
	v1.PushBack(3);
	v1.PushBack(4);
	cout << v1<<endl;
	cout << v1.Size()<<endl;
	v1.PopBack();
	cout << v1.Size() << endl;;
	cout << v1 << endl;
	v1.Insert(0, 0);
	v1.Insert(4, 4);
	cout << v1 << endl;
	v1.Erase(0);
	v1.Erase(v1.Size()-1);
	v1.Erase(2);
	cout << v1 << endl;
	cout << v1.Back() << endl;
	cout << v1.Front() << endl;
	v1.Resize(8, 11);
	cout << v1 << endl;
	v1.PopBack();
	v1.PopBack();
	v1.PopBack();
	v1.PopBack();
	v1.Clear();
	if (v1.Empty())
		cout << "Пе" << endl;

}
void teststring()
{
	Vector<String> s1;
	s1.PushBack(String("1111"));
	s1.PushBack(String("2222"));
	s1.PushBack(String("3333"));
	s1.PushBack(String("4444"));
	s1.Resize(10, String("5555"));
	cout << s1 << endl;
	s1.Insert(0, "0000");
	s1.Insert(s1.Size(), "6666");
	cout << s1 << endl;
	s1.PopBack();
	s1.PopBack();
	cout << s1 << endl;
	s1.Erase(0);
	s1.Erase(s1.Size() - 1);
	cout << s1 << endl;
}
void testList()
{
	int arr[] = { 1, 2, 3, 4 };
	List<int>l1(arr, 4);
	cout << l1 << endl;
	cout << l1.Size()<< endl;
	l1.Insert(l1.Begin(), 0);
	l1.Insert(l1.End(), 5);
	cout << l1 << endl;
	l1.Erase(l1.Begin());
	l1.Erase(l1.Find(5));
	cout << l1 << endl;
	l1.PushBack(5);
	l1.PushBack(6);
	cout << l1 << endl;
	l1.PopBack();
	l1.PopBack();
	cout << l1 << endl;
	cout << l1.Front() << endl;
	cout << l1.Back() << endl;
	 l1.PushFront(0);
	 l1.PushFront(1);
	 cout << l1 << endl;
	 l1.PopFront();
	 l1.PopFront();
	 l1.Clear();
	 cout << l1 << endl;
	 cout << l1.Size() << endl;
	 l1.PushBack(1);
	 l1.PushBack(2);
	 l1.PushBack(3);
	 l1.PushBack(4);
	 cout << l1 << endl;
	 cout << l1.Size() << endl;
}
void testContainer()
{
	Stack<int, Vector>s1;
	s1.Push(1);
	s1.Push(2);
	s1.Push(3);
	s1.Push(4);
	cout << s1.Size() << endl;
	s1.Pop();
	cout << s1.Top() << endl;
	s1.Pop();
	cout << s1.Top() << endl;

	Stack<int, List>s2;
	s2.Push(5);
	s2.Push(6);
	s2.Push(7);
	s2.Push(8);
	cout << s2.Size() << endl;
	s2.Pop();
	cout << s2.Top() << endl;
	s2.Pop();
	cout << s2.Top() << endl;
}
void testQuene()
{

	Quene<int, List>s2;
	s2.Push(5);
	s2.Push(6);
	s2.Push(7);
	s2.Push(8);
	cout << s2.Size() << endl;
	s2.Pop();
	cout << s2.Top() << endl;
	s2.Pop();
	cout << s2.Back() << endl;
}
int main()
{

	/*testint();
	teststring();
	testList();*/
	//testContainer();
	testQuene();
	return 0;
}
