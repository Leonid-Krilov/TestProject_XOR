#pragma once

#include <iostream>

#include "Work.h"
#include "WorkFile.h"

class OneTimeStart : public Work
{
protected:
  void workProgram(std::string maskFile, std::string pathInputFile, std::string pathOutFile, std::string extens) override;
};