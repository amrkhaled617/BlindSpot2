#ifndef MOTOR_DRIVER_H
#define MOTOR_DRIVER_H

#include "pico/stdlib.h"


#define MOTOR1_PWM_PIN 16
#define MOTOR1_DIR_PIN1 27
#define MOTOR1_DIR_PIN2 28

void motor_init(void);
void motor_control(uint16_t speed, bool forward);

#endif