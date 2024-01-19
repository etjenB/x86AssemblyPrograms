#pragma once

#include "MiscDef.h"

union XmmVal
{
	Int8 i8[16];
	Int16 i16[8];
	Int32 i32[4];
	Int64 i64[2];

	UInt8 ui8[16];
	UInt16 ui16[8];
	UInt32 ui32[4];
	UInt64 ui64[2];

	float r32[4];
	double r64[2];

	char* ToString_i8(char* s, size_t len);
	char* ToString_i16(char* s, size_t len);
	char* ToString_i32(char* s, size_t len);
	char* ToString_i64(char* s, size_t len);

	char* ToString_ui8(char* s, size_t len);
	char* ToString_ui16(char* s, size_t len);
	char* ToString_ui32(char* s, size_t len);
	char* ToString_ui64(char* s, size_t len);

	char* ToString_x8(char* s, size_t len);
	char* ToString_x16(char* s, size_t len);
	char* ToString_x32(char* s, size_t len);
	char* ToString_x64(char* s, size_t len);

	char* ToString_r32(char* s, size_t len);
	char* ToString_r64(char* s, size_t len);
};