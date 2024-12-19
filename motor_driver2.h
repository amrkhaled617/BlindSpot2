#ifndef MOTOR_DRIVER2_H
#define MOTOR_DRIVER2_H

#include "pico/stdlib.h"


#define MOTOR2_PWM_PIN 20
#define MOTOR2_DIR_PIN1 19
#define MOTOR2_DIR_PIN2 18

void motor2_init(void);
void motor2_control(uint16_t speed, bool forward);

#endif