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
  
  void searchInputFiles();
  void readFile();
  void saveFile();

private:
  std::string m_extens;
  std::string m_maskFile;
  std::string m_pathInputFile, m_pathOutFile;
  std::vector<std::string> m_vectorFiles;
  std::vector<uint64_t> m_variable;
};
