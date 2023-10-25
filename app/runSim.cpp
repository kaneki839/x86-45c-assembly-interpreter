#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include "runSim.hpp"
#include "ProgramState.hpp"

#include "Statement.hpp"
#include "MoveInstruction.hpp"
#include "AddInstruction.hpp"
#include "SubtractionInstruction.hpp"
#include "CmpInstruction.hpp"
#include "JmpInstruction.hpp"
#include "JLInstruction.hpp"
#include "JEInstruction.hpp"
#include "EndInstruction.hpp"

// Simulates the given program.  The starting program state
// will be provided to you via the second parameter. 
// It is expected that you use this one, not a newly declared
// one, in running your program.
void runSimulator(std::istream &in, ProgramState * ps)
{
    // You will want to modify some of this.
    // You do not need to be very well versed in how std::stringstream works
    // You should be able to figure out how it works based on 
    // your knowledge of aspects like std::cin and reading the existing
    // code.  That is a skill worth developing!

    std::string line, word;
    std::string token1, token2;
    std::stringstream ss;



    while(  getline(in, line) )
    {
        ss.clear();
        ss << line;
        while( ss >> word )
        {
            if( "MOV" == word )
            {
                ss >> token1 >> token2;
            }
        }
    }


}


