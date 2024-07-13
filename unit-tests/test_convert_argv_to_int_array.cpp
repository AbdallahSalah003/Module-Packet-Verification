#include <gtest/gtest.h>
#include <iostream>
#include <string>
#include "utils.hpp"

TEST(convertArgvToIntArrayTest, noArgs) {
    char* argv[] = {"main.cpp"};
    int argc = 1;
    EXPECT_EQ(convert_argv_to_int_array(argc, argv), nullptr);
}

TEST(convertArgvToIntArrayTest, singleArg) {
    char* argv[] = {"main.cpp", "5"};
    int argc = 2;
    int* result = convert_argv_to_int_array(argc, argv);
    EXPECT_EQ(result, nullptr);
    delete[] result;
}

TEST(convertArgvToIntArrayTest, multipleArgs) {
    char* argv[] = {"main.cpp", "5", "10", "15"};
    int argc = 4;
    int* result = convert_argv_to_int_array(argc, argv);
    cout<<result[0]<<result[1]<<result[2]<<'\n';
    ASSERT_NE(result, nullptr);
    EXPECT_EQ(result[0], 5);
    EXPECT_EQ(result[1], 10);
    EXPECT_EQ(result[2], 15);
    delete[] result;
}

TEST(convertArgvToIntArrayTest, negativeValueArgs) {
    char* argv[] = {"main.cpp",  "-5", "10", "-15"};
    int argc = 4;
    int* result = convert_argv_to_int_array(argc, argv);
    ASSERT_NE(result, nullptr);
    EXPECT_EQ(result[0], -5);
    EXPECT_EQ(result[1], 10);
    EXPECT_EQ(result[2], -15);
    delete[] result;
}
TEST(convertArgvToIntArrayTest, zeroValueArgs) {
    char* argv[] = {"main.cpp",  "0", "10"};
    int argc = 3;
    int* result = convert_argv_to_int_array(argc, argv);
    ASSERT_NE(result, nullptr);
    EXPECT_EQ(result[0], 0);
    EXPECT_EQ(result[1], 10);
    delete[] result;
}
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
