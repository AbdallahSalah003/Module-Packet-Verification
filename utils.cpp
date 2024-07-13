#include "utils.hpp"


int validate_input(int packets, int* modules)
{
    if( packets <= 0 )
        // "Invalid packets number, packets number must be postive"
        return 1;
    for(int i=0; i<packets; ++i) 
    {
        if(modules[i] <= 0)
            // "Invalid module number, all module number must be positive"
            return 2;
    }
    return 0;  // "Valid input"
}
void first_last_modules(int &first, int &last, int n, int* modules)
{

}
int* assign_valid_invalid(int n, int* modules)
{

}
void csv_output(int n, int* modules, int* validModule)
{

}