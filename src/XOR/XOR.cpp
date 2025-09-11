#include "XOR.h"

XOR::XOR(uint64_t inputBinaryValue, uint64_t readBinaryValue)
{
    this->m_inputBinaryValue = inputBinaryValue;
    this->m_readBinaryValue = readBinaryValue;
}

std::bitset<64> XOR::functionXOR()
{
    uint64_t resultXOR = m_readBinaryValue ^ m_inputBinaryValue;

    return std::bitset<64>(resultXOR);
}
