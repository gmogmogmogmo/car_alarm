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

//AT+CPIN? - CONFIRMS THE SIM IS PHYSICALLY SEATED AND READABLE NO PIN LOCK
//AT+CSQ - IF RETURNS 99 NO SIGNAL 
//AT+CNMP? - RETURNED 13 WHICH MEANT THE SIM WAS LOCKED TO GSM /
//AT+CNMP=38 - SETS MODE TO LTE ONLY
//AT+CMNB=1 - SETS PREFERRED LTE TYPE TO CAT-M ONLY 
//AT+CSQ - CHECK SIGNAL QUALITY AGAIN 31 BEING BEST SIGNAL 
//AT+CREG? - is the device registered 0,2 not registered but mt is currently searching a new operator to register to
 //picocom /dev/ttyUSB3


 //forbidden 


 //problem priorty list it prioritze atats iot core over everything its forbidden and firmware for some reason doesnt find the next best provider

 //cant send messages through sms because verizon blocks 

 //sms update system tracker http over cellular data


 //send message AT+CMGF=1 and AT+CMGS="###########"


//AT+CMGF=1
//AT+CMGS="+13104844082"