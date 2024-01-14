// SphereAreaVolume.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <stdlib.h>

extern "C" bool CalcSphereAreaVolume(double r, double* sa, double* v);

int main()
{
	double r[] = { 0,1,2,3,4,5,20,34 };
	int num_r = sizeof(r) / sizeof(double);
	double sa = -1;
	double v = -1;
	bool rv;

	for (size_t i = 0; i < num_r; i++)
	{
		rv = CalcSphereAreaVolume(r[i], &sa, &v);
		if (rv) printf("rv: %d r: %8.2lf sa: %10.4lf v: %10.4lf\n", rv, r[i], sa, v);
	}

	return 0;
}