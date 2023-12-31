#ifndef HELPERS_H
#define HELPERS_H

#include <iostream>
#include <definitions.h>
#include <vector>
#include <thread>
#include <chrono>

/**
 * @brief Convert Station type to string for console output
 * 
 * @param station_type 
 * @return std::string 
 */
std::string ToString(const StationType& station_type);

/**
 * @brief Convert assembly line to string for console output
 * 
 * @param line 
 * @return std::string 
 */
std::string ToString(const std::vector<StationType>& line);

/**
 * @brief Convert user input station type to internal representation.
 * 
 * @param station_char 
 * @return StationType 
 */
StationType Translate(const char station_char);

/**
 * @brief Convert internal representation station type external representation.
 * 
 * @param station_char 
 * @return StationType 
 */
char Translate(const StationType& station);

/**
 * @brief Print welcome message for the program
 * 
 */
void PrintWelcomeMessage();

/**
 * @brief Print main selection menu of the program along with the current assembly line config.
 * 
 * @param current_line current assembly line config
 */
void PrintMenu(const std::vector<StationType>& current_line);

/**
 * @brief Print loading message for console output. Provide the message desired
 * to display and loading dots (...) will display with a fixed delay in between.
 * ** This is time based not event drive! **
 * 
 * @param message message to display
 */
void PrintLoading(const std::string message);


#endif