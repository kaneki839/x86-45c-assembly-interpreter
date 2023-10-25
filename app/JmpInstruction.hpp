#ifndef __JMP_INSTRUCTION_HPP
#define __JMP_INSTRUCTION_HPP

#include <string>
#include "ProgramState.hpp"
#include "Statement.hpp"

class JmpInstruction : public Statement
{
public:
	JmpInstruction(const std::string & dst);
	void execute(ProgramState * state) const override;

};


#endif
