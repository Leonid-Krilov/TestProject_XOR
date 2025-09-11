#pragma once

#include <iostream>
#include <cstdint>
#include <bitset>

class XOR
{
public:
  XOR(uint64_t inputBinaryValue, uint64_t readBinaryValue);
  std::bitset<64> functionXOR();

private:
  uint64_t m_inputBinaryValue, m_readBinaryValue;
};
