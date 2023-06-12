# message("ffmpeg dir: " ${CMAKE_CURRENT_SOURCE_DIR})

macro(FFMPEG_FIND shortName)
    file(GLOB_RECURSE tmpLIB ${shortName}.lib)
    file(GLOB_RECURSE tmpDLL ${shortName}*.dll)
    set(FFMPEG_${shortName}_LIB ${tmpLIB} CACHE STRING "${shortName} LIB")
    set(FFMPEG_${shortName}_DLL ${tmpDLL} CACHE STRING "${shortName} DLL")
    #message(STATUS ${shortName} " DLL: " ${FFMPEG_${shortName}_DLL})
    #message(STATUS ${shortName} " LIB: " ${FFMPEG_${shortName}_LIB})
    add_library(FFMPEG_${shortName} SHARED IMPORTED GLOBAL)

    set_target_properties(FFMPEG_${shortName} PROPERTIES
            IMPORTED_LOCATION ${FFMPEG_${shortName}_DLL}
            IMPORTED_IMPLIB ${FFMPEG_${shortName}_LIB}
            INTERFACE_INCLUDE_DIRECTORIES ${ffmpeg_DIR}
            )
    list(APPEND FFMPEG_DLL_List ${FFMPEG_${shortName}_DLL})
    #message("-----------------")
endmacro(FFMPEG_FIND)

file(GLOB_RECURSE avcodecHeader avcodec.h)
get_filename_component(avcodec_DIR ${avcodecHeader} DIRECTORY)
get_filename_component(ffmpeg_DIR ${avcodec_DIR} DIRECTORY)
message(STATUS "ffmpeg_DIR: " ${ffmpeg_DIR})

file(GLOB_RECURSE ffmpegExe ffmpeg.exe)

FFMPEG_FIND(avcodec)
FFMPEG_FIND(avdevice)
FFMPEG_FIND(avfilter)
FFMPEG_FIND(avformat)
FFMPEG_FIND(avutil)
FFMPEG_FIND(postproc)
FFMPEG_FIND(swresample)
FFMPEG_FIND(swscale)


file(GLOB_RECURSE ffmpegExe ffmpeg.exe)
set(FFMPEG_ffmpeg ${ffmpegExe} CACHE STRING "ffmpeg executable")
#message(STATUS "ffmpeg path:" ${FFMPEG_ffmpeg})

set(FFMPEG_DLLs ${FFMPEG_DLL_List} CACHE STRING "FFMPEG_DLLs")
set(FFMPEG_EXE ${ffmpegExe} CACHE STRING "FFMPEG_EXE")
#message("FFMPEG_DLLs: " ${FFMPEG_DLLs})
