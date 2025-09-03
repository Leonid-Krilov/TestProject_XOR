#pragma once
#include <iostream>

#include "Work.h"

class FS_SelectWork
{
public:
  virtual ~FS_SelectWork() = default;
  virtual Work* createTypeWork() = 0 ;
};