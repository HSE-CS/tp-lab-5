cmake_minimum_required (VERSION 3.10.2)
project (tp-lab-5)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -O3 -g")


set(tool_dest "bin")
set(lib_dest "lib")
set(include_dest "include/")

add_subdirectory(src)
add_subdirectory(test)


################################
# Testing
################################

# Make PROJECT_SOURCE_DIR, PROJECT_BINARY_DIR, and PROJECT_NAME available.
set(CMAKE_CXX_STANDARD 17)
set(PROJECT_NAME tp-lab-5)
project(${PROJECT_NAME})


# Define project test files
file(GLOB TEST_SRC_FILES ${PROJECT_SOURCE_DIR}/test/*.cpp)

# Define all cpp files which you want to test
set(SRC_FILES ${PROJECT_SOURCE_DIR}/src/main.cpp
        ${PROJECT_SOURCE_DIR}/src/Deanary.cpp
        ${PROJECT_SOURCE_DIR}/src/Group.cpp
        ${PROJECT_SOURCE_DIR}/src/Student.cpp
        )

# ${PROJECT_SOURCE_DIR}/include/Deanary.h
# ${PROJECT_SOURCE_DIR}/include/Student.h
# ${PROJECT_SOURCE_DIR}/include/Group.h

add_library(task_lib ${SRC_FILES})

# This adds another subdirectory, which has 'project(gtest)'.
add_subdirectory(gtest)

# Unit Tests
add_executable(runUnitTests ${TEST_SRC_FILES})

# Standard linking to gtest stuff.
target_link_libraries(runUnitTests gtest gtest_main)

# Extra linking for the project.
target_link_libraries(runUnitTests task_lib)
