#pragma once
#include <iostream>
using namespace std;

//ʹ�ø��ϣ�����ģʽ
class Deque  //˫�˶��У���������
{
public:
	void push_back(int x)
	{
		cout << "Deque push_back:" << x << endl;
	}
	void push_front(int x)
	{
		cout << "Deque push_front:" << x << endl;
	}
	void pop_back()
	{
		cout << "Deque pop_back" << endl;
	}
	void pop_front()
	{
		cout << "Deque pop_front" << endl;
	}
};

class Sequence  //˳���࣬Ŀ����
{
public:
	virtual void push(int x) = 0;
	virtual void pop() = 0;
};

class Stack :public Sequence   //ջ, ������
{
public:
	void push(int x)
	{
		m_deque.push_back(x);
	}
	void pop()
	{
		m_deque.pop_back();
	}
private:
	Deque m_deque;
};

class Queue :public Sequence  //���У�������
{
public:
	void push(int x)
	{
		m_deque.push_back(x);
	}
	void pop()
	{
		m_deque.pop_front();
	}
private:
	Deque m_deque;
};
//END

/*
//ʹ�ü̳�,��ģʽ
class Deque  //˫�˶��У���������
{
public:
	void push_back(int x)
	{
		cout << "Deque push_back:" << x << endl;
	}
	void push_front(int x)
	{
		cout << "Deque push_front:" << x << endl;
	}
	void pop_back()
	{
		cout << "Deque pop_back" << endl;
	}
	void pop_front()
	{
		cout << "Deque pop_front" << endl;
	}
};

class Sequence  //˳���࣬Ŀ����
{
public:
	virtual void push(int x) = 0;
	virtual void pop() = 0;
};

class Stack :public Sequence, private Deque   //ջ, ������
{
public:
	void push(int x)
	{
		push_back(x);
	}
	void pop()
	{
		pop_back();
	}
};

class Queue :public Sequence, private Deque  //���У�������
{
public:
	void push(int x)
	{
		push_back(x);
	}
	void pop()
	{
		pop_front();
	}
};
//END
*/