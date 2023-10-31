#ifndef __PROGRAM_STATE_45C_HPP
#define __PROGRAM_STATE_45C_HPP

#include <vector>

class ProgramState
{

public:
	ProgramState();
	~ProgramState();

	size_t getCounter() const;
	void setCounter();

	// terminate means quit when something bad happened (e.g., trying to access a non-existent register)
	void terminate();

	// returns true if we're done running the program (and haven't crashed).
	bool done() const;

	// Registers are numbered 0 .. NUM_REGISTERS - 1
	// eax is 0, ebx is 1, etc.

	int getRegister(size_t registerNum) const;
	void setRegister(size_t registerNum, int value);

	// If you want to add additional public member functions, you may do so here.
	// The above functions must remain with their given interface:
	//	the grading script expects it.

private:
	std::vector<int> registers;
	int programCounter;

	// If you want to add private member variables, you may do so here.
};

#endif
