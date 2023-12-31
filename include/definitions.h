#ifndef DEFINITIONS_H
#define DEFINITIONS_H

#include <vector>
#include <unordered_map>

enum class StationType {
    A = 0,
    B = 1,
    C = 2,
    UNKNOWN
};

struct BuildLog {
    int input;
    int output;
    std::vector<StationType> line_config;
    std::unordered_map<StationType, int> station_utilization;
};

#endif