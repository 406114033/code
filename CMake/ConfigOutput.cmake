
if (${OutputPlatform} STREQUAL "")
    message(FATAL_ERROR "You need include ConfigQt.cmake in root CMakeLists.txt.")
endif ()

set(outputBin ${CMAKE_SOURCE_DIR}/VideoEditorSDK/${OutputPlatform}/Bin)
set(outputDoc ${CMAKE_SOURCE_DIR}/VideoEditorSDK/${OutputPlatform}/Doc)
set(outputInclude ${CMAKE_SOURCE_DIR}/VideoEditorSDK/${OutputPlatform}/Include)

get_filename_component(makeExe ${CMAKE_MAKE_PROGRAM} NAME)
#message("CMAKE_MAKE_PROGRAM:*** " ${makeExe})
if (NOT (${makeExe} STREQUAL MSBuild.exe))
    set(buildType ${CMAKE_BUILD_TYPE})
endif ()

#---设置输出路径
set_target_properties(${targetName} PROPERTIES
        ARCHIVE_OUTPUT_DIRECTORY "${outputBin}/${buildType}"
        LIBRARY_OUTPUT_DIRECTORY "${outputBin}/${buildType}"
        RUNTIME_OUTPUT_DIRECTORY "${outputBin}/${buildType}")

#set_target_properties(${targetName} PROPERTIES
#        ARCHIVE_OUTPUT_DIRECTORY "D:/object/HitPawVideoConverter/bin/win/x64/debug"
#        LIBRARY_OUTPUT_DIRECTORY "D:/object/HitPawVideoConverter/bin/win/x64/debug"
#        RUNTIME_OUTPUT_DIRECTORY "D:/object/HitPawVideoConverter/bin/win/x64/debug")

add_custom_command(TARGET ${targetName} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E make_directory ${outputDoc}
        COMMAND ${CMAKE_COMMAND} -E make_directory ${outputInclude}
        )

if (outputHeaders)
    add_custom_command(TARGET ${targetName} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different ${outputHeaders} ${outputInclude}/)
endif()