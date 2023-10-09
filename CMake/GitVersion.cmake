# find_package(Git) -> finds the location of the git executable
# git describe --always --abbrev=8 -> gives the abbreviated hash
# git status --short -> checks for uncommitted  work
# git describe --exact-match --tags -> gives the tag
# git rev-parse --abbrev-ref HEAD -> gives current branch
# git log -mN 1 --pretty=%cd --pretty=%cI -> gives the time of the last commit

find_package(Git REQUIRED)
#message(STATUS "GIT_EXECUTABLE: " ${GIT_EXECUTABLE})
#message(STATUS "PROJECT_SOURCE_DIR: " ${PROJECT_SOURCE_DIR})

execute_process(COMMAND ${GIT_EXECUTABLE} describe --always --abbrev=8
        WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}
        OUTPUT_VARIABLE GIT_COMMIT)
execute_process(COMMAND ${GIT_EXECUTABLE} status --short
        WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}
        OUTPUT_VARIABLE GIT_STATUS)

execute_process(COMMAND ${GIT_EXECUTABLE} describe --exact-match --tags
        WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}
        OUTPUT_VARIABLE GIT_TAG
        ERROR_QUIET)

execute_process(COMMAND ${GIT_EXECUTABLE} rev-parse --abbrev-ref HEAD
        WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}
        OUTPUT_VARIABLE GIT_BRANCH)

execute_process(COMMAND ${GIT_EXECUTABLE} log -n 1 --pretty=%cd --pretty=%cI
        WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}
        OUTPUT_VARIABLE GIT_DATE)

string(STRIP "${GIT_COMMIT}" GIT_COMMIT)
string(STRIP "${GIT_TAG}" GIT_TAG)
string(STRIP "${GIT_BRANCH}" GIT_BRANCH)
string(STRIP "${GIT_DATE}" GIT_DATE)

#message(STATUS "GIT_COMMIT: " ${GIT_COMMIT})
#message(STATUS "GIT_TAG: " ${GIT_TAG})
#message(STATUS "GIT_BRANCH: " ${GIT_BRANCH})
#message(STATUS "GIT_DATE: " ${GIT_DATE})