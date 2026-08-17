#include <iostream>
#include <chrono>
#include "adxl345.h"
#include "LED.h"
#include "pattern.h"


int main(int argc, char const *argv[])
{
    LED ledOne(gpioPinTwentySeven);
    LED ledTwo(gpioPinTwentyTwo);
    LED ledThree(gpioPinTwentyThree);
    std::cout << "LED objects have been made." << std::endl;

    Adxl345 accelerometer("/dev/i2c-1");
    std::cout << "Adxl345 object has been made. " << std::endl;
   
    accelerometer.checkIntSource();
    std::cout << "Detecting... " << std::endl;
    systemArmed(ledOne, ledTwo, ledThree, accelerometer);
    std::cout << "Movement detected!" << std::endl;
    //alarm(ledOne, ledTwo, ledThree);
    //accelerometer.playSound("/home/gmo/sounds/Alarm_Sound_Effect.wav");

    systemOffline(ledOne, ledTwo, ledThree);
        
    return 0;
}


//g++ main.cpp LED.cpp pattern.cpp adxl345.cpp -o main $(pkg-config --cflags --libs libgpiodcxx)