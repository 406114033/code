
set(targetName newTestDemo)
set(CMAKE_CXX_STANDARD 14)

file(GLOB_RECURSE sourceFiles *.cpp)
file(GLOB_RECURSE testSourceFiles Test/*.cpp)

list(REMOVE_ITEM ${sourceFiles} ${testSourceFiles})

add_executable(${targetName} ${sourceFiles})

target_link_libraries(${targetName} PUBLIC FFMPEG_avcodec FFMPEG_avfilter
        FFMPEG_avformat FFMPEG_avutil FFMPEG_postproc
        FFMPEG_swresample FFMPEG_swscale PLog Pthread
        PRIVATE Qt5::Core Qt5::Gui Qt5::Widgets Qt5::Multimedia)

target_sources(${targetName} PRIVATE ${sourceFiles}
        ${CMAKE_CURRENT_SOURCE_DIR}/FFmpegHeaders.hpp)