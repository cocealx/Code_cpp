#define _CRT_SECURE_NO_WARNINGS 1
//#include<iostream>
//using namespace std;
//template<typename T>//以实参推演模板形参
//T add(T x1, T x2)
//{
//	return x1 + x2;
//}
//template<> int add<int>(int a, int a2)
//{
//	return 2 * a + 2 * a2;
//}
//template double add<double>(double a1, double a2);
//void main()
//{
//	int x1 = 1;
//	int x2 = 2;
//	double d1 = 1.5;
//	double d2 = 2.5;
//	float f1 = 0.5f;
//	float f2 = 0.6f;
//	cout << add(x1, x2) << endl;
//	cout << add(d1, d2) << endl;
//	cout << add(f1, f2) << endl;
//	//cout << add(x1, b1) << endl;
//}
/*
#include<iostream>
using namespace std;
template<typename T>
 inline T add(T num1, T num2)
{
	return num1 + num2;
}
 template<> char* add< char*>( char* num1,  char* num2)
 {
	 return num1;
 }
 template<> const char* add<const  char*>(const char* num1, const char* num2)
 {
	 return num1;
 }
int main()
{
	char name[20] = "abd";
	char name3[] = "ssa";
	cout << add(1.0, 2.) << endl;
	cout << add(1, 4) << endl;
	cout << add<int>(1.9, 3.4) << endl;
	cout << add(name, name3) << endl;
	cout << add("abcd", "aadc") << endl;
	return 0;
}

#include<iostream>
using namespace std;
template<class T,int size>
void print(T (&str)[size])
{
	int i = 0;
	T arr[size] = { 0 };
	for (i = 0; i < size; i++)
	{
		arr[i] = str[i];
		cout << arr[i] << " ";
	}
	
}
int main()
{
	double arr1[5] = { 1.1, 1.2, 1.3, 1.4, 1.5 };
	int iaar[5] = { 2, 4, 6, 8, 10 };
	print(arr1);
	print(iaar);
	return 0;
}


#include<iostream>
using namespace std;
template<typename T>
int compare(T object1, T object2)
{
	return object1 > object2?1:(object1==object2?0:-1);
}
template<>
int compare<char*>(char*object1, char*object2)
{
	return strcmp(object1, object2);
}

int main()
{
	int a1 = 1, a2 = 2;
	double d1 = 2.0, d2 = 1.0;
	const char*str3 = "bcd";
	const char*str4= "abcd";
    char*str1 = "bcd";
    char*str2 = "abcd";
	cout << compare(a1, a2) << endl;
	cout << compare(d1, d2) << endl;
	cout << compare(str1, str2) << endl;//调用特化版本
	cout << compare(str3, str4) << endl;//因为跟特化版本参数不一致，调用编译器提供新的实例化
	return 0;
}
*/
//#include<iostream>
//using namespace std;
//template<class T>
//bool ISequal(T l, T r)
//{
//	return l == r;
//}
//template<class T1, class T2>
//bool ISequal(T1 l, T2 r)
//{
//	return l == r;
//}
//
//int main()
//{
//	 cout << ISequal(1, 2) << endl;
//	 cout << ISequal(string("11"), string("12")) << endl;
///*1*/cout << ISequal<int>(1.2, 1) << endl;//调用ISequal(T1 r,T2 l);相当于显示实列化的缺省，第一个为int 第二个推演后得到
///*2*/cout << ISequal<int>(1, 1.2) << endl;
///*3*/cout << ISequal<int, int>(1.2, 1) << endl;
////由1，2 ，3可以得到，当ISequal()的两个参数不一样时，会优先调用template<class T1, class T2> bool ISequal(T1 l, T2 r)
//
//	return 0;
//
//}


//模板类

#include<iostream>
using namespace std;
//template<class T>
//class stu
//{
//public:
//	template<class T>
//	friend void print(T a1, T a2);
//
//private:
//	int _b;
//};
//template<class T>
//void print(T a1,T a2)
//{
//
//	cout << a1 + a2 << endl;
//	cout << "hehe" << endl;
//}
//int main()
//{
//	
//	print(2, 3);
//	return 0;
//}
template <class T>
T MAX(const T &s1, const T & s2)
{
	return s1 > s2 ? s1 : s2;
}
template <>
char *MAX<char*>(char*const& s1, char*const& s2)
{
	//*s1 = 'q';
	/*s1 = "234";*/
	if (strcmp(s1, s2) > 0)
		return s1;
	else if (strcmp(s1, s2) < 0)
		return s2;	
return s1;
}
template<class T>
void fun(T const p1)
{
	int a = 1;
	//p1 = &a;
	*p1 = 10;
}
int main()
{
	char*s1 = "1234";
	char*s2 = "23456";
	MAX(s1, s2);
	/*MAX("12", "13");*/
	std::cout<<typeid("12").name() << endl;
	int a1(0);
	int *p = &a1;
	fun(p);
	cout << a1 << endl;
	return 0;
}