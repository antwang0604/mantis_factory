#include <line_configurator.h>
#include <fstream>

AssemblyLineConfigurator::AssemblyLineConfigurator() {
    try{
        if(!std::filesystem::exists(filename)) {
            ConfigFileExist = false;
            throw std::runtime_error("Unable to locate config file. Assembly line config will not be saved.");
        } else {
            ConfigFileExist = true;
            std::cout << "Loaded assembly line from previous session!" << std::endl;
        }
    } 
    catch (std::runtime_error& e) {
        std::cout << e.what() << std::endl;
    }
}
std::vector<StationType> AssemblyLineConfigurator::ReadFile() {
    std::vector<StationType> assembly_line;
    std::ifstream file(filename);
    char curr_station;
    while (file >> curr_station) {
        StationType current_station = Translate(curr_station);
        try{
            if(current_station == StationType::UNKNOWN) {
                throw std::runtime_error("Station is not supported, Building Empty Assembly Line");
            }
        }
        catch (std::runtime_error& e) {
            std::cout << e.what() << std::endl;;
            assembly_line.clear();
            break;
        }
        assembly_line.push_back(current_station);
    }
    
    WriteFile(assembly_line);
    

    return assembly_line;
}

void AssemblyLineConfigurator::WriteFile(const std::vector<StationType> assembly_line) {
    if(ConfigFileExist == true) {
        std::ofstream file(filename);
        std::string output;
        for (StationType curr_station : assembly_line) {
            output += Translate(curr_station);
        }
        file << output;
    }
}

std::vector<StationType> AssemblyLineConfigurator::PromptUserInput() {
    std::cout << "Enter stations for the assembly line (example: abcba or ABC)" << std::endl;
    std::string stations;
    std::cin >> stations;
    std::vector<StationType> assembly_line;
    for(auto curr_station : stations) {
        StationType current_station = Translate(curr_station);
        try{
            if(current_station == StationType::UNKNOWN) {
                throw std::runtime_error("Station is not support, building a empty assembly line");
            }
        }
        catch (std::runtime_error& e) {
            std::cout << e.what() << std::endl;;
            assembly_line.clear();
            break;
        }
        assembly_line.push_back(current_station);
    }
    WriteFile(assembly_line);
    return assembly_line;
}