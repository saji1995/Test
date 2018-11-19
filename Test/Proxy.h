#pragma once
#include <iostream>
using namespace std;

/*代理模式*/

class Gril
{
public:
	Gril(string name = "gril") :m_string(name) {}
	string getName()
	{
		return m_string;
	}
private:
	string m_string;
};

class Profession
{
public:
	virtual ~Profession() {}
	virtual void profess() = 0;
};

class YoungMan :public Profession
{
public:
	YoungMan(Gril gril) :m_gril(gril) {}
	void profess()
	{
		cout << "Young man love " << m_gril.getName().data() << endl;
	}
private:
	Gril m_gril;
};

class ManProxy :public Profession
{
public:
	ManProxy(Gril gril) :m_man(new YoungMan(gril)) {}
	void profess()
	{
		cout << "I am Proxy" << endl;
		m_man->profess();
	}
private:
	YoungMan* m_man;
};

//int main(int argc, char *argv[])
//{
//	Gril gril("hei");
//	Profession* proxy = new ManProxy(gril);
//	proxy->profess();
//	delete proxy;
//	return 0;
//}