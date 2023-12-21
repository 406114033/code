#pragma once
#include "iostream"
using namespace std;

//目标抽象类

class Target
{

public:
	Target();
	virtual ~Target();

	virtual void request();

};

