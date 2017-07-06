#ifndef KRATA_H
#define KRATA_H

#include <iostream>

class Krata
{
public:
	int ** tab;
	int rozmiar;
	int c;
	bool ** pary;

	Krata ( int n);
	
	Krata ( const Krata& krata );
	~Krata (); //TO DO bo wyjebuje pamiec
	bool sprawdz_gora (int x, int y);
	bool sprawdz_lewo ( int x, int y );
	void to_stream ( std::ostream& os );
	void from_stream ( std::istream & StrmWe );
	friend std::ostream& operator << ( std::ostream& os, const Krata& object );
	friend std::istream & operator >> ( std::istream & StrmWe, const Krata & object );
};

#endif