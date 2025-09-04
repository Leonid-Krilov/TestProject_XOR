#pragma once
#include <iostream>

#include "Work.h"
#include "OneTimeStart.h"
#include "FS_SelectWork.h"

class SelectOneTimeStart : public FS_SelectWork
{
public:
  Work* createTypeWork() override
  {
    return new OneTimeStart;
  }
};