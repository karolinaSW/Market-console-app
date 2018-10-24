#include<iostream>
#include"produkty.h"
#include<time.h>
using namespace std;

extern string PL(const char *text);



Produkty::Produkty()
{
    nazwa = "niewybrany";
    cena = 0.0;

}

Produkty::~Produkty()
{

}
