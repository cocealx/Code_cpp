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
	free(T);//�������
	//delete[]T0;//�޷�ȷ�������������õĴ����������
	delete T1;//������������ʱ�������û��ʱ���ᱼ��
	//free(T21);//�ᱼ���������ĸ��޷�ȷ������Ҫ�ͷŶ��ռ�
	//delete T2;//�������T2��new[]���ٵģ���������࿪���ĸ��ֽ�����¼���������ĵ��ô������ͷŵ�ʱ����޷�ȷ���ͷŶ��ռ�
	delete T3;//�������
	//delete[]T31;//�᳢��ȷ�����׵��ö��ٴ���������������malloc���ٵĿռ䲢����ר���ٶ࿪���ĸ��ֽ�����¼�������������Ĵ���
	return 0;
	
}
