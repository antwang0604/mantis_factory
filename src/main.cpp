#include <iostream>
#include <helpers.h>
#include <line_configurator.h>
#include <factory.h>

int main() {

    PrintWelcomeMessage();
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
            std::vector<StationType> stations;
            stations = config.PromptUserInput();
            f.ConfigureAssemblyLine(stations);
        } else if (selection == "2") {
            int input;
            std::cout << "Please enter raw material for process (number): " << std::endl;
            std::cin >> input;
            if(!std::cin) {
                std::cout << "Not a valid number, please retry!" << std::endl;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            } else{
                f.RunAssemblyLine(input);
            }
        } else if (selection == "3") {
            f.PrintUtilizationRecord();
        } else if (selection == "4") {
            f.PrintBuildRecord();
        } else if (selection == "-1") {
            STOP_REQ = true;
            std::cout << "Exiting Program!" << std::endl;
        } else {
            std::cout << "Not a Valid Selection, Please Try Again!" << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
}