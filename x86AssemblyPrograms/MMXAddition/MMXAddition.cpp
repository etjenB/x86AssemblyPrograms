// MMXAddition.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include "MmxVal.h"
#include <iostream>
#include <stdlib.h>

enum MmxAddOp : unsigned int {
	paddb,				//packed byte addition with wraparound
	paddsb,				//packed byte addition with signed saturation
	paddusb,			//packed byte addition with unsigned saturation
	paddw,				//packed word addition with wraparound
	paddsw,				//packed word addition with signed saturation
	paddusw,			//packed word addition with unsigned saturation
	paddd				//packed doubleword addition with wraparound
};

extern "C" MmxVal MmxAdd(MmxVal a, MmxVal b, MmxAddOp op);
void MmxAddBytes(void);
void MmxAddWords(void);

int main()
{
	//MmxAddBytes();
	MmxAddWords();
	return 0;
}

void MmxAddBytes(void) {
	MmxVal a, b, c;
	char buff[256];
	//packed byte addition - signed integers
	a.i8[0] = 50;
	a.i8[1] = 80;
	a.i8[2] = -27;
	a.i8[3] = -70;
	a.i8[4] = -42;
	a.i8[5] = 60;
	a.i8[6] = 64;
	a.i8[7] = 100;

	b.i8[0] = 30;
	b.i8[1] = 64;
	b.i8[2] = -32;
	b.i8[3] = -80;
	b.i8[4] = 90;
	b.i8[5] = -85;
	b.i8[6] = 90;
	b.i8[7] = -30;

	printf("\n\n Packed byte addition - signed integers\n");
	printf("a: %s\n", a.ToString_i8(buff, sizeof(buff)));
	printf("b: %s\n", b.ToString_i8(buff, sizeof(buff)));

	c = MmxAdd(a, b, MmxAddOp::paddsb);
	printf("\n paddsb results\n");
	printf("c: %s\n", c.ToString_i8(buff, sizeof(buff)));

	c = MmxAdd(a, b, MmxAddOp::paddb);
	printf("\n paddb results\n");
	printf("c: %s\n", c.ToString_i8(buff, sizeof(buff)));

	//packed byte addition - unsigned integers
	a.ui8[0] = 50;
	a.ui8[1] = 80;
	a.ui8[2] = 132;
	a.ui8[3] = 200;
	a.ui8[4] = 42;
	a.ui8[5] = 60;
	a.ui8[6] = 140;
	a.ui8[7] = 10;

	b.ui8[0] = 30;
	b.ui8[1] = 64;
	b.ui8[2] = 130;
	b.ui8[3] = 180;
	b.ui8[4] = 90;
	b.ui8[5] = 85;
	b.ui8[6] = 160;
	b.ui8[7] = 14;

	printf("\n\n Packed byte addition - unsigned integers\n");
	printf("a: %s\n", a.ToString_ui8(buff, sizeof(buff)));
	printf("b: %s\n", b.ToString_ui8(buff, sizeof(buff)));

	c = MmxAdd(a, b, MmxAddOp::paddusb);
	printf("\n paddusb results\n");
	printf("c: %s\n", c.ToString_ui8(buff, sizeof(buff)));

	c = MmxAdd(a, b, MmxAddOp::paddb);
	printf("\n paddb results\n");
	printf("c: %s\n", c.ToString_ui8(buff, sizeof(buff)));
}

void MmxAddWords(void) {
	MmxVal a, b, c;
	char buff[256];
	//packed word addition - signed integers
	a.i16[0] = 500;
	a.i16[1] = 30000;
	a.i16[2] = -270;
	a.i16[3] = -7000;

	b.i16[0] = 830;
	b.i16[1] = 5000;
	b.i16[2] = -320;
	b.i16[3] = -32000;

	printf("\n\n Packed word addition - signed integers\n");
	printf("a: %s\n", a.ToString_i16(buff, sizeof(buff)));
	printf("b: %s\n", b.ToString_i16(buff, sizeof(buff)));

	c = MmxAdd(a, b, MmxAddOp::paddw);
	printf("\n paddw results\n");
	printf("c: %s\n", c.ToString_i16(buff, sizeof(buff)));

	c = MmxAdd(a, b, MmxAddOp::paddsw);
	printf("\n paddsw results\n");
	printf("c: %s\n", c.ToString_i16(buff, sizeof(buff)));

	//packed word addition - unsigned integers
	a.ui16[0] = 500;
	a.ui16[1] = 48000;
	a.ui16[2] = 132;
	a.ui16[3] = 10000;

	b.ui16[0] = 30;
	b.ui16[1] = 20000;
	b.ui16[2] = 130;
	b.ui16[3] = 60000;

	printf("\n\n Packed word addition - unsigned integers\n");
	printf("a: %s\n", a.ToString_ui16(buff, sizeof(buff)));
	printf("b: %s\n", b.ToString_ui16(buff, sizeof(buff)));

	c = MmxAdd(a, b, MmxAddOp::paddw);
	printf("\n paddw results\n");
	printf("c: %s\n", c.ToString_ui16(buff, sizeof(buff)));

	c = MmxAdd(a, b, MmxAddOp::paddusw);
	printf("\n paddusw results\n");
	printf("c: %s\n", c.ToString_ui16(buff, sizeof(buff)));
}