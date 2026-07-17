include(FetchContent)
FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG main
)
FetchContent_MakeAvailable(googletest)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

add_executable(InterviewPracticeTests 
    CounterTest.cpp
    MessageValidatorTest.cpp
    CircularBufferTest.cpp)
target_include_directories(InterviewPracticeTests PRIVATE ${CMAKE_SOURCE_DIR}/Source)
target_link_libraries(InterviewPracticeTests PRIVATE GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(InterviewPracticeTests)