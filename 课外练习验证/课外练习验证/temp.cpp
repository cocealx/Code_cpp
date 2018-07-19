#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<Windows.h>
using namespace std; 
#if 0
void test()
{
	static int i = 0;
	int k = i + 1;
}
int main()
{
	int i(10);
	int k = 10;
	i = 11;
	k = 11;
	OutputDebugString(L"-----------------------\n"
		L"在调试窗口输出调试信息\n"
		L"----------------------\n");
	test();
	return 0;
}
#endif
#include<iostream>
using namespace std;
class temp
{
public: 
	temp()
	{
		/*_pDatta = new char[20];
		strcpy(_pDatta, "hello bit");*/
		i = 111;
	}
	~temp()
	{
		cout << "调用析构函数" << endl;
	}
		/*char * _pDatta;*/
	int i;
};
temp test()
{
	temp w;
	return w;
}
int main()
{
	temp ret = test();
	cout << "12345" << endl;
	temp*tp = &temp();
	int m = 1234;
	printf("%d\n",m);
	cout << ret.i<< endl;
	cout << tp->i<< endl;
	return 0;
}