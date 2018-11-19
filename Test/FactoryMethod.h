#pragma once
#include <iostream>
using namespace std;

/*工厂方法模式*/

class Tank
{
public:
	virtual void message() = 0;
};

class Tank80 :public Tank
{
public:
	void message()
	{
		cout << "Tank80" << endl;
	}
};

class Tank99 :public Tank
{
public:
	void message()
	{
		cout << "Tank99" << endl;
	}
};

class TankFactory
{
public:
	virtual Tank* createTank() = 0;
};

class Tank80Factory :public TankFactory
{
public:
	Tank* createTank()
	{
		return new Tank80();
	}
};

class Tank99Factory :public TankFactory
{
public:
	Tank* createTank()
	{
		return new Tank99();
	}
};