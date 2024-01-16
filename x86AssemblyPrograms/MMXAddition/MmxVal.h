#pragma once
#include "MiscDef.h"

union MmxVal
{
	Int8 i8[8];					//mmx registers are 64 bit in size, and can therefor hold 8 8 bit values
	Int16 i16[4];				//mmx registers can hold 4 16 bit values
	Int32 i32[2];				//mmx registers can hold 2 32 bit values
	Int64 i64;					//mmx registers can hold 1 64 bit value

	UInt8 ui8[8];
	UInt16 ui16[4];
	UInt32 ui32[2];
	UInt64 ui64;

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
};