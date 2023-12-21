#pragma onceo
#include <iostream>
using namespace std;
#include "Product.h"

//抽象建造者类   定义了产品的创建方法和返回方法

class Builder
{

public:
	Builder();
	virtual ~Builder();

	virtual void buildPartA();
	virtual void buildPartB();
	virtual void buildPartC();
	virtual Product * getResult();
protected :
	Product * m_prod;
};
