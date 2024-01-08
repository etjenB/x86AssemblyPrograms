// SignedDivMul.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <stdlib.h>

extern "C" int IntegerMulDiv(int a, int b, int* prod, int* quo, int* rem);

int main()
{
	int a = -21, b = 9;
	int prod = 0, quo = 0, rem = 0;
	int rv = IntegerMulDiv(a, b, &prod, &quo, &rem);

	printf("Input a: %4d b: %4d\n", a, b);
	printf("Output result: %4d product: %4d quotient: %4d remainder: %4d\n", rv, prod, quo, rem);

	return 0;
}