#include "pch.h"
#include "MmxVal.h"
#include <stdio.h>

char* MmxVal::ToString_i8(char* s, size_t len) {
	sprintf_s(s, len, "%4d %4d %4d %4d %4d %4d %4d %4d", i8[0], i8[1], i8[2], i8[3], i8[4], i8[5], i8[6], i8[7]);
	return s;
}
char* MmxVal::ToString_i16(char* s, size_t len) {
	sprintf_s(s, len, "%8d %8d %8d %8d", i16[0], i16[1], i16[2], i16[3]);
	return s;
}
char* MmxVal::ToString_i32(char* s, size_t len) {
	sprintf_s(s, len, "%12d %12d", i32[0], i32[1]);
	return s;
}
char* MmxVal::ToString_i64(char* s, size_t len) {
	sprintf_s(s, len, "%16lld", i64);
	return s;
}

char* MmxVal::ToString_ui8(char* s, size_t len) {
	sprintf_s(s, len, "%4u %4u %4u %4u %4u %4u %4u %4u", ui8[0], ui8[1], ui8[2], ui8[3], ui8[4], ui8[5], ui8[6], ui8[7]);
	return s;
}
char* MmxVal::ToString_ui16(char* s, size_t len) {
	sprintf_s(s, len, "%8u %8u %8u %8u", ui16[0], ui16[1], ui16[2], ui16[3]);
	return s;
}
char* MmxVal::ToString_ui32(char* s, size_t len) {
	sprintf_s(s, len, "%12u %12u", ui32[0], ui32[1]);
	return s;
}
char* MmxVal::ToString_ui64(char* s, size_t len) {
	sprintf_s(s, len, "%16llu", ui64);
	return s;
}

char* MmxVal::ToString_x8(char* s, size_t len) {
	sprintf_s(s, len, "%02X %02X %02X %02X %02X %02X %02X %02X", ui8[0], ui8[1], ui8[2], ui8[3], ui8[4], ui8[5], ui8[6], ui8[7]);
	return s;
}
char* MmxVal::ToString_x16(char* s, size_t len) {
	sprintf_s(s, len, "%04X %04X %04X %04X", ui16[0], ui16[1], ui16[2], ui16[3]);
	return s;
}
char* MmxVal::ToString_x32(char* s, size_t len) {
	sprintf_s(s, len, "%08X %08X", ui32[0], ui32[1]);
	return s;
}
char* MmxVal::ToString_x64(char* s, size_t len) {
	sprintf_s(s, len, "%016llX", ui64);
	return s;
}