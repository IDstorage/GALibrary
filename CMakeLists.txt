cmake_minimum_required (VERSION 3.8)

project (GALibrary)

# 하위 프로젝트를 포함합니다. (CMakeLists파일이 하위에 있어야 함.)
#add_subdirectory ("${PROJECT_SOURCE_DIR}/Code") 

#include_directories ("${PROJECT_SOURCE_DIR}/Code")

#add_library (GAWORLD SHARED "Code/src/GAWorld.cpp")
#add_library (GALIB SHARED "Code/src/GALib.cpp")

#add_executable (galib "Code/src/GALib.cpp")

add_subdirectory (./Code)