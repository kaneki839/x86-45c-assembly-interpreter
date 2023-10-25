#include <vector>
#include <stdlib.h>
#include "ProgramState.hpp"


ProgramState::ProgramState()
{}


ProgramState::~ProgramState()
{}

size_t ProgramState::getCounter() const
{
	return 0;
}


void ProgramState::terminate()
{
	exit(1); 
}


bool ProgramState::done() const
{
	return false;
}


int ProgramState::getRegister(size_t registerNum) const
{
	return 0;
}
