#pragma once
#include <iostream>

#include "Work.h"
#include "TimerWork.h"
#include "FS_SelectWork.h"

class SelectTimerWork : public FS_SelectWork
{
public:
  Work* createTypeWork()
  {
    return new TimerWork;
  }
};