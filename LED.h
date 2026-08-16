#ifndef LED_H
#define LED_H

#include <gpiod.hpp>
#include <memory>

constexpr int gpioPinTwentySeven = 27;
constexpr int gpioPinTwentyTwo = 22;
constexpr int gpioPinTwentyThree = 23;

class LED {
    public:
    LED(int pinNumber);
   // ~LED();
    void on();
    void off();

    private:
    int pin;
    std::unique_ptr<gpiod::line_request> request;
    void configure();
};

#endif