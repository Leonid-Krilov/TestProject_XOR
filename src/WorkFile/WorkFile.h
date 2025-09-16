#pragma once

#include <iostream>
#include <fstream>
#include <cstdint>
#include <filesystem>
#include <vector>
#include <optional>

class WorkFile
{
public:
  WorkFile() = default;
  ~WorkFile() = default;
  
  void searchInputFiles(std::string pathInputFile, std::string maskFile);
  std::vector<std::optional<uint64_t>> readFile(bool checkBoxDeletedFiles);
  void saveFile(std::vector<std::optional<uint64_t>>(resultXOR), std::string pathOutFile, bool checkBoxModificateFiles);
  void clear();

private:
  bool checkMoreСharacters(const std::string& variableString);

private:
  std::vector<std::string> m_vectorPathFiles, m_vectorNameFiles;
  std::vector<std::optional<uint64_t>> m_variable;
};
