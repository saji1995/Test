#pragma once
#include <iostream>
#include <functional>
using namespace std;

//��ͳ����ģʽʵ��
class Hurt
{
public:
	virtual void redBuff() = 0;
};

class AdcHurt :public Hurt
{
public:
	void redBuff()
	{
		cout << "Adc hurt" << endl;
	}
};

class ApcHurt :public Hurt
{
public:
	void redBuff()
	{
		cout << "Apc hurt" << endl;
	}
};

//����1������һ��ָ�����
class Soldier
{
public:
	Soldier(Hurt* hurt) :m_hurt(hurt)
	{
	}
	~Soldier()
	{
	}
	void beInjured()
	{
		m_hurt->redBuff();
	}
private:
	Hurt* m_hurt;
};

//����2������һ��������ǩ
typedef enum
{
	adc,
	apc
}HurtType;

class Master
{
public:
	Master(HurtType type)
	{
		switch (type)
		{
		case adc:
			m_hurt = new AdcHurt;
			break;
		case apc:
			m_hurt = new ApcHurt;
			break;
		default:
			m_hurt = NULL;
			break;
		}
	}
	~Master()
	{
	}
	void beInjured()
	{
		if (m_hurt != NULL)
		{
			m_hurt->redBuff();
		}
		else
		{
			cout << "Not hurt" << endl;
		}
	}
private:
	Hurt* m_hurt;
};

//����3��ʹ��ģ����
template <typename T>
class Tank
{
public:
	void beInjured()
	{
		m_hurt.redBuff();
	}
private:
	T m_hurt;
};
//END

//ʹ�ú���ָ��ʵ�ֲ���ģʽ
void adcHurt(int num)
{
	cout << "adc hurt:" << num << endl;
}

void apcHurt(int num)
{
	cout << "apc hurt:" << num << endl;
}

//��ͨ����ָ��
class Aid
{
public:
	typedef void(*HurtFun)(int);

	Aid(HurtFun fun) :m_fun(fun)
	{
	}
	void beInjured(int num)
	{
		m_fun(num);
	}
private:
	HurtFun m_fun;
};

//ʹ��std::function , ͷ�ļ���#include<functional>
class Bowman
{
public:
	typedef function<void(int)> HurtFunc;

	Bowman(HurtFunc fun) :m_fun(fun)
	{
	}
	void beInjured(int num)
	{
		m_fun(num);
	}

private:
	HurtFunc m_fun;
};
//END	