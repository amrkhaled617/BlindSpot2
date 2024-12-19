#include "infrared_driver.h"
#include "pico/stdlib.h"

// Check if the infrared sensor is triggered
bool is_infrared_triggered(uint infrared_pin) {
    return gpio_get(INFRARED_PIN) == 0;
}

void init_infrared(uint infrared_pin) {
    gpio_init(INFRARED_PIN);
    gpio_set_dir(INFRARED_PIN, GPIO_IN);
    // gpio_pull_up(INFRARED_PIN);
}