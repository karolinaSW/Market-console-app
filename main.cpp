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
		case 'π': result += static_cast < char >( 0xa5 ); break;
		case 'Ê': result += static_cast < char >( 0x86 ); break;
		case 'Í': result += static_cast < char >( 0xa9 ); break;
		case '≥': result += static_cast < char >( 0x88 ); break;
		case 'Ò': result += static_cast < char >( 0xe4 ); break;
		case 'Û': result += static_cast < char >( 0xa2 ); break;
		case 'ú': result += static_cast < char >( 0x98 ); break;
		case 'ø': result += static_cast < char >( 0xbe ); break;
		case 'ü': result += static_cast < char >( 0xab ); break;
		case '•': result += static_cast < char >( 0xa4 ); break;
		case '∆': result += static_cast < char >( 0x8f ); break;
		case ' ': result += static_cast < char >( 0xa8 ); break;
		case '£': result += static_cast < char >( 0x9d ); break;
		case '—': result += static_cast < char >( 0xe3 ); break;
		case '”': result += static_cast < char >( 0xe0 ); break;
		case 'å': result += static_cast < char >( 0x97 ); break;
		case 'Ø': result += static_cast < char >( 0xbd ); break;
		case 'è': result += static_cast < char >( 0x8d ); break;
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
	cout<< PL("RAZEM DO ZAP£ATY :   ")<<suma<<"   PLN"<<endl<<endl;
	SetConsoleTextAttribute( hOut, FOREGROUND_RED | FOREGROUND_INTENSITY );
	cout<<PL("ZAP£A∆  ->   ");
	double x;
	cin>>x;
	cout<<endl;
	if(suma==x)
	{
		{
			cout<<PL("DziÍkujemy za zakupy i zapraszamy ponownie! \n\nChrzπszcz - Codziennie randomowe ceny :) ")<<endl<<endl;
			cout<<PL("WYJåCIE!\n");
		}
	}
	while(suma>x)
	{

		cout<<PL("ODMOWA! ZAP£A∆ PONOWNIE  ->   ");
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
		cout<<PL("DZI KUJEMY ZA ZAKUPY I ØYCZYMY MI£EGO DNIA")<<char(1)<<endl<<endl;
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

			cout<<PL("NABIA£: ")<<endl;
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

	cout<<setw (30) << " "<< PL("Witaj w sieci Chrzπszcz!") << endl;
	cout << setw (29) << " " << PL("Codziennie randomowe ceny!")<<endl;
	cout<<setw (34) << " " <<PL("Udanych zakupÛw ")<<char(2)<<endl;
	cout<<endl;

	Koszyk kosz_obj;
    //kosz_obj.id=0;   w konstruktorze koszyka
    int wybor=1;
	while(wybor!=4)
	{
		SetConsoleTextAttribute( hOut, BACKGROUND_GREEN );
		cout<< setw(45) << PL("MENU G£”WNE")<< setw (35) << " ";
		SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_INTENSITY );
		cout <<PL ("\n1.Wybierz dzia≥.\n2.Sprawdü zawartoúÊ koszyka.\n3.Zap≥aÊ i zakoÒcz zakupy.\n4.Wyjúcie bez zakupÛw.")<<endl;
		cin>>wybor;

		switch(wybor)
		{
		case 1:
			SetConsoleTextAttribute( hOut, BACKGROUND_GREEN );
			cout<<PL("WYBIERZ DZIA£: ");
			SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_INTENSITY );
			cout<<PL("\n1.Warzywa\n2.Owoce\n3.Nabia≥\n4.Napoje\n5.WrÛÊ do g≥Ûwnego menu\n");
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
				bladWyjatek.ostrzezenie=PL("Niestety kwota, ktÛrπ wprowdzi≥eú nie jest wystarczajπca. SpÛbuj ponownie podczas kolejnych zakupÛw.\n\n\n Mi≥ego dnia!");
				cout<<bladWyjatek.ostrzezenie<<endl;
			}

			if (remove("paragon.txt") == 0);
			wybor=4;
			break;
		case 4:
			SetConsoleTextAttribute( hOut, FOREGROUND_RED | FOREGROUND_INTENSITY );
			if (remove("paragon.txt") == 0);
			cout<<PL("WYJåCIE!\n");
			break;
		}
	}

	system("pause");
	return 0;
}

