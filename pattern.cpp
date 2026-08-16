#include <iostream>
#include <chrono>
#include <unistd.h>
#include "pattern.h"
#include "LED.h"

const int fiveMiliseconds = 500000;

void detecting(LED& ledOne, LED& ledTwo, LED& ledThree){
    ledOne.configure();
    ledTwo.configure();
    ledThree.configure();
    int numberOfCycles = 20;
   
        ledOne.on();
        usleep(fiveMiliseconds);
        ledOne.off();
    ledTwo.on();
    usleep(fiveMiliseconds);
    ledTwo.off();
    ledThree.on();
    usleep(fiveMiliseconds);
    ledThree.off();   
    
}

void alarm(LED& ledOne, LED& ledTwo, LED& ledThree){
    //ledOne.configure();
    //ledTwo.configure();
    //ledThree.configure();

    ledOne.on();
    ledTwo.on();
    ledThree.on();
}

int main(int argc, char const *argv[])
{
    int gpioPinTwentySeven = 27;
    int gpioPinTwentyTwo = 22;
    int gpioPinTwentyThree = 23;

    LED ledOne(gpioPinTwentySeven);
    LED ledTwo(gpioPinTwentyTwo);
    LED ledThree(gpioPinTwentyThree);
    std::cout << "Objects have been declared: " << std::endl;

    detecting(ledOne, ledTwo, ledThree);
    alarm(ledOne, ledTwo, ledThree);

    return 0;
}


//g++ pattern.cpp LED.cpp -o pattern $(pkg-config --cflags --libs libgpiodcxx)