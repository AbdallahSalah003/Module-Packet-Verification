#include "utils.hpp"


int* convert_argv_to_int_array(int argc, char* argv[]) {
    if (argc <= 2) {
        cerr << "No args to convert." << endl;
        return nullptr;
    }

    int* arr = new int[argc - 1];

    for (int i = 0; i < argc-1; ++i) 
    {
        arr[i] = stoi(argv[i + 1]);
    }

    return arr;
}
int validate_input(char** modules) {
    for (int i = 1; modules[i] != nullptr; ++i) {
        try 
        {
            int num = stoi(modules[i]);
            if (num <= 0) 
                return 1;
        } 
        catch (const invalid_argument& e) 
        {
            return 1; 
        } 
        catch (const out_of_range& e) 
        {
            return 1; 
        }
    }
    return 0; // All elements are valid
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
        ofstream file1("output.csv", ios::app);
        
        if (!file1.is_open()) {
            throw runtime_error("Failed to open the file.");
        }
        file1 << "Scenario: " + to_string(scenario) + ",_,_"<< '\n';
        file1 << "PacketID,ModuleNumber,ValidModule\n";

        for (int i = 0; i < n; ++i) {
            file1 << i + 1 << "," << modules[i] << "," 
                << (validModules[i] ? "Yes" : "No") << "\n";
        }
        file1.close();
    }
    catch(const exception &e)
    {
        cerr << "There is an Error: "<<e.what()<< endl;
    }
}