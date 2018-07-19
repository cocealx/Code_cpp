//#define _CRT_SECURE_NO_WARNINGS 1
//#include<iostream>
//using namespace std;
//class CBase
//{
//public:
//	virtual void FunTest1(int _ITest){ cout << "CBase::FunTest1()" << endl; }
//	void FunTest2(int _Test){ cout << "CBase::FunTest2()" << endl; }
//	virtual void FunTest3(int _ITest){ cout << "CBase::FunTest3()" << endl; }
//	virtual void FunTest4(int _ITest){ cout << "CBase::FunTest4()" << endl; }
//	virtual ~CBase(){ cout << "调用CBase的析构函数" << endl; }
//};
//class CDerived:public CBase
//{
//public:
//
//	/*virtual */void FunTest1(int _ITest){ cout << "CDerived::FunTest1()" << endl; }
//	virtual void FunTest2(int _Test){ cout << "CDerived::FunTest2()" << endl; }
//    void FunTest3(int _ITest){ cout << "CDerived::FunTest3()" << endl; }
//	//不是重写，是重新定义，基类的FunTest4()函数将会被隐藏
//	virtual void FunTest4(int _ITest1,int _ITest2){ cout << "CDerived::FunTest4()" << endl; }
//	virtual ~CDerived(){ cout << "调用CDerived的析构函数" << endl; }
//};
//class Temp : public CDerived
//{
//public:
//	void FunTest1(int _ITest){ cout << "TCDerived::FunTest1()" << endl; }
//	void FunTest2(int _Test){ cout << "TCDerived::FunTest2()" << endl; }
//	void FunTest3(int _ITest){ cout << "TCDerived::FunTest3()" << endl; }
//	//不是重写，是重新定义，基类的FunTest4()函数将会被隐藏
//	//void FunTest4(int _ITest1){ cout << "TCDerived::FunTest4()" << endl; }
//	/*virtual*/ void FunTest4(int _ITest1, int _ITest2){ cout << "TCDerived::FunTest4()" << endl; }
//	//void FunTest4(int _ITest){ cout << "TCDerived::FunTest4()" << endl; }
//	virtual ~Temp(){ cout << "调用Temp的析构函数" << endl; }
//};
//int main()
//{
//	CBase*pBase = new CDerived;
//	CDerived*pCDerived = new Temp;
//	CBase*pBase3 = new Temp;
//	Temp temp;
//	CDerived CD;
//	temp.FunTest4(0, 0);
//	CD.FunTest4(0, 0);//基类Base的Funtest4()会被隐藏
//
//	//以Base为基类
//	pBase->FunTest1(0);//CD，因为基类CB的FunTest2()函数是虚函数,所以会动态联编
//	pBase->FunTest2(0);//CB,因为基类CB的FunTest2()函数,并不是虚函数,所以不会动态联编
//	pBase->FunTest3(0);//CD
//	pBase->FunTest4(0);//CB，虽然基类CB的FunTest4()是虚函数,但是在派生类并没有重写，而是重新定义，所以只能调用基类CB的FunTest4()函数
//	//pBase->FunTest4(0,0);//错误，重新定义了，所以CDerived派生类型中的FunTest4()被隐藏，只能调用基类的函数，基类的只能接受一个参数
//	cout << endl;
//    //以pCDerived为基类
//	pCDerived->FunTest1(0);// 1 TCD,因为CDerived以Base为基类，FunTest1()是虚函数，所以他为基类的派生类型都会进行动态联编
//	pCDerived->FunTest2(0);// 2 TCD，虽然CDerived的Base为基类FunTest2()不是虚函数，但是CDerived声明的FunTest2()虚函数，以CDerived为基类的派生类型都会进行动态联编
//	pCDerived->FunTest3(0);// 3 TCD，同1
//	pCDerived->FunTest4(0, 0);//TCD，基类CDerived把他声明为了虚函数，所以以CDerived为基类时，会进行动态联编
//	//pBase1->FunTest4(0);//错误
//	cout << endl;
//	//以Base为基类
//	pBase3->FunTest1(0);//TCD，因为基类CB的FunTest2()函数是虚函数,所以会动态联编
//	pBase3->FunTest2(0);//CB，因为基类CB的FunTest2()函数,并不是虚函数,所以不会动态联编
//	pBase3->FunTest3(0);//TCD，因为基类CB的FunTest2()函数是虚函数,所以会动态联编
//	pBase3->FunTest4(0);//CB，虽然基类CB的FunTest4()是虚函数，而且在以CDerived基类时进行重写了,但是在派生类Temp并没有重写Base基类的FunTest4()，而是重新定义，所以只能调用基类CB的FunTest4()函数
//	//pBase3->FunTest4(0,0);//错误，重新定义了，所以Temp和CDerived派生类型中的FunTest4()被隐藏，只能调用基类Base的函数，基类的只能接受一个参数
//	return 0;
//}
#include<iostream>
using namespace std;
//class Base
//{
//public:
//	Base(int pub = 0, int pro = 1, int pri = 2)
//		:_pub(pub),
//		_pro(pro),
//		_pri(pri)
//	{
//		cout << "B()" << endl;
//	}
//	~Base()
//	{
//		cout << "~B()" << endl;
//	}
//	void ShowBase()
//	{
//		cout << "_pri = " << _pri << endl;
//		cout << "_pro = " << _pro << endl;
//		cout << "_pub = " << _pub << endl;
//	}
//public:
//	int _pub;
//protected:
//	int _pro;
//private:
//	int _pri;
//};
//class Base1
//{
//public:
//	Base1(int pub1 = 3, int pro1 = 4, int pri1 = 5)
//		:_pub1(pub1),
//		_pro1(pro1),
//		_pri1(pri1)
//	{
//		cout << "B()" << endl;
//	}
//	~Base1()
//	{
//		cout << "~B1()" << endl;
//	}
//	void ShowBase1()
//	{
//		cout << "_pri = " << _pri1 << endl;
//		cout << "_pro = " << _pro1 << endl;
//		cout << "_pub = " << _pub1 << endl;
//	}
//public:
//	int _pub1;
//protected:
//	int _pro1;
//private:
//	int _pri1;
//};
//class Derived :public Base/*,public Base1*/
//{
//public:
//	Derived(int Dpub = 6,int Dpro=7,int Dpri =8)
//		:_Dpub(Dpub),
//		_Dpro(Dpro),
//		_Dpri(Dpri)
//	{
//		cout << "Derived()" << endl;
//	}
//	~Derived()
//	{
//		cout << "~Derived()" << endl;
//	}
//	void ShowDerived()
//	{
//		cout << "_pro=" << _pro << endl;
//		cout << "_Dpri = " << _Dpri << endl;
//		cout << "_Dpro = " << _Dpro << endl;
//		cout << "_Dpub = " << _Dpub << endl;
//	}
//public:
//	int _Dpub;
//protected:
//	int _Dpro;
//private:
//	int _Dpri;
//};
//void test0()
//{
//	Derived d1;
//	d1.ShowBase();
//	cout << endl;
//	d1.ShowDerived();
//	cout << endl;
//	d1._pub = 10;
//	d1._Dpub = 11;
//	d1.ShowBase();
//	cout << endl;
//	d1.ShowDerived();
//	cout << endl;
//}
class Base
{
public:
	Base(int pub = 0, int pri = 1) :_pub(pub), _pri(pri)
	{
		cout << "Base()" << endl;
	}
	int _pub;
private:
	int _pri;

};
class Deiverd0:public Base
{
public:
	Deiverd0(int Dpub0 = 2, int Dpri0 = 3) :_Dpub0(Dpub0), _Dpri0(Dpri0)
	{
		cout << "Deiverd0()" << endl;
	}
	int _Dpub0;
private:
	int _Dpri0;
};
class Deiverd:public Base
{
public:
	Deiverd(int Dpub = 4, int Dpri = 5) :_Dpub(Dpub), _Dpri(Dpri)
	{
		cout << "Deiverd()" << endl;
	}
	int _Dpub;
private:
	int _Dpri;
};
class Final:public Deiverd0,public Deiverd
{
public:
	Final(int fpub = 7, int fpri = 8) :_fpub(fpub), _fpri(fpri)
	{
		cout << "Final()" << endl;
	}
	int _fpub;
private:
	int _fpri;
};
void test0()
{
	Final f1;
	//f1._pub = 5;
	f1.Deiverd::_pub = 5;
	f1.Deiverd0::_pub = 5;
}
int main()
{
	
	test0();
	return 0;
}