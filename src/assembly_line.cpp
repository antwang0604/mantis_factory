#include <assembly_line.h>
#include <vector>
#include <unordered_map>


AssemblyLine::AssemblyLine() : AssemblyLine(std::vector<StationType>()) {};

AssemblyLine::AssemblyLine(std::vector<StationType> assembly_line) : station_sequence_{assembly_line} {
    stations_[StationType::A] = std::make_unique<Station_A>();
    stations_[StationType::B] = std::make_unique<Station_B>();
    stations_[StationType::C] = std::make_unique<Station_C>();
}

std::unordered_map<StationType, int> AssemblyLine::ProcessWorkPiece(int& workpiece) {
    int current_station_index = 0;
    std::unordered_map<StationType, int> station_utilization;

    while(current_station_index < station_sequence_.size()) {
        StationType current_station_type = station_sequence_[current_station_index];
        int next_station_increment = 1;
        station_utilization[current_station_type]++;
        stations_[current_station_type]->DoWork(workpiece);
        next_station_increment = stations_[current_station_type]->GetNextStation();
        current_station_index+=next_station_increment;
    }
    return station_utilization;

}

void AssemblyLine::UpdateAssemblyLine(std::vector<StationType> assembly_line) {
    station_sequence_ = assembly_line;
}

std::vector<StationType> AssemblyLine::GetCurrentLineConfig() {
    return station_sequence_;
}