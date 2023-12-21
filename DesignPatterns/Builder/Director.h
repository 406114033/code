#pragma onceo
#include <iostream>

using namespace std;
#include "Builder.h"

//指挥者类Director
//一方面它隔离了客户与生产过程；另一方面它负责控制产品的生成过程。

class Director
{

public:
	Director();
	virtual ~Director();
	Builder *m_Builder;

	Product* constuct();
	void setBuilder(Builder* buider);

private:
	Builder* m_pbuilder;

};

