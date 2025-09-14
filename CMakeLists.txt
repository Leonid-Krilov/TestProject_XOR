cmake_minimum_required(VERSION 3.5)

project(TestProject_XOR VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

include_directories(
  src/XOR
  src/WorkFile
  src/ConfirmationWindow
  src/MainWindow
)

file(GLOB PROJECT_SOURCES "src/*.cpp" "src/*/*.cpp" "src/*.h" "src/*/*.h")
#file(GLOB PROJECT_HEADERS )

# set(PROJECT_SOURCES
#     src/main.cpp
#     src/mainwindow.cpp
#     src/mainwindow.h
#     src/mainwindow.ui
        
#     src/XOR/XOR.cpp
#     src/XOR/XOR.h
        
#     src/WorkFile/WorkFile.cpp
#     src/WorkFile/WorkFile.h
# )

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(${PROJECT_NAME}
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
        src/ConfirmationWindow/dialogconfirmationwindow.h src/ConfirmationWindow/dialogconfirmationwindow.cpp src/ConfirmationWindow/dialogconfirmationwindow.ui

    )

else()
    if(ANDROID)
        add_library(${PROJECT_NAME} SHARED
            ${PROJECT_SOURCES} #${PROJECT_HEADERS}
        )
    else()
        add_executable(${PROJECT_NAME}
            ${PROJECT_SOURCES} #${PROJECT_HEADERS}
        )
    endif()
endif()

target_link_libraries(${PROJECT_NAME} PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

if(${QT_VERSION} VERSION_LESS 6.1.0)
  set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.${PROJECT_NAME})
endif()
set_target_properties(${PROJECT_NAME} PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS ${PROJECT_NAME}
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(${PROJECT_NAME})
endif()
