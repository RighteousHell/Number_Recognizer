#pragma once
#include <iostream>
/*****
Custom container developed accordance with principles of RAII
*****/
class StatsMatrix 
{
private:
	uint16_t lines_m;
	uint16_t rows_m;
	float** matrix_m;


public:
	StatsMatrix(uint16_t lines, uint16_t rows);
	~StatsMatrix();
	void printMatrix();

};

