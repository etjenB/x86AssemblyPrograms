// SSEfpSphereVolArea.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <stdlib.h>

extern "C" bool SseSphereCalculator(double r, double* sa, double* v);

int main()
{
	const double r[] = { -1.0,0.0,1.0,3.0,9.0,8.0,2.3,4.5,6.7 };
	int num_r = sizeof(r) / sizeof(double);

	for (size_t i = 0; i < num_r; i++)
	{
		double sa, v;
		bool rv;
		rv = SseSphereCalculator(r[i], &sa, &v);
		printf("rv: %d r: %8.2lf sa: %10.4lf vol: %10.4lf\n", rv, r[i], sa, v);
	}

	return 0;
}