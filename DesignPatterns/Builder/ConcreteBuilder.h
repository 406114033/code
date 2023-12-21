#pragma onceo
#include <iostream>
using namespace std;
#include "Builder.h"

class ConcreteBuilder : public Builder
{

public:
	ConcreteBuilder();
	virtual ~ConcreteBuilder();

	virtual void buildPartA();
	virtual void buildPartB();
	virtual void buildPartC();

};

