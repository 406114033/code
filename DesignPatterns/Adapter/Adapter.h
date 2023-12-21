#pragma once
#include "iostream"
using namespace std;
#include "Target.h"
#include "Adaptee.h"

//适配器类

class Adapter : public Target
{

public:
	Adapter(Adaptee *adaptee);
	virtual ~Adapter();

	virtual void request();

private:
	Adaptee* m_pAdaptee;

};

