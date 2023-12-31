#ifndef ASSEMBLY_LINE_H
#define ASSEMBLY_LINE_H

#include <definitions.h>
#include <station.h>
#include <unordered_map>
#include <vector>

class AssemblyLine {
private:
    std::unordered_map<StationType, std::unique_ptr<Station>> stations_;
    std::vector<StationType> station_sequence_;
public:
    AssemblyLine();

    AssemblyLine(std::vector<StationType> assembly_line);

    std::unordered_map<StationType, int> ProcessWorkPiece(int& workpiece);

    void UpdateAssemblyLine(std::vector<StationType> assembly_line);

    std::vector<StationType> GetCurrentLineConfig();

};
#endif