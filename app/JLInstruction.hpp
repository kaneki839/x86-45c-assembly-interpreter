#ifndef __JL_INSTRUCTION_HPP
#define __JL_INSTRUCTION_HPP

#include <string>
#include "ProgramState.hpp"
#include "Statement.hpp"

class JLInstruction : public Statement
{
public:
	JLInstruction(const std::string & dst);
	void execute(ProgramState * state) const override;


};


#endif


