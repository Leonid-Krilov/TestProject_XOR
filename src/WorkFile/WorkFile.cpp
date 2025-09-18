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

unsigned long long WorkFile::checkMoreСharacters(const std::string& variableString)
{
  std::stringstream ss;

  if (variableString.size() >=2 && (variableString.substr(0, 2) == "0x" ||  variableString.substr(0, 2) == "0X"))
    return std::stoull(variableString.substr(2), nullptr, 16);

  if (variableString.size() >=2 && (variableString.substr(0, 2) == "0b" ||  variableString.substr(0, 2) == "0B"))
    return std::stoull(variableString.substr(2), nullptr, 2);

  if(variableString.size() >=1 && variableString[0] == '0')
  {
    std::string cleanBinary = variableString.substr(1);
    for (char c : cleanBinary)
    {
      if(c < '0' || c > '7')
      return -1;
    }

    unsigned long long number = std::stoull(cleanBinary, nullptr, 8);
      return std::stoull(variableString.substr(1), nullptr, 8);
  }

  if (!variableString.empty() && std::all_of(variableString.begin(), variableString.end(), ::isdigit))
    return std::stoull(variableString, nullptr, 10);

  return -1;
}

std::vector<unsigned long long> WorkFile::readFile(bool checkBoxDeletedFiles)
{
  unsigned long long variableInt;
  std::string variableString;
  std::ifstream read;

  for (auto pathFiles = m_vectorPathFiles.begin(); pathFiles != m_vectorPathFiles.end();)
  {
    read.open(*pathFiles);
    if (!read.is_open())
      qDebug() << "\nError open input file";

    while (std::getline(read, variableString))
    {
      variableInt = checkMoreСharacters(variableString);
      if (variableInt == -1)
      {
        m_variable.push_back(variableInt);
        pathFiles = m_vectorPathFiles.erase(pathFiles);
      }
      else
      {
        m_variable.push_back(variableInt);
        pathFiles++;
      }
    }

    if (checkBoxDeletedFiles)
        std::filesystem::remove(*pathFiles);

    read.close();
  }

  return m_variable;
}

void WorkFile::saveFile(std::vector<std::string>(resultXOR), std::string pathOutFile, bool checkBoxModificateFiles)
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
      if(resultXOR[i].empty())
        writeFile << "Error! Incorrected input or read binary meaning!";
      else
      {
        writeFile << resultXOR[i];
        writeFile.close();
      }
    }
  }
}
