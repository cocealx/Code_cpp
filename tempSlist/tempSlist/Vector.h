#pragma once
//������ȡ
struct Istrue
{
	bool Get()
	{
		return true;
	}
};
struct Isflase
{
	bool Get()
	{
		return false;
	}
};
template<class T>
struct ISTypename
{
	//Ĭ�����Ϊ���������ͣ���Ϊ���������;Ͳ�����memcpy
	typedef Isflase IsType;
};

//ֻ�ػ�һ������������
template<>
struct ISTypename<int>
{
	typedef Istrue IsType;
};

template<>
struct ISTypename<double>
{
	typedef Istrue IsType;
};
template<>
struct ISTypename<float>
{
	typedef Istrue IsType;
};
template<>
struct ISTypename<char>
{
	typedef Istrue IsType;
};
//ʵ��Vector�����½ӿڣ�
#include<iostream>
#include<assert.h>
using namespace std;
template<class T>
class Vector
{
public:
	//Ĭ�Ϲ��캯��
	Vector() :_start(NULL), _finish(NULL), _endOfStorage(NULL)
	{

	}
	//���캯��
	Vector(const T* array, size_t size) :_start(new T[size]),
		_finish(_start + size),
		_endOfStorage(_start + size)
	{
		if (!ISTypename<T>::IsType().Get())
		{
			for (size_t i = 0; i < size; i++;)
			{
				_start[i] = array[i];
			}
		}
		else
		{
			memcpy(_start, array, size*sizeof(T));
		}
	}
	//�������캯��
	Vector(const Vector& v) :_start(new T[v.Size()]),
		_finish(_start + v.Size()),
		_endOfStorage(_finish)
	{
		//���Ϊ���������;���forѭ����Ч�ʵͣ�������ȷ�Ը�
		if (!ISTypename<T>::IsType().Get())
		{
			for (size_t i = 0; i < v.Size(); i++)
			{
				_start[i] = v._start[i];
			}
		}
		else
		{
			//����������memcpy(),��Ϊ�����漰�����������Ч�ʱȽϸ�
			memcpy(_start, v._start, v.Size()*sizeof(T));
		}
	}
	//��ֵ���������
	Vector& operator=(const Vector& s)
	{
		if (_start)
		{
			delete[]_start;
		}
		_start = new T[s.Capacity()];
		if (!ISTypename<T>::IsType().Get())
		{
			for (size_t i = 0; i < s.Size(); i++)
			{
				_start[i] = s._start[i];
			}
		}
		else
		{
			memcpy(_start, v._start, v.Size()*sizeof(T));
		}
		_finish = _start + s.Size();
	}
	~Vector()
	{
		if (_start)
			delete[]_start;
		_finish = _start = _endOfStorage = NULL;
	}
		///////////////////Modify//////////////////////////////// 
	void PushBack(const T& data)
	{
		_CheckCapacity();
		*_finish = data;
		++_finish;
	}
	void PopBack()
	{
		if (!Empty())
			--_finish;
	}
	void Insert(size_t pos, const T& data)
	{
		assert(pos >= 0 && pos<=Size());
		_CheckCapacity();
		//**��Ҫ����pos�����pos����0������ѭ���ˣ�i���޷�������
		for (size_t i = Size(); i > pos; i--)
		{
			_start[i] = _start[i - 1];
		}
		_start[pos] = data;
		++_finish;
	}
	void Erase(size_t pos)
	{
		assert(pos >= 0 && pos < Size());
		for (size_t i = pos; i < Size()-1; i++)
		{
			_start[i] = _start[i + 1];
		}
		--_finish;
	}

		//////////////////capacity//////////////////////////// 
	size_t Size()const
	{
		return _finish - _start;
	}

	size_t Capacity()const
	{
		return _endOfStorage - _start;
	}
	bool Empty()const
	{
		return _finish == _start;
	}
	void Resize(size_t newSize, const T& data = T())
	{
		if (newSize <= Size())
		{
			_finish = _start + newSize;
		}
		else if (Size() <newSize&&newSize <= Capacity())
		{
			for (size_t i = Size(); i < newSize; i++)
			{
				_start[i] = data;
			}
			_finish = _start + newSize;
		}
		else
		{
			T*temp = new T[newSize];
			if (!ISTypename<T>::IsType().Get())
			{
				for (size_t i = 0; i < Size(); i++)
				{
					temp[i] = _start[i];
				}
			}
			else
			{
				memcpy(temp, _start, Size()*sizeof(T));
			}
			for (size_t i = Size(); i < newSize; i++)
			{
				temp[i] = data;
			}
			delete[]_start;
			_start = temp;
			_finish = _endOfStorage = temp + newSize;
		}
	}
	//////////////Acess/////////////////////////// 
	T& operator[](size_t index)
	{
		assert(_start);
		return _start[index];
	}
	const T& operator[](size_t index)const
	{
		assert(_start);
		return _start[index];
	}
	T& Front()
	{
		assert(_start);
		return _start[0];
	}
	const T& Front()const
	{
		assert(_start);
		return _start[0];
	}
	T& Back()
	{
		assert(_start);
		return _start[Size()-1];
	}
	const T& Back()const
	{
		assert(_start);
		return _start[Size() - 1];
	}
	void Clear()
	{
		_finish = _start;
	}
private:
	void _CheckCapacity()
	{
		if (_finish == _endOfStorage)
		{
			T*temp = new T[Capacity() * 2 + 3];

			if (!ISTypename<T>::IsType().Get())
			{
				for (size_t i = 0; i < Size(); i++)
				{
					temp[i] = _start[i];
				}
			}
			else
			{
				memcpy(temp, _start, Size()*sizeof(T));
			}
			_finish = temp + Size();
			_endOfStorage = temp + Capacity()*2+3;
			delete[]_start;
			_start = temp;
		}
	}
private:
	T* _start;
	T* _finish;
	T* _endOfStorage;
	//�������Ϊģ�庯���Ļ����Ͳ��������涨�壬ֻ������һ�£���Ȼ��ʵ�л���ͬ����ʱ����������ģ�庯���Ķ��塣
    //template<class T>
	friend ostream& operator<<(ostream& _cout, const Vector<T>&data)
	{
			for (size_t i = 0; i < data.Size(); i++)
			{
				_cout << data._start[i] << " ";
			}
			return _cout;
	}
};
