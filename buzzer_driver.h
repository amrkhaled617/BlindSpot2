#ifndef BUZZER_DRIVER_H
#define BUZZER_DRIVER_H

#include "pico/stdlib.h"

// Pin assignment for buzzer
#define BUZZER_PIN 21

void buzzer_on(uint buzzer_pin);
void buzzer_off(uint buzzer_pin);
void init_buzzer(uint buzzer_pin);

#endif // BUZZER_DRIVER_H
