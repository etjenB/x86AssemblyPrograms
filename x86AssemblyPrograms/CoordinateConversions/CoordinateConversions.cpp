// CoordinateConversions.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <stdlib.h>

extern "C" void RectToPolar(double x, double y, double* r, double* a);
extern "C" void PolarToRect(double r, double a, double* x, double* y);

int main()
{
	double x[] = { 0,3,-3,-5,6 };
	double y[] = { 0,3,5,-7,8 };
	const int nx = sizeof(x) / sizeof(double);
	const int ny = sizeof(y) / sizeof(double);

	for (size_t i = 0; i < ny; i++)
	{
		double r, a, _x, _y;
		int j;
		for (j = 0; j < nx; j++)
		{
			RectToPolar(x[i], y[i], &r, &a);
			PolarToRect(r, a, &_x, &_y);
		}
		printf("%8.4lf, %8.4lf", x[i], y[i]);
		printf("(%8.4lf, %10.4lf)", r, a);
		printf("(%8.4lf, %8.4lf)\n", _x, _y);
	}

	return 0;
}