#pragma once
template<class T>
struct ListNode
{
	ListNode(const T& data = T())
	: _pPre(0)
	, _pNext(0)
	, _data(data)
	{}

	ListNode* _pPre;
	ListNode* _pNext;
	T _data;
};

template<class T,class Ref,class Ptr >
class ListIterator
{
	typedef ListIterator Self;
	typedef ListNode<T> Node;
public:
	ListIterator(Node*pCur)
		: _pCur(pCur)
	{}
	ListIterator(const Self& s)
		: _pCur(s._pCur)
	{}
	Ref operator*()
	{
		return _pCur->_data;
	}

	Ptr operator->()
	{
		return &(_pCur->_data); 
	}

	Self& operator++()
	{
		_pCur = _pCur->_pNext;
		return*this;
	}

	Self operator++(int)
	{
		Self temp(*this);
		_pCur = _pCur->_pNext;
		return temp;
	}

	Self& operator--()
	{
		_pCur = _pCur->_pPre;
		return*this;
	}

	Self operator--(int)
	{
		Self temp(*this);
		_pCur = _pCur->_pPre;
		return temp;
	}

	bool operator!=(const Self& s)
	{
		return _pCur != s._pCur;
	}

	bool operator==(const Self& s)
	{
		return _pCur == s._pCur;
	}

	Node* _pCur;
};

template<class T>
class List
{
public:
	typedef ListIterator<T,T&,T*> Iterator;
	typedef ListIterator<T, const T&, const T*> ConstIterator;
	typedef ListNode<T> Node;
public:
	List()
		: _pHead(new Node)
	{
		_pHead->_pNext = _pHead;
		_pHead->_pPre = _pHead;
	}
	List(const T* array, size_t size) : _pHead(new Node)
	{
		_pHead->_pNext = _pHead;
		_pHead->_pPre = _pHead;
		for (size_t i = 0; i < size; ++i)
		{
			PushBack(array[i]);
		}
	}

	List(const List& l) : _pHead(new Node)
	{
		_pHead->_pNext = _pHead;
		_pHead->_pPre = _pHead;
		ConstIterator it = l.Begin();
		while (it != l.End())
		{
			PushBack(*it);
			++it;
		}
	}
	List& operator=(const List& l)
	{
		if (&l == this)
			return *this;
		List temp(l);
		swap(l._pHead, _pHead);
	}
	~List()
	{
		Clear();
	}

		///////////////////////////////////////////////////// 
	Iterator Begin()
	{
		return _pHead->_pNext;
	}
	ConstIterator Begin()const 
	{
		return _pHead->_pNext;
	}

	Iterator End()
	{
		return _pHead;
	}
	ConstIterator End()const
	{
		return _pHead;
	}
	/////////////////////Modify////////////////////////// 
	void PushBack(const T& data)
	{
		Node*newnoed = new Node(data);
		newnoed->_pPre= _pHead->_pPre;
		newnoed->_pNext = _pHead;
		_pHead->_pPre->_pNext = newnoed;
		_pHead->_pPre = newnoed;
	}
	void PopBack()
	{
		assert(!Empty());
		Node* del = _pHead->_pPre;
		del->_pPre->_pNext = _pHead;
		_pHead->_pPre = del->_pPre;
		delete del;
	}
	void PushFront(const T& data)
	{
		//Insert(Begin(), data);
		Node*newnode = new Node(data);
		newnode->_pNext = _pHead->_pNext;
		newnode->_pPre = _pHead;
		_pHead->_pNext->_pPre = newnode;
		_pHead->_pNext = newnode;
	}
	void PopFront()
	{
		assert(!Empty());
		//Erase(Begin());
		Node*del = _pHead->_pNext;
		del->_pNext->_pPre = _pHead;
		_pHead->_pNext = del->_pNext;
	}
	Iterator Insert(Iterator pos, const T& data)
	{
		Node*newnode = new Node(data);
		Node*Pos = pos._pCur;
		newnode->_pNext = Pos;
		newnode->_pPre = Pos->_pPre;
		Pos->_pPre->_pNext = newnode;
		Pos->_pPre = newnode;
		return newnode;
	}
	Iterator Erase(Iterator pos)
	{
		assert(!Empty()&&pos._pCur!=_pHead);
		Node*Pos = pos._pCur;
		Node*del = Pos;
		Pos->_pPre->_pNext = del->_pNext;
		del->_pNext->_pPre = del->_pPre;
		Iterator ret(del->_pNext);
		delete del;
		return ret;
	}
	Iterator Find(const T&data)
	{
		List<T>::Iterator it = Begin();
		while (it != End())
		{
			if (*it == data)
				return it;
			++it;
		}
		return End();
	}
	bool Empty()const
	{
		return _pHead == _pHead->_pNext;
	}
	size_t Size()const
	{
		size_t count = 0;
		ConstIterator it = Begin();
		while (it != End())
		{
			++count;
			++it;
		}
		return count;
	}
	T& Front()
	{
		return _pHead->_pNext->_data;
	}
	const T& Front()const
	{
		return _pHead->_pNext->_data;
	}
	T& Back()
	{
		return _pHead->_pPre->_data;
	}
	const T& Back()const
	{
		return _pHead->_pPre->_data;
	}
	void Clear()
	{
		Node*del = _pHead->_pNext;
		Node*next = del->_pNext;
		while (del != _pHead)
		{
			next = del->_pNext;
			delete del;
			del = next;
		}
		_pHead->_pNext = _pHead;
		_pHead->_pPre = _pHead;
	}
	friend ostream& operator<<(ostream& _cout, const List<T>&l1)
	{
		List<T>::ConstIterator it = l1.Begin();
		while (it != l1.End())
		{
			_cout << *it << " ";
			++it;
		}
		return _cout;
	}
private:
	Node* _pHead;
};

