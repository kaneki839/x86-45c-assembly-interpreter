#ifndef __RUN_X86_45C_SIMULATOR
#define __RUN_X86_45C_SIMULATOR

#include <fstream>
#include "ProgramState.hpp"

// Simulates the given program.  The starting program state
// will be provided to you via the second parameter.
void runSimulator(std::istream &in, ProgramState * ps);

#endif
