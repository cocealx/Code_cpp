
//#include<iostream>
//#include<vector>
//using namespace std;
//template<class T,int _size>
//void sort(T(&arr[_size]))
//{
//	for (int i = 0; i < _size - 1; i++)
//	{
//		for (int j = 0; j < _size - i-1; j++)
//		{
//			if (arr[i]>arr[i + 1])
//			{
//				T temp = arr[i];
//				arr[i] = arr[i + 1];
//				arr[i + 1] = temp;
//			}
//		}
//	}
//}
//void sort(int arr[],int _size)
//{
//	for (int i = 0; i < _size - 1; i++)
//	{
//		for (int j = 0; j < _size - i - 1; j++)
//		{
//			if (arr[j]>arr[j + 1])
//			{
//				int temp = arr[j];
//				arr[j] = arr[j + 1];
//				arr[j + 1] = temp;
//			}
//		}
//	}
//}
//int main()
//{
//	cout << "输入数据" << endl;
//	int arr[500] = { 0 };
//	int i = 0;
//	//vector<int>arr;
//	while (1)
//	{
//		cin >> arr[i];
//		if (arr[i] == -1)
//		{
//			break;
//		}
//		i++;
//	}
//	sort(arr, i);
//	for (int j = 0;j < i; j += 2)
//		cout << arr[j] << "和" << arr[j + 1] << "配对" << endl;
//	return 0;

/*
#include<iostream>
using namespace std;
template <typename T>
class complex
{
private:
	 ////这是一个《模板函数》的声明
		//template<typename T>
		//friend	ostream& operator<<(ostream &out, const complex<T> &n);
	////这是一个显示实列化的《模板函数》的《声明》类型是<T>
	friend	ostream& operator<< <T>(ostream &out, const complex<T> &n);
	////这是一个《普通的函数》声明，如果要调用的话，要单独定义，跟上面的两个函数有很大区别
	//friend	ostream& operator<< (ostream &out, const complex<T> &n);
	T a;
	T b;
public:
	complex(T a, T b);
	void print();
	complex operator+(const complex &n);
};
template <typename T>
complex<T>::complex(T a, T b)
{
	this->a = a;
	this->b = b;
}
template <typename T>
void complex<T>::print()
{
	cout << "a=" << a << "  b=" << b;
}
template <typename T>
complex<T> complex<T>::operator+(const complex<T> &n)
{
	complex c1(this->a + n.a, this->b + n.b);//在这个里面加不加<T>都可以
	return  c1;
}
template<typename T>
ostream& operator<<(ostream &out, const complex<T>&n)
{
	out << "a=" << n.a << " b=" << n.b << endl;
	return out;
}
int main()
{
	//需要把模版类具体话以后才能定义对象，因为编译器要分配内存
	complex <int>c1(1, 2);
	complex<int> c2(2, 4);
	complex<int> c3 = c1 + c2;
	//c1 << cout;//     complex <int>c1(1, 2);
	cout << c1;
	c3.print();
	system("pause");
	return 0;
}
*/
//#include<iostream>
//using namespace std;
//template <typename T>
//class complex
//{
//private:
//	friend ostream& operator<<<T>(ostream &out, const complex<T> &n);
//  ////两个友元函数不能同用一个template<typename T>
//	template<typename T>
//	friend complex<T> mysub<T>(const complex<T> &n, const complex<T>&m);
//	T a;
//	T b;
//public:
//	complex(T a, T b);
//	void print();
//	complex operator+(const complex &n);
//};
//template <typename T>
//complex<T>::complex(T a, T b)
//{
//	this->a = a;
//	this->b = b;
//}
//template <typename T>
//void complex<T>::print()
//{
//	cout << "a=" << a << "  b=" << b;
//}
//template <typename T>
//complex<T> complex<T>::operator+(const complex<T> &n)
//{
//	complex c1(this->a + n.a, this->b + n.b);//在这个里面加不加<T>都可以
//	return  c1;
//}
//template <typename T>
//ostream& operator<<(ostream &out, const complex<T> &n)
//{
//	out << "a=" << n.a << " b=" << n.b << endl;
//	return out;
//}
//template <typename T>
//complex<T> mysub(const complex<T> &n, const complex<T>&m)
//{
//	complex<T> c1(n.a - m.a, n.b - m.b);
//	return c1;
//}
//int main()
//{
//	//需要把模版类具体话以后才能定义对象，因为编译器要分配内存
//	complex <int>c1(1, 2);
//	complex<int> c2(2, 4);
//	complex<int> c3 = c1 + c2;
//	cout << mysub(c1, c2);
//	c3.print();
//	system("pause");
//	return 0;
//}
//}
//
//#include<iostream>
//using namespace std;
//
//class Date
//{
//public:
//	friend void* operator new(size_t  _count);
//	Date()
//	:_year(2017),
//	_month(9),
//	_day(18){}
//private:
//	
//	int _year;
//	int _month;
//	int _day;
//
//};
//void*operator new(size_t  _count)
//{
//    Date*temp= (Date*)malloc(_count);
//	new(temp)Date;
//	return temp;
//}
////#define new (Date*)new
//int main()
//{
//	Date *temp = new Date;
//}
//类




//怎么定义一个宏，
////只能创建一个对象
//#include<iostream>
//using namespace std;
//class  Oneobject
//{
//public:
//
//	static Oneobject*Getobject()
//	{
//		Oneobject*ret = NULL;
//		if (count == 0)
//		{
//			ret = new Oneobject;
//		}
//		return ret;
//	}
//	
//	~Oneobject()
//	{
//
//	}
//private:
//	Oneobject()
//	{
//		count++;
//		cout << "Oneobject" << endl;
//	}
//	Oneobject(const Oneobject&);
//	void *operator=(const Oneobject&);
//	static int count;
//
//};
//int Oneobject::count = 0;
//int main()
//{
//	Oneobject*ptr = Oneobject::Getobject();
//	Oneobject*ptr1 = Oneobject::Getobject();
//	return 0;
//}

////只能在堆上创建
//#include<iostream>
//using namespace std;
//class  Oneobject
//{
//public:
//
//	static Oneobject*Getobject()
//	{
//			Oneobject*ret = new Oneobject;
//			return ret;
//	}
//	
//	~Oneobject()
//	{
//
//	}
//private:
//	Oneobject()
//	{
//		count++;
//		cout << "Oneobject" << endl;
//	}
//	Oneobject(const Oneobject&);
//	void *operator=(const Oneobject&);
//	static int count;
//
//};
////怎么防拷贝
////把类的构造函数和赋值运算符声明为私有的，只声明不定义
//
//
////只能在栈上创建
////把new

//
//#include<iostream>
//using namespace std;
//
//class Date
//{
//public:
//	friend void* operator new(size_t  _count);
//	Date()
//	:_year(2017),
//	_month(9),
//	_day(18)
//	{}
//	Date(Date&d)
//		:_year(2017),
//		_month(9),
//		_day(18)
//	{
//		cout << "Date(Date&)" << endl;
//	}
//	void copy(Date &temp)
//	{
//		copy22(Date());
//		cout << "11" << endl;
//	}
//	void copy22(Date &temp)
//	{
//
//		cout << "22" << endl;
//	}
//private:
//	
//	int _year;
//	int _month;
//	int _day;
//
//};
//void test()
//{
//	Date d1;
//	Date d2=Date();
//	d2.copy(d1);
//}
//int main()
//{
//	test();
//	return 0;
//}
//
////在模板类里面定义非成员模板函数时，当实例化不同对象时报模板函数重复定义
//
////例如：
//template<class T>
//class
//{
//	template<class T>
//	friend funtest()
//	{
//		cout << "hehe" << endl;
//	}
//};
////对比
//template<class T>
//class ww
//{
//	template <class T>
//	friend void fun1(Vector<T>)
//	{
//
//		cout << " hehe" << endl;
//	}
//
//};
//template<class T>
//class ss
//{
//	template <class T>
//	friend void fun1(Vector<T>)
//	{
//		T t1();
//		cout << t1 << endl;
//	}
//};
//int main()
//{
//	//ww<char> w1;
//	//ss<int> w2;
//	//fun1(Vector<int>());
//	//fun1(Vector<char>());
//}
//#include<iostream>
//#include<vector>
//#include<string>
//using namespace std;
//string Formatstring(const string str, int n, const vector<char>&arg, int m)
//{
//	string ret;
//	int j = 0;
//	for (int i = 0; i < n; ++i)
//	{
//		if (i <n-1 && str[i] == '%'&&str[i + 1] == 's'&&j<m)
//		{
//			ret.push_back(arg[j]);
//			++j;
//			++i;
//		}
//		else
//		{
//			ret.push_back(str[i]);
//		}
//	}
//	if (j < m)
//	{
//		for (; j < m; j++)
//		{
//			ret.push_back(arg[j]);
//		}
//	}
//	ret.push_back(0);
//	return ret;
//}
//int main()
//{
//	string str = "AB%scd%s%";
//	vector<char> arg;
//	arg.push_back('A');
//	arg.push_back('B');
//	arg.push_back('D');
//	string ret = Formatstring(str, str.size(), arg, 3);
//	return 0;
//}
//#define _CRT_SECURE_NO_WARNINGS 1
//#include<iostream>
//#include<string>
//#include<stdio.h>
//using namespace std;
//void becString(int number, string&str)
//{
//	if (number < 10)
//	{
//		str.push_back('0');
//		str.push_back('0' + number);
//	}
//	else
//	{
//		str.push_back('0' + number/10);
//		str.push_back('0' + number%10); 
//	}
//
//}
//void Becyear(long long year, string&str)
//{
//	int temp = year % 10;
//	if (year > 9)
//	{
//		Becyear(year/10,str);
//	}
//	str.push_back('0' + temp);
//}
//string CalculationDate(long long second)
//{
//	string ret;
//	long long  mintue = second / 60;
//	second %= 60;
//	long long hour = mintue / 60;
//	mintue %=  60;
//	long long day = hour / 24+1;
//	hour %= 24;
//	long long year = 1970;
//	int month = 1;
//	while (day >30)
//	{
//		day -= 30;
//		++month;
//		if (month > 12)
//		{
//			month -= 12;
//			++year;
//		}
//	}
//	char data[80];
//	//%02d输出2个不够补0；
//	sprintf(data, "%lld/%02d/%02lld %02lld:%02lld:%02lld\n", year, month, day, hour, mintue, second);
//	/*Becyear(year, ret);
//	ret.push_back('/');
//	becString(month,ret);
//	ret.push_back('/');
//	becString(day, ret);
//	ret.push_back(' ');
//	becString(hour, ret);
//	ret.push_back(':');
//	becString(mintue, ret);
//	ret.push_back(':');
//	becString(second, ret);
//	return ret;*/
//	return string(data);
//}
//string CalculationDate1(long long second)
//{
//	string ret;
//	long long year = 1970, month = 1, day = 1, hour = 0, mintute = 0, s1 = 0;
//	while (second > 60)
//	{
//		second -= 60;
//		mintute += 1;
//		if (mintute >= 60)
//		{
//			mintute -= 60;
//			hour += 1;
//			if (hour >= 24)
//			{
//				day += 1;
//				hour -= 24;
//				if (day > 30)
//				{
//					month+= 1;
//					day -= 30;
//					if (month > 12)
//					{
//						year += 1;
//						month -= 12;
//					}
//				}
//			}
//			
//		}
//	}
//	Becyear(year, ret);
//	ret.push_back('/');
//	becString(month, ret);
//	ret.push_back('/');
//	becString(day, ret);
//	ret.push_back(' ');
//	becString(hour, ret);
//	ret.push_back(':');
//	becString(mintute, ret);
//	ret.push_back(':');
//	becString(second, ret);
//	return ret;
//}
//int main()
//{
//	string ret(CalculationDate(12349876));
//	string ret1(CalculationDate1(12349876));
//	cout << ret<<endl;
//	cout << ret1 << endl;
//
//	return 0;
//}
//#include<iostream>
//using namespace std;
//int sumjump(size_t n, size_t s1, size_t s2)
//{
//	if (n <= 2)
//		return n;
//	if (n == 3)
//		return s1 + s2;
//	if (n > 3)
//	sumjump(n - 1, s2, s1 + s2);
//}
//int sumjump(size_t n)
//{
//	if (n <= 2)
//		return n;
//	return sumjump(n - 1)+sumjump(n-2);
//}
//int main()
//{
//	cout << sumjump(50) << endl;
//	cout << sumjump(50,1,2) << endl;
//	return 0;
//}
#include<iostream>
#include"标头.h"
using namespace std;

//int main()
//{
//	int a[] = { 1, 2, 3, 4, 5 };
//	size_t size = sizeof(a) / sizeof(a[0]);
//	Vector<int> v(a, size);
//	return 0;
//}

