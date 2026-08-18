#ifndef BUTTON_H
#define BUTTON_H

#include <gpiod.hpp>
#include <memory>

class Button
{
private:
    int pin; 
    bool isButtonOn = false;
    std::unique_ptr<gpiod::line_request> request;
    void configure();
public:
    Button(int pinNumber);

    void hasButtonPressed(); 

    //~Button();
};


#endif