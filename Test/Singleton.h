#pragma once
#include <iostream>
using namespace std;

/*����ģʽ*/

//����ʽһ��ʵ�֣����̰߳�ȫ��getInstance���ص�ʵ��ָ����Ҫdelete
class Singleton
{
public:
	static Singleton* getInstance();
	~Singleton() {}

private:
	static Singleton* m_pSingleton;
	Singleton() {}
	Singleton(const Singleton& obj) = delete;  //��ȷ�ܾ�
	Singleton& operator=(const Singleton& obj) = delete; //��ȷ�ܾ�
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

//����ʽ����lock���̰߳�ȫ
std::mutex mt;

class Singleton
{
public:
	static Singleton* getInstance();
private:
	Singleton() {}
	Singleton(const Singleton&) = delete;  //��ȷ�ܾ�
	Singleton& operator=(const Singleton&) = delete; //��ȷ�ܾ�

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

//����һ��referenceָ��local static����
//���߳̿��ܴ��ڲ�ȷ���ԣ��κ�һ��non-const static���󣬲�������local��non-local,�ڶ��̻߳����¡��ȴ�ĳ�·������������鷳������ķ������ڳ���ĵ��߳������׶��ֹ���������reference-returning������
class Singleton
{
public:
	static Singleton& getInstance();
private:
	Singleton() {}
	Singleton(const Singleton&) = delete;  //��ȷ�ܾ�
	Singleton& operator=(const Singleton&) = delete; //��ȷ�ܾ�
};


Singleton& Singleton::getInstance()
{
	static Singleton singleton;
	return singleton;
}
//END

//����ʽ���̰߳�ȫ��ע��delete
class Singleton
{
public:
	static Singleton* getInstance();
private:
	Singleton() {}
	Singleton(const Singleton&) = delete;  //��ȷ�ܾ�
	Singleton& operator=(const Singleton&) = delete; //��ȷ�ܾ�

	static Singleton* m_pSingleton;
};

Singleton* Singleton::m_pSingleton = new Singleton();

Singleton* Singleton::getInstance()
{
	return m_pSingleton;
}
//END