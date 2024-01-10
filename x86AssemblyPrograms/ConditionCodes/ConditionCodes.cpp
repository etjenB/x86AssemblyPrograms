// ConditionCodes.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <stdlib.h>

//conditional jumps
extern "C" int SignedMinA(int a, int b, int c);
extern "C" int SignedMaxA(int a, int b, int c);
//conditional moves
extern "C" int SignedMinB(int a, int b, int c);
extern "C" int SignedMaxB(int a, int b, int c);

int main()
{
	int a = 345, b = -783, c = 34;
	int max_a, min_a, max_b, min_b;

	max_a = SignedMaxA(a, b, c);
	min_a = SignedMinA(a, b, c);

	max_b = SignedMaxB(a, b, c);
	min_b = SignedMinB(a, b, c);

	printf("SignedMaxA(%4d, %4d, %4d) = %4d\n", a, b, c, max_a);
	printf("SignedMinA(%4d, %4d, %4d) = %4d\n", a, b, c, min_a);

	printf("SignedMaxB(%4d, %4d, %4d) = %4d\n", a, b, c, max_b);
	printf("SignedMinB(%4d, %4d, %4d) = %4d\n", a, b, c, min_b);

	return 0;
}