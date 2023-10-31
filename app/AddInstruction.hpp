#ifndef __ADD_INSTRUCTION_HPP
#define __ADD_INSTRUCTION_HPP

#include <string>
#include "ProgramState.hpp"
#include "Statement.hpp"

class AddInstruction : public Statement
{
public:
	AddInstruction(const std::string & dest, const std::string & src);
	void execute(ProgramState * state) const override;

private:
	const std::string addDest;
	const std::string addSrc;
};

#endif
