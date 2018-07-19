#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<assert.h>
using namespace std;
template<class T>
struct Listnode
{
	typedef Listnode<T> Node;
	Listnode(const T& data=T())
		:_data(data),
		prev(NULL),
		next(NULL)
	{

	}
	Node*prev;
	Node*next;
	T _data;
};
//迭代器
template < class T, class Ref, class Ptr>
class MYiterator
{

public:


	self operator++(int)
	{
		//self t1(_node);
		//return t1;//调用两次构造函数
		//Node*ret = _node;
		//_node = _node->next;
		////return self(ret);//编译器会进行优化，函数结束时对象没有释放。所以少调用一次构造函数
		//return ret;//隐式调用迭代器的单参构造函数
	}
	self&operator--()
	{

	}
	self operator--(int)
	{

	}
	bool operator!=(const self&t1)
	{
	}
	Ptr operator->()
	{
	
	}
	Ref operator*()
	{
	
	}
	Node* GetNode()
	{
	
	}
private:
	Node* _node;
};

template <class T>
class MYList
{
public:
	template MYList<T> self;
	typedef Listnode<T> Node;
	typedef  MYiterator< T, T&, T*>   Iterator;
	typedef MYiterator<const T, const T&, const T*>  ConstIterator;
	MYList()
	{
		_head = new Node;
		_head->next = _head;
		_head->prev = _head;
	}
	MYList(const self& lst )
	{
		_head = new Node;
		_head->next = _head;
		_head->prev = _head;
	}
	//~MYList();
	void Pushback(const T &data)
	{

	}
	void PopBack()
	{
	
	}
	void PushFront(const T&data)
	{

	}
	void PopFront()
	{

	}
	Iterator& Erase(Iterator& pos)
	{

	
	}
	Iterator Insert(Iterator pos, const T & data)
	{

	}
	Iterator Find(const T&data)
	{

	}
	Iterator Begin()
	{

	}
	ConstIterator Begin()const
	{
	
	}
	Iterator End()
	{

	}
	ConstIterator End()const
	{

	}
	size_t Size()
	{
		
	}
	void Clear();
	Node*GetNode(const T&data)
	{

	}
private:
	Node* _head;
};

