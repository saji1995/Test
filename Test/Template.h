#pragma once

#include <iostream>
using namespace std;

/*Ä£°åÄ£Ê½*/

class Computer
{
public:
	void product()
	{
		installCpu();
		installRam();
		installGraphicsCard();
	}

protected:
	virtual    void installCpu() = 0;
	virtual void installRam() = 0;
	virtual void installGraphicsCard() = 0;

};

class ComputerA :public Computer
{
protected:
	void installCpu() override
	{
		cout << "ComputerA install Inter Core i5" << endl;
	}

	void installRam() override
	{
		cout << "ComputerA install 2G Ram" << endl;
	}

	void installGraphicsCard() override
	{
		cout << "ComputerA install Gtx940 GraphicsCard" << endl;
	}
};

class ComputerB :public Computer
{
protected:
	void installCpu() override
	{
		cout << "ComputerB install Inter Core i7" << endl;
	}

	void installRam() override
	{
		cout << "ComputerB install 4G Ram" << endl;
	}

	void installGraphicsCard() override
	{
		cout << "ComputerB install Gtx960 GraphicsCard" << endl;
	}
};