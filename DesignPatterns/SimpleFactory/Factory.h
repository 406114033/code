
#pragma once
#include "Product.h"
#include <string>
using namespace std;

//工厂角色负责实现创建所有实例的内部逻辑；

class Factory
{

public:
	Factory();
	virtual ~Factory();

	static Product * createProduct(string proname);

};

