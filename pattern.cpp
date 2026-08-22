#include <iostream>
#include <chrono>
#include <unistd.h>

#include "pattern.h"
#include "LED.h"
#include "adxl345.h"
#include "sim.h"

const int fiveSeconds = 5;
const int fiveMiliseconds = 500000;

void detectingLights(LED& ledOne, LED& ledTwo, LED& ledThree, Adxl345& accel){
    while (true)
    {
        ledOne.on();
        usleep(fiveMiliseconds);
        ledOne.off();
        ledTwo.on();
        usleep(fiveMiliseconds);
        ledTwo.off();
        ledThree.on();
        usleep(fiveMiliseconds);
        ledThree.off();
        if(accel.tapDetected()){
            break;
        }
    }
}

void alarmLights(LED& ledOne, LED& ledTwo, LED& ledThree){
    ledOne.on();
    ledTwo.on();
    ledThree.on();
}

void offlineLights(LED& ledOne, LED& ledTwo, LED& ledThree){
    ledOne.off();
    ledTwo.off();
    ledThree.off();
}

//g++ pattern.cpp LED.cpp -o pattern $(pkg-config --cflags --libs libgpiodcxx)


//g++ main.cpp adxl345.cpp alarm_controller.cpp LED.cpp pattern.cpp sim.cpp -o car_alarm $(pkg-config --cflags --libs libgpiodcxx)