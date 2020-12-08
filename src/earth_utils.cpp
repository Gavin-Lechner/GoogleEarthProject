/**
 * @file earth_utils.cpp
 * @brief Lab 10.2
 * handles parsing a lat/long csv file and conversion of that file to kml format
 * @author Gavin Lechner
 * @assignment Lab 10.2
 * @date 11/15/2020
 */

#include "earth_utils.h"

using namespace std;

int processCSV(ifstream& inFile, string kmlFileName)
{
    ofstream kml;
    string strCountry, strCapital, strLat, strLong;
    string strLine;
    int recordCount;
    recordCount=0;
    if(inFile)
    {
        getline(inFile,strLine);
        kml.open(kmlFileName);
        kml << KMLHEADER1 << endl;
        kml << KMLHEADER2 << endl;
        kml << KMLDOCSTART << endl;
        while(getline(inFile,strLine))
        {
            stringstream s_stream(strLine);
            getline(s_stream, strCountry, ',');
            getline(s_stream, strCapital, ',');
            getline(s_stream, strLat, ',');
            getline(s_stream, strLong, ',');
            string name = strCountry + ", " + strCapital;
            WritePlacemark(kml, name, strLat, strLong);
            recordCount++;
        }
        kml << KMLDOCEND << endl;
        kml << KMLFOOTER << endl;
        kml.close();
    }
    return recordCount;
}

void WritePlacemark(ofstream& kmlFile,string name, string lattitude,string longitude)
{
        kmlFile << "<Placemark>" << endl;
        kmlFile << "<name>" << name << "</name>" << endl;
        kmlFile << "<Point><coordinates>" << longitude << "," << lattitude << "</coordinates></Point>" << endl;
        kmlFile << "</Placemark>" << endl;
}