#include <string>
#include "MoveInstruction.hpp"

MoveInstruction::MoveInstruction(const std::string &dest, const std::string &src)
    : dest{""}, src{""}
{
}

void MoveInstruction::execute(ProgramState *state) const
{
    // dest = src
}
