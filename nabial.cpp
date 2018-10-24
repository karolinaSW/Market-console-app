#include<iostream>
#include<time.h>

#include"nabial.h"

using namespace std;

extern string PL(const char *text);





Nabial::Nabial()
{
}

Nabial::~Nabial()
{
}



void Nabial::utworzKoszyk(Koszyk &kosz_obj)
{
	srand(time(NULL));
	const int ilosc=7;
	this->tab=new Produkty[ilosc];
	this->tab[0].nazwa="mleko";
	this->tab[1].nazwa="jogurt";
	this->tab[2].nazwa=PL("mas³o");
	this->tab[3].nazwa="jajka";
	this->tab[4].nazwa=PL("twaro¿ek");
	this->tab[5].nazwa=PL("maœlanka");
	this->tab[6].nazwa=PL("ser ¿ó³ty");
	for(int i=0;i<ilosc;i++)
	{
		tab[i].cena= ((rand () % 3) + 1) * 0.95;
		cout<<i+1<<": "<<this->tab[i].nazwa<<"\t-\t"<<this->tab[i].cena<<PL(" z³")<<endl;
	}
	char wybor='t';
	while(wybor=='t')
	{
		cout<<endl;
		cout<<PL("Dodaæ produkt? (t/n): ");
		cin>>wybor;
		if(wybor=='n')
			break;
		if(wybor!=116)
		{
			cout<<PL("Error, wybierz \" t \" lub \" n \" ")<<endl;
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

