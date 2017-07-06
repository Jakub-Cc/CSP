#ifndef CSP_H
#define CSP_H
#include "Hetmans.h"
#include "Krata.h"
class CSP
{

public:
	CSP();
	~CSP();
	int Count_back(Hetmans hetmans, int &nodes);
	int Count_forward(Hetmans hetmans, int& nodes);
	int Count_forward_fix2(Hetmans hetman, bool tab[], int& nodes);
	int Count_forward_fix(Hetmans hetman, bool **tab, int& nodes);
	int backtracking ( Krata krata, int &odwiedzone);
	int forward_checking ( Krata krata, int &odwiedzone );
	int backtracking_helper ( Krata krata, int &odwiedzone, int x, int y );
};
#endif
