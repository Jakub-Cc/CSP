#include <iostream>
#include <string> 
#include <math.h> 
#include <cmath>
#include <windows.h>

#include "CSP.h"


LARGE_INTEGER startTimer()
{
	LARGE_INTEGER start;
	DWORD_PTR oldmask = SetThreadAffinityMask(GetCurrentThread(), 0);
	QueryPerformanceCounter(&start);
	SetThreadAffinityMask(GetCurrentThread(), oldmask);
	return start;
}
LARGE_INTEGER endTimer()
{
	LARGE_INTEGER stop;
	DWORD_PTR oldmask = SetThreadAffinityMask(GetCurrentThread(), 0);
	QueryPerformanceCounter(&stop);
	SetThreadAffinityMask(GetCurrentThread(), oldmask);
	return stop;
}

void main()
{
	LARGE_INTEGER performanceCountStart, performanceCountEnd;
	LARGE_INTEGER frequency;
	QueryPerformanceFrequency(&frequency);

	//hetmans
	int n = 12;
	for (int i = 14; i < 14;i++)
	{ 
			n = i;
			std::cout << n << "\n";
		Hetmans hetman = Hetmans(n);
		CSP csp;

		bool ** tab = new bool *[n];
		for (int i = 0;i<n;i++)
		{
			tab[i] = new bool[n];
			for (int j = 0;j<n;j++)
			{
				tab[i][j] = true;
			}
		}
		int count = 0;
		performanceCountStart = startTimer();
		std::cout << csp.Count_forward_fix(hetman,tab,count)<<"\n";
		performanceCountEnd = endTimer();

		double tm = (double) performanceCountEnd.QuadPart - performanceCountStart.QuadPart;
		tm = tm / frequency.QuadPart;
		std::cout << std::to_string(tm) << " " << count <<"\n";
		int count2 = 0;

		performanceCountStart = startTimer();
		std::cout << csp.Count_back(hetman,count2) << "\n";
		performanceCountEnd = endTimer();

		tm = (double) performanceCountEnd.QuadPart - performanceCountStart.QuadPart;
		tm=tm/frequency.QuadPart;
		std::cout << std::to_string(tm) <<" "<< count2<< "\n";
	}
	
	std::cout << "test\n";

	Krata krata = Krata ( 3 );
	/*krata.tab[0][0] = 0;
	krata.tab[0][1] = 0;
	krata.tab[1][0] = 0;
	 krata.tab[1][1] = 0;
	int x = -1;
	int y = 0;
	for ( int i = 0; i < krata.rozmiar; i++ )
	{
		for ( int j = 0; j < krata.rozmiar; j++ )
		{
			std::cout << krata.tab[i][j]<<" ";
		}
		std::cout << "\n";
	}
	for ( int i = 0; i < krata.rozmiar; i++ )
	{
		for ( int j = 0; j < krata.rozmiar; j++ )
		{
			std::cout << "x: " << i << " y: " << j << '\n';
			std::cout << ( krata.sprawdz_gora ( i, j ) && krata.sprawdz_lewo ( i, j ) ) << '\n';
		}
	}
	*/
	//
	CSP csp;
	int licznik = 0;
	std::cout << "c: " << krata.c << " n: " << krata.rozmiar<<'\n' ;
	std::cout <<"\nznalezione wyniki "<< std::to_string ( csp.backtracking ( krata, licznik ) );
	std::cout <<"\nwezly "<< std::to_string ( licznik );
	std::cout << "\n";

	/*
	krata.tab[0][0] = 0;
	krata.tab[0][1] = 1;
	krata.tab[1][0] = 2;
	krata.tab[1][1] = 3;
	Krata krata2 = Krata(krata);
	krata.tab[0][0] = 5;
	for ( int i = 0; i < krata.rozmiar; i++ )
	{
		for ( int j = 0; j < krata.rozmiar; j++ )
		{
			std::cout << krata.tab[i][j] << " ";
		}
		std::cout << "\n";
	}
	std::cout << "k2 \n";

	for ( int i = 0; i < krata.rozmiar; i++ )
	{
		for ( int j = 0; j < krata.rozmiar; j++ )
		{
			std::cout << krata2.tab[i][j] << " ";
		}
		std::cout << "\n";
	}*/
	system("pause");
}