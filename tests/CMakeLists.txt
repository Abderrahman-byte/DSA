# Enable FetchContent for dependencies
include(FetchContent)

# Add Catch2 as a testing framework
FetchContent_Declare(
    Catch2
    GIT_REPOSITORY https://github.com/catchorg/Catch2.git
    GIT_TAG v3.7.1
)
FetchContent_MakeAvailable(Catch2)

# Glob all test files
file(GLOB TEST_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)

# Create the test executable
add_executable(run_tests ${TEST_SOURCES})

# Link the library and Catch2 to the test executable
target_link_libraries(run_tests PRIVATE 
    DSA 
    Catch2::Catch2WithMain
)

# Add test to CTest
include(Catch)
catch_discover_tests(run_tests)
