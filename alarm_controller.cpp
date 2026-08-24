#include "alarm_controller.h"
#include <iostream>
#include <unistd.h>

Adxl345 accelerometer("/dev/i2c-1");

// 3 lEDs
LED ledOne(gpioPinTwentySeven);
LED ledTwo(gpioPinTwentyTwo);
LED ledThree(gpioPinTwentyThree);

Button buttonOne(gpioPinNumberSix);

Sim gps("/dev/ttyUSB2");

bool ledModeSetup(){
    std::cout << "Tap button to engage LED mode. " << std::endl;

    return buttonOne.hasButtonPressed();
}
void systemArmed(const bool& ledMode){
    accelerometer.lineSetupSignalDetection();
    std::cout << "LED mode set to: " << ledMode << std::endl;
    sleep(3);    
    std::cout << "Detecting..." << std::endl;
    while (true){
        std::cout "Inside while loop " << std::endl;
        if(ledMode){
            detectingLights(ledOne, ledTwo, ledThree);
        }
        // if(accelerometer.tapDetected()){
        //     break;
        // }
    }
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




//command: g++ adxl345.cpp alarm_controller.cpp button.cpp LED.cpp main.cpp pattern.cpp sim.cpp -o car_alarm $(pkg-config --cflags --libs libgpiodcxx)

