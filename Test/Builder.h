#pragma once
#include <iostream>
using namespace std;

/*建造者模式*/

typedef enum
{
	type1,
	type2
}ProductType;

class Product   //产品
{
public:
	void setNum(int num);
	void setColor(string color);
	void setType(ProductType type);

	void showProduct();
private:
	int m_num;
	string m_color;
	ProductType m_type;

};

void Product::setNum(int num)
{
	m_num = num;
}

void Product::setColor(string color)
{
	m_color = color;
}

void Product::setType(ProductType type)
{
	m_type = type;
}

void Product::showProduct()
{
	cout << "Product: " << endl;
	cout << "       num  : " << m_num << endl;
	cout << "       color: " << m_color.data() << endl;
	cout << "       type : " << m_type << endl;
}

//建造者父类，定义接口
class Builder
{
public:
	Builder() {}
	virtual ~Builder() {}
	virtual void buildNum(int num) = 0;
	virtual void buildColor(string color) = 0;
	virtual void buildType(ProductType type) = 0;
	virtual void createProduct() = 0;
	virtual Product* getProduct() = 0;
	virtual void show() = 0;
};

//建造者A
class BuilderA :public Builder
{
public:
	BuilderA() {}
	~BuilderA() {}
	void buildNum(int num) override;
	void buildColor(string color) override;
	void buildType(ProductType type) override;
	void createProduct() override;
	Product* getProduct() override;
	void show() override;
private:
	Product* m_product;
};

void BuilderA::buildNum(int num)
{
	cout << "BuilderA build Num: " << num << endl;
	m_product->setNum(num);
}

void BuilderA::buildColor(string color)
{
	cout << "BuilderA build color: " << color.data() << endl;
	m_product->setColor(color);
}

void BuilderA::buildType(ProductType type)
{
	cout << "BuilderA build type: " << type << endl;
	m_product->setType(type);
}

void BuilderA::createProduct()
{
	cout << "BuilderA CreateProduct: " << endl;
	m_product = new Product();
}

Product* BuilderA::getProduct()
{
	return m_product;
}
void BuilderA::show()
{
	m_product->showProduct();
}

//建造者B
class BuilderB :public Builder
{
public:
	BuilderB() {}
	~BuilderB() {}
	void buildNum(int num) override;
	void buildColor(string color) override;
	void buildType(ProductType type) override;
	void createProduct() override;
	Product* getProduct() override;
	void show() override;
private:
	Product* m_product;
};

void BuilderB::buildNum(int num)
{
	cout << "BuilderB build Num: " << num << endl;
	m_product->setNum(num);
}

void BuilderB::buildColor(string color)
{
	cout << "BuilderB build color: " << color.data() << endl;
	m_product->setColor(color);
}

void BuilderB::buildType(ProductType type)
{
	cout << "BuilderB build type: " << type << endl;
	m_product->setType(type);
}

void BuilderB::createProduct()
{
	cout << "BuilderB CreateProduct: " << endl;
	m_product = new Product();
}

Product* BuilderB::getProduct()
{
	return m_product;
}
void BuilderB::show()
{
	m_product->showProduct();
}

//管理类，负责安排构造的具体过程
class Director
{
public:
	Director(Builder* builder) :m_builder(builder)
	{
	}
	void construct(int num, string color, ProductType type)
	{
		m_builder->createProduct();
		m_builder->buildNum(num);
		m_builder->buildColor(color);
		m_builder->buildType(type);
	}

private:
	Builder* m_builder;
};

