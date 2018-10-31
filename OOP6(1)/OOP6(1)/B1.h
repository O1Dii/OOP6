#pragma once
#include "D1.h"
#include "D2.h"
class B1 :
	public D1, protected D2
{
public:
	B1(int b) : D3(b), D1(b), D2(b) {};
	void show() override;
};

