#include <string>
#include "SubtractionInstruction.hpp"

SubtractionInstruction::SubtractionInstruction(const std::string &dest, const std::string &src)
    : subDest{dest}, subSrc{src}
{
}

void SubtractionInstruction::execute(ProgramState *state) const
{
    int destIdx = subDest[1] - 'a';
    int newVal = 0;
    if (subSrc[0] == 'e')
    {
        int srcIdx = subSrc[1] - 'a';
        newVal = state->getRegister(destIdx) - state->getRegister(srcIdx);
        state->setRegister(destIdx, newVal);
    }
    else
    {
        newVal = state->getRegister(destIdx) - std::stoi(subSrc);
        state->setRegister(destIdx, newVal);
    }
}