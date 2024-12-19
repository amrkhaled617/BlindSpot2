#ifndef DISTANCE_DRIVER_H
#define DISTANCE_DRIVER_H

#include "pico/stdlib.h"

// Pin assignment for distance measurement
#define TRIG_PIN 12
#define ECHO_PIN 13

float measure_distance();
void init_ultrasonic(int trig_pin, int echo_pin);

#endif // DISTANCE_DRIVER_H
