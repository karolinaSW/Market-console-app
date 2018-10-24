#ifndef NAPOJE_H_
#define NAPOJE_H_

#include<iostream>
#include<time.h>



#include "dzial.h"
extern string PL(const char *text);


class Napoje : public Dzial
{
public:

	Produkty *tab;
	void utworzKoszyk(Koszyk&);

	Napoje();
	~Napoje();
};

#endif
