#pragma once
#include <iostream>
#include "NeuronNetwork.h"
NeuronNetwork::NeuronNetwork(uint16_t inpuht, uint16_t hidden, uint16_t out, float learming_rate): wih(hidden, inpuht), who(out,hidden)
{
	//wih.printMatrix();
	//who.printMatrix();
}


void NeuronNetwork::train()
{

}
