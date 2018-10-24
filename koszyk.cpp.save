
#include "koszyk.h"

using namespace std;


extern string PL(const char *text);
extern Produkty tablica_gl[50];
extern int straznik;



Koszyk::Koszyk()
{
    this->id = 0;
}

Koszyk::~Koszyk()
{
}



ostream& operator<<(ostream& strumien, Produkty kosz_obj)
{
	cout<<"Posiadany produkt: ";
	cout<<kosz_obj.nazwa<<" koszt: ";
	cout<<kosz_obj.cena<<PL(" zł")<<endl;
	return strumien;
}

Produkty Koszyk::dodaj(Produkty zakup, int id)
{
	this->tablica[id]=zakup;
	id++;
	return *tablica;
}


void Koszyk::pokaz(int id)
{
	for(int i=0; i<id; i++)
	{
		cout<<this->tablica[i];
	}
}




double Koszyk::cena(int id, Produkty arr[])
{

	double razem = 0.0;


	string a;
	double b;


			for(int i=0; i<id; i++)
            {
                a = arr[i].nazwa;
                b = arr[i].cena;
                razem = razem + b;
                Sleep(700);
                cout<<"Produkt "<<a<<" "<<(char)26<<" "<<(char)7<<b<<PL(" zł")<<endl;
            }

            //razem = 5.50;

    cout<<endl<<endl;
	cout<<"Razem: "<<razem<< PL(" PLN")<<endl;



	cout<<endl<<endl;

	return razem;
}






void Koszyk::dodawanie_par(int id)
{
	fstream paragon;
	paragon.open("paragon.txt", ios::out | ios::app);  // out do pliku, app, bo dopisuje



	if(paragon.good())
	{
		//paragon<<id << endl;  w zasadzie mi to nie potrzebne
		for(int i=0; i<id; i++)

        {
            paragon<<tablica[i].nazwa<<" "<<tablica[i].cena<<endl;

            tablica_gl[straznik].cena = this->tablica[i].cena;
            tablica_gl[straznik].nazwa = this->tablica[i].nazwa;
            straznik++;

        }

			//przepisanie


	}


	else
		cout<<PL("Error!!! Nie zapisano paragonu!!! \nNależy skasować produkty jeszcze raz!\n");
	paragon.close();




	 cout << endl;


}



void Koszyk::wczytaj_paragon()
{
	fstream plik;
	plik.open("paragon.txt", ios::in );

	if(plik.good())
	{

		string a;


        while( !plik.eof() ) //Dopóki kursor nie znajdzie sie na koncu EOF - 'EndOfFile'
        {
            getline( plik, a ); //

            cout << a << endl;
        }
	}

	 cout << endl;


}



Produkty* Koszyk::przepisz()
{
    for(int i= 0; i<50; i++)
    {
        tablica_gl[i].cena = this->tablica[i].cena;
        tablica_gl[i].nazwa = this->tablica[i].nazwa;


    }

    /*for (int i=0; i<5 ; i++)
    {
        cout << tablica_gl[i] << endl;
    }*/
     cout << endl;

    return tablica_gl;
}





