#include <gtest/gtest.h>
#include "utils.hpp"


// Test case for a regular array with multiple unique elements
TEST(FirstLastModulesTest, RegularArray) {
    int modules[] = {3, 1, 4, 1, 5, 9, 2, 6};
    int first, last;
    int n = sizeof(modules) / sizeof(modules[0]);

    first_last_modules(first, last, n, modules);

    EXPECT_EQ(first, 1);  // Smallest element in the array
    EXPECT_EQ(last, 9);   // Largest element in the array
}

// Test case for an array with a single element
TEST(FirstLastModulesTest, SingleElement) {
    int modules[] = {42};
    int first, last;
    int n = sizeof(modules) / sizeof(modules[0]);

    first_last_modules(first, last, n, modules);

    EXPECT_EQ(first, 42);  
    EXPECT_EQ(last, 42);   
}

// Test case for an array with all elements the same
TEST(FirstLastModulesTest, AllSameElements) {
    int modules[] = {7, 7, 7, 7};
    int first, last;
    int n = sizeof(modules) / sizeof(modules[0]);

    first_last_modules(first, last, n, modules);

    EXPECT_EQ(first, 7);  
    EXPECT_EQ(last, 7);   
}

// Test case for an array with negative numbers
TEST(FirstLastModulesTest, NegativeNumbers) {
    int modules[] = {-3, -1, -4, -1, -5, -9, -2, -6};
    int first, last;
    int n = sizeof(modules) / sizeof(modules[0]);

    first_last_modules(first, last, n, modules);

    EXPECT_EQ(first, -9);  
    EXPECT_EQ(last, -1);   
}

// Test case for an array with only two elements
TEST(FirstLastModulesTest, TwoElements) {
    int modules[] = {15, 5};
    int first, last;
    int n = sizeof(modules) / sizeof(modules[0]);

    first_last_modules(first, last, n, modules);

    EXPECT_EQ(first, 5);   
    EXPECT_EQ(last, 15);   
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
