// TemperatureConversion.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <stdlib.h>

extern "C" double FtoC(double deg_f);
extern "C" double CtoF(double deg_c);

int main()
{
	double cel_temp = 30;
	double f_temp = 86;

	printf("C value: %10.4lf F value: %10.4lf\n", cel_temp, CtoF(cel_temp));
	printf("F value: %10.4lf C value: %10.4lf\n", f_temp, FtoC(f_temp));

	return 0;
}