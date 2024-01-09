// IntegersExploration.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <stdlib.h>

extern "C" char GlobalChar = 10;
extern "C" short GlobalShort = 20;
extern "C" int GlobalInt = 30;
extern "C" long long GlobalLongLong = 200;

extern "C" void IntegerAddition(char a, short b, int c, long long d);

int main()
{
	IntegerAddition(3, 5, -37, -100);

	printf("Char value %d\nShort value %d\nInt value %d\nLong Long value %lld\n", GlobalChar, GlobalShort ,GlobalInt, GlobalLongLong);

	return 0;
}