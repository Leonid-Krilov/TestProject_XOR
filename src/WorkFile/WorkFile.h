#pragma once

#include <iostream>
#include <fstream>
#include <cstdint>
#include <filesystem>
#include <vector>
#include <optional>
#include <QDebug>
#include <bitset>

class WorkFile
{
public:
  WorkFile() = default;
  ~WorkFile() = default;
  
  void searchInputFiles(std::string& pathInputFile, std::string& maskFile);
  std::vector<unsigned long long> readFile(bool& checkBoxDeletedFiles);
  void saveFile(std::vector<std::string>&(resultXOR), std::string& pathOutFile, bool& checkBoxModificateFiles);
  void clear();
  unsigned long long checkMoreСharacters(const std::string& variableString);

private:
  std::vector<std::string> m_vectorPathFiles, m_vectorNameFiles;
  std::vector<unsigned long long> m_variable;
};
