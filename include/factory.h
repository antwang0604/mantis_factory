#ifndef FACTORY_H
#define FACTORY_H

#include <definitions.h>
#include <vector>
#include <unordered_map>
#include <assembly_line.h>

class Factory {
    AssemblyLine line_;
    std::unordered_map<StationType, int> total_utilization_records_;
    std::vector<BuildLog> build_records_;
public:
    Factory();

public:
    std::vector<StationType> GetCurrentLine();

    void ConfigureAssemblyLine(std::vector<StationType> assembly_line);

    void UpdateRecords(const BuildLog& log);

    void RunAssemblyLine(int input);

    void PrintUtilizationRecord();

    void PrintBuildRecord();

};

#endif