#include <iostream>
#include <chrono>
#include <unistd.h>
#include "pattern.h"
#include "LED.h"

const int fiveMiliseconds = 500000;

void detecting(LED& ledOne, LED& ledTwo, LED& ledThree){
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
    }
}

void alarm(LED& ledOne, LED& ledTwo, LED& ledThree){
    ledOne.on();
    ledTwo.on();
    ledThree.on();
    
}

// int main(int argc, char const *argv[])
// {

//     LED ledOne(gpioPinTwentySeven);
//     LED ledTwo(gpioPinTwentyTwo);
//     LED ledThree(gpioPinTwentyThree);
//     std::cout << "Objects have been declared: " << std::endl;

//     detecting(ledOne, ledTwo, ledThree);
//     std::cout << "Alarm is going off now!" << std::endl;
//     alarm(ledOne, ledTwo, ledThree);

//     return 0;
// }


//g++ pattern.cpp LED.cpp -o pattern $(pkg-config --cflags --libs libgpiodcxx)