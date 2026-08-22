#include "alarm_controller.h"
#include <iostream>
Adxl345 accelerometer("/dev/i2c-1");

LED ledOne(gpioPinTwentySeven);
LED ledTwo(gpioPinTwentyTwo);
LED ledThree(gpioPinTwentyThree);

Sim gps("/dev/ttyUSB2");

void systemArmed(){
    accelerometer.checkIntSource();
    std::cout << "Detecting... " << std::endl;
    detectingLights(ledOne, ledTwo, ledThree, accelerometer);
}

void trigger(){
    std::cout << "---------------------------------------------------------------------------------" << std::endl;
    std::cout << "MOVEMENT DETECTED!" << std::endl;
    accelerometer.playSound("/home/gmo/sounds/Alarm_Sound_Effect.wav");
    alarmLights(ledOne, ledTwo, ledThree);
    gps.readData();
}

void systemOffline(){
    offlineLights(ledOne, ledTwo, ledThree);
}


