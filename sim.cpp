#include <iostream>
#include "sim.h"
#include <fcntl.h>
#include <unistd.h>
#include <string>

Sim::Sim(const char* device){
    fd = open(device, O_RDWR);

    if (fd == -1)
    {
        std::cerr << "Failed to open " << device << std::endl;
    }
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
    std::cout.write(data.data() + start, end - start); 
    std::cout << std::endl;

}

//wait long enough to get enough raw data from the gps satellite

// create algorithm that collects one specific sentence that has the postion run program everytime the alarm goes off 

//create a separate function that gives 


//buffer.end()


// H E L L 0 _ (<- .end() is _)