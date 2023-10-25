#ifndef __END_INSTRUCTION_HPP
#define __END_INSTRUCTION_HPP

#include <string>
#include "ProgramState.hpp"
#include "Statement.hpp"

class EndInstruction : public Statement
{
public:
	EndInstruction();
	void execute(ProgramState * state) const override;

};


#endif
