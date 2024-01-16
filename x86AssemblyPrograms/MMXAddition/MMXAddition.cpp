// MMXAddition.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include "MmxVal.h"
#include <iostream>
#include <stdlib.h>

enum MmxAddOp : unsigned int {
	paddb,				//packed byte addition with wraparound
	paddsb,				//packed byte addition with signed saturation
	paddusb,			//packed byte addition with unsigned saturation
	paddw,				//packed word addition with wraparound
	paddsw,				//packed word addition with signed saturation
	paddusw,			//packed word addition with unsigned saturation
	paddd				//packed doubleword addition with wraparound
};

extern "C" MmxVal MmxAdd(MmxVal a, MmxVal b, MmxAddOp op);

int main()
{

	return 0;
}