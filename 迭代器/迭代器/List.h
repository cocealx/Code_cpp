#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<assert.h>
using namespace std;
template<class T>
struct Listnode
{
	typedef Listnode<T> Node;
	Listnode(const T& data)
		:_data(data),
		prev(NULL),
		next(NULL)
	{

	}
	Node*prev;
	Node*next;
	T _data;
};
//������
template < class T,class Ref,class Ptr>
class MYiterator
{

public:
	typedef Listnode<T> Node;
	typedef MYiterator<T, Ref, Ptr> self;
	MYiterator(Node*node) :_node(node){}
	self&operator++()
	{
		_node = _node->next;
		return *this;
	}
	self operator++(int)
	{
		//self t1(_node);
		//return t1;//�������ι��캯��
		Node*ret = _node;
		_node = _node->next;
		//return self(ret);//������������Ż�����������ʱ����û���ͷš������ٵ���һ�ι��캯��
		return ret;//��ʽ���õ������ĵ��ι��캯��
	}
	self&operator--()
	{
		_node = _node->prev;
		return *this;
	}
	self operator--(int)
	{
		Node*ret = _node;
		_node = _node->prev;
		return ret;
	}
	bool operator!=(const self&t1)
	{
		return _node != t1._node;
	}
	Ptr operator->()
	{
		return &_node->_data;
	}
	Ref operator*()
	{
		return _node->_data;
	}
	Node* GetNode()
	{
		return _node;
	}
private:
	Node* _node;
};

template <class T>
class MYList
{
public:
	typedef Listnode<T> Node;
	typedef MYiterator<T, T&,T*>  Iterator;
	typedef MYiterator< T, const T&,const T*>  ConstIterator;
	MYList(const T &data = T())
	{
		_head = GetNode(data);
		_head->next = _head;
		_head->prev = _head;
	}
//~MYList();
	void Pushback(const T &data
		)
	{
		/*Node*tail = GetNode(data);
		_head->prev->next= tail;
		tail->next = _head;
		tail->prev = _head->prev;
		_head->prev = tail;*/
		Insert(End(), data);
	}
	void PopBack()
	{
		Erase(Iterator(_head->prev));
	}
	void PushFront(const T&data)
	{
		Insert(Begin(),data);
	}
	void PopFront()
	{
		Erase(Begin());
	}
	Iterator Erase(Iterator& pos)
	{
		assert(pos != End() && _head != _head->next);
		/*	Node*del = _head->next;
		while (del != _head)
		{
		if (del->_data == *pos)
		{
		del->prev->next = del->next;
		del->next->prev = del->prev;
		pos = del->prev;
		delete del;
		return pos;
		}
		del = del->next;
		}*/
		Iterator it = Begin();
		while (it != End())
		{
			if (*it == *pos)
			{
				Node* del = pos.GetNode();
				del->prev->next = del->next;
				del->next->prev = del->prev;
				pos = del->prev;
				Iterator ret(del->next);
				delete del;
				return ret;
			}
			++it;
		}
		return End();
	}
	Iterator Insert(Iterator pos, const T & data)
	{
		Node*Nodepos = pos.GetNode();
		Node*NewNode = GetNode(data);
		NewNode->next = Nodepos;
		NewNode->prev = Nodepos->prev;
		Nodepos->prev->next = NewNode;
		Nodepos->prev = NewNode;
		//��ʽ���õ�����Iterator�ĵ��ι��캯����
		return NewNode;
	}
	Iterator Find(const T&data)
	{
		Iterator t1 = Begin();
		while (t1 != End())
		{
			if (data == *t1)
				return t1;
			++t1;
		}
		return End();
	}
	Iterator Begin()
	{
		return  Iterator(_head->next);
	}
	ConstIterator Begin()const
	{
		return ConstIterator(_head->next);
	}
	Iterator End()
	{
		return Iterator(_head);
	}
	ConstIterator End()const
	{
		return ConstIterator(_head);
	}
	size_t Size()
	{
		size_t count = 0;
		Iterator t1 = Begin();
		while (t1 != End())
		{
			++count;
			++t1;
		}
	}
	void Clear();
	Node*GetNode(const T&data)
	{
		return new Node(data);
	}
private:
	Node* _head;
};


