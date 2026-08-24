#include <gpiod.hpp>
#include <iostream>
#include "button.h"
#include <memory>
#include <chrono>

Button::Button(int pinNumber){
    pin = pinNumber;
    configure();
}

void Button::configure(){
    gpiod::chip chip("/dev/gpiochip0");
    gpiod::line_settings settings;
    settings.set_direction(gpiod::line::direction::INPUT);
    settings.set_bias(gpiod::line::bias::PULL_UP);
    settings.set_active_low(true);
    settings.set_edge_detection(gpiod::line::edge::FALLING);

    gpiod::line_config configForGPIO;
    configForGPIO.add_line_settings(pin, settings);
    gpiod::request_config request_config;
    request_config.set_consumer("BUTTON");
    request = std::make_unique<gpiod::line_request>(chip.prepare_request().set_request_config(request_config).set_line_config(configForGPIO).do_request());
}

bool Button::hasButtonPressed(){
    if (request->wait_edge_events(std::chrono::seconds(waitTimeForButton))){
        return true;
    }
    return false;
}



//command to compile: g++ button.cpp button.h  -o button $(pkg-config --cflags --libs libgpiodcxx)