#include "buzzer_driver.h"
#include "pico/stdlib.h"

// Turn on the buzzer
void buzzer_on(uint buzzer_pin) {
    gpio_put(buzzer_pin, true);
}

// Turn off the buzzer
void buzzer_off(uint buzzer_pin) {
    gpio_put(buzzer_pin, false);
}

void init_buzzer(uint buzzer_pin) {
    gpio_init(BUZZER_PIN);
    gpio_set_dir(BUZZER_PIN, GPIO_OUT);
}