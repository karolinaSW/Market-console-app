#include<iostream>
#include<time.h>

#include"napoje.h"

using namespace std;

extern string PL(const char *text);



Napoje::Napoje()
{
}

Napoje::~Napoje()
{
}


void Napoje::utworzKoszyk(Koszyk &kosz_obj)
{
		srand(time(NULL));
	const int ilosc=5;
	this->tab=new Produkty[ilosc];
	this->tab[0].nazwa="Woda mineralna";
	this->tab[1].nazwa="Piwo bezalkoholowe";
	this->tab[2].nazwa="Sok multiwitamina";
	this->tab[3].nazwa="Prawie Coca - Cola";
	this->tab[4].nazwa="Sok pomidorowy";
	for(int i=0; i<ilosc; i++)
	{
		tab[i].cena= ((rand () % 7) + 1)*1.23;
		cout<<i+1<<": "<<this->tab[i].nazwa<<"\t-\t"<<this->tab[i].cena<<" zl"<<endl;
	}
	char zmienna='t';
	while(zmienna=='t')
	{
		cout<<endl;
		cout<<PL("Doda� produkt? (t/n): ");
		cin>>zmienna;
		if(zmienna=='n')
			break;
		if(zmienna!=116)
		{
			cout<<"Error, wybierz \" t \" lub \" n \" !"<<endl;
			break;
		}
		int x;
		cout<<PL("Wprowad� numer produktu: ");
		cin>>x;

		kosz_obj.dodaj(tab[x-1], kosz_obj.id);
		kosz_obj.id++;
		kosz_obj.pokaz(kosz_obj.id);

	}
	kosz_obj.dodawanie_par(kosz_obj.id);
	cout<<endl<<endl;
}
