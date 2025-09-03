cmake_minimum_required(VERSION 3.10)

project(ProjectTest)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

find_package(PostgreSQL REQUIRED)

include_directories(
  src/XOR
  src/WorkFile
  src/SelectWork
  src/WorkProgram
)

set(SOURCE
  src/main.cpp
  
  src/XOR/XOR.cpp

  src/WorkFile/WorkFile.cpp
)

set(HEADERS
  src/XOR/XOR.h

  src/WorkFile/WorkFile.h

  src/SelectWork/FS_SelectWork.h
  src/SelectWork/SelectOneTimeStart.h
  src/SelectWork/SelectTimerWork.h

  src/WorkProgram/Work.h
  src/WorkProgram/OneTimeStart.h
  src/WorkProgram/TimerWork.h
)

add_executable(${PROJECT_NAME} ${SOURCE} ${HEADERS})