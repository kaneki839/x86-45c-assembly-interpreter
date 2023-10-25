#ifndef __CMP_INSTRUCTION_HPP
#define __CMP_INSTRUCTION_HPP

#include <string>
#include "ProgramState.hpp"
#include "Statement.hpp"

class CmpInstruction : public Statement
{
public:
	CmpInstruction(const std::string & lhs, const std::string & rhs);
	void execute(ProgramState * state) const override;

private:
	std::string m_lhs;
	std::string m_rhs;

};


#endif
