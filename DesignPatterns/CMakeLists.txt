
set(targetName DesignPatterns)
set(CMAKE_CXX_STANDARD 14)

#file(GLOB_RECURSE sourceFiles *.cpp)
#file(GLOB_RECURSE testSourceFiles Test/*.cpp)
#
#list(REMOVE_ITEM ${sourceFiles} ${testSourceFiles})

#add_executable(${targetName} ${sourceFiles})
file(GLOB_RECURSE designSourceFiles Strategy/*.cpp)

add_executable(${targetName} main.cpp Singleton.cpp ${designSourceFiles})

target_link_libraries(${targetName} PUBLIC FFMPEG_avcodec FFMPEG_avfilter
        FFMPEG_avformat FFMPEG_avutil FFMPEG_postproc
        FFMPEG_swresample FFMPEG_swscale PLog Pthread
        PRIVATE Qt5::Core Qt5::Gui Qt5::Widgets Qt5::Multimedia)

message(STATUS " source_Dir" ${CMAKE_SOURCE_DIR})

target_sources(${targetName} PRIVATE ${sourceFiles}
        ${CMAKE_SOURCE_DIR}/TestPro/FFmpegHeaders.hpp
        ${CMAKE_SOURCE_DIR}/TestPro/Logger.hpp
        )
