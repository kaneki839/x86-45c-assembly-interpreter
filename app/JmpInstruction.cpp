#include <string>
#include "JmpInstruction.hpp"

JmpInstruction::JmpInstruction(const std::string &dst)
    : jumpTo{dst}
{
}

void JmpInstruction::execute(ProgramState *state) const
{
    int jumpVal = std::stoi(jumpTo);
    state->setCounter(jumpVal);
}
