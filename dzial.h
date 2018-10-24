#ifndef DZIAL_H_
#define DZIAL_H_

#include"koszyk.h"
#include "Produkty.h"

class Dzial
{
public:
	virtual void utworzKoszyk(Koszyk&)=0;

	virtual ~Dzial(){};

};

#endif
