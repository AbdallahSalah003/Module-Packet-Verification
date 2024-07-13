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
    first = INT_MAX;
    last = INT_MIN;

    for (int i = 0; i < n; ++i) 
    {
        if (modules[i] < first) 
            first = modules[i];
        if (modules[i] > last)
            last = modules[i];
    }
}
int* assign_valid_invalid(int first, int last, int n, int* modules)
{
    int* validModules = new int[n];

    validModules[0] = 1; // Default value for the first packet to be sent

    int current, next;
    for (int i = 1; i < n; ++i) 
    {
        current = modules[i-1];
        next = modules[i];

        if (current == last) 
        {
            // If current module is the last module then next module should be last or first
            validModules[i] = (next == last || next == first) ? 1 : 0;
        } 
        else 
        {
            // If current module is not the last
            validModules[i] = (next == current || next == current + 1) ? 1 : 0;
        }
    }

    return validModules;
}
void csv_output(int n, int* modules, int* validModules)
{
    std::ofstream file;
    try {
        file.open("output.csv");
        
        if (!file.is_open()) {
            throw std::runtime_error("Failed to open the file.");
        }
        
        file << "PacketID,ModuleNumber,ValidModule\n";

        for (int i = 0; i < n; ++i) {
            file << i + 1 << "," << modules[i] << "," 
                << (validModules[i] ? "Yes" : "No") << "\n";
        }
    }
    catch(const std::exception &e)
    {
        std::cerr << "There is an Error: "<<e.what()<< std::endl;
    }

    if(file.is_open()) 
    {
        file.close();
    }
}