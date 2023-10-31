#include <string>
#include "CmpInstruction.hpp"

CmpInstruction::CmpInstruction(const std::string &lhs, const std::string &rhs)
    : m_lhs{lhs}, m_rhs{rhs}
{
}

void CmpInstruction::execute(ProgramState *state) const
{
    int new_lhs = 0;
    int new_rhs = 0;
    if (m_lhs[0] == 'e')
    {
        int leftIdx = m_lhs[1] - 'a';
        new_lhs = state->getRegister(leftIdx);
    }
    if (m_rhs[0] == 'e')
    {
        int rightIdx = m_rhs[1] - 'a';
        new_rhs = state->getRegister(rightIdx);
    }
    if (m_lhs[0] != 'e' and m_rhs[0] != 'e')
    {
        new_lhs = std::stoi(m_lhs);
        new_rhs = std::stoi(m_rhs);
    }

    if (new_lhs < new_rhs)
    {
        state->setCmp('<');
    }
    else if (new_lhs == new_rhs)
    {
        state->setCmp('=');
    }
    else if (new_lhs > new_rhs)
    {
        state->setCmp('>');
    }
}
