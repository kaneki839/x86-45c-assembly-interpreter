#ifndef __STATEMENT_ABSTRACT_CLASS_HPP
#define __STATEMENT_ABSTRACT_CLASS_HPP

#include "ProgramState.hpp"


class Statement
{
public:
	virtual ~Statement(){}
	
	virtual void execute(ProgramState * state) const = 0;

};


#endif
