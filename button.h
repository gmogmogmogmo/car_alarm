#ifndef BUTTON_H
#define BUTTON_H

#include <gpiod.hpp>
#include <memory>

constexpr int gpioPinNumberSix = 6;
constexpr int waitTimeForButton = 5;
class Button
{
private:
    int pin; 
    std::unique_ptr<gpiod::line_request> request;
    void configure();
public:
    Button(int pinNumber);
    bool hasButtonPressed(); 

    //~Button();
};

#endif