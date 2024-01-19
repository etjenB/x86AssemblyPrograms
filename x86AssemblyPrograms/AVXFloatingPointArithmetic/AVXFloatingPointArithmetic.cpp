// AVXFloatingPointArithmetic.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <stdlib.h>

extern "C" void AVX_fp_Arith(double a, double b, double results[8]);

int main()
{
	const char* inames[8] = { "vaddsd","vsubsd","vmulsd","vdivsd","vminsd","vmaxsd","vsqrtsd a","fabs b" };
	double a = 13.90;
	double b = -78.67;
	double output[8];

	AVX_fp_Arith(a, b, output);

	printf("\nResult from computation\n");
	printf("a: %.6lf\n", a);
	printf("b: %.6lf\n", b);

	for (size_t i = 0; i < 8; i++)
	{
		printf("%-14s %-12.6lf\n", inames[i], output[i]);
	}

	return 0;
}