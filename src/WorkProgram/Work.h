#pragma once

#include <iostream>
#include <string>

class Work
{
public:
  ~Work() = default;
  virtual void workProgram(std::string maskFile, std::string pathInputFile, std::string pathOutFile, std::string extens) = 0; 
};