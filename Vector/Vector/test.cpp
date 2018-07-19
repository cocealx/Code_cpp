#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<assert.h>
#include<string>
using namespace std;
struct IsTrue
{
	bool Get()
	{
		return true;
	}
};
struct IsFalse
{
	bool Get()
	{
		return false;
	}
};
template<class T>
struct TypeName
{
	typedef IsFalse IsPODType;
};
template<>
struct TypeName<int>
{
	typedef IsTrue IsPODType;
};
template<>
struct TypeName<double>
{
	typedef IsTrue IsPODType;
};
template<>
struct TypeName<float>
{
	typedef IsTrue IsPODType;

};
template<>
struct TypeName<char>
{
	typedef IsTrue IsPODType;
};
//完成标准容器Vector
template<typename T>
class Vector
{
public:
	typedef T* Iterator;
	typedef const T* ConstIterator;
public:
	Vector()
		: _start(0)
		, _finish(0)
		, _endOfStorage(0)
	{}

	Vector(const T* array, size_t size) :_start(new T[size]),
		_finish(_start+size),
		_endOfStorage(_finish)
	{
		if (TypeName<T>::IsPODType().Get())
		{
			memcpy(_start, array, size*sizeof(T));
		}
		else
		{
			for (size_t i = 0; i < size; i++)
			{
				_start[i] = array[i];
			}
		}
	}
	Vector(const Vector& v) :_start(new T[v.Size()]),
		_finish(_start + size()),
		_endOfStorage(_finish)
	{
		if (TypeName<T>::IsPODType().Get())
		{
			memcpy(_start, array, v.Size()*sizeof(T));
		}
		else
		{
			for (int i = 0; i <v.Size(); i++)
			{
				_start[i] = array[i];
			}
		}
	}
	Vector& operator=(const Vector& s)
	{
		if (&s == this)
			return *this;

		delete _start;
		_start = new T[s.Size()];
		if (TypeName<T>::IsPODType().Get())
		{
			memcpy(_start, array, s.Size()*sizeof(T));
		}
		else
		{
			for (int i = 0; i <s.Size(); i++)
			{
				_start[i] = array[i];
			}
		}
		_endOfStorage = _finish = _start + s.Size();
	}
	~Vector()
	{
		if (_start)
			delete[]_start;
		_start = NULL;
		_endOfStorage = NULL;
		_finish = NULL;
	}

		//////////////Iterator///////////////////////////////// 
	Iterator Begin()
	{
		return _start;
	}
	Iterator End()
	{
		return _finish;
	}
	ConstIterator Begin()const
	{
		return _start;
	}
	ConstIterator End()const
	{
		return _finish;
	}
	void PushBack(const T& data)
	{
		_CheckCapacity();
		*_finish++ = data;
	}
	void PopBack()
	{
		assert(!Empty());
		--_finish;
	}
	void Insert(size_t pos, const T& data)
	{
		assert(pos >= 0 && pos <= Size());
		_CheckCapacity();
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
			_start[i] = _start[i+1];
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
		return _start == _finish;
	}
	void Resize(size_t newSize, const T& data = T())
	{
		size_t size = Size();
		size_t capacity = Capacity();
		if (newSize <= size)
		{
			_finish = _start + newSize;
		}
		else if (size < newSize&& newSize <= capacity)
		{
			for (size_t i =0; i < newSize; i++)
			{
				_start[i] = data;
			}
			_finish = _start + newSize;
		}
		else
		{
			T*temp = new T[newSize];
			if (TypeName<T>::IsPODType().Get())
			{
				memcpy(temp, _start, size *sizeof(T));
			}
			else
			{
				for (size_t i = 0; i < size; i++)
				{
					temp[i] = _start[i];
				}
			}
			for (size_t i = size; i < newSize; i++)
			{
				temp[i] = data;
			}
			delete[] _start;
			_start = temp;
			_endOfStorage = _finish = _start + newSize;
		}
	}

		//////////////Acess/////////////////////////// 
	T& operator[](size_t index)
	{
		assert(0 <= index&&index < Size());
		return _start[index];
	}
	const T& operator[](size_t index)const
	{
		assert(0 <= index&&index < Size());
		return _start[index];
	}
	T& Front()
	{
		assert(!Empty());
		return _start[0];
	}
	const T& Front()const
	{
		assert(!Empty());
		return _start[0];
	}
	T& Back()
	{
		assert(!Empty());
		return _finish[0];
	}
	const T& Back()const
	{
		assert(!Empty());
		return _finish[0];
	}
	void Clear()
	{
		_finish = _start;
	}

private:
	void _CheckCapacity()
	{
		size_t size = Size();
		if (_finish == _endOfStorage)
		{
			T*temp = new T[size * 2 + 3];
			if (TypeName<T>::IsPODType().Get())
			{
				memcpy(temp, _start, size *sizeof(T));
			}
			else
			{
				for (size_t i = 0; i < size; ++i)
				{
					temp[i] = _start[i];
				}
			}
			_finish = temp + size;
			_endOfStorage = temp + size * 2 + 3;
			delete[] _start;
			_start = temp;
		}
	}
	friend ostream& operator<<(ostream& _cout, const Vector<T>& v)
	{
		Vector<T>::ConstIterator t1 = v.Begin();
		while (t1 != v.End())
		{
			_cout << *t1 << " ";
			++t1;
		}
		return _cout;
	}

private:
	T* _start;
	T* _finish;
	T* _endOfStorage;
};
void testint()
{
	int arr[] = { 1, 2, 3, 4 };

	Vector<int>v1(arr, 4);
	cout << v1 << endl;
	v1.Insert(0, 0);
	v1.Insert(v1.Size(), 5);
	v1.Insert(4, -4);
	cout << v1 << endl;
	v1.Erase(4);
	v1.Erase(0);
	v1.Erase(v1.Size() - 1);
	v1.PopBack();
	v1.PopBack();
	v1.PopBack();
	v1.PopBack();
	//v1.Erase(0);
	//v1.PopBack();
	cout << v1 << endl;
	v1.PushBack(1);
	v1.PushBack(2);
	v1.PushBack(3);
	v1.PushBack(4);
	cout << v1 << endl;
	v1.Resize(20, 5);
	cout << v1 << endl;
	v1.Resize(50, 6);
	cout << v1 << endl;
}
void teststring()
{
	string arr[4] = { string("111"), string("22222222222222222222222222"), string("3333"), string("44444") };
	Vector<string>v1(arr, 4);
	cout << v1 << endl;
	v1.Insert(0, string("000000"));
	v1.Insert(v1.Size(), string("5555"));
	cout << v1 << endl;
	v1.Resize(20, string("1234"));
	cout << v1 << endl;

}
int main()
{
	testint();
	teststring();
	return 0;
}

