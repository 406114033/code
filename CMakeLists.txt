
cmake_minimum_required(VERSION 3.19)
project(newTestDemo LANGUAGES CXX C)
#--------------------------------------------------------------------------------
include(CMake/ConfigQt.cmake)
include(CMake/ConfigCxx.cmake)
include(CMake/GitVersion.cmake)

add_subdirectory(TestPro)

add_subdirectory(ThirdParty)