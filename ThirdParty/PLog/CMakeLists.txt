
project(PLog LANGUAGES CXX)

add_library(PLog INTERFACE IMPORTED GLOBAL)

target_include_directories(PLog
        INTERFACE $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>)

add_library(PLog::PLog ALIAS PLog)
