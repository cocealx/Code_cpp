#define _CRT_SECURE_NO_WARNINGS 1

//以模板参数和模板的模板参数完成容器适配器栈和队列，底层容器使用自行实现的Vector和List，
//template<class T, class Container = Vector<T>>
template<class T, template<class > class Container = Vector>
class Stack
{
	typedef Container<T> Container;
public:
	Stack(const Container&con = Container()) :_con(con)
	{}
	Stack(const Stack&co1)
	{
		_con = co1._con;
	}
	void Push(const T&data)
	{
		_con.PushBack(data);
	}
	void Pop()
	{
		_con.PopBack();
	}
	T&Top()
	{
		return _con.Back();
	}
	bool Empty()
	{
		return _con.Empty();
	}
	size_t Size()
	{
		return _con.Size();
	}
private:
	Container _con;
};

//template<class T, class Container = List<T>>
template<class T, template<class > class Container = List>
class Quene
{
	typedef Container<T> Container;
public:
	Quene(const Container&con = Container()) :_con(con)
	{}
	Quene(const Quene&co1)
	{
		_con = co1._con;
	}
	void Push(const T&data)
	{
		_con.PushBack(data);
	}
	void Pop()
	{
		_con.PopFront();
	}
	T&Top()
	{
		return _con.Front();
	}
	T&Back()
	{
		return _con.Back();
	}
	bool Empty()
	{
		return _con.Empty();
	}
	size_t Size()
	{
		return _con.Size();
	}
private:
	Container _con;
};
