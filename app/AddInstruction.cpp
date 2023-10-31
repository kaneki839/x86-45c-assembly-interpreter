#include <string>
#include "AddInstruction.hpp"

AddInstruction::AddInstruction(const std::string &dest, const std::string &src)
    : addDest{dest}, addSrc{src}
{
}

void AddInstruction::execute(ProgramState *state) const
{
    int destIdx = addDest[1] - 'a';
    int newVal = 0;
    if (addSrc[0] == 'e')
    {
        int srcIdx = addSrc[1] - 'a';
        newVal = state->getRegister(destIdx) + state->getRegister(srcIdx);
        state->setRegister(destIdx, newVal);
    }
    else
    {
        newVal = state->getRegister(destIdx) + std::stoi(addSrc);
        state->setRegister(destIdx, newVal);
    }

}