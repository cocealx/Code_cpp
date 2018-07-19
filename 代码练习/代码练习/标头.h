#ifndef _VECTOR_H__
#define	_VECTOR_H__

#include<iostream>
using namespace std;
template<typename T>
class Vector
{
public:
	Vector()
		:_start(0)
		, _finish(0)
		, _endOfStorage(0)
	{}
	Vector(const T* array, size_t size)
		:_start(new T[size])
		, _finish(_start + size)
		, _endOfStorage(_start + size)
	{
		for (size_t i = 0; i < size; ++i)
		{
			_start[i] = array[i];
		}
	}
	Vector(const Vector& v);
	Vector& operator=(const Vector& s);
	~Vector()
	{

	}

	///////////////////Modify//////////////////////////////// 
	void PushBack(const T& data);
	void PopBack();
	void Insert(size_t pos, const T& data);
	void Erase(size_t pos);
	//////////////////capacity//////////////////////////// 
	size_t Size()const;
	size_t Capacity()const;
	bool Empty()const;
	void Resize(size_t newSize, const T& data = T());

	//////////////Acess/////////////////////////// 
	T& operator[](size_t index);
	const T& operator[](size_t index)const;
	T& Front();
	const T& Front()const;
	T& Back();
	const T& Back()const;
	void Clear();
private:
	void _CheckCapacity();

private:
	T* _start;
	T* _finish;
	T* _endOfStorage;
};
#endif
