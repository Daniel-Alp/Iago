# CMakeList.txt : CMake project for Iago, include source and define
# project specific logic here.
#
cmake_minimum_required(VERSION 3.21)
project (Iago)

set(CMAKE_CXX_STANDARD 17)
#
if(NOT CMAKE_BUILD_TYPE)
        set(CMAKE_BUILD_TYPE RelWithDebugInfo)
endif()

# Add source to this project's executable.
add_executable (Iago "Iago.cpp" "Iago.h")