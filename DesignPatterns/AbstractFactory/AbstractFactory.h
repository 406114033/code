#include "AbstractProductA.h"
#include "AbstractProductB.h"

/*
 抽象工厂模式包含四个角色：

- 抽象工厂用于声明生成抽象产品的方法；
- 具体工厂实现了抽象工厂声明的生成抽象产品的方法，生成一组具体产品，这些产品构成了一个产品族，每一个产品都位于某个产品等级结构中；
- 抽象产品为每种产品声明接口，在抽象产品中定义了产品的抽象业务方法；
- 具体产品定义具体工厂生产的具体产品对象，实现抽象产品接口中定义的业务方法。

 */

class AbstractFactory
{

public:
	AbstractFactory();
	virtual ~AbstractFactory();

	virtual AbstractProductA * createProductA() = 0;
	virtual AbstractProductB * createProductB() = 0;

};
