#include "XOR.h"
#include <QDebug>


XOR::XOR(std::vector<std::optional<uint64_t>> inputBinaryValue, uint64_t readBinaryValue)
{
    this->m_inputBinaryValue = inputBinaryValue;
    this->m_readBinaryValue = readBinaryValue;
}

std::vector<std::optional<uint64_t>> XOR::functionXOR()
{
  std::vector<std::optional<uint64_t>> resultXOR;

  for (std::optional<uint64_t> inputValue : m_inputBinaryValue)
  {
    if (!inputValue.has_value())
      resultXOR.push_back(std::nullopt);
    else
    {
      std::optional<uint64_t> uintResultXOR = inputValue.value() ^ m_readBinaryValue;
      resultXOR.push_back(uintResultXOR.value());
    }
  }

  return resultXOR;
}
