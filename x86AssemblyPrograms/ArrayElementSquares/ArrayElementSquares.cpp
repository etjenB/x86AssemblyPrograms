// ArrayElementSquares.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <stdlib.h>

extern "C" int CalcArraySquaresASM(int* y, int* x, int n);
int CalcArraySquaresCPP(int* y, int* x, int n);

int main()
{
	int x[] = { 2,3,4,5,6,7,8,9 };
	const int n = sizeof(x) / sizeof(int);
	int y1[n];
	int y2[n];
	int ass_sum, cpp_sum;

	ass_sum = CalcArraySquaresASM(y2, x, n);
	cpp_sum = CalcArraySquaresCPP(y1, x, n);

	for (size_t i = 0; i < n; i++)
	{
		printf("i: %2d x: %4d y1: %4d y2: %4d\n", i, x[i], y1[i], y2[i]);
		printf("\n");
	}
	printf("Assembly sum: %d\n", ass_sum);
	printf("C++ sum: %d\n", cpp_sum);

	return 0;
}

int CalcArraySquaresCPP(int* y, int* x, int n) {
	int sum = 0;

	for (size_t i = 0; i < n; i++)
	{
		y[i] = x[i] * x[i];
		sum += y[i];
	}

	return sum;
}