#ifndef HETMANS_H
#define HETMANS_H

#include <iostream>

class Hetmans
{
	int n;
	int * positions;
	int seted;
public:
	Hetmans(int h_n);
	bool set_new_position(int position_x);
	bool validate();
	bool validate2();
	int get_n();
	int get_s();
	void to_stream(std::ostream& os);
	void from_stream(std::istream & StrmWe) ;
	friend std::ostream& operator<< (std::ostream& os, const Hetmans& object);
	friend std::istream & operator >> (std::istream & StrmWe, const Hetmans & object);
};

#endif
