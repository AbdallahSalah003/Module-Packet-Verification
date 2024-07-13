#include <gtest/gtest.h>
#include "utils.hpp"

char** create_char_array(const std::initializer_list<std::string>& strings) {
    char** arr = new char*[strings.size() + 1];
    int i = 0;
    for (const auto& str : strings) {
        arr[i] = new char[str.size() + 1];
        strcpy(arr[i], str.c_str());
        ++i;
    }
    arr[i] = nullptr; 
    return arr;
}

void delete_char_array(char** arr) {
    int i = 0;
    while (arr[i] != nullptr) {
        delete[] arr[i];
        ++i;
    }
    delete[] arr;
}

TEST(ValidateInputTest, ValidInputs) {
    char** valid_args = create_char_array({"program", "1", "2", "3", "4"});
    EXPECT_EQ(validate_input(valid_args), 0);
    delete_char_array(valid_args);
}

TEST(ValidateInputTest, ZeroOrNegativeInputs) {
    char** invalid_args = create_char_array({"program", "0", "2", "3", "-1"});
    EXPECT_EQ(validate_input(invalid_args), 1);
    delete_char_array(invalid_args);
}

TEST(ValidateInputTest, NonNumericInputs) {
    char** invalid_args = create_char_array({"program", "1", "two", "3", "4"});
    EXPECT_EQ(validate_input(invalid_args), 1);
    delete_char_array(invalid_args);
}

TEST(ValidateInputTest, EmptyInputs) {
    char** invalid_args = create_char_array({"program", ""});
    EXPECT_EQ(validate_input(invalid_args), 1);
    delete_char_array(invalid_args);
}

TEST(ValidateInputTest, LargeNumbers) {
    char** valid_args = create_char_array({"program", "2147483647", "123456789", "1000"});
    EXPECT_EQ(validate_input(valid_args), 0);
    delete_char_array(valid_args);
}

TEST(ValidateInputTest, LargeNumbersWithOutOfRange) {
    char** invalid_args = create_char_array({"program", "2147483648", "123456789", "1000"});
    EXPECT_EQ(validate_input(invalid_args), 1);
    delete_char_array(invalid_args);
}

TEST(ValidateInputTest, MixedValidAndInvalidInputs) {
    char** invalid_args = create_char_array({"program", "1", "two", "3", "0"});
    EXPECT_EQ(validate_input(invalid_args), 1);
    delete_char_array(invalid_args);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
