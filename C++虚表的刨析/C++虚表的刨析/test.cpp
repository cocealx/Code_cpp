#define _CRT_SECURE_NO_WARNINGS 1
////单一虚函数继承
//#include<iostream>
//using namespace std;
//class CBase
//{
//public:
//	CBase(){ cout << "this: " << this << endl; }
//	virtual void FunTest1(int _ITest){ cout << "CBase::FunTest1()" << endl; }
//	void FunTest2(int _Test){ cout << "CBase::FunTest2()" << endl; }
//	virtual void FunTest3(int _ITest){ cout << "CBase::FunTest3()" << endl; }
//	virtual void FunTest4(int _ITest){ cout << "CBase::FunTest4()" << endl; }
//	virtual ~CBase(){ cout << "调用CBase的析构函数" << endl; }
//private:
//	int tmp;
//};
//class CDerived :public CBase
//{
//public:
//
//	/*virtual */void FunTest1(int _ITest){ cout << "CDerived::FunTest1()" << endl; }
//	virtual void FunTest2(int _Test){ cout << "CDerived::FunTest2()" << endl; }
//	void FunTest3(int _ITest){ cout << "CDerived::FunTest3()" << endl; }
//	//不是重写，是重新定义，基类的FunTest4()函数将会被隐藏
//	//virtual void FunTest4(int _ITest1, int _ITest2){ cout << "CDerived::FunTest4()" << endl; }
//	virtual ~CDerived(){ cout << "调用CDerived的析构函数" << endl; }
//};
////class Temp : public CDerived
////{
////public:
////	void FunTest1(int _ITest){ cout << "TCDerived::FunTest1()" << endl; }
////	void FunTest2(int _Test){ cout << "TCDerived::FunTest2()" << endl; }
////	void FunTest3(int _ITest){ cout << "TCDerived::FunTest3()" << endl; }
////	//不是重写，是重新定义，基类的FunTest4()函数将会被隐藏
////	//void FunTest4(int _ITest1){ cout << "TCDerived::FunTest4()" << endl; }
////	/*virtual*/ void FunTest4(int _ITest1, int _ITest2){ cout << "TCDerived::FunTest4()" << endl; }
////	//void FunTest4(int _ITest){ cout << "TCDerived::FunTest4()" << endl; }
////	virtual ~Temp(){ cout << "调用Temp的析构函数" << endl; }
////};
//int main()
//{
//	{
//		CBase test,test2;
//		CBase*pBase = new CDerived;
//		CBase*pBase1 = new CBase;
//		cout << sizeof(test) << endl;
//		test.FunTest1(0); 
//		test.~CBase();
//		test2.~CBase();
//
//		pBase1->FunTest1(0);
//		delete pBase1;
//
//		pBase->FunTest1(0);
//		delete pBase;
//	}
//}
//多重继承没有虚函数覆盖
//#include<iostream>
//using namespace std;
//class CBase0
//{
//public:
//	CBase0(){ _Itest0 = 0xB0; }
//	virtual void PrintB0(){ cout << "CBase0::PrintB0" << endl; }
//	///*virtual*/ ~CBase0(){ cout << "析构函数CBase0()被调用" << endl; }
//private:
//	int _Itest0;
//};
//class CBase1
//{
//public:
//	CBase1(){ _Itest1 = 0xB0; }
//	virtual void PrintB1(){ cout << "CBase1::PrintB1" << endl; }
//	///*virtual*/ ~CBase1(){ cout << "析构函数CBase1()被调用" << endl; }
//private:
//	int _Itest1;
//};
//class CDerived:public CBase0,public CBase1
//{
//public:
//	CDerived() :CBase0(), CBase1(){ _Itest3 = 0xB0; }
//	virtual void PrintCD(){ cout << "CDerived::PrintCD" << endl; }
//	//~CDerived(){ cout << "析构函数CDerived()被调用" << endl; }
//
//private:
//	int _Itest3;
//}; 
//typedef  void(*VFTABLE_FUN)();
//void printVfpTab(char* _pstr,int*_pVfAdder)
//{
//	cout << _pstr << endl;
//	for (int ildx = 0;1; ildx++)
//	{
//		VFTABLE_FUN pPrintTVab = (VFTABLE_FUN)*(_pVfAdder + ildx);
//		if (NULL == pPrintTVab)
//		{
//			break;
//		}
//		pPrintTVab();
//		cout << (int*)pPrintTVab << endl;
//	}
//}
//int main()
//{
//	CDerived derived;
//	cout << sizeof(derived) << endl;
//	int*pVfTAdder = NULL;
//	CBase0& base0 = derived;
//	pVfTAdder = (int*)(*(int*)(&base0));
//	printVfpTab("CBase0",pVfTAdder);
//
//	CBase1&base1 = derived;
//	pVfTAdder = (int*)(*(int*)(&base1));
//	printVfpTab("CBase1",pVfTAdder);
//
//	pVfTAdder = (int*)(*(int*)(&derived));
//	printVfpTab("CDerived", pVfTAdder);
//
//	derived.PrintB0();
//	derived.PrintB1();
//	derived.PrintCD();
//}
//
//////多重继承，虚函数有覆盖
//#include<iostream>
//using namespace std;
//class CBase0
//{
//public:
//	CBase0(){ _Itest0 = 0xB0; }
//	virtual void Print(){ cout << "CBase0::PrintB0" << endl; }
//	///*virtual*/ ~CBase0(){ cout << "析构函数CBase0()被调用" << endl; }
//private:
//	int _Itest0;
//};
//class CBase1
//{
//public:
//	CBase1(){ _Itest1 = 0xB0; }
//	virtual void Print(){ cout << "CBase1::PrintB1" << endl; }
//	///*virtual*/ ~CBase1(){ cout << "析构函数CBase1()被调用" << endl; }
//private:
//	int _Itest1;
//};
//class CBase2
//{
//public:
//	CBase2(){ _Itest2 = 0xB0; }
//	virtual void PrintB2(){ cout << "CBase2::PrintB1" << endl; }
//	///*virtual*/ ~CBase2(){ cout << "析构函数CBase2()被调用" << endl; }
//private:
//	int _Itest2;
//};
//class CDerived :public CBase0, public CBase1,public CBase2
//{
//public:
//	CDerived() :CBase0(), CBase1(),CBase2(){ _Itest3 = 0xB0; }
//	virtual void Print(){ cout << "CDerived::PrintCD" << endl; }
//	//~CDerived(){ cout << "析构函数CDerived()被调用" << endl; }
//
//private:
//	int _Itest3;
//};
//typedef  void(*VFTABLE_FUN)();
//void printVfpTab(char* _pstr, int*_pVfAdder)
//{
//	cout << _pstr << endl;
//	for (int ildx = 0; 1; ildx++)
//	{
//		VFTABLE_FUN pPrintTVab = (VFTABLE_FUN)*(_pVfAdder + ildx);
//		if (NULL == pPrintTVab)
//		{
//			break;
//		}
//		pPrintTVab();
//		cout << (int*)pPrintTVab << endl;
//	}
//}
//int main()
//{
//	CDerived derived;
//	cout << sizeof(derived) << endl;
//	int*pVfTAdder = NULL;
//	CBase0& base0 = derived;
//	pVfTAdder = (int*)(*(int*)(&base0));
//	printVfpTab("CBase0", pVfTAdder);
//
//	CBase1&base1 = derived;
//	pVfTAdder = (int*)(*(int*)(&base1));
//	printVfpTab("CBase1", pVfTAdder);
//
//	CBase2&base2 = derived;
//	pVfTAdder = (int*)(*(int*)(&base2));
//	printVfpTab("CBase2", pVfTAdder);
//	//base2.PrintB2();
//
//	pVfTAdder = (int*)(*(int*)(&derived));
//	printVfpTab("CDerived", pVfTAdder);
//	return 0;
//}
////重复菱形继承
//#include<iostream>
//using namespace std;
//class CBase0
//{
//public:
//	CBase0(){ _Itest0 = 1; }
//virtual void Print(){ cout << "CBase0::PrintB0" << endl; }
//	///*virtual*/ ~CBase0(){ cout << "析构函数CBase0()被调用" << endl; }
////private:
//	int _Itest0;
//};
//class CBase1: public CBase0
//{
//public:
//	CBase1(){ _Itest1 = 2; }
//	/*virtual*/ void Print(){ cout << "CBase1::PrintB1" << endl; }
//	///*virtual*/ ~CBase1(){ cout << "析构函数CBase1()被调用" << endl; }
//private:
//	int _Itest1;
//};
//class CBase2 :public CBase0
//{
//public:
//	CBase2(){ _Itest2 = 3; }
//	virtual void Print(){ cout << "CBase2::PrintB1" << endl; }
//	///*virtual*/ ~CBase2(){ cout << "析构函数CBase2()被调用" << endl; }
//private:
//	int _Itest2;
//};
//class CDerived : public CBase1,public CBase2
//{
//public:
//	CDerived() : CBase1(),CBase2(){ _Itest3 = 4; }
//	virtual void PrintCD(){ cout << "CDerived::PrintCD" << endl; }
//	//~CDerived(){ cout << "析构函数CDerived()被调用" << endl; }
//
//private:
//	int _Itest3;
//};
//typedef void(*VFTABLE_FUN)();
//void printVfpTab(int*_pVfAdder)
//{
//	for (int ildx = 0;; ildx++)
//	{
// 		VFTABLE_FUN pPrintTVab = (VFTABLE_FUN)*(_pVfAdder + ildx);
//		if (NULL == pPrintTVab)
//		{
//			break;
//		}
//		if (ildx <= 1)
//			pPrintTVab();
//		else
//			;//cout << *(int*)pPrintTVab << endl;
//		cout << (int*)pPrintTVab << endl;
//	}
//}
//int main()
//{
//	CDerived derived;
//	//test1.Print();
//	int*pVfTAdder = *(int**)((&derived));
//	int*pVfTAdder1 = *(int**)((int)&derived+sizeof(CBase1));
//	printVfpTab(pVfTAdder1);
//	cout << endl;
//	printVfpTab(pVfTAdder);
//	//derived._Itest0 = 1;//有可能是CBase1里面的CBase0::_Itest0也可能是CBase2的CBase0::_Itest0，
//	CBase1 test;
//	test.Print();
//}
#if 0
//菱形虚拟继承
#include<iostream>
using namespace std;
class CBase0
{
public:
	CBase0(){ _Itest0 = 1; }
	virtual void Print(){ cout << "CBase0::PrintB0" << endl; }
	///*virtual*/ ~CBase0(){ cout << "析构函数CBase0()被调用" << endl; }
	//private:
	int _Itest0;
};
class CBase1 : virtual public CBase0
{
public:
	CBase1(){ _Itest1 = 2; }
	virtual void Print(){ cout << "CBase1::PrintB1" << endl; }
	///*virtual*/ ~CBase1(){ cout << "析构函数CBase1()被调用" << endl; }
private:
	int _Itest1;
};
class CBase2 : virtual public CBase0
{
public:
	CBase2(){ _Itest2 = 3; }
	virtual void Print(){ cout << "CBase2::PrintB1" << endl; }
	///*virtual*/ ~CBase2(){ cout << "析构函数CBase2()被调用" << endl; }
private:
	int _Itest2;
};
class CDerived : public CBase1, public CBase2
{
public:
	CDerived() : CBase0(), CBase2(), CBase1() { _Itest3 = 4; }
	virtual void PrintCD(){ cout << "CDerived::PrintCD" << endl; }
	virtual void Print(){ cout << "CDerived::PrintCD" << endl; }
	//~CDerived(){ cout << "析构函数CDerived()被调用" << endl; }

private:
	int _Itest3;
};
typedef void(*VFTABLE_FUN)();
void printVfpTab(int*_pVfAdder)
{
	for (int ildx = 0;; ildx++)
	{
		VFTABLE_FUN pPrintTVab = (VFTABLE_FUN)*(_pVfAdder + ildx);
		if (NULL == pPrintTVab)
		{
			break;
		}
			pPrintTVab();
		cout << (int*)pPrintTVab << endl;
	}
}
int main()
{
	CDerived derived;
	CBase0 base0;
	CBase1 base1;
	CBase2 base2;

	//test1.Print();
	int*pVfTAdder = *(int**)((&derived));
	int*pVfTAdder1 = *(int**)((int)&derived + sizeof(CBase1));
	
	cout << "CBase0 " << sizeof(CBase0) << endl;
	cout << "CBase1 " << sizeof(CBase1) << endl;
	cout << "CBase2 " << sizeof(CBase2) << endl;
	cout << "CDerived " << sizeof(derived) << endl;

//printVfpTab(pVfTAdder1);
	cout << endl;
	printVfpTab(pVfTAdder);
	//derived._Itest0 = 1;//有可能是CBase1里面的CBase0::_Itest0也可能是CBase2的CBase0::_Itest0，
	CBase1 test;
	/*test.Print();*/
}

#include<iostream>
using namespace std;
class Parent
{
public:
	virtual void test(){ cout << "hehe" << endl; }
private:
};
class Child
{
public:
	;
private:
	;
};
int main()
{
	Parent object;
	Parent*p = &object;
	object.test();
	p->test();
	return 0;
}
#endif
#if(0)
//构造函数里面调用虚函数，能否实现多态
#include<iostream>
using namespace std;
class Base
{
public:
	Base()
	{
		Function();
	}

	virtual void Function()
	{
		cout << "Base::Function" << endl;
	}
};

class A : public Base
{
public:
	A() :Base()
	{
		Function();
	}

	virtual void Function()
	{
		cout << "A::Function" << endl;
	}
};
class C :public A
{
public:
	C() :A()
	{
		Function();
	}
	virtual void Function()
	{
		cout << "C::Function" << endl;
	}
};
class D :public C
{
public:
	D() :C()
	{
		Function();
	}
	virtual void Function()
	{
		cout << "D::Funtion" << endl;
	}
	virtual void  print()
	{
		cout << "hehe" << endl;
	}
};
class E :public D
{
public:
	E() :D()
	{
		Function();
	}
	virtual void Function()
	{
		cout << "E::Funtion" << endl;
	}
	virtual void print()
	{
		cout << "haha" << endl;
	}
};
typedef void(*Pdf)();
int main()
{
	E a;
	int*ptr = *(int**)&a;
	for (; *ptr != NULL; ptr++)
	{
		((Pdf)*ptr)();
	}
	system("pause");
	return 0;
}
#endif
//

//B() :_b(1)
//{

//}
//A() :_a(0)
//{
//	
//}
#include<iostream>
using namespace std;
class A
{
public:

	virtual void functest1()
	{
		cout << "A::functest1()" << endl;
	}
private:
	int _a;
};
class B:virtual public A
{
public:
	//重写基类的虚函数
	virtual void functest1()
	{
		cout << "B::functest1()" << endl;
	}
	////派生类新定义的虚函数
	virtual void functest2()
	{
	cout << "B::functest2()" << endl;
	}
private:
	int _b;
};
class B1 :virtual public A
{
public:
	//重写基类的虚函数
	virtual void functest1()
	{
		cout << "B1::functest1()" << endl;
	}
	////派生类新定义的虚函数
	virtual void functest3()
	{
		cout << "B1::functest2()" << endl;
	}
private:
	int _b0;
};
class C: public B, public B1
{
public:
	//重写A基类的虚函数
	virtual void functest1()
	{
		cout << "c::functest1()" << endl;
	}
	//重写B基类的虚函数
	virtual void functest2()
	{
		cout << "C::functest2()" << endl;
	}
	//重写B0基类的虚函数
	virtual void functest3()
	{
		cout << "C::functest3()" << endl;
	}
	//派生类新定义的虚函数
	virtual void functest4()
	{
		cout << "C::functest4()" << endl;
	}
private:
	int _c;
};
typedef void(*Pfun)();
void display(const B&b1)
{
	//把虚表的首地址放到pfun里面
	Pfun *pfun = (Pfun*)(*((int*)&b1));

	//遍历整个虚表
	while (*pfun)
	{
		(*pfun)();
		pfun++;
	}
}
int main()
{
	C c1;
	cout << sizeof(c1) << endl;
	display(c1);
	return 0;
}

