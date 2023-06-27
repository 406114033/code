set(targetName PcSysInfo)
set(CMAKE_CXX_STANDARD 14)

file(GLOB_RECURSE sourceFiles *.cpp)
file(GLOB_RECURSE testSourceFiles Test/*.cpp)

list(REMOVE_ITEM ${sourceFiles} ${testSourceFiles})

add_executable(${targetName} ${sourceFiles})

find_package(Qt5Charts)
target_link_libraries(${targetName} PUBLIC PLog
        PRIVATE Qt5::Core Qt5::Gui Qt5::Widgets Qt5::Charts)

target_sources(${targetName} PRIVATE ${sourceFiles})