#include "Hetmans.h"

bool Hetmans::validate()
{
	for (int i = 0; i < seted; i++)
	{
		for (int j = i + 1; j < seted; j++)
		{
			if (positions[i] == positions[j])
			{
				return false;
			}
			else
			{
				for (int x = -seted; x < seted ; x++)
				{ 
					if (i==j+x && positions[i]==positions[j] + x)
					{
						return false;
					}
					else if (i==j+x && positions[i] == positions[j] - x)
					{
						return false;
					}
				}
			}
		}
	}
	return true;
}
bool Hetmans::validate2()
{
	int i = seted - 1;
	for (int j = 0; j< i;j++)
	{
		if (positions[i] == positions[j])
		{
			return false;
		}
		else
		{
			for (int x = 1; x < seted; x++)
			{
				if (i == j + x)
				{
					if (positions[i] == positions[j] + x)
					{
						return false;
					}
					else if (positions[i] == positions[j] - x)
					{
						return false;
					}
				}
			}
		}
	}
	return true;
}
int Hetmans::get_n()
{
	return n;
}

int Hetmans::get_s()
{
	return seted;
}

void Hetmans::to_stream(std::ostream & os)
{
	os<< "n: " << n << " seted: " << seted <<" [";
	for (int i = 0;i < seted;i++)
	{
		os  << positions[i]  ;
		if (i != seted - 1)
			os << ",";
	}
	
	os << " ]\n";
}

void Hetmans::from_stream(std::istream & is)
{
	is.ignore(3);
	is >> n;
	is.ignore(8);
	is >> seted;
	is.ignore(2);
	for (int i = 0;i < seted;i++)
	{
		is >> positions[i];
		is.ignore(1);
	}
	is.ignore(1);
}

bool Hetmans::set_new_position(int position_x)
{
	if (seted == n)
	{
		return false;
	}
	else
	{
		positions[seted] = position_x;
		seted++;
		return true;
	}
}

Hetmans::Hetmans(int h_n)
{
	n = h_n;
	seted = 0;
	positions = new int [h_n];
	for (int i = 0;i < n;i++)
		positions[i] = -1;
}

std::ostream & operator<<(std::ostream & os, Hetmans & object)
{
	object.to_stream(os);
	return os;
}

std::istream & operator>>(std::istream & is, Hetmans & object)
{
	object.from_stream(is);
	return is;
}
