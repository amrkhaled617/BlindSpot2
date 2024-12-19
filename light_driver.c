#include "light_driver.h"
#include "pico/stdlib.h"

// Check if the light sensor is triggered
bool is_light_triggered(uint light_pin) {
    return gpio_get(light_pin) == 1;
}

void init_light(uint light_pin) {
    gpio_init(LIGHT_PIN);
    gpio_set_dir(LIGHT_PIN, GPIO_IN);
}