#pragma once
#include <iostream>
using namespace std;

/*装饰模式*/

class Dumplings    //抽象类   饺子
{
public:
	virtual ~Dumplings() {}
	virtual void showDressing() = 0;
};

class MeatDumplings :public Dumplings    //现实类  肉馅饺子
{
public:
	~MeatDumplings() { cout << "~MeatDumplings()" << endl; }
	void showDressing()
	{
		cout << "Add Meat" << endl;
	}
};

class DecoratorDumpling :public Dumplings    //装饰类
{
public:
	DecoratorDumpling(Dumplings* d) :m_dumpling(d) {}
	virtual ~DecoratorDumpling() { cout << "~DecoratorDumpling()" << endl; }
	void showDressing()
	{
		m_dumpling->showDressing();
	}
private:
	Dumplings* m_dumpling;
};

class SaltDecorator :public DecoratorDumpling   // 装饰类  加盐
{
public:
	SaltDecorator(Dumplings* d) :DecoratorDumpling(d) {}
	~SaltDecorator() { cout << "~SaltDecorator()" << endl; }
	void showDressing()
	{
		DecoratorDumpling::showDressing();   //注意点
		addDressing();
	}

private:
	void addDressing()
	{
		cout << "Add Salt" << endl;
	}
};

class OilDecorator :public DecoratorDumpling   //装饰类  加油
{
public:
	OilDecorator(Dumplings* d) :DecoratorDumpling(d) {}
	~OilDecorator() { cout << "~OilDecorator()" << endl; }
	void showDressing()
	{
		DecoratorDumpling::showDressing(); //注意点
		addDressing();
	}

private:
	void addDressing()
	{
		cout << "Add Oil" << endl;
	}
};

class CabbageDecorator :public DecoratorDumpling  //装饰类   加蔬菜
{
public:
	CabbageDecorator(Dumplings* d) :DecoratorDumpling(d) {}
	~CabbageDecorator() { cout << "~CabbageDecorator()" << endl; }
	void showDressing()
	{
		DecoratorDumpling::showDressing(); //注意点
		addDressing();
	}

private:
	void addDressing()
	{
		cout << "Add Cabbage" << endl;
	}
};

//int main()
//{
//	Dumplings* d = new MeatDumplings;       //原始的肉饺子
//	Dumplings* d1 = new SaltDecorator(d);   //加盐后的饺子
//	Dumplings* d2 = new OilDecorator(d1);   //加油后的饺子
//	Dumplings* d3 = new CabbageDecorator(d2);  //加蔬菜后的饺子
//	d3->showDressing();
//	delete d;
//	delete d1;
//	delete d2;
//	delete d3;
//	return 0;
//}