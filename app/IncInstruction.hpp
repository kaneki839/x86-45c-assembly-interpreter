#ifndef __INC_INSTRUCTION_HPP
#define __INC_INSTRUCTION_HPP

#include <string>
#include "ProgramState.hpp"
#include "Statement.hpp"

class IncInstruction : public Statement
{
public:
	IncInstruction(const std::string & reg);
	void execute(ProgramState * state) const override;

};


#endif
