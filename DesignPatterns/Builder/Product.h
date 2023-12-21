#pragma onceo
#include <iostream>

using namespace std;


class Product
{

public:
	Product();
	virtual ~Product();
	
	void setA(string str);
	void setB(string str);
	void setC(string str);
	void show();
private:
	string m_a;
	string m_b;
	string m_c;
};
