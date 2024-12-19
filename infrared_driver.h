#ifndef INFRARED_DRIVER_H
#define INFRARED_DRIVER_H

#include "pico/stdlib.h"

// Pin assignment for infrared sensor
#define INFRARED_PIN 25

bool is_infrared_triggered(uint infrared_pin);
void init_infrared(uint infrared_pin);

#endif // INFRARED_DRIVER_H
