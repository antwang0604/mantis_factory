#ifndef ASSEMBLY_LINE_H
#define ASSEMBLY_LINE_H

#include <definitions.h>
#include <station.h>
#include <unordered_map>
#include <vector>

/**
 * @brief Assembly Line class that contains various stations.
 * 
 */
class AssemblyLine {
private:

    // stations in the assembly line is store in an unordered map
    // key: station type, value: actualy station object to perform work on
    std::unordered_map<StationType, std::unique_ptr<Station>> stations_;

    // assembly line's configuration
    std::vector<StationType> station_sequence_;
public:

    /**
     * @brief Construct a new Assembly Line object
     * 
     */
    AssemblyLine();

    /**
     * @brief Construct a new Assembly Line object with specified assembly line config
     * 
     * @param assembly_line 
     */
    AssemblyLine(std::vector<StationType> assembly_line);

    /**
     * @brief Run the workpiece through the assembly line. The workpiece is passed by reference
     * so it doesn't need to be returned.
     * 
     * @param workpiece 
     * @return std::unordered_map<StationType, int> The current run's utilization record
     */
    std::unordered_map<StationType, int> ProcessWorkPiece(int& workpiece);

    /**
     * @brief Update the assmebly line configuration based on input
     * 
     * @param assembly_line vector of Station Types
     */
    void UpdateAssemblyLine(std::vector<StationType> assembly_line);

    /**
     * @brief Get the Current Assembly Line Configuration
     * 
     * @return std::vector<StationType> 
     */
    std::vector<StationType> GetCurrentLineConfig();

};
#endif