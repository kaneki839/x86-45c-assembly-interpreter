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
#include "ImulInstruction.hpp"
#include "IncInstruction.hpp"
#include "CmpInstruction.hpp"
#include "JmpInstruction.hpp"
#include "JLInstruction.hpp"
#include "JEInstruction.hpp"
#include "EndInstruction.hpp"

// Simulates the given program.  The starting program state
// will be provided to you via the second parameter.
// It is expected that you use this one, not a newly declared
// one, in running your program.
void runSimulator(std::istream &in, ProgramState *ps)
{
    // You will want to modify some of this.
    // You do not need to be very well versed in how std::stringstream works
    // You should be able to figure out how it works based on
    // your knowledge of aspects like std::cin and reading the existing
    // code.  That is a skill worth developing!

    std::string line, word;
    std::string token1, token2;
    std::stringstream ss;

    std::vector<Statement *> statements;

    // reading program
    while (getline(in, line))
    {
        ss.clear();
        ss << line;
        while (ss >> word)
        {
            if ("MOV" == word)
            {
                ss >> token1 >> token2;
                Statement *moveCommand = new MoveInstruction(token1, token2);
                statements.push_back(moveCommand);
            }

            else if ("ADD" == word)
            {
                ss >> token1 >> token2;
                Statement *addCommand = new AddInstruction(token2, token1);
                statements.push_back(addCommand);
            }

            else if ("SUB" == word)
            {
                ss >> token1 >> token2;
                Statement *subCommand = new SubtractionInstruction(token2, token1);
                statements.push_back(subCommand);
            }

            else if ("IMUL" == word)
            {
                ss >> token1 >> token2;
                Statement *multCommand = new ImulInstruction(token2, token1);
                statements.push_back(multCommand);
            }

            else if ("INC" == word)
            {
                ss >> token1;
                Statement *incCommand = new IncInstruction(token1);
                statements.push_back(incCommand);
            }

            else if ("CMP" == word)
            {
                ss >> token1 >> token2;
                Statement *cmpCommand = new CmpInstruction(token1, token2);
                statements.push_back(cmpCommand);
            }

            else if ("JMP" == word)
            {
                ss >> token1 >> token2;
                Statement *jmpCommand = new JmpInstruction(token1);
                statements.push_back(jmpCommand);
            }

            else if ("JL" == word)
            {
                ss >> token1 >> token2;
                Statement *jmpLessCommand = new JLInstruction(token1);
                statements.push_back(jmpLessCommand);
            }

            else if ("JE" == word)
            {
                ss >> token1 >> token2;
                Statement *jmpEqCommand = new JEInstruction(token1);
                statements.push_back(jmpEqCommand);
            }
            
            else if ("END" == word)
            {
                Statement *endCommand = new EndInstruction();
                statements.push_back(endCommand);
            }
        }
    }

    // run the program
    bool running = true;

    while (running)
    {
        int pc = ps->getCounter() - 1;
        EndInstruction *endInsPtr = dynamic_cast<EndInstruction *>(statements[pc]);
        JmpInstruction *jmpInsPtr = dynamic_cast<JmpInstruction *>(statements[pc]);
        JLInstruction *jmpLessInsPtr = dynamic_cast<JLInstruction *>(statements[pc]);
        JEInstruction *jmpEqInsPtr = dynamic_cast<JEInstruction *>(statements[pc]);

        if (endInsPtr)
        {
            running = ps->done();
        }
        else if (jmpInsPtr)
        {
            statements[pc]->execute(ps);
        }

        else if (jmpLessInsPtr)
        {
            if (ps->getCmp() == '<')
            {
                statements[pc]->execute(ps);
            }
            else
            {
                ps->increCounter();
            }
        }

        else if (jmpEqInsPtr)
        {
            if (ps->getCmp() == '=')
            {
                statements[pc]->execute(ps);
            }
            else
            {
                ps->increCounter();
            }
        }

        else
        {
            statements[pc]->execute(ps);
            ps->increCounter();
        }
    }

    // free the memory
    for (size_t i = 0; i < statements.size(); i++)
    {
        delete statements[i];
    }
}
