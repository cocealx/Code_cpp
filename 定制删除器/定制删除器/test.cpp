#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
struct  delsh
{
	template<class T>
	void operator()(T*ptr)
	{
		delete ptr;
	}
};
struct  delarray
{
	template<class T>
	void operator()(T*ptr)
	{
		delete[] ptr;
	}
};
template<class T,class D>
class shareptr
{

public:
	shareptr(T*ptr = NULL,D del=delsh())
		:_ptr(ptr),
		_pcount(new int(1)),
		_del(del)
	{};
	shareptr(const shareptr<T,D>& object, D del = delsh())
		:_ptr(object._ptr),
		_pcount(object._pcount),
		_del(del)
	{
		++(*_pcount);
	}
	~shareptr()
	{
		if (--(*_pcount) == 0)
		{
			printf("%p\n", _ptr);
			_del(_ptr);
			delete _pcount;
		}
	}
	shareptr<T,D>& operator=(const shareptr<T,D> &object)
	{
		if (--(*_pcount) == 0)
		{
			delete _ptr;
			delete _pcount;
		}
		_ptr = object._ptr;
		_pcount = object._pcount;
		++(*_pcount);
		return *this;
	}
	T operator*()
	{
		return *_ptr;
	}
	T*operator->()
	{
		return _ptr;
	}
private:
	T* _ptr;
	int* _pcount;
    D& _del;
};
struct AA
{
	~AA()
	{
		cout << "AA()" << endl;
	}
};
void testshared()
{
	shareptr <AA, delarray>sp1(new AA[10], delarray());
}
int main()
{
	testshared();
	return 0;
}
#include<iostream>
using namespace std;
class Oneobject
{
	static Oneobject*
};