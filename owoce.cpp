#include<iostream>
#include<time.h>

#include"owoce.h"

using namespace std;

extern string PL(const char *text);



Owoce::Owoce()
{
}

Owoce::~Owoce()
{
}

void Owoce::utworzKoszyk(Koszyk &kosz_obj)
{
	srand(time(NULL));
	const int ilosc=7;
	this->tab=new Produkty[ilosc];
	this->tab[0].nazwa=PL("¯urawina");
	this->tab[1].nazwa="Banan";
	this->tab[2].nazwa="Mandarynki";
	this->tab[3].nazwa="Winogrona";
	this->tab[4].nazwa="Truskawki";
	this->tab[5].nazwa="Maliny";
	this->tab[6].nazwa=PL("Jab³ka");
	for(int i=0;i<ilosc;i++)
	{
		tab[i].cena= ((rand () % 6 ) +3)*1.38;
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
		if(zmienna!=116)
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
