// Statistics.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <stdlib.h>

extern "C" bool CalcMeanStdDevASM(const double* a, int n, double* mean, double* stdDev);
bool CalcMeanStdDevCPP(const double* a, int n, double* mean, double* stdDev);

int main()
{
	double a[] = { 2,5,6,7,12,45,67,12,9,0,1,3,21 };
	const int n = sizeof(a) / sizeof(double);

	double mean_cpp, stdev_cpp, mean_asm, stdev_asm;

	CalcMeanStdDevASM(a, n, &mean_asm, &stdev_asm);
	CalcMeanStdDevCPP(a, n, &mean_cpp, &stdev_cpp);

	for (size_t i = 0; i < n; i++)
	{
		printf("a[%d] = %g\n", i, a[i]);
	}

	printf("\n");
	printf("Assembly mean: %g Assembly stddev: %g\n", mean_asm, stdev_asm);
	printf("CPP mean: %g CPP stddev: %g\n", mean_cpp, stdev_cpp);

	return 0;
}

bool CalcMeanStdDevCPP(const double* a, int n, double* mean, double* stdDev) {
	if (n <= 1) return false;
	double sum = 0;

	for (size_t i = 0; i < n; i++)
	{
		sum += a[i];
	}

	*mean = sum / n;
	sum = 0;

	for (size_t i = 0; i < n; i++)
	{
		double temp = a[i] - *mean;
		sum += temp * temp;
	}

	*stdDev = sqrt(sum / (n - 1));
	return true;
}