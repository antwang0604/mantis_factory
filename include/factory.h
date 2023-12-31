#ifndef FACTORY_H
#define FACTORY_H

#include <definitions.h>
#include <vector>
#include <unordered_map>
#include <assembly_line.h>

/**
 * @brief Factory Class that contains the assembly line, and provide client with
 * interfaces to run operations. Also keeps the statistics of the the factory.
 * 
 */
class Factory {
private:
    AssemblyLine line_; // Assembly Line
    std::unordered_map<StationType, int> total_utilization_records_; // station utilization record of current session
    std::vector<BuildLog> build_records_; // detail build record of current session
public:
    /**
     * @brief Construct a new Factory object
     * 
     */
    Factory();

    /**
     * @brief Retrieve the current assembly line configuration
     * 
     * @return std::vector<StationType> assembly line configuration
     */
    std::vector<StationType> GetCurrentLine();

    /**
     * @brief Allows client to configure the assembly line in factory
     * 
     * @param assembly_line desired configuration
     */
    void ConfigureAssemblyLine(std::vector<StationType> assembly_line);

    /**
     * @brief Update the build record by appending new log to the session record.
     * @param log Current record to append to session record.
     */
    void UpdateRecords(const BuildLog& log);

    /**
     * @brief Run the assembly line by passing the workpiece through the line.
     * 
     * @param input raw material to process
     */
    void RunAssemblyLine(int input);

    /**
     * @brief Print the overall utilization record of different stations.
     * 
     */
    void PrintUtilizationRecord();

    /**
     * @brief Print the Build records of current session.
     * 
     */
    void PrintBuildRecord();

};

#endif