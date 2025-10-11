#include "XOR.h"
#include <QDebug>


XOR::XOR(std::vector<unsigned long long> inputBinaryValue, unsigned long long readBinaryValue)
{
    this->m_inputBinaryValue = inputBinaryValue;
    this->m_readBinaryValue = readBinaryValue;
}

std::vector<std::string> XOR::functionXOR()
{
  std::vector<std::string> resultVectorXOR;

  for (unsigned long long inputValue : m_inputBinaryValue)
  {
      if (inputValue == -1)
      resultVectorXOR.push_back("");
    else
    {
      unsigned long long resultXOR = inputValue ^ m_readBinaryValue;
      std::stringstream ss;
      ss << "0x" << std::hex << std::uppercase << resultXOR;

      resultVectorXOR.push_back(ss.str());
    }
  }

  return resultVectorXOR;
}
