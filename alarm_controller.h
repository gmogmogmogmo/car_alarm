#ifndef ALARM_CONTROLLER_H
#define ALARM_CONTROLLER_H

#include "adxl345.h"
#include "sim.h"
#include "LED.h"
#include "pattern.h"
#include "button.h"

bool ledModeSetup();
void systemArmed(const bool& ledMode);
void trigger();
void systemOffline();


#endif