#include <string>
#include "MoveInstruction.hpp"

MoveInstruction::MoveInstruction(const std::string &dest, const std::string &src)
    : movDest{dest}, movSrc{src}
{
}

void MoveInstruction::execute(ProgramState *state) const
{
    int destIdx = movDest[1] - 'a';
    if (movSrc[0] == 'e')
    {
        int srcIdx = movSrc[1] - 'a';
        int newVal = state->getRegister(srcIdx);
        state->setRegister(destIdx, newVal);
    }
    else
    {
        state->setRegister(destIdx, std::stoi(movSrc));
    }
}