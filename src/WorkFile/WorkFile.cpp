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

bool WorkFile::checkMoreСharacters(const std::string& variableString)
{
    return !variableString.empty() && std::all_of(variableString.begin(), variableString.end(), ::isdigit);
}

std::vector<std::optional<uint64_t>> WorkFile::readFile(bool checkBoxDeletedFiles)
{
  std::string variableString;
  std::ifstream read;

  for (auto pathFiles = m_vectorPathFiles.begin(); pathFiles != m_vectorPathFiles.end();)
  {
    read.open(*pathFiles);
    if (!read.is_open())
      qDebug() << "\nError open input file";

    while (std::getline(read, variableString))
    {
      if (!checkMoreСharacters(variableString))
      {
        m_variable.push_back(std::nullopt);
        pathFiles = m_vectorPathFiles.erase(pathFiles);
      }
      else
      {
        m_variable.push_back(std::stoll(variableString));
        pathFiles++;
      }
    }

    if (checkBoxDeletedFiles)
        std::filesystem::remove(*pathFiles);

    read.close();
  }

  return m_variable;
}

void WorkFile::saveFile(std::vector<std::optional<uint64_t>>(resultXOR), std::string pathOutFile, bool checkBoxModificateFiles)
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
      if(!resultXOR[i].has_value())
        writeFile << "Error! Incorrected input or read binary meaning!";
      else
      {
        writeFile << resultXOR[i].value();
        writeFile.close();
      }
    }
  }
}
