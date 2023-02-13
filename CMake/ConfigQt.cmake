
include_guard(GLOBAL)

#-------------------------------------------------------------------------------
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

#-------------------------------------------------------------------------------
# Qt Config
# win平台自动使用msvc
# Win上Qt需安装在C:\Qt或D:\Qt或E:\Qt， Mac上Qt需安装在用户主目录 $HOME/Qt
set(QT_VERSION 5.15.1)   # 当前只能设定为5.15.x, 5.12.x
set(CFG_64bit TRUE)


set(Qt_Install_Dir_List "C:" "D:" "E:" "F:")
set(Qt_Compiler_List msvc2019 msvc2017)

if (APPLE)
    set(QT_VER_DIR "$ENV{HOME}/Qt/${QT_VERSION}/clang_64" CACHE STRING "Qt Dir")
elseif (WIN32)
    if (CFG_64bit)
        set(Compiler_Suffix _64)
    endif()
    foreach(rootDir IN LISTS Qt_Install_Dir_List)
        foreach(compilerItem IN LISTS Qt_Compiler_List)
            #---qt online install path
            set(checkDir "${rootDir}/Qt/${QT_VERSION}/${compilerItem}${Compiler_Suffix}")
            #message(STATUS "checkDir: " ${checkDir})
            if (IS_DIRECTORY ${checkDir})
                set(QT_VER_DIR ${checkDir} CACHE STRING "Qt Dir")
                break()
            endif()
            #---qt offline install path
            set(checkDir "${rootDir}/Qt/Qt${QT_VERSION}/${QT_VERSION}/${compilerItem}${Compiler_Suffix}")
            #message(STATUS "checkDir: " ${checkDir})
            if (IS_DIRECTORY ${checkDir})
                set(QT_VER_DIR ${checkDir} CACHE STRING "Qt Dir")
                break()
            endif()
        endforeach()
        if (IS_DIRECTORY ${QT_VER_DIR})
            break()
        endif()
    endforeach()
elseif(UNIX)
    # /home/Qt/5.15.1/gcc_64
    set(QT_VERSION 5.15.2)
    set(QT_DIR "/home/Qt")
    if(NOT IS_DIRECTORY ${QT_DIR})
        set(QT_DIR "/opt/Qt")
    endif()
    if (CFG_64bit)
        set(Compiler_Suffix gcc_64)
    endif()
    set(QT_VER_DIR "/home/Qt/${QT_VERSION}/${Compiler_Suffix}")
    # QT_VER_DIR: ~/Qt/${QT_VERSION}/gcc${Compiler_Suffix}
    message( ${QT_VER_DIR} )
endif ()

if (NOT IS_DIRECTORY ${QT_VER_DIR})
    message(FATAL_ERROR "QT_VER_DIR is not exists.(QT_VER_DIR: ${QT_VER_DIR})")
else ()
    message(STATUS "QT_VER_DIR: ${QT_VER_DIR}")
endif ()

#-------------------------------------------------------------------------------
# 定义Qt_LIB_DIR，是为了在macOS上，把Qt LIB写入到RPATH
set(QT_LIB_DIR "${QT_VER_DIR}/lib")

#-------------------------------------------------------------------------------
# 找Qt库，只需要下面这一行
set(CMAKE_PREFIX_PATH ${QT_VER_DIR})
find_package(Qt5 COMPONENTS
        Gui Widgets Multimedia Network Concurrent
        WebChannel WebSockets Quick RemoteObjects Qml QuickWidgets
        REQUIRED)


#-------------------------------------------------------------------------------
# env setting print
if (WIN32)
    MESSAGE(STATUS "debug env: " PATH=${QT_VER_DIR}/bin\;%PATH%\;QT_ASSUME_STDERR_HAS_CONSOLE=1)
endif ()


#-------------------------------------------------------------------------------
# OutputPlatform
# 用来辅助配置输出路径
if (${QT_VERSION} MATCHES "5\.15\.*")
    set(QtVerDir Qt5.15)
elseif(${QT_VERSION} MATCHES "5\.12\.*")
    set(QtVerDir Qt5.12)
endif()

if(APPLE)
    set(PlatformDir macOS)
elseif(UNIX)
    set(PlatformDir gcc64)
else()
    if(${CFG_64bit})
        set(PlatformDir Win64)
    else()
        set(PlatformDir Win32)
    endif()
endif()


set(OutputPlatform ${QtVerDir}/${PlatformDir})

#-------------------------------------------------------------------------------
# platform print
MESSAGE(STATUS "OutputPlatform: " ${OutputPlatform})
