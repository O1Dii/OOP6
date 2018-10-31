#include "B1.h"
#include "B2.h"
#include "D1.h"
#include "D2.h"
#include "D3.h"
#include <iostream>

using namespace std;

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	D3 d3(3);
	D3 *p;
	D2 d2(2);
	D1 d1(1);
	B2 b2(2);
	B1 b1(1);
	d3.show();
	d2.show();
	d1.show();
	b2.show();
	b1.show();
	cout << "\
	     B1        B2\n\
	    \/  \\      \/\n\
	pub\/    \\prot\/pub\n\
	  \/      \\  \/\n\
	 D1       D2\n\
	  \\      \/\n\
	pub\\    \/prot\n\
	    \\  \/\n\
	     D3\n" << endl;
	system("PAUSE");
}




