#define _CRT_SECURE_NO_WARNINGS 1
//#define _CRT_SECURE_NO_WARNINGS 1
//#include<stdio.h>
////当函数没有参数时，C和C++的情况对比
////C编译情况下：当一个函数没有返回值时，默认返回值为int型，
////当它没有参数时，可以向它传任意多个参数，当调用时参数会进行压栈
// /*ADD()
//{
//}*/
////C++编译情况下：当一个函数没有参数时，编译时就会报错；
////(error C4430: 缺少类型说明符 - 假定为 int。注意:  C++ 不支持默认 int)
////当它没有参数时，向它传任意多个参数时，编译会报错（error C2660: “ADD”: 函数不接受 1 个参数）
//void ADD()
//{
//
//}
////void ADD(char, char);
//int main()
//{
//	ADD();
//	ADD(1);
//	ADD(1,2);
//	return 0;
//}
//缺省参数:缺省时必须从右到左缺省，中间不能断开
//调用时：是从左到右赋值
//声明和定义不能同时出现缺省
//void ADD(int x=0,int y=0)
//{
//
//}
//int main()
//{
//	ADD();
//	ADD(1);//从左到右赋值
//	ADD(1, 2);
//}
//函数重载
//c:函数不支持重载因为，当C编译器对函数编译时，只是在函数名前加了个_，所以当声明的两个函数一样时，
//当在链接时产生了二义性，编译器并不知道才是你需要的函数定义
//int ADD()
//{
//	return 0;
//}
//int ADD(int x)
//{
//	return 1;
//}
//int main()
//{
//	//ADD();//_ADD
//	ADD(1);//_ADD
//}
////C++：函数支持重载，当C++编译器对函数编译时，会对函数名字进行特殊处理，
////新的函数名格式是：?@函数名@@YA返回类型参数列表@Z，如果函数没有参数
////函数名字格式：?@函数名@@YA返回类型XZ
////H 代表int X代表void D 代表char  M代表float N代表double
//void ADD(char);//1.新起的函数名 ?ADD@@YAXD@Z
////int ADD(char);//2.新起的函数名 ?ADD@@YAHD@Z 
////总结：上面两个编译器虽然对名字重新命名了，但是不能构成重载，
////因为标准并没有把返回类型放进重载的条件，所以不一样的编译器可能对返回类型右不一样的处理
//int ADD(int x);//新起的函数名 ?ADD@@YAHH@Z
//void ADD(float );//新起的函数名 ?ADD@@YAXM@Z
//void ADD(double);//新起的函数名 ?ADD@@YAXN@Z
//int main()
//{
//	ADD(1);
//    ADD('1');//
//	ADD(1);//
//	ADD(1.1f);
//	ADD(1.1);
//}
//// C++函数重载的条件:1.必须在同一作用域  2.函数必须同名  3.特征标不同(参数个数，参数顺序，参数类型)


//函数重载和缺省
//void ADD()
//{
//
//}
//void ADD(char = '0')
//{
//	
//}
//int main()
//{
//	//ADD();//会产生二义性，函数无法确定调用的是第一个还是第二个
//}
/*void ADD(char x,char y)
{

}
void ADD(char x,int y)
{

}
void SUB(char x, char y)
{

}
void SUB(int x, int y)
{

}
void DUL(double x, double y)
{

}
void DUL(int x, int y)
{

}
void test(char x, int y)
{

}
void test(int x, int y)
{

}
int main()
{
ADD(2,'1');//调用char,char,会把2当成字符的ASC码值
test(2, '1');//字符型的匹配不上，所以进行提升变成int int
//SUB(2, '1')和 SUB('1', 2);;//报错 “ADD”: 2 个重载有相似的转换
//可能是“void ADD(int,int)” 或  “void ADD(char,char)”，编译器不知道把2当成ASC码值，还是当成整型对char进行提升
DUL(2, '1');//对char进行提升，变成 int int
}*/
//#include<iostream>
//void test(int i)
//{
//	i++;
//}
//int main()
//{
//	using namespace std;
//	double b = 12.34;
//	test(1);
//	const int&a = b;//中间产生了一个零时变量，引用的不上b本身，而是临时变量
//	cout << &a << endl;
//	cout << &b << endl;
//	cout << a << endl;
//	test(1);
//	cout << &a << endl;
//	cout << &b << endl;
//	cout << a << endl;
//}
//函数传参过程？
//1.先传参数（如果有传数）
//call funtest(地址ox12345678)------->jmp--------->  位置(函数的真实地址)
//必须先跳到跳转指令的位置，然后从跳转指令到函数的真实地址


////函数和引用
//#include<iostream>
//void ADD(int& a, int& b)
//{
//	int temp = a;//16 4
//	a = b;
//	b = temp;
//}
//int main()
//{
//	int a = 10;
//	int b = 20;
//	int*p = &a;
//	int*p1 = NULL;
//	ADD(a, *p1);//能编译过，而且还能运行，在ADD()函数中的a=b;报错，
//	            //ADD()在传参时，并没有对p1解引用，而是把p1的值传过去
//}
//#define off_setoff(S,typedata) (size_t)(&(((S*)0)->typedata))
//#include<iostream>
//struct S
//{
//	char c;
//	int b;
//	double d;
//};
//int main()
//{
//
//	int  i = off_setoff(S, d);
//	printf("%d", i);
//	getchar();
//	return 0;
//}
////如何修改this指针，使this指针为空
//#include<iostream>
//using  namespace std;
//class S
//{
//public :
//	void find(int k,int b=1)
//	{
//		int*p = &b;
//		p = p - 5;
//		*p = 0;
//	/*	this->i = k;
//		k++;
//		this->j = k;
//		k = i + j;*/
//		cout << this << endl;
//	}
//	void test(int k,...)
//	{
//		int*p = &k;
//		p--;
//		*p = 0;
//		cout << "heheh" << endl;
//		cout << this << endl;
//	}
//private:
//	int i;
//	int j;
//};
//int main()
//{
//	S s1;
//	s1.find(5);
//	//s1.test(1,2);
//	getchar();
//	return 0;
//}
//类的六个默认成员函数 1.构造函数 2.拷贝构造函数 3.析构函数 4.赋值操作符重载 5.取地址操作符重载 6.const 修饰的取地址操作符重载
//#include<iostream>
//#include<string.h>
//#include<stdlib.h>
//class  CDate
//{
//public:
//	//静态函数
//	static void STAtic( /*CDate*  temp*/);
//
//	//构造函数
//	CDate(char name[], int old, char *sex) :_old(old)
//	{
//		strcpy(_name, name);
//		strcpy(_sex, sex);
//		count++;
//	};
//	//默认构造函数
//	CDate()
//	{
//		memset(this, 0, sizeof(CDate));
//		count++;
//		std::cout << "call -->默认构造函数" << std::endl;
//	}
//	//析构函数
//	~CDate()
//	{
//		std::cout << "call--->析构函数" << std::endl;
//		count--;
//	};
//	void display()
//	{
//		std::cout << _name << "  " << "年龄：" << _old << "性别：" << _sex << std::endl;
//		//std::cout << "对象的总个数：" << count << std::endl;
//		STAtic();
//	}
//	//拷贝构造函数
//	CDate( const CDate& temp)
//	{
//		_old = temp._old;
//		strcpy(_name, temp._name);
//		strcpy(_sex, temp._sex);
//		count++;
//		std::cout << "call -->拷贝构造函数" << std::endl;
//	}	
//	CDate ADD()
//	{
//		CDate temp("wqg",20,"nan");
//		display();
//		return temp;
//	}
//	//CDate(CDate*temp)
//	//{
//	//	_old = temp->_old;
//	//	strcpy(_name, temp->_name);
//	//	strcpy(_sex, temp->_sex);
//	//	count++;
//	//	std::cout << "call -->拷贝构造函数" << std::endl;
//	//}
//private:
//	char _name[20];
//	int _old;
//	char _sex[2];
//	static int count;
//};
//int CDate::count = 0;
//void CDate:: STAtic( /*CDate* temp*/)
//{
//	/*CDate cate(temp);
//	cate.display();*/
//	std::cout << "对象的总个数：" << count << std::endl;
//}
//int main()
//{
//	CDate*p = NULL;
//	CDate date1{ "liugang", 10, "男" };
//	date1.display();
//	//CDate::STAtic(&date1);
//	CDate date2(date1);
//	//CDate::STAtic(&date2);
//	date2.display();
//	//date2.ADD().display();
//	//CDate temp1创建对象时并没有调用拷贝构造函数，把temp1的地址传过去，然后date2.ADD()函数在返回时会返回一个对象，
//	//返回对象时会创建新的对象返回，但编译器并没在中间创建新的对象，而是把temp1的地址给它，让它通过拷贝构造函数直接拷贝到temp1上
//	//所以这个过程一个涉及2对象，一个是temp1，一个是ADD()函数创建的一个临时对象。（编译器优化现象）
//	//CDate temp1(date2.ADD());
//	//temp1.display();
//	//出来后会对ADD()函数返回的对象进行析构
//	p = &(date2.ADD());
//	CDate temp2(*p);
//	getchar();
//	return 0;
//
//}
//
//#include<iostream>
//using namespace std;
////using std::ostream;
//class TEST
//{
//public:
//	friend ostream& operator<<(ostream &os, const TEST&temp);
//	friend const TEST operator+(const TEST&t1, const TEST&t2);
//	//构造函数
//	TEST(char name[], int old, char *sex) :_old(old)
//		{
//			strcpy(_name, name);
//			strcpy(_sex, sex);
//			count++;
//		};
//	//默认构造函数
//	TEST()
//		{
//		memset(this, 0, sizeof(TEST));
//			count++;
//			std::cout << "call -->默认构造函数" << std::endl;
//		}
//	//析构函数
//	~TEST()
//		{
//			std::cout << "call--->析构函数" << std::endl;
//			count--;
//		};
//		void display()
//		{
//			std::cout << _name << "  " << "年龄：" << _old << "性别：" << _sex << std::endl;
//			//std::cout << "对象的总个数：" << count << std::endl;
//		}
//	//拷贝构造函数
//	TEST(const TEST& temp)
//		{
//			_old = temp._old;
//			strcpy(_name, temp._name);
//			strcpy(_sex, temp._sex);
//			count++;
//			std::cout << "call -->拷贝构造函数" << std::endl;
//		}	
//	//取地址运算符重载
//	TEST* operator&()
//	{
//		return this;
//	}
//	//const修饰的取地址运算符重载
//	const TEST*operator &()const
//	{
//		return this;
//	}
//	//前置++运算符重载
//    TEST& TEST:: operator++();
//	//后置++运算符重载
//	const TEST TEST:: operator++(int);
//private:
//	int _old;
//	char _name[10];
//	char _sex[4];
//	static int count;
//};
//int TEST::count = 0;
//const TEST operator+(const TEST&t1, const TEST&t2)
//{
//	TEST ret{ "0", 0, "0" };
//	ret._old = t1._old + t2._old;
//	return ret;
//}
////重载非成员函数运算符时，其函数参数必须是内置类型或枚举类型。
////int operator+(int t1, int t2)
////{
////	return t1 + t2;
////}
//
//
////前置++运算符重载
//TEST& TEST:: operator++()
//{
//	_old = _old + 1;
//	cout << "调用前置++运算符重载成员函数" << endl;
//	return *this;
//}
////后置++运算符重载
//const TEST TEST:: operator++(int)
//{
//	TEST ret = *this;
//	_old++;
//	cout << "调用后置++运算符重载成员函数" << endl;
//	return ret;
//}
////<<运算符的重载
////不能返回ostream对象，因为他没有默认构造函数，只能返回指针或者引用
////所以就不能创建一个ostream对象，只能创建他的引用
//ostream& operator<<(ostream &os, const TEST&temp)
//{
//	os <<"姓名"<< temp._name<< std::endl;
//	return os;
//}
//int main()
//{
//	ostream &cout1(cout);
//	TEST  people1{ "liugang", 10, "男" };
//	const TEST  people2{ "wqg", 21, "男" };
//	TEST *p1 = &people1;
//	const TEST*p2 = &people2;
//	TEST people3 = people1 + people2;
//	people3.display();
//	cout1 << people2 << "调用<<运算符重载函数"<<endl;
//	++people1;
//	people1++;
//	return 0;
//}
#include<iostream>
int main()
{
	

}
