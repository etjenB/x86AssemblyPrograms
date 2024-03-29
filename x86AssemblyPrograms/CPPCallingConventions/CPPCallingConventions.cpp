// CPPCallingConventions.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <stdlib.h>

extern "C" void CalculateSum(int a, int b, int c, int* s1, int* s2, int* s3);

int main()
{
	int a = 2, b = 3, c = 4;
	int s1, s2, s3;

	CalculateSum(a, b, c, &s1, &s2, &s3);

	printf("Inputs - > a: %4d b: %4d c: %4d\n", a, b, c);
	printf("Outputs - > sum: %4d square: %4d cube: %4d\n", s1, s2, s3);

	return 0;
}