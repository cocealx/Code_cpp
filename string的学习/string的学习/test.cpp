//#define _CRT_SECURE_NO_WARNINGS 1
//#include<iostream>
//using namespace std;
//int main()
//{
//	string s1 = "123456";
//	string s2(s1);
//	string s3 = s1;
//	string s4;
//	size_t len = s3.size();
//	s3 = "789";
//    len = s3.size();
//	len = s4.size();
//	s4 = "10111213";
//	len = s4.size();
//	s3 = s1 + s3;
//	s3 = s1 + "78910";
//	s3 = "789" + s1;
//	//s3 = "123" + "456";
//	int i = s3.find('1');
//}
//class String
//{
//public:
//	String();
//	String(const char*string);
//	String(String const &str);
//	~String();
//	//
//	String&operator = (const String&string);
//	String&operator = (const char* str);
//	//
//	friend::String operator + (const String str1, const String str2);
//	friend::String operator + (const string str1, const char*  str2);
//	//
//	int find(char ch);
//protected:
//	char*str;
//	size_t size;
//	size_t capacity;
//};
////默认构造函数
//String::String()
//{
//	str = new char[10];
//	str[0] = 0;
//	size = 0;
//	capacity = 10;
//	cout << "调用默认构造函数" << endl;
//}
////拷贝构造函数
//String::String(String const &string)
//{
//	size = string.size;
//	str = new char[capacity];
//	strcpy(str, string.str);
//}
////构造函数
//String::String(const char*string)
//{
//	size = strlen(string);
//	str = new char[size+20];
//	strcpy(str, string);
//}
////析构函数
//String::~String()
//{
//	delete[] str;
//	cout << "调用析构函数" << endl;
//}
////=运算符重载
//String& String::operator= (const String& string)
//{
//	if (this == &string)
//		return *this;
//	delete[]this->str;
//	size =string.size;
//	str = new char[string.capacity];
//	strcpy(str, string.str);
//	return *this;
//}


//
//#define _CRT_SECURE_NO_WARNINGS 1
//#include<iostream>
//using namespace std;
//class String
//{
//public:
//	String(char* ptr = "")
//	{
//		if (NULL == ptr)
//		{
//
//			_ptr = "";
//
//		}
//		int len = strlen(ptr);
//		_ptr = new char[len + 1];
//		strcpy(_ptr, ptr);
//	}
//	String(const String&str) :_ptr(NULL)//必须初始化，不然用swap()交换的时候，_ptr是随机值，释放的时候可能出问题
//	{
//		String temp(str._ptr);
//		/*	int len = strlen(str._ptr);
//		_ptr = new char[len + 1];
//		strcpy(_ptr, str._ptr);*/
//		swap(_ptr, temp._ptr);
//	}
//	String&operator=(String /*&s1*/temp)
//	{
////       if(this==&s1)
////         return *this;
//		/*String temp(s1);*/
//		swap(_ptr, temp._ptr);
//		return *this;
//	}
//	~String()
//	{
//		delete[] _ptr;
//		cout << "String()" << endl;
//	}
//private:
//	char* _ptr;
//};
//void testString()
//{
//	String S1("123");
//	String S2(S1);
//	String S3;
//	S3 = S1;
//}
//int main()
//{
//	testString();
//	//int p = 1;
//	//int q = 2;
//	//cout << p << q << endl;
//	//swap(p, q);
//	//cout << p << q << endl;
//	return 0;
//}
//1.什么是浅拷贝，里面存在什么问题？
//2.用深拷贝怎么解决，给出深拷贝的两种书写方式：普通版和简洁版
//3.什么是引用计数，用引用计数能解决浅拷贝存在的问题吗？ 怎么解决
//4、对引用计数进行改进，完成string的引用计数版本。即写时拷贝
//5、把课件链接中的文章好好学习下，做好总结
//6、在深拷贝版本的任何一个string类中，完成以下函数，要求：不能调用库函数
#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
using namespace std;
class String	
{
public:
	String(char* pStr = "")
	{
		if (pStr == NULL)
		{
			pStr = "";
		}
		size_t len = strlen(pStr);
		_pStr = new char[len + 1];
		strcpy(_pStr, pStr);
	}
	String(const String& s) :_pStr(NULL)
	{
		String temp(s._pStr);
		swap(_pStr, temp._pStr);
	}
	String& operator=(const String& s)
	{
		if (this == &s)
			return *this;
		String temp(s);
		swap(_pStr, temp._pStr);
		return*this;
	}
	~String()
	{
		delete _pStr;
	}

	// 不能使用库函数 
	size_t Size()const;
	size_t Lengh()const
	{
		char*src = _pStr;
		while (*src)
		{
			src++;
		}
		return src - _pStr;
	}
	char& operator[](size_t index)
	{
		return _pStr[index];
	}
	const char& operator[](size_t index)const
	{
		return _pStr[index];
	}
	bool operator>(const String& s)
	{
		char*src1 = _pStr;
		char*src2 = s._pStr;
		while (*src1 == *src2)
		{
			src1++;
			src2++;
		}
		if (*src1 > *src2)
			return true;
		return false;
	}
	bool operator<(const String& s)
	{
		char*src1 = _pStr;
		char*src2 = s._pStr;
		while (*src1 == *src2)
		{
			src1++;
			src2++;
		}
		if (*src1 < *src2)
			return true;
		return false;
	}
	bool operator==(const String& s)
	{
		if (s.Lengh() == Lengh())
		{
			char*src1 = _pStr;
			char*src2 = s._pStr;
			while (*src1 == *src2)
			{
				if (!*src1)
					return true;
				src1++;
				src2++;
			}
		}
		return false;
	}
	bool operator!=(const String& s)
	{
		if (s.Lengh() == Lengh())
		{
			char*src1 = _pStr;
			char*src2 = s._pStr;
			while (*src1 == *src2)
			{
				if (!*src1)
					return false;
				src1++;
				src2++;
			}
		}
		return true;
	}
	void Copy(const String& s)
	{
		if (this == &s)
			return;
		String temp(s);
		swap(_pStr, temp._pStr);
	}
	bool strstr(const String& s)
	{
		char*ps1 = _pStr;
		while (*ps1)
		{
			char*temp_ps1 = ps1;
			char*ps2 = s._pStr;
			while (*temp_ps1==*ps2&&*ps2)
			{
				temp_ps1++;
				ps2++;
			}
			if (!*ps2)
				return true;
			if (!*temp_ps1)
				return false;
			ps1++;
		}
		return false;
	}
	String& operator+=(const String&s)
	{
		size_t len = s.Lengh() + Lengh();
		char*Ps = new char[len + 1];
		char*temp = Ps;
		char*_tpstr = _pStr;
		while (*temp = *_tpstr)
		{
			temp++;
			_tpstr++;
		}
		_tpstr = s._pStr;
		while (*temp++ = *_tpstr++)
		{
		}
		delete _pStr;
		_pStr = Ps;
		return *this;
	}
private:
	char* _pStr;
};
void testString()
{
	String s1("12345");
	String s2("123457");
	String s3(s1);
	String s4("123455");
	String s5("abcdef");
	if (s4 > s3)
		cout << "s4>s3" << endl;
	String s6("gh");
	s3 = s2;
	if (s3.strstr(s1))
		cout << "s1是s3的子字符串" << endl;
	if (s1.strstr(s4))
		cout << "s4是s1的子字符串" << endl;
	cout << s1.Lengh() << endl;
	s6 += s5;
	s4[s4.Lengh() - 1] = '6';
	if (s4< s3)
		cout << "s4<s3" << endl;
	s4.Copy(s3);
}
int main()
{
	testString();
	return 0;
}
//#include<iostream>
//using namespace std;
//class String
//{
//public:
//	String(const char*ptr = "")
//	{
//		if (!ptr)
//		{
//			ptr = "";
//		}
//		int len = strlen(ptr);
//		_ptr = new char[len + 1 + 4];
//		_ptr += 4;
//		Getcount() = 1;
//	}
//	String(const String&s1):_ptr ( s1._ptr)
//	{
//	
//		++s1.Getcount();
//	}
//	String& operator=(const String&s1)
//	{
//
//		if (--Getcount() == 0)
//		{
//			release();
//		}
//		++s1.Getcount();
//	}
//	char&operator[](size_t index)
//	{
//		if (Getcount() != 1)
//		{
//			String temp(_ptr);
//			if (--Getcount() == 0)
//			{
//				release();
//			}
//			_ptr = temp._ptr;
//			temp._ptr = NULL;
//		}
//		return _ptr[index];
//	}
//	~String()
//	{
//		if (--Getcount() == 0)
//		{
//			release();
//		}
//	}
//private:
//	void release()
//	{
//		if (_ptr != NULL)
//		{
//			_ptr -= 4;
//			delete[]_ptr;
//		}
//	}
//	int& Getcount()const
//	{
//		return*(int*)(_ptr - 4);
//	}
//	char*_ptr;
//};
//void testSring()
//{
//
//}
//int main()
//{
//	testSring();
//	return 0;
//}