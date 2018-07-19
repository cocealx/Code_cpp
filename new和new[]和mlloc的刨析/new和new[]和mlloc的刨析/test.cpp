#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<stdlib.h>
using namespace std;
class Date
{
public:
	Date(int year=2017, int month=9, int day=16) :_year(year), _month(month), _day(day)
	{
		cout << "DATE" << endl;
	}
	~Date()
	{
		cout << _year << endl;
		cout << "~DATE()" << endl;
	}
private:
	int _year;
	int _month;
	int _day;
	
};
int main()
{

	Date *T = new Date;
	Date *T0=new Date;
	Date *T1 = (Date*)malloc(sizeof(Date));
	Date*T5 = new Date[5];
	Date *T2 = new Date[3];
	Date *T21 = new Date[3];
	Date *T3 = (Date*)malloc(3*sizeof(Date));
	Date *T31 = (Date*)malloc(3 * sizeof(Date));
	free(T);//不会崩溃
	//delete[]T0;//无法确定析构函数调用的次数，会崩溃
	delete T1;//当有析构函数时会崩溃，没有时不会奔溃
	//free(T21);//会奔溃，多了四个无法确定到底要释放多大空间
	//delete T2;//会崩溃，T2是new[]开辟的，编译器会多开辟四个字节来记录析构函数的调用次数，释放的时候就无法确定释放多大空间
	delete T3;//不会崩溃
	//delete[]T31;//会尝试确定到底调用多少次析构函数，但是malloc开辟的空间并不会专门再多开辟四个字节来记录调用析构函数的次数
	return 0;
	
}
