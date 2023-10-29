#include <vector>
#include <stdlib.h>
#include "ProgramState.hpp"

ProgramState::ProgramState()
	: registers{16, 0}, running{true}, programCounter{1}
{
}

ProgramState::~ProgramState()
{
}

size_t ProgramState::getCounter() const
{
	return programCounter;
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
	return registers[registerNum];
}
