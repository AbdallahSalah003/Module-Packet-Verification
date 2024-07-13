#ifndef UTILS_HPP
#define UTILS_HPP
#include <iostream>
#include <fstream>
#include <climits>
#include <algorithm>
#include <cstdio>

int* convert_argv_to_int_array(int argc, char* argv[]);
int validate_input(int packets, int* modules);
void first_last_modules(int &first, int &last, int n, int* modules);
int* assign_valid_invalid(int first, int last, int n, int* modules);
void csv_output(int scenario, int n, int* modules, int* validModules);

#endif UTILS_HPP
