#include <iostream>
#include <pwd.h>
#include <unistd.h>
#include <libgen.h>
#include "logger.h"
#include "earth_utils.h"

using namespace std;
int main(int argc, char* argv[])
{
    int opt{};
    int kmlFlag{};
    int logFlag{};
    string logValue;
    string kmlValue;
    bool optErr = true;
    while((opt = getopt(argc, argv, "k:l:")) != EOF)
    {
        switch(opt)
        {
            case 'k':
                kmlFlag=true;
                kmlValue = optarg;
                break;
            case 'l':
                logFlag = true;
                logValue = optarg;
                break;
            default:
                optErr=true;
                break;
        }
    }
    //cout<<"Flags - countFlag: " << kmlFlag << " logFlag: " << logFlag << endl;
    if(kmlFlag && logFlag)
    {
        //cout << "flags set!" <<endl;
        if(logValue.empty() || kmlValue.empty())
        {
            optErr=true;
            cout << "Option arguements are not set" << endl;
        }
        else
        {
            ofstream flog;
            flog.open(logValue, ios_base::app);
            if(flog)
            {
                string programName = basename(argv[0]);
                string msg = "The kmlfile is: " + kmlValue + " and the logfile is: " + logValue;
                log(msg, programName, flog);
                optErr = false;
                flog.close();
                ifstream inFile;
                inFile.open(kmlValue);
                if(inFile)
                {
                    int recordCount = processCSV(inFile,kmlValue + ".kml");
                    inFile.close();
                    if(recordCount)
                    {
                        cout<<recordCount<<" records processed" << endl;
                        optErr = false;
                    }
                    else
                    {
                        cout << "records not working" << endl;
                        optErr = true;
                    }
                }
                else
                {
                    cout << "Infile not working" << endl;
                    optErr = true;
                }
                
            }
            else
            {
                cout<< "couldn't open " << logValue << endl;
                optErr = true;
            }
            
        }
    }
    else
    {
        cout<<"error - flags are not set!"<<endl;
        optErr = true;
    }

    if(optErr)
    {
        return EXIT_FAILURE;
    }

    

    //cout<<"The count is: " << kmlValue << " and the logfile is: " << logValue << endl;
    //cout<<"optErr:" << optErr << endl;
    return EXIT_SUCCESS;
}