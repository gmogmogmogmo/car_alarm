#include <iostream>
#include <gpiod.hpp>
#include "LED.h"
#include <unistd.h>
#include <chrono>
#include <string>
#include <memory>

LED::LED(int pinNumber){
  pin = pinNumber;
  configure();
}

void LED::configure(){
    gpiod::chip chip("/dev/gpiochip0");
    gpiod::line_settings settings;
    settings.set_direction(gpiod::line::direction::OUTPUT);
    settings.set_output_value(gpiod::line::value::INACTIVE);
    gpiod::line_config configForGPIO;
    configForGPIO.add_line_settings(pin, settings);
    gpiod::request_config request_config;
    request_config.set_consumer("LED");
    request = std::make_unique<gpiod::line_request>(chip.prepare_request().set_request_config(request_config).set_line_config(configForGPIO).do_request());

}

void LED::off(){
    request->set_value(pin, gpiod::line::value::INACTIVE);
}

void LED::on(){
    request->set_value(pin, gpiod::line::value::ACTIVE);
}

// int main(int argc, char const *argv[])
// {
//     LED ledOne(gpioPinTwentySeven);
//     LED ledTwo(gpioPinTwentyTwo);
//     LED ledThree(gpioPinTwentyThree);
    
//     std::cout << "LED light has been configured: " << std::endl;
//     sleep(5);
//     ledOne.on();
//     ledTwo.on();
//     ledThree.on();
//     std::cout << "LED light should be on" << std::endl;
//     sleep(5);
//     ledOne.off();
//     ledTwo.off();
//     ledThree.off();
//     std::cout << "LED light should be off" << std::endl;
//     return 0;
// }



// g++ LED.cpp -o LED $(pkg-config --cflags --libs libgpiodcxx)