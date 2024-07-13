#include <gtest/gtest.h>
#include "utils.hpp"


void compare_arrays(int* arr1, int* arr2, int size) {
    for (int i = 0; i < size; ++i) 
    {
        EXPECT_EQ(arr1[i], arr2[i]);
    }
}

// Test case for all valid input
TEST(AssignValidInvalidTest, allValidInput) {
    int modules[] = {1, 2, 3, 4};
    int n = 4, first, last;
    first_last_modules(first, last, n, modules);
    int* validModules = assign_valid_invalid(first, last, n, modules);

    int expectedValidModules[] = {1, 1, 1, 1};
    compare_arrays(validModules, expectedValidModules, n);
    delete[] validModules;  
}

// Test case for an array with the last module comes before the first element
TEST(AssignValidInvalidTest, lastMdouleBeforeFirstModule) {
    int modules[] = {2, 3, 4, 2};
    int n = 4, first, last;
    first_last_modules(first, last, n, modules);
    int* validModules = assign_valid_invalid(first, last, n, modules);

    int expectedValidModules[] = {1, 1, 1, 1};
    compare_arrays(validModules, expectedValidModules, n);
    delete[] validModules;  
}
// Test case sending packets from one module only
TEST(AssignValidInvalidTest, sameModules) {
    int modules[] = {5, 5, 5};
    int n = 3, first, last;
    first_last_modules(first, last, n, modules);
    int* validModules = assign_valid_invalid(first, last, n, modules);

    int expectedValidModules[] = {1, 1, 1};
    compare_arrays(validModules, expectedValidModules, n);
    delete[] validModules;  
}

// Test case for an array with only two non consecutive elements
TEST(AssignValidInvalidTest, twoElements) {
    int modules[] = {1, 12};
    int n = 2, first, last;
    first_last_modules(first, last, n, modules);
    int* validModules = assign_valid_invalid(first, last, n, modules);
    int expectedValidModules[] = {1, 0};
    compare_arrays(validModules, expectedValidModules, n);
    delete[] validModules;  

    int modules1[] = {12, 1};
    first_last_modules(first, last, n, modules1);
    int* validModules1 = assign_valid_invalid(first, last, n, modules1);
    int expectedValidModules1[] = {1, 1};
    compare_arrays(validModules1, expectedValidModules1, n);
    delete[] validModules1;  
}


int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
