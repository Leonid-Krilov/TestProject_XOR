#pragma once

#include <iostream>
#include <fstream>
#include <cstdint>
#include <filesystem>
#include <vector>
#include <bitset>

class WorkFile
{
public:
  WorkFile(std::string maskFile, std::string pathInputFile, std::string pathOutFile, std::string m_extens);
  ~WorkFile();
  
  void searchInputFiles();
  std::vector<uint64_t> readFile();
  void saveFile(std::bitset<64>(resultXOR));

private:
  std::string m_extens;
  std::string m_maskFile;
  std::string m_pathInputFile, m_pathOutFile;
  std::vector<std::string> m_vectorPathFiles, m_vectorNameFiles;
  std::vector<uint64_t> m_variable;
};
