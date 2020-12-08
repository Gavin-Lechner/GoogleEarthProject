/**
 * @file logger.h
 * @brief Lecture 10.2
 * handles the declaration of all logging functionality
 * @author Bilbo Baggins
 * @assignment Lab 10.2
 * @date 11/12/2020
 */
#ifndef LOGGER_H
#define LOGGER_H
#include <string>
#include <fstream>

/**
 * @brief creates a discrete syslog message
 * @date 11/12/2020
 * @return returns a boolean indicating the message was written ok
 * @param msg std:string containing syslog message
 * @param logFile ofstream reference, validation of this file is expected
 */
bool log(std::string msg, std::string programName,std::ofstream& logFile);
#endif