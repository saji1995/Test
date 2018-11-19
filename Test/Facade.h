#pragma once
#include <iostream>
using namespace std;

/*外观模式*/

class Cpu
{
public:
	void productCpu()
	{
		cout << "Product Cpu" << endl;
	}
};

class Ram
{
public:
	void productRam()
	{
		cout << "Product Ram" << endl;
	}
};

class Graphics
{
public:
	void productGraphics()
	{
		cout << "Product Graphics" << endl;
	}
};

class Computer
{
public:
	void productComputer()
	{
		Cpu cpu;
		cpu.productCpu();
		Ram ram;
		ram.productRam();
		Graphics graphics;
		graphics.productGraphics();
	}
};

//int main()
//{
//	//客户直接调用computer生产函数，无需关心具体部件的生产过程。也可直接单独生产部件
//	Computer computer;
//	computer.productComputer();
//
//	Cpu cpu;
//	cpu.productCpu();
//
//	return 0;
//}