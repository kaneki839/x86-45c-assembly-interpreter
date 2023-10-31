#include <string>
#include "JLInstruction.hpp"


JLInstruction::JLInstruction(const std::string & dst)
    : jumpTo{dst}
{}

void JLInstruction::execute(ProgramState * state) const
{
    if (state->getCmp() == '<')
    {
        int jumpVal = std::stoi(jumpTo);
        state->setCounter(jumpVal);
    }
}
