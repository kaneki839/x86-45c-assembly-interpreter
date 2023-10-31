#include <string>
#include "ImulInstruction.hpp"


ImulInstruction::ImulInstruction(const std::string & dest, const std::string & src)
    : multDest{dest}, multSrc{src}
{}

void ImulInstruction::execute(ProgramState * state) const
{
    int destIdx = multDest[1] - 'a';
    int newVal = 0;
    if (multSrc[0] == 'e')
    {
        int srcIdx = multSrc[1] - 'a';
        newVal = state->getRegister(destIdx) * state->getRegister(srcIdx);
        state->setRegister(destIdx, newVal);
    }
    else
    {
        newVal = state->getRegister(destIdx) * std::stoi(multSrc);
        state->setRegister(destIdx, newVal);
    }
}
