

//抽象产品角色是所创建的所有对象的父类，负责描述所有实例所共有的公共接口；
#pragma once
using namespace std;

class Product
{

public:
	Product();
	virtual ~Product();
	
	virtual void Use() = 0;

};
