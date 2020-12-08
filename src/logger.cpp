/**
 * @file logger.h
 * @brief Lecture 10.2
 * handles the declaration of all logging functionality
 * @author Bilbo Baggins
 * @assignment Lab 10.2
 * @date 11/12/2020
 */
#include "logger.h"
#include <pwd.h>
#include <unistd.h>
#include <libgen.h>

using namespace std;

bool log(string msg,string programName,ofstream& logFile)
{
    string strTime;

    time_t logTime = time(0);
    strTime = ctime(&logTime);

    int timeSize = strTime.size();
    if(timeSize)
    {
        strTime[timeSize -1] = ' ';
    }

    pid_t pid = getpid();
    char hostName[500];
    gethostname(hostName,500);
    string strHostName(hostName);
    if(logFile)
    {
        logFile << strTime << strHostName << " " << programName  << "[" << pid << "]: " << msg << endl;
        return true;
    }
    else
    {
        return false;
    }
}