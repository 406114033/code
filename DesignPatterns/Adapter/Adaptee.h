
#pragma once
#include "iostream"
using namespace std;

//适配者类

class Adaptee
{

public:
	Adaptee();
	virtual ~Adaptee();

	void specificRequest();

};

