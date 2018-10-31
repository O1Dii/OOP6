#include "D3.h"



D3::D3(int b)
{
	this->a = b;
}

void D3::show()
{
	std::cout << "В классе D3 есть одна переменная " << this->a << std::endl;
}
