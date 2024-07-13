#include "utils.hpp"
using namespace std;

int main(int argc, char** argv) 
{
    int packets = stoi(argv[1]);
    while(packets<=0) 
    {
        cout<<"Invalid packets number, packets number must be postive"<<'\n';
        return 1;
    }
    int* modules = convert_argv_to_int_array(argc, argv);
    int check = validate_input(packets, modules);
    if(check==1)
    {
        cout<<"Invalid module number, all module number must be positive"<<'\n';
        return 1;
    }
    else
    {
        cout<<"Valid inputs"<<'\n';
        int counter = 1;
        if (std::remove("output.csv") != 0) 
        {
            std::cerr << "Error deleting the file: " << "output.csv" << std::endl;
        } 
        else 
        {
            std::cout << "File successfully deleted: " << "output.csv" << std::endl;
        }
        do {
                int first, last;
                first_last_modules(first, last, packets, modules);
                int* validModules =  assign_valid_invalid(first, last, packets, modules);
                csv_output(counter++, packets, modules, validModules);
                delete[] validModules;
        } while (std::next_permutation(modules, modules + packets));
    }
    return 0;
    
}