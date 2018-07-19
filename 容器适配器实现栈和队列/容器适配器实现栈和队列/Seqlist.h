#pragma
#include<iostream>
#include<assert.h>
using namespace std;
template<class T>
struct ListNode
{
	ListNode(const T x = 0) :data (x), next( NULL), prev ( NULL){}
	T data;
	ListNode<T>*next;
	ListNode<T>*prev;
};

template<class T>
class Seqlist
{
	
public:
	typedef ListNode<T>  Node;
	Seqlist();
	~Seqlist();
	void PushBack(const T&x);
	void PopBack();
	void Print();
	bool Empty();
	const T&Top();
	size_t Size();
private:
	Node* _head;
	Node* _tail;
};
//默认构造函数
template< class T>
Seqlist<T>::Seqlist() :_head( NULL), _tail(NULL){}
//析构函数
template<class T>
Seqlist<T>::~Seqlist()
{
	Node*temp = _head;
	while (temp != NULL)
	{

		Node*next = temp->next;
		delete temp;
		temp = next;
	}
	_head = _tail = NULL;
}
//尾插
template<class T>
void Seqlist<T>::PushBack(const T&x)
{
	if (_head == NULL)
	{
		_head = _tail = new Node(x);
		return;
	}
	else
	{
		Node*temp = new Node(x);
		_tail->next = temp;
		temp->prev = _tail;
		_tail = temp;
	}
}
template<class T>
void Seqlist<T>::Print()
{
	Node*cur = _head;
	while (cur)
	{
		cout << cur->data << " ";
		cur = cur->next;
	}
	cout << endl;
}
template<class T>
void Seqlist<T>::PopBack()
{
	Node*temp = _tail;
	_tail = _tail->prev;
	_tail->next = NULL;
	delete temp;
}
template<class T>
bool Seqlist<T>::Empty()
{
	return _head == NULL;
}
template<class T>
const T& Seqlist<T>::Top()
{
	assert(_tail);
	return _tail->data;
}
template<class T>
size_t Seqlist<T>::Size()
{
	Node*cur = _head;
	size_t count = 0;
	while (cur)
	{
		count++;
		cur = cur->next;
	}
	return count;
}