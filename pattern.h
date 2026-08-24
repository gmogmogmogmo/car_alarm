#ifndef PATTERNS_H
#define PATTERNS_H

#include "LED.h"
#include "sim.h"
#include "adxl345.h"

void detectingLights(LED& ledOne, LED& ledTwo, LED& ledThree);
void alarmLights(LED& ledOne, LED& ledTwo, LED& ledThree);
void offlineLights(LED& ledOne, LED& ledTwo, LED& ledThree);

//more
#endif