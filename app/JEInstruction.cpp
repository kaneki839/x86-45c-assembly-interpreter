#include <string>
#include "JEInstruction.hpp"


JEInstruction::JEInstruction(const std::string & dst)
    : jumpTo{dst}
{}

void JEInstruction::execute(ProgramState * state) const
{
    if (state->getCmp() == '=')
    {
        int jumpVal = std::stoi(jumpTo);
        state->setCounter(jumpVal);
    }
}

