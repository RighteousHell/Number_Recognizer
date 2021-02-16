#include "StatsMatrix.h"
#include "NeuronNetwork.h"
#include <iostream>
#include <stdio.h>

StatsMatrix::StatsMatrix(uint16_t lines, uint16_t rows): lines_m(lines), rows_m(rows)
{
	matrix_m = new float* [lines_m];

	//std::cout << "Given " << lines << "lines. Address = " << &matrix_m << std::endl;
	for (uint16_t i = 0; i < lines_m; i++)
	{
		matrix_m[i] = new float[rows_m];
		//std::cout << "Given " << i << "rows. address = " << matrix_m[i]  << std::endl;
		memset(matrix_m[i], 0., rows_m*sizeof(float));
	}

}
StatsMatrix::~StatsMatrix()
{
	for (uint16_t i = 0; i < lines_m; i++)
	{
		delete[] matrix_m[i];
	}
	delete[] matrix_m;
}

void StatsMatrix::printMatrix()
{
	for (uint16_t i = 0; i < lines_m; i++)
	{
		for (uint16_t j = 0; j < rows_m; j++)
		{
			std::cout << matrix_m[i][j] << " ";
		}
		std::cout << std::endl;

	}
}