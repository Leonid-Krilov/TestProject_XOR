#pragma once

#include <iostream>
#include <cstdint>
#include <bitset>
#include <vector>
#include <optional>

class XOR
{
public:
  XOR(std::vector<std::optional<uint64_t>> inputBinaryValue, uint64_t readBinaryValue);
  ~XOR() = default;

  std::vector<std::optional<uint64_t>> functionXOR();

private:
  std::vector<std::optional<uint64_t>> m_inputBinaryValue;
  uint64_t m_readBinaryValue;
};
