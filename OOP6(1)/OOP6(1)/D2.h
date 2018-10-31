#pragma once
#include "D3.h"
class D2 :
	protected virtual D3
{
public:
	D2(int b) : D3(b) {};
	void show() override;
};

