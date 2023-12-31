#ifndef DEFINITIONS_H
#define DEFINITIONS_H

#include <vector>
#include <unordered_map>

/**
 * @brief Type of stations represented using a scoped enum
 * 
 */
enum class StationType {
    A = 0,
    B = 1,
    C = 2,
    UNKNOWN
};

/**
 * @brief Internal struct for storing each assembly line run
 * 
 */
struct BuildLog {
    int input;
    int output;
    std::vector<StationType> line_config;
    std::unordered_map<StationType, int> station_utilization;
};

#endif