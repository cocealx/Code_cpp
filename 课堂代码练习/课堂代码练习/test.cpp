#define _CRT_SECURE_NO_WARNINGS 1
//#define _CRT_SECURE_NO_WARNINGS 1
//#include<stdio.h>
////������û�в���ʱ��C��C++������Ա�
////C��������£���һ������û�з���ֵʱ��Ĭ�Ϸ���ֵΪint�ͣ�
////����û�в���ʱ������������������������������ʱ���������ѹջ
// /*ADD()
//{
//}*/
////C++��������£���һ������û�в���ʱ������ʱ�ͻᱨ��
////(error C4430: ȱ������˵���� - �ٶ�Ϊ int��ע��:  C++ ��֧��Ĭ�� int)
////����û�в���ʱ������������������ʱ������ᱨ��error C2660: ��ADD��: ���������� 1 ��������
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
//ȱʡ����:ȱʡʱ������ҵ���ȱʡ���м䲻�ܶϿ�
//����ʱ���Ǵ����Ҹ�ֵ
//�����Ͷ��岻��ͬʱ����ȱʡ
//void ADD(int x=0,int y=0)
//{
//
//}
//int main()
//{
//	ADD();
//	ADD(1);//�����Ҹ�ֵ
//	ADD(1, 2);
//}
//��������
//c:������֧��������Ϊ����C�������Ժ�������ʱ��ֻ���ں�����ǰ���˸�_�����Ե���������������һ��ʱ��
//��������ʱ�����˶����ԣ�����������֪����������Ҫ�ĺ�������
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
////C++������֧�����أ���C++�������Ժ�������ʱ����Ժ������ֽ������⴦��
////�µĺ�������ʽ�ǣ�?@������@@YA�������Ͳ����б�@Z���������û�в���
////�������ָ�ʽ��?@������@@YA��������XZ
////H ����int X����void D ����char  M����float N����double
//void ADD(char);//1.����ĺ����� ?ADD@@YAXD@Z
////int ADD(char);//2.����ĺ����� ?ADD@@YAHD@Z 
////�ܽ᣺����������������Ȼ���������������ˣ����ǲ��ܹ������أ�
////��Ϊ��׼��û�аѷ������ͷŽ����ص����������Բ�һ���ı��������ܶԷ��������Ҳ�һ���Ĵ���
//int ADD(int x);//����ĺ����� ?ADD@@YAHH@Z
//void ADD(float );//����ĺ����� ?ADD@@YAXM@Z
//void ADD(double);//����ĺ����� ?ADD@@YAXN@Z
//int main()
//{
//	ADD(1);
//    ADD('1');//
//	ADD(1);//
//	ADD(1.1f);
//	ADD(1.1);
//}
//// C++�������ص�����:1.������ͬһ������  2.��������ͬ��  3.�����겻ͬ(��������������˳�򣬲�������)


//�������غ�ȱʡ
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
//	//ADD();//����������ԣ������޷�ȷ�����õ��ǵ�һ�����ǵڶ���
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
ADD(2,'1');//����char,char,���2�����ַ���ASC��ֵ
test(2, '1');//�ַ��͵�ƥ�䲻�ϣ����Խ����������int int
//SUB(2, '1')�� SUB('1', 2);;//���� ��ADD��: 2 �����������Ƶ�ת��
//�����ǡ�void ADD(int,int)�� ��  ��void ADD(char,char)������������֪����2����ASC��ֵ�����ǵ������Ͷ�char��������
DUL(2, '1');//��char������������� int int
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
//	const int&a = b;//�м������һ����ʱ���������õĲ���b����������ʱ����
//	cout << &a << endl;
//	cout << &b << endl;
//	cout << a << endl;
//	test(1);
//	cout << &a << endl;
//	cout << &b << endl;
//	cout << a << endl;
//}
//�������ι��̣�
//1.�ȴ�����������д�����
//call funtest(��ַox12345678)------->jmp--------->  λ��(��������ʵ��ַ)
//������������תָ���λ�ã�Ȼ�����תָ���������ʵ��ַ


////����������
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
//	ADD(a, *p1);//�ܱ���������һ������У���ADD()�����е�a=b;����
//	            //ADD()�ڴ���ʱ����û�ж�p1�����ã����ǰ�p1��ֵ����ȥ
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
////����޸�thisָ�룬ʹthisָ��Ϊ��
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
//�������Ĭ�ϳ�Ա���� 1.���캯�� 2.�������캯�� 3.�������� 4.��ֵ���������� 5.ȡ��ַ���������� 6.const ���ε�ȡ��ַ����������
//#include<iostream>
//#include<string.h>
//#include<stdlib.h>
//class  CDate
//{
//public:
//	//��̬����
//	static void STAtic( /*CDate*  temp*/);
//
//	//���캯��
//	CDate(char name[], int old, char *sex) :_old(old)
//	{
//		strcpy(_name, name);
//		strcpy(_sex, sex);
//		count++;
//	};
//	//Ĭ�Ϲ��캯��
//	CDate()
//	{
//		memset(this, 0, sizeof(CDate));
//		count++;
//		std::cout << "call -->Ĭ�Ϲ��캯��" << std::endl;
//	}
//	//��������
//	~CDate()
//	{
//		std::cout << "call--->��������" << std::endl;
//		count--;
//	};
//	void display()
//	{
//		std::cout << _name << "  " << "���䣺" << _old << "�Ա�" << _sex << std::endl;
//		//std::cout << "������ܸ�����" << count << std::endl;
//		STAtic();
//	}
//	//�������캯��
//	CDate( const CDate& temp)
//	{
//		_old = temp._old;
//		strcpy(_name, temp._name);
//		strcpy(_sex, temp._sex);
//		count++;
//		std::cout << "call -->�������캯��" << std::endl;
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
//	//	std::cout << "call -->�������캯��" << std::endl;
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
//	std::cout << "������ܸ�����" << count << std::endl;
//}
//int main()
//{
//	CDate*p = NULL;
//	CDate date1{ "liugang", 10, "��" };
//	date1.display();
//	//CDate::STAtic(&date1);
//	CDate date2(date1);
//	//CDate::STAtic(&date2);
//	date2.display();
//	//date2.ADD().display();
//	//CDate temp1��������ʱ��û�е��ÿ������캯������temp1�ĵ�ַ����ȥ��Ȼ��date2.ADD()�����ڷ���ʱ�᷵��һ������
//	//���ض���ʱ�ᴴ���µĶ��󷵻أ�����������û���м䴴���µĶ��󣬶��ǰ�temp1�ĵ�ַ����������ͨ���������캯��ֱ�ӿ�����temp1��
//	//�����������һ���漰2����һ����temp1��һ����ADD()����������һ����ʱ���󡣣��������Ż�����
//	//CDate temp1(date2.ADD());
//	//temp1.display();
//	//��������ADD()�������صĶ����������
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
//	//���캯��
//	TEST(char name[], int old, char *sex) :_old(old)
//		{
//			strcpy(_name, name);
//			strcpy(_sex, sex);
//			count++;
//		};
//	//Ĭ�Ϲ��캯��
//	TEST()
//		{
//		memset(this, 0, sizeof(TEST));
//			count++;
//			std::cout << "call -->Ĭ�Ϲ��캯��" << std::endl;
//		}
//	//��������
//	~TEST()
//		{
//			std::cout << "call--->��������" << std::endl;
//			count--;
//		};
//		void display()
//		{
//			std::cout << _name << "  " << "���䣺" << _old << "�Ա�" << _sex << std::endl;
//			//std::cout << "������ܸ�����" << count << std::endl;
//		}
//	//�������캯��
//	TEST(const TEST& temp)
//		{
//			_old = temp._old;
//			strcpy(_name, temp._name);
//			strcpy(_sex, temp._sex);
//			count++;
//			std::cout << "call -->�������캯��" << std::endl;
//		}	
//	//ȡ��ַ���������
//	TEST* operator&()
//	{
//		return this;
//	}
//	//const���ε�ȡ��ַ���������
//	const TEST*operator &()const
//	{
//		return this;
//	}
//	//ǰ��++���������
//    TEST& TEST:: operator++();
//	//����++���������
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
////���طǳ�Ա���������ʱ���亯�������������������ͻ�ö�����͡�
////int operator+(int t1, int t2)
////{
////	return t1 + t2;
////}
//
//
////ǰ��++���������
//TEST& TEST:: operator++()
//{
//	_old = _old + 1;
//	cout << "����ǰ��++��������س�Ա����" << endl;
//	return *this;
//}
////����++���������
//const TEST TEST:: operator++(int)
//{
//	TEST ret = *this;
//	_old++;
//	cout << "���ú���++��������س�Ա����" << endl;
//	return ret;
//}
////<<�����������
////���ܷ���ostream������Ϊ��û��Ĭ�Ϲ��캯����ֻ�ܷ���ָ���������
////���ԾͲ��ܴ���һ��ostream����ֻ�ܴ�����������
//ostream& operator<<(ostream &os, const TEST&temp)
//{
//	os <<"����"<< temp._name<< std::endl;
//	return os;
//}
//int main()
//{
//	ostream &cout1(cout);
//	TEST  people1{ "liugang", 10, "��" };
//	const TEST  people2{ "wqg", 21, "��" };
//	TEST *p1 = &people1;
//	const TEST*p2 = &people2;
//	TEST people3 = people1 + people2;
//	people3.display();
//	cout1 << people2 << "����<<��������غ���"<<endl;
//	++people1;
//	people1++;
//	return 0;
//}
#include<iostream>
int main()
{
	

}
