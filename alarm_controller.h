#ifndef ALARM_CONTROLLER_H
#define ALARM_CONTROLLER_H

#include "adxl345.h"
#include "sim.h"
#include "LED.h"
#include "pattern.h"
#include "button.h"


void systemArmed();
void trigger();
void systemOffline();


#endif