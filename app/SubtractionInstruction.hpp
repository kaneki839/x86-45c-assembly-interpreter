#ifndef __SUB_INSTRUCTION_HPP
#define __SUB_INSTRUCTION_HPP

#include <string>
#include "ProgramState.hpp"
#include "Statement.hpp"

class SubtractionInstruction : public Statement
{
public:
	SubtractionInstruction(const std::string & dest, const std::string & src);
	void execute(ProgramState * state) const override;

private:
	const std::string subDest;
	const std::string subSrc;
};


#endif
