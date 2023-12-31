#include <iostream>
#include <helpers.h>
#include <line_configurator.h>
#include <factory.h>

int main() {

    PrintWelcomeMessage();

    // Initialization
    PrintLoading("Initializing assembly line configurator");
    AssemblyLineConfigurator config;
    PrintLoading("Initializing factory simulator");
    Factory f;
    f.ConfigureAssemblyLine(config.ReadFile());
    PrintLoading("Launching Program");
    bool STOP_REQ = false;

    std::string selection;
    while(STOP_REQ == false) {
        PrintMenu(f.GetCurrentLine());
        std::cin >> selection;
        if(selection == "1") {
            // Configuring the assembly line
            std::vector<StationType> stations;
            stations = config.PromptUserInput();
            f.ConfigureAssemblyLine(stations);
        } else if (selection == "2") {
            // Running the assembly line
            int input;
            std::cout << "Please enter raw material for process (number): " << std::endl;
            std::cin >> input;
            if(!std::cin) {
                std::cout << "Not a valid number, please retry!" << std::endl;

                // Prevent infinite loop when input is bad.
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            } else{
                f.RunAssemblyLine(input);
            }
        } else if (selection == "3") {
            // Print Utilization Record
            f.PrintUtilizationRecord();
        } else if (selection == "4") {
            // Print build record
            f.PrintBuildRecord();
        } else if (selection == "-1") {
            // Exiting Program
            STOP_REQ = true;
            std::cout << "Exiting Program!" << std::endl;
        } else {
            // Invalid input
            std::cout << "Not a Valid Selection, Please Try Again!" << std::endl;

            // Prevent infinite loop when input is bad.
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
}