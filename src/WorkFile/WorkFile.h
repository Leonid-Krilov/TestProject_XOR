#pragma once

#include <iostream>
#include <fstream>
#include <cstdint>
#include <filesystem>
#include <vector>

class WorkFile
{
public:
  WorkFile(std::string maskFile, std::string pathInputFile, std::string pathOutFile, std::string m_extens);
  ~WorkFile();
  
  std::vector<std::string> searchInputFiles(std::string extens);
  uint64_t readFile();
  void saveFile(uint64_t saveVariable);
  bool searchSimbol();
private:
  std::string m_extens;
  std::string m_maskFile;
  std::string m_pathInputFile, m_pathOutFile;
};