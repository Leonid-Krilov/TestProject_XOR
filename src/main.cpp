#include <iostream>

#include "FS_SelectWork.h"
#include "Work.h"
#include "SelectOneTimeStart.h"
#include "SelectTimerWork.h"

int main()
{
  int type = 1;
  FS_SelectWork* selectWork = nullptr;
  Work* work = nullptr;

  switch(type)
  {
    case 1:
      selectWork = new SelectOneTimeStart();
      work = selectWork->createTypeWork();
      break;
    case 2:
      selectWork = new SelectTimerWork();
      work = selectWork->createTypeWork();
      break;
  }
  
  if(!work)
    std::cout << "Device not create\n";
  else
  {
    work->workProgram("1dsgfs", "2dgsfsdf", "3sdfsd", "4sdfsf");
  }

  delete selectWork;
  delete work;

  return 0;
}