#ifndef NABIAL_H_
#define NABIAL_H_

#include<iostream>
#include<time.h>

#include "dzial.h"
extern string PL(const char *text);


class Nabial : public Dzial
{
public:

	Produkty *tab;
	void utworzKoszyk(Koszyk &kosz_obj);
	Nabial();
	~Nabial();
};

#endif
