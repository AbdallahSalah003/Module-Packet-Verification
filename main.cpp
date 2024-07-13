#include "utils.hpp"

int main(int argc, char** argv) 
{
    int check = validate_input(argv);
    if(check)
    {
        cout<<"Invalid inputs, all inputs must be positive numbers"<<'\n';
        return 1;
    }
    int packets = stoi(argv[1]);
    int* modules = convert_argv_to_int_array(argc, argv);
    if (modules == nullptr)
    {
        cout<<"No modules provided, please provide modules"<<'\n';
        return 1;
    }
    int counter = 1;
    remove("output.csv"); // remove prev output file
    int first, last;
    first_last_modules(first, last, packets, modules);
    do
    {
        int* validModules =  assign_valid_invalid(first, last, packets, modules);
        csv_output(counter++, packets, modules, validModules);
        delete[] validModules;
    } while (next_permutation(modules, modules + packets));
    return 0;
    
}