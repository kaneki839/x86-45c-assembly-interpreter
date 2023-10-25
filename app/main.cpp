#include <iostream>
#include <fstream>
#include "ProgramState.hpp"
#include "runSim.hpp"


int main()
{
    std::ifstream in{"prog1.txt"};
    ProgramState ps;
    runSimulator(in, &ps);


    return 0;
}

