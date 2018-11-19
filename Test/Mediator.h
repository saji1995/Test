#pragma once
#include <iostream>
using namespace std;

/*中介者模式*/

class Mediator;

class Person   //抽象同事类
{
public:
	virtual ~Person() {}
	virtual void setMediator(Mediator* mediator)
	{
		m_mediator = mediator;
	}
	virtual void sendMessage(const string& message) = 0;
	virtual void getMessage(const string& message) = 0;
protected:
	Mediator* m_mediator;
};

class Mediator    //抽象中介类
{
public:
	virtual ~Mediator() {}
	virtual void setBuyer(Person* buyer) = 0;
	virtual void setSeller(Person* seller) = 0;
	virtual void send(const string& message, Person* person) = 0;
};

class Buyer :public Person   //买家类
{
public:
	void sendMessage(const string& message)
	{
		m_mediator->send(message, this);
	}
	void getMessage(const string& message)
	{
		cout << "Buyer Get: " << message.data() << endl;
	}
};

class Seller :public Person  //卖家类
{
public:
	void sendMessage(const string& message)
	{
		m_mediator->send(message, this);
	}
	void getMessage(const string& message)
	{
		cout << "Seller Get: " << message.data() << endl;
	}
};

class HouseMediator :public Mediator  //具体的中介类
{
public:
	HouseMediator() :m_buyer(nullptr), m_seller(nullptr) {}
	void setBuyer(Person* buyer)
	{
		m_buyer = buyer;
	}
	void setSeller(Person *seller)
	{
		m_seller = seller;
	}
	void send(const string& message, Person* person)
	{
		if (person == m_buyer)
		{
			m_seller->getMessage(message);
		}
		if (person == m_seller)
		{
			m_buyer->getMessage(message);
		}
	}
private:
	Person* m_buyer;
	Person* m_seller;
};

//int main()
//{
//	Person* buyer = new Buyer;
//	Person* seller = new Seller;
//	Mediator* houseMediator = new HouseMediator;
//	buyer->setMediator(houseMediator);
//	seller->setMediator(houseMediator);
//	houseMediator->setBuyer(buyer);
//	houseMediator->setSeller(seller);
//	buyer->sendMessage("1.5?");
//	seller->sendMessage("2!!!");
//	return 0;
//}