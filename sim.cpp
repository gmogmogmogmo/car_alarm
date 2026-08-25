#include <iostream>
#include "sim.h"
#include <fcntl.h>
#include <unistd.h>
#include <string>
#include <vector>


Sim::Sim(const char* device){
    fd = open(device, O_RDWR);
    if (fd == -1)
    {
        std::cerr << "Failed to open " << device << std::endl;
        return;
    }
    sendATCommand("AT+CGNSPWR=1");
    sendATCommand("AT+CGNSTST=1");
}
void Sim::sendATCommand(const std::string& command){
    std::string cmd = command + "\r\n";
    write(fd, cmd.c_str(), cmd.size());
}
std::string Sim::getField(const std::string& gpsData, const std::vector<size_t>& commaPos, size_t field){
   
    return gpsData.substr(commaPos[field] + 1, (commaPos[field + 1] - commaPos[field]) - 1);
}
void Sim::reformatData(const std::string& gpsData){
    std::vector<size_t> commaPos = {};
    for (size_t i = 0; i < gpsData.length(); i++){
        if (gpsData[i] == ','){
            commaPos.push_back(i);
        }
    }
    std::string time = getField(gpsData, commaPos, TIME_FIELD);
    std::string latitude = getField(gpsData, commaPos, LATITUDE_FIELD);
    std::string latitudeDirection = getField(gpsData, commaPos, LATITUDE_DIRECTION_FIELD);
    std::string longitude = getField(gpsData, commaPos, LONGITUDE_FIELD);
    std::string longitudeDirection = getField(gpsData, commaPos, LONGITUDE_DIRECTION_FIELD);
    std::cout << "Time: " << time << std::endl; 
    std::cout << "Latitude: " << latitude << std::endl; 
    std::cout << "Latitude Direction: " << latitudeDirection << std::endl;
    std::cout << "Longitude Direction: " << longitudeDirection << std::endl;
}
void Sim::readData(){
    bool foundGNGGA = false;
    char temp[256];
    std::string data;
    int bytesRead = 0;
    std::size_t end;
    std::size_t start;
    std::cout << "Here is the coordinates" << std::endl;

    while(!(foundGNGGA)){
        bytesRead = read(fd, temp, 256);
        data.append(temp, bytesRead);
        if(data.find("$GNGGA") != std::string::npos){
            start = data.find("$GNGGA");
            end = data.find("\n", start);
            foundGNGGA = true;
            break;
        }
    }
    std::string location = data.substr(start, end - start);
    reformatData(location); 

    std::cout << std::endl;

}