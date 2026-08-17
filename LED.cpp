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

// g++ LED.cpp -o LED $(pkg-config --cflags --libs libgpiodcxx)