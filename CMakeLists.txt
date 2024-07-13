
cmake_minimum_required(VERSION 3.22)
project(ModulePacketVerification)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

include_directories(${CMAKE_SOURCE_DIR})

add_executable(test_convert_argv_to_int_array
    utils.cpp
    unit-tests/test_convert_argv_to_int_array.cpp
)
add_executable(test_validate_input
    utils.cpp
    unit-tests/test_validate_input.cpp
)
add_executable(test_first_last_modules
    utils.cpp
    unit-tests/test_first_last_modules.cpp
)
add_executable(test_assign_valid_invalid
    utils.cpp
    unit-tests/test_assign_valid_invalid.cpp
)
target_link_libraries(test_assign_valid_invalid ${GTEST_LIBRARIES} pthread)
target_link_libraries(test_validate_input ${GTEST_LIBRARIES} pthread)
target_link_libraries(test_convert_argv_to_int_array ${GTEST_LIBRARIES} pthread)
target_link_libraries(test_first_last_modules ${GTEST_LIBRARIES} pthread)

enable_testing()
add_test(NAME test_assign_valid_invalid COMMAND test_assign_valid_invalid)
add_test(NAME test_first_last_modules COMMAND test_first_last_modules)
add_test(NAME test_validate_input COMMAND test_validate_input)
add_test(NAME test_convert_argv_to_int_array COMMAND test_convert_argv_to_int_array)



