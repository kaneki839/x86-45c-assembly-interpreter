#ifndef __MOVE_INSTRUCTION_HPP
#define __MOVE_INSTRUCTION_HPP

#include <string>
#include "ProgramState.hpp"
#include "Statement.hpp"

class MoveInstruction : public Statement
{
public:
	MoveInstruction(const std::string &dest, const std::string &src);
	void execute(ProgramState *state) const override;

private:
	const std::string movDest;
	const std::string movSrc;
};

#endif
