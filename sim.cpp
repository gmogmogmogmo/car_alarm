#include <iostream>
#include "sim.h"
#include <fcntl.h>
#include <unistd.h>
#include <string>
#include <chrono>

Sim::Sim(const char* device){
    fd = open(device, O_RDWR);

    if (fd == -1)
    {
        std::cerr << "Failed to open " << device << std::endl;
    }
}

void Sim::readData(){
    char buffer[256];
    std::cout << "About to read... " << std::endl;
    int bytesRead = read(fd, buffer, 256);
    std::cout.write(buffer, bytesRead); 
  
    // if(bytesRead > 0){
    //     std::string data(buffer, bytesRead);
    //     size_t position = data.find("$GNGGA");
    //     std::cout << "Number of bytes: " << bytesRead << std::endl;
    //     std::cout.write(buffer, bytesRead);   
    // }
    // else {
    //     std::cout << "Received no data. " << std::endl;
    // }
}


int main(int argc, char const *argv[])
{   
    Sim gps("/dev/ttyUSB2");

    auto start = std::chrono::steady_clock::now();
    
    //batch of 2 second data from stream 
    while (std::chrono::steady_clock::now() - start < std::chrono::seconds(2))
    {
        gps.readData();
    }


    return 0;
}




//wait long enough to get enough raw data from the gps satellite

// create algorithm that collects one specific sentence that has the postion run program everytime the alarm goes off 

//create a separate function that gives 
