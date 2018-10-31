#pragma once
#include "D2.h"
class B2 :
	public D2
{
public:
	B2(int b) : D3(b), D2(b) {};
	void show() override;
};

