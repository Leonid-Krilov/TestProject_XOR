#include "XOR.h"
#include <QDebug>


XOR::XOR(std::vector<uint64_t> inputBinaryValue, uint64_t readBinaryValue)
{
    this->m_inputBinaryValue = inputBinaryValue;
    this->m_readBinaryValue = readBinaryValue;
}

std::vector<uint64_t> XOR::functionXOR()
{
  std::vector<uint64_t> resultXOR;

  for (uint64_t inputValue : m_inputBinaryValue)
  {
    uint64_t uintResultXOR = inputValue ^ m_readBinaryValue;
    resultXOR.push_back(uintResultXOR);
  }

  return resultXOR;
}
