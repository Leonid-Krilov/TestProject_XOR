#include "WorkFile.h"

#include <QDebug>

void WorkFile::clear()
{
    m_vectorPathFiles.clear();
    m_vectorNameFiles.clear();
    m_variable.clear();
}

void WorkFile::searchInputFiles(std::string pathInputFile, std::string maskFile)
{
  try {
    for (const auto& entry : std::filesystem::directory_iterator(pathInputFile))
    {
      if (entry.is_regular_file())
      {
        std::filesystem::path filePath = entry.path();
          if (filePath.extension().string() == maskFile)
        {
            m_vectorPathFiles.push_back(filePath.string());
            m_vectorNameFiles.push_back(entry.path().filename().string());
        }
      }
    }
  }
  catch (const std::filesystem::filesystem_error& e)
  {
    qDebug() << "Error directory:" << e.what();
  }
}

std::vector<uint64_t> WorkFile::readFile(bool checkBoxDeletedFiles)
{
  std::string variableString;
  std::ifstream read;

  for (std::string pathFiles : m_vectorPathFiles)
  {
    read.open(pathFiles);

    if (!read.is_open())
        qDebug() << "\nError open input file";
    else
    {
      while (std::getline(read, variableString))
        m_variable.push_back(std::stoi(variableString));
    }

    read.close();

    if (checkBoxDeletedFiles)
      std::filesystem::remove(pathFiles);
  }

  return m_variable;
}

void WorkFile::saveFile(std::vector<uint64_t>(resultXOR), std::string pathOutFile, bool checkBoxModificateFiles)
{
  static int counter = 1;

  for (size_t i = 0; i < m_vectorNameFiles.size(); i++)
  {
    std::string pathSaveFile = pathOutFile + "result_" + m_vectorNameFiles[i];
    std::ofstream writeFile;

    if (checkBoxModificateFiles)
    {
      writeFile.open(pathSaveFile, std::ios::trunc);
    }
    else
    {
      std::string finalPath = pathSaveFile;

      while (std::filesystem::exists(finalPath))
      {
        finalPath = pathOutFile + std::to_string(counter++) + "_result_" + m_vectorNameFiles[i];
      }

      writeFile.open(finalPath, std::ios::binary);
    }

    if (writeFile.is_open())
    {
      writeFile << resultXOR[i];
      writeFile.close();
    }
  }
}
