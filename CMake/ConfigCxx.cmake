
#-------------------------------------------------------------------------------
# C++ Config
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS ON)
if(UNIX)
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fPIC")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fPIC")
endif()

add_compile_options("$<$<CONFIG:DEBUG>:-DDEBUG>")
#mac调试触发断言会导致程序终止。禁用Mac环境的断言。
if(APPLE)
    add_compile_options("$<$<CONFIG:DEBUG>:-DQT_NO_DEBUG>")
endif()
add_compile_options("$<$<CONFIG:RELEASE>:-DQT_NO_DEBUG>")
#add_compile_options("$<$<CONFIG:RELEASE>:-DQT_NO_DEBUG_OUTPUT>")
if (MSVC)
    add_compile_options("$<$<CONFIG:RelWithDebInfo>:/Od>")
endif ()
