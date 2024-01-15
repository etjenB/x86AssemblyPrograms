// LeastSquares.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <stdlib.h>

extern "C" double LsEpsilon;
extern "C" bool CalcLeastSquaresASM(const double* x, const double* y, int n, double* m, double* b)
bool CalcLeastSquaresCPP(const double* x, const double* y, int n, double* m, double* b);

int main()
{

	return 0;
}

bool CalcLeastSquaresCPP(const double* x, const double* y, int n, double* m, double* b) {
	if (n <= 0) return false;
	double sum_x = 0;
	double sum_y = 0;
	double sum_xy = 0;
	double sum_xx = 0;

	for (size_t i = 0; i < n; i++)
	{
		sum_x += x[i];
		sum_y += y[i];
		sum_xy += x[i] * y[i];
		sum_xx = x[i] * x[i];
	}

	double denom = n * sum_xx - sum_x * sum_x;

	if (LsEpsilon >= fabs(denom)) return false;

	*m = (n * sum_xy - sum_x * sum_y) / denom;
	*b = (sum_xx * sum_y - sum_x * sum_xy) / denom;

	return true;
}