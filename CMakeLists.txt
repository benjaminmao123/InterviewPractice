cmake_minimum_required(VERSION 3.28)

project(InterviewPractice)
set(CMAKE_CXX_STANDARD 23)

add_subdirectory(Source)

include(CTest)
option(BUILD_TESTING "Enable testing" ON)
if (BUILD_TESTING)
    enable_testing()
    add_subdirectory(Tests)
endif()