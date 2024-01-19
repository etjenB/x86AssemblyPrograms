#include "pch.h"
#include "Xmm.h"
#include <stdio.h>

char* XmmVal::ToString_i8(char* s, size_t len) {
	sprintf_s(s, len, "%4d %4d %4d %4d %4d %4d %4d %4d | %4d %4d %4d %4d %4d %4d %4d %4d", i8[0], i8[1], i8[2], i8[3], i8[4], i8[5], i8[6], i8[7], i8[8], i8[9], i8[10], i8[11], i8[12], i8[13], i8[14], i8[15]);
	return s;
}
char* XmmVal::ToString_i16(char* s, size_t len) {
	sprintf_s(s, len, "%8d %8d %8d %8d | %8d %8d %8d %8d", i16[0], i16[1], i16[2], i16[3], i16[4], i16[5], i16[6], i16[7]);
	return s;
}
char* XmmVal::ToString_i32(char* s, size_t len) {
	sprintf_s(s, len, "%12d %12d | %12d %12d", i32[0], i32[1], i32[2], i32[3]);
	return s;
}
char* XmmVal::ToString_i64(char* s, size_t len) {
	sprintf_s(s, len, "%25lld | %25lld", i64[0], i64[1]);
	return s;
}

char* XmmVal::ToString_ui8(char* s, size_t len) {
	sprintf_s(s, len, "%4u %4u %4u %4u %4u %4u %4u %4u | %4u %4u %4u %4u %4u %4u %4u %4u", ui8[0], ui8[1], ui8[2], ui8[3], ui8[4], ui8[5], ui8[6], ui8[7], ui8[8], ui8[9], ui8[10], ui8[11], ui8[12], ui8[13], ui8[14], ui8[15]);
	return s;
}
char* XmmVal::ToString_ui16(char* s, size_t len) {
	sprintf_s(s, len, "%8u %8u %8u %8u | %8u %8u %8u %8u", ui16[0], ui16[1], ui16[2], ui16[3], ui16[4], ui16[5], ui16[6], ui16[7]);
	return s;
}
char* XmmVal::ToString_ui32(char* s, size_t len) {
	sprintf_s(s, len, "%12u %12u | %12u %12u", ui32[0], ui32[1], ui32[2], ui32[3]);
	return s;
}
char* XmmVal::ToString_ui64(char* s, size_t len) {
	sprintf_s(s, len, "%25llu | %25llu", ui64[0], ui64[1]);
	return s;
}

char* XmmVal::ToString_x8(char* s, size_t len) {
	sprintf_s(s, len, "%02X %02X %02X %02X %02X %02X %02X %02X | %02X %02X %02X %02X %02X %02X %02X %02X", ui8[0], ui8[1], ui8[2], ui8[3], ui8[4], ui8[5], ui8[6], ui8[7], ui8[8], ui8[9], ui8[10], ui8[11], ui8[12], ui8[13], ui8[14], ui8[15]);
	return s;
}
char* XmmVal::ToString_x16(char* s, size_t len) {
	sprintf_s(s, len, "%04X %04X %04X %04X | %04X %04X %04X %04X", ui16[0], ui16[1], ui16[2], ui16[3], ui16[4], ui16[5], ui16[6], ui16[7]);
	return s;
}
char* XmmVal::ToString_x32(char* s, size_t len) {
	sprintf_s(s, len, "%08X %08X | %08X %08X", ui32[0], ui32[1], ui32[2], ui32[3]);
	return s;
}
char* XmmVal::ToString_x64(char* s, size_t len) {
	sprintf_s(s, len, "%025llX | %025llX", ui64[0], ui64[1]);
	return s;
}

char* XmmVal::ToString_r32(char* s, size_t len) {
	sprintf_s(s, len, "%12.6f %12.6f | %12.6f %12.6f", r32[0], r32[1], r32[2], r32[3]);
	return s;
}
char* XmmVal::ToString_r64(char* s, size_t len) {
	sprintf_s(s, len, "%24.12lf | %24.12lf", r64[0], r64[1]);
	return s;
}