#include<iostream>
#include <windows.h>
#include <iomanip>
#include <fstream>
#include <cstdio>


#include"koszyk.h"
#include"produkty.h"
#include"owoce.h"
#include"warzywa.h"
#include"dzial.h"
#include"nabial.h"
#include"napoje.h"
#include"bledy.h"

using namespace std;





//----------------------------------                   KODOWANIE POLSKICH ZNAKOW        ---------------------------------------------------






string PL( const char * text )  // CP852 - kodowanie znakow lacinskich w formie 8-bitowej;  setlocale(LC_ALL,"") nie dzialala

{
	std::string result;
	for(; * text; text++ )
		switch( * text )
	{
		case '�': result += static_cast < char >( 0xa5 ); break;
		case '�': result += static_cast < char >( 0x86 ); break;
		case '�': result += static_cast < char >( 0xa9 ); break;
		case '�': result += static_cast < char >( 0x88 ); break;
		case '�': result += static_cast < char >( 0xe4 ); break;
		case '�': result += static_cast < char >( 0xa2 ); break;
		case '�': result += static_cast < char >( 0x98 ); break;
		case '�': result += static_cast < char >( 0xbe ); break;
		case '�': result += static_cast < char >( 0xab ); break;
		case '�': result += static_cast < char >( 0xa4 ); break;
		case '�': result += static_cast < char >( 0x8f ); break;
		case '�': result += static_cast < char >( 0xa8 ); break;
		case '�': result += static_cast < char >( 0x9d ); break;
		case '�': result += static_cast < char >( 0xe3 ); break;
		case '�': result += static_cast < char >( 0xe0 ); break;
		case '�': result += static_cast < char >( 0x97 ); break;
		case '�': result += static_cast < char >( 0xbd ); break;
		case '�': result += static_cast < char >( 0x8d ); break;
		default: result += * text; break;
	}
	return result;
}



//-----------------------------------------------------         OBSLUGA PARAGONU           ------------------------------------------




void podliczanie(double suma)
{

	HANDLE hOut;
	hOut = GetStdHandle( STD_OUTPUT_HANDLE );
	SetConsoleTextAttribute( hOut, FOREGROUND_BLUE | FOREGROUND_INTENSITY );
	cout<< PL("RAZEM DO ZAP�ATY :   ")<<suma<<"   PLN"<<endl<<endl;
	SetConsoleTextAttribute( hOut, FOREGROUND_RED | FOREGROUND_INTENSITY );
	cout<<PL("ZAP�A�  ->   ");
	double x;
	cin>>x;
	cout<<endl;
	if(suma==x)
	{
		{
			cout<<PL("Dzi�kujemy za zakupy i zapraszamy ponownie! \n\nChrz�szcz - Codziennie randomowe ceny :) ")<<endl<<endl;
			cout<<PL("WYJ�CIE!\n");
		}
	}
	while(suma>x)
	{

		cout<<PL("ODMOWA! ZAP�A� PONOWNIE  ->   ");
		cin>>x;
		cout<<endl;
		if(x<suma)
		{
			Warning wyjatek;
			throw wyjatek;
		}

	}


	if(x>suma)
	{
		double reszta;
		reszta = x - suma;
		cout<<PL("RESZTA W WYNOSI:  ")<<reszta<<"  PLN"<<endl<<endl;
		cout<<PL("DZI�KUJEMY ZA ZAKUPY I �YCZYMY MI�EGO DNIA")<<char(1)<<endl<<endl;
	}
}



//-------------------------------------------------         PODMENU         -------------------------------------------------------------



void podMenu(Koszyk &koszyk_obj)
{
	HANDLE hOut;
	hOut = GetStdHandle( STD_OUTPUT_HANDLE );
	int choice;
	cin>>choice;
	switch(choice)
	{
	case 1:
		{
			SetConsoleTextAttribute( hOut, BACKGROUND_GREEN );

			cout<<"WARZYWA: "<<endl;
			Warzywa warzywa;

			SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED );

			warzywa.utworzKoszyk(koszyk_obj);
			cout<<endl;
			break;
		}
	case 2:
		{
			SetConsoleTextAttribute( hOut, BACKGROUND_GREEN );

			cout<<"OWOCE: "<<endl;
			Owoce owoce;

			SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_BLUE );

			owoce.utworzKoszyk(koszyk_obj);
			cout<<endl;
			break;
		}
	case 3:
		{
			SetConsoleTextAttribute( hOut, BACKGROUND_GREEN );

			cout<<PL("NABIA�: ")<<endl;
			Nabial nabial;

			SetConsoleTextAttribute( hOut, FOREGROUND_BLUE | FOREGROUND_RED );

			nabial.utworzKoszyk(koszyk_obj);
			break;
		}
	case 4:
		{
			SetConsoleTextAttribute( hOut, BACKGROUND_GREEN );

			cout<<"NAPOJE: "<<endl;
			Napoje napoje;

			SetConsoleTextAttribute( hOut, FOREGROUND_BLUE | FOREGROUND_INTENSITY | FOREGROUND_RED );

			napoje.utworzKoszyk(koszyk_obj);
			break;
		}
	}

}






//------------------------------------------------------         MAIN           -------------------------------------------------------------

Produkty tablica_gl[50]={};
int straznik = 0;

int main()
{

	HANDLE hOut;
	hOut = GetStdHandle( STD_OUTPUT_HANDLE );
	SetConsoleTextAttribute( hOut, FOREGROUND_GREEN);

	cout<<setw (30) << " "<< PL("Witaj w sieci Chrz�szcz!") << endl;
	cout << setw (29) << " " << PL("Codziennie randomowe ceny!")<<endl;
	cout<<setw (34) << " " <<PL("Udanych zakup�w ")<<char(2)<<endl;
	cout<<endl;

	Koszyk kosz_obj;
    //kosz_obj.id=0;   w konstruktorze koszyka
    int wybor=1;
	while(wybor!=4)
	{
		SetConsoleTextAttribute( hOut, BACKGROUND_GREEN );
		cout<< setw(45) << PL("MENU G��WNE")<< setw (35) << " ";
		SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_INTENSITY );
		cout <<PL ("\n1.Wybierz dzia�.\n2.Sprawd� zawarto�� koszyka.\n3.Zap�a� i zako�cz zakupy.\n4.Wyj�cie bez zakup�w.")<<endl;
		cin>>wybor;

		switch(wybor)
		{
		case 1:
			SetConsoleTextAttribute( hOut, BACKGROUND_GREEN );
			cout<<PL("WYBIERZ DZIA�: ");
			SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_INTENSITY );
			cout<<PL("\n1.Warzywa\n2.Owoce\n3.Nabia�\n4.Napoje\n5.Wr�� do g��wnego menu\n");
			SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_INTENSITY );

			podMenu(kosz_obj);

			break;
		case 2:
			cout<<"PRODUKTY W TWOIM KOSZYKU: "<<endl;

			kosz_obj.wczytaj_paragon();

			break;

		case 3:
			SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_INTENSITY );
			cout<<"DRUKOWANIE PARAGONU: "<<endl<<endl;

			/*for (int i=0 ; i< 5 ; i++)
            {
                cout << tablica_gl[i] << endl;
            }*/

			try
			{
				podliczanie(kosz_obj.cena(kosz_obj.id, tablica_gl));
			}
			catch(Warning bladWyjatek)
			{
				bladWyjatek.ostrzezenie=PL("Niestety kwota, kt�r� wprowdzi�e� nie jest wystarczaj�ca. Sp�buj ponownie podczas kolejnych zakup�w.\n\n\n Mi�ego dnia!");
				cout<<bladWyjatek.ostrzezenie<<endl;
			}

			if (remove("paragon.txt") == 0);
			wybor=4;
			break;
		case 4:
			SetConsoleTextAttribute( hOut, FOREGROUND_RED | FOREGROUND_INTENSITY );
			if (remove("paragon.txt") == 0);
			cout<<PL("WYJ�CIE!\n");
			break;
		}
	}

	system("pause");
	return 0;
}

