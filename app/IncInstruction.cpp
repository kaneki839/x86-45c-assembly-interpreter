#include <string>
#include "IncInstruction.hpp"

IncInstruction::IncInstruction(const std::string &reg)
    : incReg{reg}
{
}

void IncInstruction::execute(ProgramState *state) const
{
    int destIdx = incReg[1] - 'a';
    int newVal = state->getRegister(destIdx) + 1;
    state->setRegister(destIdx, newVal);
}