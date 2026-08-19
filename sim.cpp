#include <iostream>
#include "sim.h"
#include <fcntl.h>
#include <unistd.h>

Sim::Sim(const char* device){
    fd = open(device, O_RDWR);
}



int main(int argc, char const *argv[])
{
    
    char buffer[256];

    int bytesRead = read(fd, buffer, 256);
    



    return 0;
}
