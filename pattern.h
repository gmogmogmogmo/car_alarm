#ifndef PATTERNS_H
#define PATTERNS_H

#include "LED.h"
#include "adxl345.h"

void systemArmed(LED& led, LED& ledTwo, LED& ledThree, Adxl345& accelerometer);
void alarm(LED& led, LED& ledtwo, LED& ledThree);
void systemOffline(LED& led, LED& ledTwo, LED& ledThree);

//more
#endif