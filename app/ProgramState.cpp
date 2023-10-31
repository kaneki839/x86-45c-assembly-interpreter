#include <vector>
#include <stdlib.h>
#include "ProgramState.hpp"
#include <string>

ProgramState::ProgramState()
	: registers{std::vector<int>(16, 0)}, programCounter{0}, cmpResult{}
{
}

ProgramState::~ProgramState()
{
}

size_t ProgramState::getCounter() const
{
	return programCounter;
}

void ProgramState::setCounter()
{
	programCounter++;
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

void ProgramState::setRegister(size_t registerNum, int value)
{
	registers[registerNum] = value;
}

void ProgramState::setCmp(char cmpVal)
{
	cmpResult = cmpVal;
}

char ProgramState::getCmp() const
{
	return cmpResult;
}