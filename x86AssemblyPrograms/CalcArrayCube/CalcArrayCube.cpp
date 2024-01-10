// CalcArrayCube.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stdlib.h>

void CalcArrayCube(int* y, int* x, int nrows, int ncols) {
	for (size_t i = 0; i < nrows; i++)
	{
		for (size_t j = 0; j < ncols; j++)
		{
			int k = i * ncols + j;
			y[k] = x[k] * x[k] * x[k];
		}
	}
}

int main()
{
	const int nrows = 4;
	const int ncols = 3;
	int x[nrows][ncols] = { {1,2,3},{4,5,6}, {7,8,9},{10,11,12} };
	int y[nrows][ncols];

	CalcArrayCube(&y[0][0], &x[0][0], nrows, ncols);

	for (size_t i = 0; i < nrows; i++)
	{
		for (size_t j = 0; j < ncols; j++)
		{
			printf("(%2d, %2d) : %6d, %6d\n", i, j, x[i][j], y[i][j]);
		}
	}
}
