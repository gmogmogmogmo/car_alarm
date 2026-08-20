#include <iostream>
#include <chrono>
#include "adxl345.h"
#include "LED.h"
#include "pattern.h"
#include "button.h"


int main(int argc, char const *argv[])
{
    LED ledOne(gpioPinTwentySeven);
    LED ledTwo(gpioPinTwentyTwo);
    LED ledThree(gpioPinTwentyThree);

    Button setLED();

    Adxl345 accelerometer("/dev/i2c-1");
   
    accelerometer.checkIntSource();
    std::cout << "Detecting... " << std::endl;
    systemArmed(ledOne, ledTwo, ledThree, accelerometer);
    std::cout << "Movement detected!" << std::endl;
    //alarm(ledOne, ledTwo, ledThree);
    //accelerometer.playSound("/home/gmo/sounds/Alarm_Sound_Effect.wav");

    systemOffline(ledOne, ledTwo, ledThree);
        
    return 0;
}

//set up led pattern 
//start detecting 





//g++ main.cpp LED.cpp pattern.cpp adxl345.cpp -o main $(pkg-config --cflags --libs libgpiodcxx)