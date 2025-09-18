#pragma once

#include <iostream>
#include <cstdint>
#include <bitset>
#include <vector>
#include <optional>
#include <sstream>

class XOR
{
public:
  XOR(std::vector<unsigned long long> inputBinaryValue, unsigned long long readBinaryValue);
  ~XOR() = default;

  std::vector<std::string> functionXOR();

private:
  std::vector<unsigned long long> m_inputBinaryValue;
  unsigned long long m_readBinaryValue;
};
