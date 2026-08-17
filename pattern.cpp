#include <iostream>
#include <chrono>
#include <unistd.h>

#include "pattern.h"
#include "LED.h"
#include "adxl345.h"

const int fiveMiliseconds = 500000;
const int fiveSeconds = 5;

void systemArmed(LED& ledOne, LED& ledTwo, LED& ledThree, Adxl345& accel){
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
            //break;
            alarm(ledOne, ledTwo, ledThree);
            accelerometer.playSound("/home/gmo/sounds/Alarm_Sound_Effect.wav");
            sleep(fiveSeconds)
        }
    }
}

void alarm(LED& ledOne, LED& ledTwo, LED& ledThree){
    ledOne.on();
    ledTwo.on();
    ledThree.on();
    
}

void systemOffline(LED& ledOne, LED& ledTwo, LED& ledThree){
    ledOne.off();
    ledTwo.off();
    ledThree.off();
}

//g++ pattern.cpp LED.cpp -o pattern $(pkg-config --cflags --libs libgpiodcxx)