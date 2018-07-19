#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include<cstdlib>
template<class T>
class SList
{
public:
	SList();
	~SList();
	void PushBack(const T &x)
	{
		CheckCapacity();
//����������ͣ�ͨ��malloc���ٵĿռ䲢������ù��캯����Ҳ����˵��
//��_a[_size]���Ե������ǵĸ�ֵ�������ʱ������������Ӧ����new�����ٿռ�
		_a[_size] = x;
		++_size;
	}
	void PopBack()
	{
		if (_size > 0)
			--_size;
	}
	SList(const SList<T>&object)
	{
		_a = new T[object._size];
		for (size_t i = 0; i < object._size; i++)
		{
			_a[i] = object._a[i];
		}
		/*memcpy(_a, object._a, object._size*sizeof(T));*/
		_size = object._size;
		_capacity = object._capacity;
	}
	SList&operator=( SList<T> object)
	{
		if (this == &object)
			return *this;
	/*	delete[] _a;*/
	/*	_a = new T[_size];*/
		T*temp = object._a;
		object._a = _a;
		_a = temp;
	/*	free(_a);*/
		/*_a =(T*) malloc(_size*sizeof(T));*/
		//*_a=*object._a   //malloc ���ٵĿռ䲻��ֱ�ӽ����ø�ֵ

		//���T�������ͣ��������漰����̬�ڴ濪�٣�ʹ��memcpy()�ͻ�������⣬Ҳ������ǳ��������
		/*memcpy(_a, object._a, object._size*sizeof(T));*/
		_size = object._size;
		_capacity = object._capacity;
		return*this;
	}
	void Print()
	{
		size_t i = 0;
		for (i = 0; i < _size; i++)
		{
			cout << _a[i] <<endl;
		}
	}
protected:
	void CheckCapacity()
	{
		/*T*temp = NULL;
		if (_size == _capacity)
		{
			temp = (T*)realloc(_a, (_capacity * 2 + 3)*sizeof(T));
			if (temp == NULL)
			{
				return;
			}
			_a = temp;
			_capacity = _capacity * 2 + 3;
		}*/
		if (_size == _capacity)
		{
			T*temp = _a;
			_a = new T[_capacity * 2 + 3];
			/*memcpy(_a, temp, sizeof(T)*_size);*/
			for (size_t i = 0; i < _size; i++)
			{
				_a[i] = temp[i];
			}
			delete[]temp;
			_capacity = _capacity * 2 + 3;
		}
	}
	T*_a;
	size_t _size;
	size_t _capacity;
};
template<class T>
SList<T>::SList() :_a(NULL), _size(0), _capacity(0)
{

}
template < class  T>
SList<T>::~SList()
{
	delete[]_a;
	/*free(_a);*/
	_size = _capacity = 0;
}

