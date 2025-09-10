#include "WorkFile.h"

WorkFile::WorkFile(std::string maskFile, std::string pathInputFile, std::string pathOutFile, std::string extens)
{
  this->m_maskFile = maskFile;
  this->m_pathInputFile = pathInputFile;
  this->m_pathOutFile = pathOutFile;
  this->m_extens = extens;
}

WorkFile::~WorkFile()
{
  m_maskFile.clear();
  m_pathInputFile.clear();
  m_pathOutFile.clear();
  m_extens.clear();
}

void WorkFile::searchInputFiles()
{
  for (const auto& entry : std::filesystem::directory_iterator(m_pathInputFile))
  {
    if (entry.is_regular_file())
    {
      std::filesystem::path filePath = entry.path();
      if (filePath.extension() == m_extens)
        m_vectorFiles.push_back(filePath);
    }
  }
}

void WorkFile::readFile()
{
  std::vector<uint64_t> variableInput;
  std::string variableString;
  std::ifstream read;

  for (std::string pathFiles : m_vectorFiles)
  {
    read.open(pathFiles);

    if (!read.is_open())
      std::cout << "\nError open input file";
    else
    {
      while (std::getline(read, variableString))
        m_variable.push_back(std::stoi(variableString));
    }

    read.close();
  }
}

void WorkFile::saveFile()
{
  int counter;
  std::string pathsaveFile;
  std::string outFile;
  std::ofstream write;

  for (uint64_t saveData : m_variable)
  {
    counter++;
    outFile = m_pathInputFile + std::to_string(counter) + "result." + m_maskFile;

    write.open(outFile);
    if(!write.is_open())
      std::cout << "\nError open out file";
    else
    {
      if(saveData == 0)
        std::cout  << "\nVariable NULL";
      else
        write << saveData;
    }

    write.close();
  }
}
