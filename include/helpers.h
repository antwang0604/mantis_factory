#ifndef HELPERS_H
#define HELPERS_H

#include <iostream>
#include <definitions.h>
#include <vector>
#include <thread>
#include <chrono>


std::ostream& operator<<(std::ostream& os, const StationType& station_type);
std::string ToString(const StationType& station_type);
std::string ToString(const std::vector<StationType>& line);
StationType Translate(const char station_char);
char Translate(const StationType& station);
void PrintWelcomeMessage();
void PrintMenu(const std::vector<StationType>& current_line);
void PrintLoading(const std::string message);


#endif