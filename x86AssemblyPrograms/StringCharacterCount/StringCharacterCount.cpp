// StringCharacterCount.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <stdlib.h>

extern "C" int CountChar(wchar_t* s, wchar_t c); //wchat_t is 16 bit character

int main()
{
	wchar_t c;
	wchar_t* s;
	s = (wchar_t*)L"Assembly is awesome!";
	c = L'e';

	wprintf(L"\nTest string : %s\n", s);
	wprintf(L"Search Character : %c\nCount : %d\n", c, CountChar(s, c));

	return 0;
}