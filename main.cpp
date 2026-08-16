#include <iostream>
#include "adxl345.h"
#include "LED.h"
#include "pattern.h"

int gpioPinTwentySeven = 27;
int gpioPinTwentyTwo = 22;
int gpioPinTwentyThree = 23;

int main(int argc, char const *argv[])
{
    
    LED ledOne(gpioPinTwentySeven);
    LED ledTwo(gpioPinTwentyTwo); 
    LED ledThree(gpioPinTwentyThree);
    ledOne.configure();
    ledTwo.configure();
    ledThree.configure();
    //had configurations to LED class?

    Adxl345 accel("/dev/i2c-1");
    accel.setUpSingleTapDetection(accel);
    accel.watchForLine();
        
    while(true){
        accel.checkIntSource();
        std::cout << "Detecting... " << std::endl;
        armed(ledOne, ledTwo, ledThree, *request);
    
        std::cout << "Movement detected!" << std::endl;
        request->read_edge_events(eventBuffer);
        alarm(ledOne, ledTwo, ledThree);
        accel.playSound("/home/gmo/sounds/Alarm_Sound_Effect.wav");
    }

    return 0;
}


//g++ main.cpp LED.cpp pattern.cpp adxl345.cpp -o main $(pkg-config --cflags --libs libgpiodcxx)