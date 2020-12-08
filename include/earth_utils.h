/**
 * @file earth_utils.h
 * @brief Lecture 10.2 Sample Code
 * handles parsing a lat/long csv file and conversion of that file to kml format
 * @author Gavin Lechner
 * @assignment Lecture 10.2
 * @date 11/15/2020
 */
#ifndef EARTH_UTILS_H
#define EARTH_UTILS_H
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

const std::string KMLHEADER1 = "<?xml version=\"1.0\" encoding=\"UTF-8\"?>";
const std::string KMLHEADER2 = "<kml xmlns=\"http://www.opengis.net/kml/2.2\">";
const std::string KMLFOOTER = "</kml>";
const std::string KMLDOCSTART = "<Document>";
const std::string KMLDOCEND = "</Document>";


/**
 * @brief process a country capital csv file
 * @date 11/15/2020
 * @return returns the number of records processed
 * @param inFile ifstream to an opened and validated csv file
 * @param kmlFileName std:string containing the name of the kml file you wish to produce
 */
int processCSV(std::ifstream& inFile, std::string kmlFileName);

/**
 * @brief Writes a placemark record into an existing kmlFile
 * @date 11/15/2020
 * @param name string represented the capital and country
 * @param latitude string representing lattitude 
 * @param longitude string representing longitude
 * @param elevation string representing elevation, defaults to 0
 */
void WritePlacemark(std::ofstream& kmlFile,std::string name, std::string lattitude,std::string longitude);

#endif