// RowColSumCalculator.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <stdlib.h>

extern "C" int CalcArrayRowColSum(const int* x, int nrows, int ncols, int* row_sums, int* col_sums);
void PrintArrayResults(const int* x, int nrows, int ncols, int* row_sums, int* col_sums);

int main()
{
	const int nrows = 7, ncols = 5;
	int x[nrows][ncols];

	for (size_t i = 0; i < nrows; i++)
	{
		for (size_t j = 0; j < ncols; j++)
		{
			x[i][j] = i + j;
		}
	}

	int row_sums[nrows], col_sums[ncols];
	CalcArrayRowColSum((const int*)x, nrows, ncols, row_sums, col_sums);
	PrintArrayResults((const int*)x, nrows, ncols, row_sums, col_sums);

	return 0;
}

void PrintArrayResults(const int* x, int nrows, int ncols, int* row_sums, int* col_sums) {
	for (size_t i = 0; i < nrows; i++)
	{
		for (size_t j = 0; j < ncols; j++)
		{
			printf("%5d", x[i * ncols + j]);
		}
		printf("%5d\n", row_sums[i]);
	}
	printf("\n");
	for (size_t i = 0; i < ncols; i++)
	{
		printf("%5d", col_sums[i]);
	}
	printf("\n");
}