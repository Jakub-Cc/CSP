#include "CSP.h"

#include <string>

CSP::CSP()
{
}


CSP::~CSP()
{
}

int CSP::Count_back(Hetmans hetman, int &nodes)
{
	nodes++;
	if (hetman.validate2())
	{
		if (hetman.get_n() == hetman.get_s())
		{
			return 1;
		}
		else
		{
			int sum = 0;
			for (int i = 0;i < hetman.get_n();i++)
			{
				Hetmans new_hetman = hetman;
				new_hetman.set_new_position(i);
				sum += Count_back(new_hetman,nodes);
			}
			return sum;
		}
	}
	else
	{
		return 0;
	}
}

int CSP::Count_forward(Hetmans hetman, int &nodes)
{
	nodes++;
	if (hetman.get_n() == hetman.get_s())
	{
		return 1;
	}
	else
	{
		int sum = 0;
		for (int i = 0;i < hetman.get_n();i++)
		{
			Hetmans new_hetman = hetman;
			new_hetman.set_new_position(i);
			if (new_hetman.validate())
			{
				sum += Count_forward(new_hetman, nodes);
			}
		}
		return sum;
	}
	return 0;
}

int CSP::Count_forward_fix2(Hetmans hetman, bool tab[], int& nodes)
{
	nodes++;
	/*
	int n = hetman.get_n();
	int s = hetman.get_s();
	if (s == n)
	{
		return 1;
	}
	bool help = true;
	for (int i = s; i<n && help;i++)
	{
		help = false;
		for (int j = 0; j<n && !help;j++)
		{
			help = tab[i][j];
		}
	}
	if (!help)
	{
		return 0;
	}
	else
	{
		int sum = 0;
		for (int i = 0;i<n;i++)
		{
			if (tab[s][i] == true)
			{
				Hetmans new_hetman = hetman;
				new_hetman.set_new_position(i);

				bool ** new_tab = new bool *[n];
				for (int j = 0;j<n;j++)
				{
					new_tab[j] = new bool[n];
					for (int k = 0;k<n;k++)
						new_tab[j][k] = tab[j][k];
				}

				for (int x = 1; x<n - s; x++)
				{
					new_tab[s + x][i] = false;
					if (i + x < n)
						new_tab[s + x][i + x] = false;
					if (i - x >= 0)
						new_tab[s + x][i - x] = false;
				}
				sum += Count_forward_fix(new_hetman, new_tab);
			}
		}
		return sum;
	}*/
	return 0;
}

int CSP::Count_forward_fix(Hetmans hetman, bool ** tab, int& nodes)
{
	nodes++;
	int n = hetman.get_n();
	int s = hetman.get_s();
	if (s == n)
	{
		return 1;
	}
	bool help = true;
	for (int i = s; i<n && help;i++)
	{
		help = false;
		for (int j = 0; j<n && !help;j++)
		{
			help = tab[i][j];
		}
	}
	if (!help)
	{
		return 0;
	}
	else
	{
		int sum = 0;
		for (int i = 0;i<n;i++)
		{
			if (tab[s][i] == true)
			{
				Hetmans new_hetman = hetman;
				new_hetman.set_new_position(i);

				bool ** new_tab = new bool *[n];
				for (int j = 0;j<n;j++)
				{
					new_tab[j] = new bool[n];
					for (int k = 0;k<n;k++)
						new_tab[j][k] = tab[j][k];
				}

				for (int x = 1; x<n - s; x++)
				{
					new_tab[s + x][i] = false;
					if (i + x < n)
						new_tab[s + x][i + x] = false;
					if (i - x >= 0)
						new_tab[s + x][i - x] = false;
				}
				sum += Count_forward_fix(new_hetman, new_tab, nodes);
				
				for (int j = 0;j < n;j++)
				{
					delete[] new_tab[j];
				}
				delete[] new_tab;
			}
		}
		return sum;
	}
}

int CSP::backtracking ( Krata krata, int & odwiedzone)
{
	int licznik = 0;
	for ( int i = 0; i < krata.c; i++ )
	{
		Krata nowa_krata = Krata(krata);
		nowa_krata.tab[0][0] = i;
		licznik += backtracking_helper ( nowa_krata, odwiedzone, 0, 0 );
	}
	return licznik;
}

int CSP::forward_checking ( Krata krata, int & odwiedzone )
{
	return 0;
}

int CSP::backtracking_helper ( Krata krata, int & odwiedzone, int x, int y )
{
	odwiedzone++;
	/*std::cout << odwiedzone << '\n';
	for ( int i = 0; i < krata.rozmiar; i++ )
	{
		for ( int j = 0; j < krata.rozmiar; j++ )
		{
			std::cout << krata.tab[i][j] << ' ';
		}
		std::cout << '\n';
	}*/
	Krata nowa_krata = Krata(krata);
	if ( !( nowa_krata.sprawdz_gora ( x, y ) && nowa_krata.sprawdz_lewo ( x, y ) ) )
	{
		//std::cout << "back \n";
		return 0;
	}
		
	else
	{
		if ( x == krata.rozmiar - 1 && y == krata.rozmiar - 1 ) 
		{
		//	std::cout << "return 1 \n";
			return 1;
		}
		int licznik = 0;
		for ( int i = 0; i < krata.c; i++ )
		{
			int next_x = x + 1;
			int next_y = y;
			if ( next_x == krata.rozmiar )
			{
				next_x = 0;
				next_y++;
			}
			nowa_krata.tab[next_x][next_y] = i;
			licznik += backtracking_helper ( nowa_krata, odwiedzone, next_x, next_y );
		}
		return licznik;
	}
}
