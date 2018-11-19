#pragma once
#include <iostream>
using namespace std;

/*原型模式*/

class Clone
{
public:
	Clone()
	{
	}
	virtual ~Clone()
	{
	}
	virtual Clone* clone() = 0;
	virtual void show() = 0;
};

class Sheep :public Clone
{
public:
	Sheep(int id, string name) :Clone(), m_id(id), m_name(name)
	{
		cout << "Sheep() id add:" << &m_id << endl;
		cout << "Sheep() name add:" << &m_name << endl;
	}
	~Sheep()
	{
	}

	Sheep(const Sheep& obj)
	{
		this->m_id = obj.m_id;
		this->m_name = obj.m_name;
		cout << "Sheep(const Sheep& obj) id add:" << &m_id << endl;
		cout << "Sheep(const Sheep& obj) name add:" << &m_name << endl;
	}

	Clone* clone()
	{
		return new Sheep(*this);
	}
	void show()
	{
		cout << "id  :" << m_id << endl;
		cout << "name:" << m_name.data() << endl;
	}
private:
	int m_id;
	string m_name;
};

//int main()
//{
//	Clone* s1 = new Sheep(1, "abs");
//	s1->show();
//	Clone* s2 = s1->clone();
//	s2->show();
//	delete s1;
//	delete s2;
//	return 0;
//}