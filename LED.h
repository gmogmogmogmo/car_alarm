#ifndef LED_H
#define LED_H

#include <gpiod.hpp>
#include <memory>
class LED {
    public:
    LED(int pinNumber);
   // ~LED();

    void configure();
    void on();
    void off();

    private:
    int pin;
    std::unique_ptr<gpiod::line_request> request;
};

#endif