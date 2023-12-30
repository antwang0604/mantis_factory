#include <unordered_map>
#include <vector>
#include <iostream>
#include <string>
#include <memory>
#include <fstream>
#include <filesystem>

enum class StationType {
    A = 0,
    B = 1,
    C = 2,
    UNKNOWN
};


// ***************************** HELPERS *****************************

std::ostream& operator<<(std::ostream& os, const StationType& station_type)
{
    switch (station_type) {
        case StationType::A:
            os << "Station A";
            break;
        case StationType::B:
            os << "Station B";
            break;
        case StationType::C:
            os << "Station C";
            break;
        default:
            os << "Unknown Station";
            break;
    }

    return os;
}

std::string ToString(const StationType& station_type)
{
    std::string output;
    switch (station_type) {
        case StationType::A:
            output = "Station A";
            break;
        case StationType::B:
            output = "Station B";
            break;
        case StationType::C:
            output = "Station C";
            break;
        default:
            output = "Unknown Station";
            break;
    }

    return output;
}

std::string ToString(const std::vector<StationType>& line) {
    std::string output;
    for(auto station : line) {
            output += ToString(station);
            output += " -> ";
    }
    output += "End";
    if(output == "End"){
        output = " EMPTY! ";
    }
    return output;
}

class Station {
public:
    virtual void DoWork(int& workpiece) = 0;
    virtual int GetNextStation() = 0;
    Station() = default;
    virtual ~Station() = default;
};

class Station_A : public Station {
public:
    void DoWork(int& workpiece) override {
        workpiece++;
    }
    int GetNextStation() override {
        return 1;
    };
    ~Station_A() = default;
};

class Station_B : public Station {
public:
    void DoWork(int& workpiece) override {
        workpiece--;
    }
    int GetNextStation() override {
        return 1;
    }
    ~Station_B() = default;
};

class Station_C : public Station {
private:
    bool skip_next_station = false;

public:
    void DoWork(int& workpiece) override {
        if(workpiece%2 == 0) {
            skip_next_station = true;
        } else {
            skip_next_station = false;
        }
    }
    int GetNextStation() override {
        return (skip_next_station == true) ? 2 : 1;
    }
    ~Station_C() = default;
};

class AssemblyLine {
private:
    std::unordered_map<StationType, std::unique_ptr<Station>> stations_;
    std::vector<StationType> station_sequence_;
public:
    AssemblyLine() : AssemblyLine(std::vector<StationType>()) {};

    AssemblyLine(std::vector<StationType> assembly_line) : station_sequence_{assembly_line} {
        stations_[StationType::A] = std::make_unique<Station_A>();
        stations_[StationType::B] = std::make_unique<Station_B>();
        stations_[StationType::C] = std::make_unique<Station_C>();
    }

    std::unordered_map<StationType, int> ProcessWorkPiece(int& workpiece) {
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

    void UpdateAssemblyLine(std::vector<StationType> assembly_line) {
        station_sequence_ = assembly_line;
    }

    std::vector<StationType> GetCurrentLineConfig() {
        return station_sequence_;
    }

};

struct BuildLog {
    int input;
    int output;
    std::vector<StationType> line_config;
    std::unordered_map<StationType, int> station_utilization;
};



class Factory {
    AssemblyLine line_;
    std::unordered_map<StationType, int> total_utilization_records_;
    std::vector<BuildLog> build_records_;
public:
    Factory() {
        total_utilization_records_[StationType::A] = 0;
        total_utilization_records_[StationType::B] = 0;
        total_utilization_records_[StationType::C] = 0;
    }

public:
    std::vector<StationType> GetCurrentLine() {
        return line_.GetCurrentLineConfig();
    }

    void ConfigureAssemblyLine(std::vector<StationType> assembly_line) {
        line_.UpdateAssemblyLine(assembly_line);
    }

    void UpdateRecords(const BuildLog& log) {
        build_records_.push_back(log);
        for(auto kv : log.station_utilization) {
            total_utilization_records_[kv.first] += kv.second;
        }
    }

    void RunAssemblyLine(int input) {
        BuildLog log;
        log.input = input;
        log.station_utilization = line_.ProcessWorkPiece(input);
        log.output = input;
        log.line_config = line_.GetCurrentLineConfig();
        UpdateRecords(log);
    }

    void PrintUtilizationRecord() {
        std::cout << "=======================================================" << std::endl;
        std::cout << "                OPERATIONAL   SUMMARY:                 " << std::endl;
        std::cout << "-------------------------------------------------------" << std::endl;
        for(auto kv : total_utilization_records_) {
            std::cout << kv.first << " processed " << kv.second << " times" << std::endl;
        }
        std::cout << "=======================================================" << std::endl;
    }

    void PrintBuildRecord() {
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

};

StationType Translate(const char station_char) {
    StationType output;
    switch (station_char) {
        case 'a':
            output = StationType::A;
            break;
        case 'A':
            output = StationType::A;
            break;
        case 'b':
            output = StationType::B;
            break;
        case 'B':
            output = StationType::B;
            break;
        case 'c':
            output = StationType::C;
            break;
        case 'C':
            output = StationType::C;
            break;
        default:
            output = StationType::UNKNOWN;
            break;
    }

    return output;
}

char Translate(const StationType& station) {
    char output;
    switch (station) {
        case StationType::A:
            output = 'a';
            break;
        case StationType::B:
            output = 'b';
            break;
        case StationType::C:
            output = 'c';
            break;
        default:
            output = '*';
            break;
    }

    return output;
}

class AssemblyLineConfigurator {
    std::string filename = "assm_line_config.txt";
    bool ConfigFileExist;
public:
    AssemblyLineConfigurator() {
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
    std::vector<StationType> ReadFile() {
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

    void WriteFile(const std::vector<StationType> assembly_line) {
        if(ConfigFileExist == true) {
            std::ofstream file(filename);
            std::string output;
            for (StationType curr_station : assembly_line) {
                output += Translate(curr_station);
            }
            file << output;
        }
    }

    std::vector<StationType> PromptUserInput() {
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
};

void PrintWelcomeMessage() {
    std::cout << "////////////////////////////////////////////////" << std::endl;
    std::cout << "    __  __                _    _             " << std::endl;
    std::cout << "   |  \\/  |              | |  (_)            " << std::endl;
    std::cout << "   | \\  / |  __ _  _ __  | |_  _  ___        " << std::endl;
    std::cout << "   | |\\/| | / _` || '_ \\ | __|| |/ __|       " << std::endl;
    std::cout << "   | |  | || (_| || | | || |_ | |\\__ \\       " << std::endl;
    std::cout << "   |_|__|_| \\__,_||_| |_| \\__||_||___/       " << std::endl;
    std::cout << "   |  ____|          | |                     " << std::endl;
    std::cout << "   | |__  __ _   ___ | |_  ___   _ __  _   _ " << std::endl;
    std::cout << "   |  __|/ _` | / __|| __|/ _ \\ | '__|| | | |" << std::endl;
    std::cout << "   | |  | (_| || (__ | |_| (_) || |   | |_| |" << std::endl;
    std::cout << "   |_|   \\__,_| \\___| \\__|\\___/ |_|    \\__, |" << std::endl;
    std::cout << "                                        __/ |" << std::endl;
    std::cout << "                                       |___/ " << std::endl;
    std::cout << "\n   Welcome to the Mantis Factory Simulator!" << std::endl;
    std::cout << "////////////////////////////////////////////////" << std::endl;
}

void PrintMenu(const std::vector<StationType>& current_line) {
    std::cout << "*****************************************************" << std::endl;
    std::cout << "Current Assembly Line: " << ToString(current_line) << std::endl;
    std::cout << "Please Select an Option:" << std::endl;
    std::cout << "| 1 | Configure Assembly Line" << std::endl; 
    std::cout << "| 2 | Run Assembly Line" << std::endl; 
    std::cout << "| 3 | Print Total Station Utilization Record" << std::endl;
    std::cout << "| 4 | Print Build Logs" << std::endl;
    std::cout << "|-1 | Exit the Program" << std::endl;
    std::cout << "*****************************************************" << std::endl;
}

#include <chrono>
#include <thread>
void PrintLoading(const std::string message) {
    std::cout << message;
    for(int i=0; i<5; i++) {
        std::this_thread::sleep_for(std::chrono::milliseconds(200));
        std::cout << "." << std::flush;
    }
    std::cout << "\b\b\b   \b\b\b" << std::flush;
    std::cout << std::endl;
}
int main() {

    PrintWelcomeMessage();
    PrintLoading("Initializing assembly line configurator");
    AssemblyLineConfigurator config;
    PrintLoading("Initializing factory simulator");
    Factory f;
    PrintLoading("Launching Program");
    bool STOP_REQ = false;

    std::string selection;
    while(STOP_REQ == false) {
        PrintMenu(f.GetCurrentLine());
        std::cin >> selection;
        if(selection == "1") {
            std::vector<StationType> stations;
            stations = config.PromptUserInput();
            f.ConfigureAssemblyLine(stations);
        } else if (selection == "2") {
            int input;
            std::cout << "Please enter raw material for process (number): " << std::endl;
            std::cin >> input;
            if(!std::cin) {
                std::cout << "Not a valid number, please retry!" << std::endl;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            } else{
                f.RunAssemblyLine(input);
            }
        } else if (selection == "3") {
            f.PrintUtilizationRecord();
        } else if (selection == "4") {
            f.PrintBuildRecord();
        } else if (selection == "-1") {
            STOP_REQ = true;
            std::cout << "Exiting Program!" << std::endl;
        } else {
            std::cout << "Not a Valid Selection, Please Try Again!" << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
}