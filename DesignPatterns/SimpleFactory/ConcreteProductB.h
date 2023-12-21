
#pragma once

#include "Product.h"


//具体产品角色是创建目标，所有创建的对象都充当这个角色的某个具体类的实例
class ConcreteProductB : public Product
{

public:
	ConcreteProductB();
	virtual ~ConcreteProductB();
	
	virtual void Use();

};

