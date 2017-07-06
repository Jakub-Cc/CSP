#include "Krata.h"



Krata::Krata (int n)
{
	rozmiar = n;
	if ( n % 2 == 0 )
	{
		c = 2 * n;
	}
	else
	{
		c = 2 * n + 1;
	}
	tab = new int*[n];
	pary = new bool*[c];
	for ( int i = 0; i < n; i++ )
	{
		tab[i] = new int[n]() ;
		
	}
	for ( int i = 0; i < c; i++ )
	{
		pary[i] = new bool[c] ();
		pary[i][i] = true;
	}
}




Krata::Krata ( const Krata & krata )
{

	rozmiar=krata.rozmiar;
	c=krata.c;
	tab = new int*[rozmiar];
	for ( int i = 0; i < rozmiar; i++ )
	{
		tab[i] = new int[rozmiar];
		for ( int j = 0; j < rozmiar; j++ )
		{
			tab[i][j] = krata.tab[i][j];
		}
	}
	pary = new bool *[c];
	for ( int i = 0; i < c; i++ )
	{
		pary[i] = new bool[c];
		for ( int j = 0; j < c; j++ )
		{
			 pary[i][j]=krata.pary[i][j];
		}
	}
}

Krata::~Krata ()
{
	for ( int j = 0; j < rozmiar; j++ )
	{
		delete[] tab[j];
	}
	delete[] tab;

	for ( int j = 0; j < c; j++ )
	{
		delete[] pary[j];
	}
	delete[] pary;
}

bool Krata::sprawdz_gora (int x, int y)
{
	if ( x == 0 ) return true;
	else
	{
		int kolor1 = tab[x][y];
		int kolor2 = tab[x - 1][y];
		if ( pary[kolor1][kolor2] == 0 )
		{
			pary[kolor2][kolor1] = 1;
			pary[kolor1][kolor2] = 1;
			return true;
		}
		else
			return false;
	}
}

bool Krata::sprawdz_lewo (int x, int y)
{
	if ( y  == 0 ) return true;
	else
	{
		int kolor1 = tab[x][y];
		int kolor2 = tab[x][y-1];
		if ( pary[kolor1][kolor2] == 0 )
		{
			pary[kolor2][kolor1] = 1;
			pary[kolor1][kolor2] = 1;
			return true;
		}
		else
			return false;
	}
}

std::ostream & operator<<( std::ostream & os, Krata & object )
{
	object.to_stream ( os );
	return os;
}

std::istream & operator >> ( std::istream & is, Krata  & object )
{
	object.from_stream ( is );
	return is;
}

void Krata::to_stream ( std::ostream & os ) //TO REDO
{
	os << "n: " << rozmiar << " c: " << c << " [";
}

void Krata::from_stream ( std::istream & is ) //TO DO
{
	is.ignore ( 3 );
	is >> rozmiar;
	is.ignore ( 8 );
	is >> c;
	is.ignore ( 2 );
	is.ignore ( 1 );
}