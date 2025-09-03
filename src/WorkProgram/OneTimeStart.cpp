#include "OneTimeStart.h"

void OneTimeStart::workProgram(std::string maskFile, std::string pathInputFile, std::string pathOutFile, std::string extens)
{
  uint64_t resultXOR;
  WorkFile workFile(maskFile, pathInputFile, pathOutFile);
  //workFile.readFile(); закинуть сразу в функцию XOE
  //функция выполнения XOR
  workFile.saveFile(resultXOR);

}