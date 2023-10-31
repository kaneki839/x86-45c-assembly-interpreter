#include <iostream>
#include <fstream>
#include "ProgramState.hpp"
#include "runSim.hpp"

int main()
{
    std::ifstream in{"test1.txt"};
    ProgramState ps;
    runSimulator(in, &ps);
    std::cout << ps.getRegister(0) << std::endl;
    std::cout << ps.getRegister(1) << std::endl;

    return 0;
}
