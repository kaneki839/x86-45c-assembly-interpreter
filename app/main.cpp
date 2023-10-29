#include <iostream>
#include <fstream>
#include "ProgramState.hpp"
#include "runSim.hpp"

int main()
{
    std::ifstream in{"prog1.txt"};
    ProgramState ps;
    std::cout << ps.getRegister(3) << std::endl;
    runSimulator(in, &ps);

    return 0;
}
