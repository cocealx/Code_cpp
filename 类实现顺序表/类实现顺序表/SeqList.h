#pragma
#include<iostream>
#include<iomanip>
#include<string.h>
using namespace std;

////////////////////////////////////////////////////////顺序表//////////////////////////////////////////////////////////////////////////////////////////// 
typedef int DataType;
class SeqList
{
private:
	void _CheckCapacity()
	{
		if (_size == _capacity)
		{
			DataType*p = new DataType[_capacity * 2+3];
			/*memmove(p, _array, _size*sizeof(DataType));*/
			//用for循环写
			delete[] _array;
			_array = p;
			_capacity = 2 * _capacity;
		}
	}
private:
	DataType* _array;
	size_t _size;
	size_t _capacity;
public:
	SeqList()
		: _array(new DataType[3])
		, _capacity(3)
		, _size(0)
	{}

	// 思考两种方式的优缺点 
	SeqList(DataType* array, size_t size)
		: _array(new DataType[size])
		, _capacity(size)
		, _size(size)
	{
		// 1、循环逐个搬移-缺陷：效率低 正确性 
		for (size_t i = 0; i < size; ++i)
			_array[i] = array[i];

		// 2、优点：效率高--->问题？---可能会出错 
		//如果是自定义类型涉及深拷贝时，memcpy会出错了
		//memcpy(_array, array, size*sizeof(array[0])); 
	}

	// 三大big 
	SeqList(const SeqList& s) 
		:_size(s._size),
		_capacity(s._capacity)
	{
		_array = new DataType[_capacity];
		for (size_t i = 0; i < _size; i++)
		{
			_array[i] = s._array[i];
		}
	}
	SeqList& operator=(const SeqList& s)
	{
		if (this == &s)
			return *this;
		delete[]_array;
		_size = s._size;
		_capacity = s._capacity;
		_array = new DataType[s._capacity];
		for (size_t i = 0; i < _size; i++)
		{
			_array[i] = s._array[i];
		}
	}
	~SeqList()
	{
		if (_array)
		{
			delete[] _array;
			_size = 0;
			_capacity = 0;
		}
	}
	void PushBack(int data)
	{
		_CheckCapacity();
		_array[_size] = data;
		++_size;
	}
	void PopBack()
	{
		if (_size > 0)
			--_size;
	}
	//指定位置插入
	void Insert(size_t pos, DataType data)
	{
		if (0 <= pos&&pos < _size)
		{
			_CheckCapacity();
			int j = pos;
			for (int i = _size - 1; i >= j; i--)
			{
				_array[i + 1] = _array[i];
			}
			_array[pos] = data;
			++_size;
		}
	}
	//指定位置删除
	void Erase(size_t pos)
	{
		if (0 <= pos&&pos < _size)
		{
			for (size_t i = pos; i < _size-1; i++)
			{
				_array[i] = _array[i + 1];
			}
			--_size;
		}
	}
	size_t Size()const
	{
		return _size;
	}
	size_t Capacity()const
	{
		return _capacity;
	}
	bool Empty()const
	{
		return _size == 0;
	}
	DataType& operator[](size_t index)
	{
		return _array[index];
	}
	const DataType& operator[](size_t index)const
	{
		return _array[index];
	}

	// 返回顺序表中的第一个元素 
	DataType& Front()
	{
		return _array[0];
	}
	const DataType& Front()const
	{
		return _array[0];
	}
	// 返回顺序表中最后一个元素 
	DataType& Back()
	{
		return _array[_size - 1];
	}
	const DataType& Back()const
	{
		return _array[_size - 1];
	}

	// 清空顺序表中的所有元素 
	void Clear()
	{
		_size = 0;
	}

	// reserve() 
	// 将顺序表中元素个数改变到newSize 
	void ReSize(size_t newSize, const DataType& data = DataType())
	{
		if (newSize>=0&&newSize <= _size)
		{
			_size = newSize;
		}
		else if(newSize > _size&&newSize <= _capacity)
		{
			for (; _size < newSize; _size++)
			{
				_array[_size] = data;
			}
		}
		else
		{
			DataType*p = new DataType[newSize * 2];
			memmove(p, _array, sizeof(DataType)*_size);
			for (; _size < newSize; _size++)
			{
				p[_size] = data;
			}
			_capacity = 2 * newSize;
			delete[]_array;
			_array = p;
		}
	}
	friend ostream& operator<<(ostream& _cout, const SeqList& s)
	{
		for (size_t i = 0; i < s._size; i++)
		{
			_cout << s._array[i] << " ";
		}
		_cout << endl;
		return _cout;
	}

};
void test()
{
	int arr[5] = { 1, 2, 3, 5, 6 };
	SeqList sq1(arr, 5);
	SeqList sq2(sq1);
	cout << sq1;
	sq1.PushBack(7);
	sq2.PopBack();
	sq1.Insert(3, 4);
	sq1.Insert(0, 0);
	sq1.Insert(6, 8);
	sq1.Erase(6);
	sq1.Erase(0);
	sq1.Erase(3);
	sq1.ReSize(8, 6);
	sq1.ReSize(14, 6);
	sq1.ReSize(5, 5);
	sq1[0] = 0;
	sq1.Clear();
}
int main()
{
	test();
	return 0;
}

///////////////////////////////////////////////////////////双向链表/////////////////////////////////////////////////////////////////////////////////////////////////////////// 
//typedef int DataType;
//struct Node
//{
//	Node(const DataType& data)
//	: _pNext(NULL)
//	, _pPre(NULL)
//	, _data(data)
//	{}
//
//	Node* _pNext;
//	Node* _pPre;
//	DataType _data;
//};
//
//class List
//{
//public:
//	List()
//		: _pHead(NULL)
//	{}
//
//	List(DataType* array, size_t size) :_pHead(NULL)
//	{
//		for (size_t i = 0; i < size; ++i)
//			PushBack(array[i]);
//	}
//
//	// 有没有问题？ 
//	void PushBack(const DataType data)
//	{
//		if (_pHead == NULL)
//		{
//			_pHead = new Node(data);
//			return;
//		}
//		Node* pTail = _pHead;
//		while (pTail->_pNext)
//			pTail = pTail->_pNext;
//
//		Node* pNewNode = new Node(data);
//		pTail->_pNext = pNewNode;
//		pNewNode->_pPre = pTail;
//	}
//
//	void PopBack()
//	{
//		if (_pHead == NULL)
//			return;
//		if (_pHead->_pNext == NULL)
//		{
//			delete _pHead;
//			_pHead = NULL;
//			return;
//		}
//		Node* pTail = _pHead;
//		while (pTail->_pNext)
//			pTail = pTail->_pNext;
//		pTail->_pPre->_pNext = NULL;
//		delete pTail;
//	}
//	void PushFront(const DataType data)
//	{
//		if (_pHead == NULL)
//		{
//			_pHead = new Node(data);
//			return;
//		}
//		Node*_head = new Node(data);
//		_head->_pNext = _pHead;
//		_pHead->_pPre = _head;
//		_pHead = _head;
//	}
//	void PopFront()
//	{
//		if (_pHead == NULL)
//		{
//			return;
//		}
//		if (_pHead->_pNext == NULL)
//		{
//			delete _pHead;
//			_pHead = NULL;
//			return;
//		}
//		Node*temp = _pHead->_pNext;
//		delete _pHead;
//		_pHead = temp;
//		_pHead->_pPre = NULL;
//	}
//	Node* Erase(Node* pos)
//	{
//		Node*temp = NULL;
//		if (_pHead == NULL||pos==NULL)
//			return pos;
//		if (pos == _pHead)
//		{
//			temp = _pHead->_pNext;
//			if (temp)
//			{
//				temp->_pPre = NULL;
//			}
//			delete _pHead;
//			_pHead = temp;
//		}
//		Node*head = _pHead;
//		while (head->_pNext != NULL&&head->_pNext != pos)
//		{
//			head = head->_pNext;
//		}
//		if (head->_pNext == NULL)
//		{
//			return pos;
//		}
//		temp = pos->_pNext;
//		if (temp != NULL)
//		{
//			temp->_pPre = head;
//		}
//		head->_pNext = temp;
//		delete pos;
//		return NULL;
//	}
//	Node* Insert(Node* pos, const DataType& data)
//	{
//		Node*temp = NULL;
//		if (_pHead == NULL&&pos != NULL)
//			return NULL;
//		if (_pHead == NULL&&pos == NULL)
//		{
//			_pHead = new Node(data);
//			return _pHead;
//		}
//		if (_pHead == pos)
//		{
//			temp = _pHead;
//			_pHead = new Node(data);
//			_pHead->_pNext = temp;
//			temp->_pPre = _pHead;
//			return _pHead;
//		}
//		Node*tail = _pHead;
//		while (tail->_pNext != NULL&&tail->_pNext != pos)
//		{
//			tail = tail->_pNext;
//		}
//		
//		if (pos == NULL)
//		{
//			temp = new Node(data);
//			temp->_pPre = tail;
//			tail->_pNext = temp;
//			return temp;
//		}
//		if (tail->_pNext == NULL)
//			return NULL;
//		temp = new Node(data);
//		temp->_pNext = tail->_pNext;
//		tail->_pNext->_pPre = temp;
//		temp->_pPre = tail;
//		tail->_pNext = temp;
//		return temp;
//	}
//	size_t Size()
//	{
//		size_t count = 0;
//		Node*tail = _pHead;
//		while (tail != NULL)
//		{
//			++count;
//			tail = tail->_pNext;
//		}
//		return count;
//	}
//	void Clear()
//	{
//		Node*next = _pHead;
//		Node*temp = NULL;
//		while (next)
//		{
//			temp = next->_pNext;
//			delete next;
//			next = temp;
//		}
//		_pHead = NULL;
//	}
//	~List()
//	{
//		if (_pHead!=NULL)
//		Clear();
//	}
//	Node* find(const DataType &data)
//	{
//		Node*next = _pHead;
//		while (next != NULL)
//		{
//			if (next->_data == data)
//			{
//				return next;
//			}
//			next = next->_pNext;
//		}
//		return NULL;
//	}
//	friend ostream& operator<<(ostream&_cout, const List&object);
//private:
//	Node* _pHead;
//};
//ostream& operator<<(ostream&_cout,const  List&object)
//{
//	Node*next = object._pHead;
//	while (next)
//	{
//		_cout << next->_data << " ";
//		next = next->_pNext;
//	}
//	return _cout;
//}
//void test()
//{
//
//	int arr[5] = { 1, 3, 5, 7, 9 };
//	List ls1(arr, 5);
//	ls1.PushBack(10);
//	cout << ls1 << endl;
//	ls1.Insert(ls1.find(1),0);
//	ls1.Insert(ls1.find(3), 2);
//	ls1.Insert(ls1.find(10), 11);
//	ls1.Insert(ls1.find(5), 4);
//	cout << ls1 << endl;
//	ls1.Erase(ls1.find(11));
//	ls1.Erase(ls1.find(0));
//	ls1.Erase(ls1.find(4));
//	cout << ls1 << endl;
//	ls1.PopBack();
//	ls1.PushFront(0);
//	ls1.PushFront(-1);
//	ls1.Insert(NULL, 11);
//	cout << ls1 << endl;
//	cout << ls1.Size() << endl;
//	ls1.Clear();
//	cout << ls1 << endl;
//}
//int main()
//{
//	test();
//	return 0;
//}

//////////////////////////////////////////////////////////////////////////////////////////////////////////
/*struct Data
{
	char name[20];
	int old;
	char number[12];
};
template< typename T>
class SeqList
{
public:
	SeqList();
	~SeqList();
	void Add();
	void remove();
	void modification();
	void show();
	void sort();
	void search();
private:
	T*_pdata;
	int _size;
	int _capacity;
};
template<typename T>
SeqList<typename T>::SeqList()
{
	_size = 0;
	_capacity = 20;
	_pdata = new T[_capacity];
}
template<typename T>
SeqList<typename T>::~SeqList()
{
	delete[] _pdata;
}
template<typename T>
void SeqList<typename T>::show()
{
	int i = 0;
	cout << "姓名" << setw(8) << "年龄" << setw(20) << "联系方式"<<endl ;
	for (i = 0; i < _size; i++)
	{
		cout << _pdata[i].name << setw(10) << _pdata[i].old << setw(23) << _pdata[i].number<< endl;
	}
}
template<typename T>
void SeqList<typename T>::Add()
{
	if (_size == _capacity)
	{
		cout << "空间已满" << endl;
		return ;
	}
	cout << "输入姓名：" << endl;
	cin >>_pdata[_size].name;
	cout << "输入年龄：" << endl;
	cin >> _pdata[_size].old;
	cout << "输入电话号码：" << endl;
	cin >> _pdata[_size].number;
	_size++;
}
template<typename T>
void SeqList<typename T>:: remove()
{
	char _name[20] = {0};
	int i = 0;
	cout<<"输入要删除人的姓名："<<endl;
	cin >> _name;
	for (i = 0; i < _size; i++)
	{
		if (!strcmp(_name, _pdata[i].name))
		{
			for (; i + 1 < _size; i++)
			{
				strcpy(_pdata[i].name, _pdata[i + 1].name);
				strcpy(_pdata[i].number, _pdata[i + 1].number);
				_pdata[i].old = _pdata[i + 1].old;
			}
			cout << "删除成功" << endl;
			_size--;
			return;
		}
	}
	cout << "没有找到该联系人" << endl;
}
template<typename T>
void SeqList<typename T>::modification()
{
	;
}
template<typename T>

void SeqList<typename T>::sort()
{
	;
}
template<typename T>
void SeqList<typename T>::search()
{
	char _name[20] = { 0 };
	int i = 0;
	cout << "输入要查找人的姓名：" << endl;
	cin >> _name;
	for (i = 0; i < _size; i++)
	{
		if (!strcmp(_name, _pdata[i].name))
		{
			cout << "姓名：" << _pdata[i].name << endl;
			cout << "年龄：" << _pdata[i].old << endl;
			cout << "电话号码：" << _pdata[i].number << endl;
			return;
		}
	}
	cout << "查找不到改联系人" << endl;
}*/