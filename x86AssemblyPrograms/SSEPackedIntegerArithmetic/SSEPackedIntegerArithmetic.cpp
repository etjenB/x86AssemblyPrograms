// SSEPackedIntegerArithmetic.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <stdlib.h>
#include "Xmm.h"

extern "C" void SsePackedInt16_Add(const XmmVal * a, const XmmVal * b, XmmVal c[2]);
extern "C" void SsePackedInt32_Sub(const XmmVal * a, const XmmVal * b, XmmVal* c);
extern "C" void SsePackedInt32_Mul(const XmmVal * a, const XmmVal * b, XmmVal c[2]);

void SsePackedInt16_Add_Test();
void SsePackedInt32_Sub_Test();
void SsePackedInt32_Mul_Test();

int main()
{
    SsePackedInt16_Add_Test();
	SsePackedInt32_Sub_Test();
	SsePackedInt32_Mul_Test();
	return 0;
}

void SsePackedInt16_Add_Test() {
	_declspec(align(16))XmmVal a;
	_declspec(align(16))XmmVal b;
	_declspec(align(16))XmmVal c[2];
	char buff[256];

	a.i16[0] = 10;
	a.i16[1] = 210;
	a.i16[2] = -890;
	a.i16[3] = 234;
	a.i16[4] = 46;
	a.i16[5] = 67;
	a.i16[6] = 0;
	a.i16[7] = 254;

	b.i16[0] = 90;
	b.i16[1] = 78;
	b.i16[2] = 90;
	b.i16[3] = 76;
	b.i16[4] = 4;
	b.i16[5] = -89;
	b.i16[6] = 1;
	b.i16[7] = 18;

	SsePackedInt16_Add(&a, &b, c);

	printf("\nResult for SsePackedInt16_Add\n");
	printf("a: %s\n", a.ToString_i16(buff, sizeof(buff)));
	printf("b: %s\n", b.ToString_i16(buff, sizeof(buff)));
	printf("c: %s\n", c[0].ToString_i16(buff, sizeof(buff)));

	printf("\n");

	printf("a: %s\n", a.ToString_i16(buff, sizeof(buff)));
	printf("b: %s\n", b.ToString_i16(buff, sizeof(buff)));
	printf("c: %s\n", c[1].ToString_i16(buff, sizeof(buff)));
}

void SsePackedInt32_Sub_Test() {
	_declspec(align(16))XmmVal a;
	_declspec(align(16))XmmVal b;
	_declspec(align(8))XmmVal c;
	char buff[256];

	a.i32[0] = 200;
	a.i32[1] = 2901;
	a.i32[2] = -890;
	a.i32[3] = 234;

	b.i32[0] = 100;
	b.i32[1] = -56;
	b.i32[2] = 90;
	b.i32[3] = 76;

	SsePackedInt32_Sub(&a, &b, &c);

	printf("\nResult for SsePackedInt32_Sub\n");
	printf("a: %s\n", a.ToString_i32(buff, sizeof(buff)));
	printf("b: %s\n", b.ToString_i32(buff, sizeof(buff)));
	printf("c: %s\n", c.ToString_i32(buff, sizeof(buff)));
}

void SsePackedInt32_Mul_Test() {
	_declspec(align(16))XmmVal a;
	_declspec(align(16))XmmVal b;
	_declspec(align(16))XmmVal c[2];
	char buff[256];

	a.i32[0] = 10;
	a.i32[1] = 20;
	a.i32[2] = 2;
	a.i32[3] = 1000;

	b.i32[0] = 2;
	b.i32[1] = 13;
	b.i32[2] = 90;
	b.i32[3] = -20;

	SsePackedInt32_Mul(&a, &b, c);

	printf("\nResult for SsePackedInt32_Mul\n");
	printf("a: %s\n", a.ToString_i32(buff, sizeof(buff)));
	printf("b: %s\n", b.ToString_i32(buff, sizeof(buff)));
	printf("c: %s\n", c[0].ToString_i32(buff, sizeof(buff)));

	printf("\n");

	printf("a: %s\n", a.ToString_i32(buff, sizeof(buff)));
	printf("b: %s\n", b.ToString_i32(buff, sizeof(buff)));
	printf("c: %s\n", c[1].ToString_i64(buff, sizeof(buff)));
}