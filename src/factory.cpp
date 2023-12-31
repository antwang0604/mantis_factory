#include <factory.h>
#include <iostream>
#include <helpers.h>

Factory::Factory() {
        total_utilization_records_[StationType::A] = 0;
        total_utilization_records_[StationType::B] = 0;
        total_utilization_records_[StationType::C] = 0;
}

std::vector<StationType> Factory::GetCurrentLine() {
    return line_.GetCurrentLineConfig();
}

void Factory::ConfigureAssemblyLine(std::vector<StationType> assembly_line) {
    line_.UpdateAssemblyLine(assembly_line);
    PrintLoading("Updating Assembly Line");
    std::cout << "Done!" << std::endl;
}

void Factory::UpdateRecords(const BuildLog& log) {
    build_records_.push_back(log);
    for(auto kv : log.station_utilization) {
        total_utilization_records_[kv.first] += kv.second;
    }
}

void Factory::RunAssemblyLine(int input) {
    BuildLog log;
    log.input = input;
    log.station_utilization = line_.ProcessWorkPiece(input);
    PrintLoading("Running Production");
    std::cout << "Done!" << std::endl;
    log.output = input;
    log.line_config = line_.GetCurrentLineConfig();
    UpdateRecords(log);
}

void Factory::PrintUtilizationRecord() {
    std::cout << "=======================================================" << std::endl;
    std::cout << "                OPERATIONAL   SUMMARY:                 " << std::endl;
    std::cout << "-------------------------------------------------------" << std::endl;
    for(auto kv : total_utilization_records_) {
        std::cout << kv.first << " processed " << kv.second << " times" << std::endl;
    }
    std::cout << "=======================================================" << std::endl;
}

void Factory::PrintBuildRecord() {
    std::cout << "=======================================================" << std::endl;
    std::cout << "              CURRENT SESSION BUILD RECORD             " << std::endl;
    std::cout << "-------------------------------------------------------" << std::endl;

    for(int i=0; i<build_records_.size(); i++) {
        auto build_log = build_records_[i];
        std::cout << "RUN " << i+1 << " SUMMARY:" << std::endl;
        std::cout << "-------------------------------------------------------" << std::endl;
        std::cout << "[Assembly Line] " << ToString(build_log.line_config) << std::endl;
        std::cout << "[Input] " << build_log.input << std::endl;
        std::cout << "[Output] " << build_log.output << std::endl;
        std::cout << "-------------------------------------------------------" << std::endl;
    }
    std::cout << "=======================================================" << std::endl;
}