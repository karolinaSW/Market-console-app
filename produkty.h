#ifndef Produkty_H_
#define Produkty_H_

#include<iostream>
#include<time.h>


#include<iostream>
#include<string>

using namespace std;

extern string PL(const char *text);


class Produkty
{

private:

	double cena;
	string nazwa;

public:

	friend class Warzywa;
	friend class Owoce;
	friend class Napoje;
	friend class Nabial;
	friend class Koszyk;

	friend ostream & operator<< (ostream&, Produkty);

	Produkty();
	~Produkty();

};
#endif
