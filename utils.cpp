#include "utils.hpp"


int* convert_argv_to_int_array(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "No args to convert." << std::endl;
        return nullptr;
    }

    int* arr = new int[argc - 2];

    for (int i = 0; i < argc-2; ++i) 
    {
        try 
        {
            arr[i] = std::stoi(argv[i + 2]);
        } 
        catch (const std::invalid_argument& e) 
        {
            std::cerr<<"Invalid argument: " <<argv[i+ 2]<< std::endl;
            delete[] arr;
            return nullptr;
        } 
        catch (const std::out_of_range& e) 
        {
            std::cerr <<"Out of range: " << argv[i+2] << std::endl;
            delete[]arr;
            return nullptr;
        }
    }

    return arr;
}
int validate_input(int packets, int* modules)
{
    for(int i=0; i<packets; ++i) 
    {
        if(modules[i] <= 0)
            // "Invalid module number, all module number must be positive"
            return 1;
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
void csv_output(int scenario, int n, int* modules, int* validModules)
{
    try {
        std::ofstream file1("output.csv", std::ios::app);
        
        if (!file1.is_open()) {
            throw std::runtime_error("Failed to open the file.");
        }
        file1 << "Scenario: ";
        file1 << scenario << '\n';
        file1 << "PacketID,ModuleNumber,ValidModule\n";

        for (int i = 0; i < n; ++i) {
            file1 << i + 1 << "," << modules[i] << "," 
                << (validModules[i] ? "Yes" : "No") << "\n";
        }
        file1.close();
    }
    catch(const std::exception &e)
    {
        std::cerr << "There is an Error: "<<e.what()<< std::endl;
    }
}