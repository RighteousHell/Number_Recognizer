#pragma once
#include "StatsMatrix.h"
class NeuronNetwork
{
private:

	float learning_rate_m = static_cast<float>(0.3);
	StatsMatrix wih;
	StatsMatrix who;

public:
	NeuronNetwork() = default;
	NeuronNetwork(uint16_t lines, uint16_t rows, uint16_t out, float learming_rate);
	~NeuronNetwork() = default;

	void train();


	void query();
};