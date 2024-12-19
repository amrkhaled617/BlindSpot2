#ifndef LIGHT_DRIVER_H
#define LIGHT_DRIVER_H

#include "pico/stdlib.h"

// Pin assignment for light sensor
#define LIGHT_PIN 5

bool is_light_triggered(uint light_pin);
void init_light(uint light_pin);

#endif // LIGHT_DRIVER_H
