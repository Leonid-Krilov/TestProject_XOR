#pragma once

#include <iostream>
#include <fstream>
#include <cstdint>
#include <filesystem>
#include <vector>

class WorkFile
{
public:
  WorkFile();
  ~WorkFile();
  
  void searchInputFiles(std::string pathInputFile, std::string maskFile);
  std::vector<uint64_t> readFile(bool checkBoxDeletedFiles);
  void saveFile(std::vector<uint64_t>(resultXOR), std::string pathOutFile, bool checkBoxModificateFiles);
  void clear();

private:
  std::vector<std::string> m_vectorPathFiles, m_vectorNameFiles;
  std::vector<uint64_t> m_variable;
};
