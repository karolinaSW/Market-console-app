#include<iostream>
#include<time.h>

#include"warzywa.h"

using namespace std;

extern string PL(const char *text);



Warzywa::Warzywa()
{
}

Warzywa::~Warzywa()
{
}


void Warzywa::utworzKoszyk(Koszyk &kosz_obj)
{
	srand(time(NULL));
	const int ilosc=7;
	this->tab=new Produkty[ilosc];
	this->tab[0].nazwa="Marchew";
	this->tab[1].nazwa="Pomidor";
	this->tab[2].nazwa=PL("Ogórek");
	this->tab[3].nazwa=PL("Bak³a¿an");
	this->tab[4].nazwa="Szpinak";
	this->tab[5].nazwa=PL("Broku³y");
	this->tab[6].nazwa="Ziemniaki";

	for(int i=0; i<ilosc; i++)
	{
		this->tab[i].cena= ((rand () % 5) + 2 )*1.28;
		cout<<i+1<<": "<<this->tab[i].nazwa<<"\t-\t"<<this->tab[i].cena<<" zl"<<endl;
	}

	char zmienna='t';
	while(zmienna=='t')
	{
		cout<<endl;
		cout<<PL("Dodaæ produkt? (t/n): ");
		cin>>zmienna;
		cout<<endl;

		if(zmienna=='n')
			break;
		if(zmienna!=116) //ascii dla 't'
		{
			cout<<"Error, wybierz \" t \" lub \" n \" !"<<endl;
			break;
		}

		int x;
		cout<<PL("WprowadŸ numer produktu: ");
		cin>>x;
		kosz_obj.dodaj(tab[x-1], kosz_obj.id);
		kosz_obj.id++;
		kosz_obj.pokaz(kosz_obj.id);


	}
	kosz_obj.dodawanie_par(kosz_obj.id);
	cout<<endl<<endl;

}


