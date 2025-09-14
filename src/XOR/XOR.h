#pragma once

#include <iostream>
#include <cstdint>
#include <bitset>
#include <vector>

class XOR
{
public:
  XOR(std::vector<uint64_t> inputBinaryValue, uint64_t readBinaryValue);
  std::vector<uint64_t> functionXOR();

private:
  std::vector<uint64_t> m_inputBinaryValue;
  uint64_t m_readBinaryValue;
};
