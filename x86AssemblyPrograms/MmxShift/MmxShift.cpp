// MmxShift.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <stdlib.h>
#include "MmxVal.h"

enum MmxShiftOp : unsigned int {
	psllw,
	psrlw,
	psraw,
	pslld,
	psrld,
	psrad
};

extern "C" bool MmxShifter(MmxVal a, MmxShiftOp shift_op, int count, MmxVal * b);
void MmxShiftDWords();
void MmxShiftWords();

int main()
{
	//MmxShiftWords();
	MmxShiftDWords();
	return 0;
}

void MmxShiftWords() {
	MmxVal a, b;
	int count;
	char buff[256];

	a.ui16[0] = 0x1234;
	a.ui16[1] = 0xFF00;
	a.ui16[2] = 0x00CC;
	a.ui16[3] = 0x8000;
	count = 2;

	MmxShifter(a, MmxShiftOp::psllw, count, &b);
	printf("\nResult for psllw - count = %d\n", count);
	printf("a: %s\n", a.ToString_x16(buff, sizeof(buff)));
	printf("b: %s\n", b.ToString_x16(buff, sizeof(buff)));

	MmxShifter(a, MmxShiftOp::psrlw, count, &b);
	printf("\nResult for psrlw - count = %d\n", count);
	printf("a: %s\n", a.ToString_x16(buff, sizeof(buff)));
	printf("b: %s\n", b.ToString_x16(buff, sizeof(buff)));

	MmxShifter(a, MmxShiftOp::psraw, count, &b);
	printf("\nResult for psraw - count = %d\n", count);
	printf("a: %s\n", a.ToString_x16(buff, sizeof(buff)));
	printf("b: %s\n", b.ToString_x16(buff, sizeof(buff)));
}

void MmxShiftDWords() {
	MmxVal a, b;
	int count;
	char buff[256];

	a.ui32[0] = 0x00010001;
	a.i32[1] = 0x80008000;
	count = 3;

	MmxShifter(a, MmxShiftOp::pslld, count, &b);
	printf("\nResult for pslld - count = %d\n", count);
	printf("a: %s\n", a.ToString_x32(buff, sizeof(buff)));
	printf("b: %s\n", b.ToString_x32(buff, sizeof(buff)));

	MmxShifter(a, MmxShiftOp::psrld, count, &b);
	printf("\nResult for psrld - count = %d\n", count);
	printf("a: %s\n", a.ToString_x32(buff, sizeof(buff)));
	printf("b: %s\n", b.ToString_x32(buff, sizeof(buff)));

	MmxShifter(a, MmxShiftOp::psrad, count, &b);
	printf("\nResult for psrad - count = %d\n", count);
	printf("a: %s\n", a.ToString_x32(buff, sizeof(buff)));
	printf("b: %s\n", b.ToString_x32(buff, sizeof(buff)));
}