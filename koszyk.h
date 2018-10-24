#ifndef KOSZYK_H_
#define KOSZYK_H_


#include <iostream>
#include <string>
#include <fstream>
#include <math.h>
#include <windows.h>
#include <time.h>

#include"produkty.h"


extern string PL(const char *text);

extern Produkty tablica_gl[50];
extern int straznik;

class Koszyk
{
public:
	Produkty tablica[50];
	int id;
	Produkty dodaj(Produkty, int);
	void pokaz(int);
    double cena(int id , Produkty arr[]);
    friend ostream& operator<<(ostream&, Produkty);
	void dodawanie_par(int id);
	void wczytaj_paragon();
	Produkty* przepisz();


	Koszyk();
	~Koszyk();


};
#endif
