#ifndef LINE_CONFIGURATOR_H
#define LINE_CONFIGURATOR_H

#include <string>
#include <filesystem>
#include <iostream>
#include <definitions.h>
#include <helpers.h>

class AssemblyLineConfigurator {
    std::string filename = "assm_line_config.txt";
    bool ConfigFileExist;
public:
    AssemblyLineConfigurator();
    
    std::vector<StationType> ReadFile();

    void WriteFile(const std::vector<StationType> assembly_line);

    std::vector<StationType> PromptUserInput();
};

#endif