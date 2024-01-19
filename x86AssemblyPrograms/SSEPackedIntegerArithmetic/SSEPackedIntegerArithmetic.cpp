// SSEPackedIntegerArithmetic.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <stdlib.h>
#include "Xmm.h"

extern "C" void SsePackedInt16_Add(const XmmVal * a, const XmmVal * b, XmmVal c[2]);
extern "C" void SsePackedInt32_Sub(const XmmVal * a, const XmmVal * b, XmmVal* c);
extern "C" void SsePackedInt32_Mul(const XmmVal * a, const XmmVal * b, XmmVal c[2]);

int main()
{

	return 0;
}