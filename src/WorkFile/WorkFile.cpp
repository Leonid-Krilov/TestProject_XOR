#include "WorkFile.h"

#include <QDebug>

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
    m_vectorPathFiles.clear(); // Очищаем вектор перед новым поиском
    m_vectorNameFiles.clear();

    try {
        for (const auto& entry : std::filesystem::directory_iterator(m_pathInputFile))
        {
            if (entry.is_regular_file())
            {
                std::filesystem::path filePath = entry.path();
                if (static_cast<std::string>(filePath.extension()) == m_maskFile)
                {
                    m_vectorPathFiles.push_back(filePath.string());
                    m_vectorNameFiles.push_back(entry.path().filename().string());
                }
            }
        }
    }
    catch (const std::filesystem::filesystem_error& e) {
        qDebug() << "Error directory:" << e.what();
    }
}

std::vector<uint64_t> WorkFile::readFile()
{
  std::string variableString;
  std::ifstream read;

  for (std::string pathFiles : m_vectorPathFiles)
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

  return m_variable;
}

void WorkFile::saveFile(std::bitset<64>(resultXOR))
{
  int counter;
  std::string pathsaveFile;
  std::string outFile;
  std::ofstream write;
    //сделать сохранение фа
  for (uint64_t saveData : m_variable)
  {
    counter++;
    outFile = m_pathOutFile + std::to_string(counter) + "result." + m_maskFile;

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
