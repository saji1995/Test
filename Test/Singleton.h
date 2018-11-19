#pragma once
#include <iostream>
using namespace std;

/*单例模式*/

//懒汉式一般实现：非线程安全，getInstance返回的实例指针需要delete
class Singleton
{
public:
	static Singleton* getInstance();
	~Singleton() {}

private:
	static Singleton* m_pSingleton;
	Singleton() {}
	Singleton(const Singleton& obj) = delete;  //明确拒绝
	Singleton& operator=(const Singleton& obj) = delete; //明确拒绝
};

Singleton* Singleton::m_pSingleton = NULL;

Singleton* Singleton::getInstance()
{
	if (m_pSingleton == NULL)
	{
		m_pSingleton = new Singleton;
	}
	return m_pSingleton;
}
//END

//懒汉式：加lock，线程安全
std::mutex mt;

class Singleton
{
public:
	static Singleton* getInstance();
private:
	Singleton() {}
	Singleton(const Singleton&) = delete;  //明确拒绝
	Singleton& operator=(const Singleton&) = delete; //明确拒绝

	static Singleton* m_pSingleton;

};
Singleton* Singleton::m_pSingleton = NULL;

Singleton* Singleton::getInstance()
{
	if (m_pSingleton == NULL)
	{
		mt.lock();
		m_pSingleton = new Singleton();
		mt.unlock();
	}
	return m_pSingleton;
}
//END

//返回一个reference指向local static对象
//多线程可能存在不确定性：任何一种non-const static对象，不论它是local或non-local,在多线程环境下“等待某事发生”都会有麻烦。解决的方法：在程序的单线程启动阶段手工调用所有reference-returning函数。
class Singleton
{
public:
	static Singleton& getInstance();
private:
	Singleton() {}
	Singleton(const Singleton&) = delete;  //明确拒绝
	Singleton& operator=(const Singleton&) = delete; //明确拒绝
};


Singleton& Singleton::getInstance()
{
	static Singleton singleton;
	return singleton;
}
//END

//饿汉式：线程安全，注意delete
class Singleton
{
public:
	static Singleton* getInstance();
private:
	Singleton() {}
	Singleton(const Singleton&) = delete;  //明确拒绝
	Singleton& operator=(const Singleton&) = delete; //明确拒绝

	static Singleton* m_pSingleton;
};

Singleton* Singleton::m_pSingleton = new Singleton();

Singleton* Singleton::getInstance()
{
	return m_pSingleton;
}
//END