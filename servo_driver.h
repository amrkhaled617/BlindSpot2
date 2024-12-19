#ifndef SERVO_DRIVER_H
#define SERVO_DRIVER_H

#include "pico/stdlib.h"

// Pin assignment for servo motor
#define SERVO_PIN 4

void servo_motor_set_angle(uint servo_pin, uint angle);
void init_servo(uint servo_pin);

#endif // SERVO_DRIVER_H