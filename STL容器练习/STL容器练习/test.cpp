#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
#include<vector>
#include<list>
using namespace std;
void teststring()
{
	string s1;
	cout << s1.size() << endl;
	s1.push_back('0');
	s1.push_back('1');
	s1.push_back('2');
	s1.push_back('3');
	s1.push_back('4');
	s1.push_back('5');
	cout << s1.size() << endl;
	s1.assign("123456789123456789123456789");
	cout << s1.size() << endl;
	s1.reserve(70);
	cout << s1.size() << endl;
	s1.resize(20);
	cout << s1.size() << endl;
}
void testvector()
{
	vector<int> v1;
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	v1.push_back(4);
	v1.push_back(5);
	v1.push_back(6);
	cout << v1.size() << endl;
	 v1.reserve(20);
	 cout << v1.size() << endl;
	 v1.resize(10, 7);
	 cout << v1.size() << endl;
}
void testlist()
{
	list<int>l1;
	l1.push_back(1);
	l1.push_back(2);
	l1.push_back(3);
	l1.push_back(4);
	l1.push_back(5);
	cout << l1.size() << endl;
	l1.resize(7, 6);
	//ÄæÖÃ
	l1.reverse();
}

int main()
{
	//teststring();
	testvector();
	return 0;
}