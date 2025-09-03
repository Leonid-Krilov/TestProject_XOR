#pragma once
#include <iostream>

#include "Work.h"

class TimerWork : public Work
{
protected:
  void workProgram(std::string maskFile, std::string pathInputFile, std::string pathOutFile, std::string extens) override;
};