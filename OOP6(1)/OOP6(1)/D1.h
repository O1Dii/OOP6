#pragma once
#include "D3.h"
class D1 :
	public virtual D3
{
public:
	D1(int b) : D3(b) {};
	void show() override;
};

