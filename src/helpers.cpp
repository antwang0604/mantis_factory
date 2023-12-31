#include <helpers.h>

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


void PrintLoading(const std::string message) {
    std::cout << message;
    for(int i=0; i<5; i++) {
        std::this_thread::sleep_for(std::chrono::milliseconds(200));
        std::cout << "." << std::flush;
    }
    std::cout << "\b\b\b   \b\b\b" << std::flush;
    std::cout << std::endl;
}

