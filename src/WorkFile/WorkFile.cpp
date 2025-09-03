#include <WorkFile.h>

WorkFile::WorkFile(std::string maskFile, std::string pathInputFile, std::string pathOutFile)
{
  this->m_maskFile = maskFile;
  this->m_pathInputFile = pathInputFile;
  this->m_pathOutFile = pathOutFile;
}

WorkFile::~WorkFile()
{
  m_maskFile.clear();
  m_pathInputFile.clear();
  m_pathOutFile.clear();
}

std::vector<std::string> WorkFile::searchInputFiles(std::string extens)
{
  std::vector<std::string> vectorFiles;

  for (const auto& entry : std::filesystem::directory_iterator(m_pathInputFile))
  {
    if (entry.is_regular_file())
    {
      std::filesystem::path filePath = entry.path();
      if (filePath.extension() == extens)
        vectorFiles.push_back(filePath);      
    }
  }

  return vectorFiles;
}

uint64_t WorkFile::readFile()
{
  uint64_t variableInput;
  std::string variableString;
  std::ifstream read(m_pathInputFile);

  if (!read.is_open())
    std::cout << "\nError open input file";
  else
  {
    while (std::getline(read, variableString))
      variableInput = std::stoi(variableString);

    read.close();
    return variableInput;
  }

  read.close();
  return 0;
}

void WorkFile::saveFile(uint64_t saveVariable)
{
  std::ofstream write(m_pathOutFile);

  if(!write.is_open())
    std::cout << "\nError open out file";
  else
  {
    if(saveVariable == 0)
      std::cout  << "\nVariable NULL";
    else
      write << saveVariable;
  }

  write.close();
}
