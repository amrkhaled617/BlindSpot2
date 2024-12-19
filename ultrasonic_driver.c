#include "ultrasonic_driver.h"
#include "pico/stdlib.h"

// Function to measure distance using ultrasonic sensor
float measure_distance() {
    gpio_put(TRIG_PIN, 1);
    sleep_us(10);
    gpio_put(TRIG_PIN, 0);

    while (gpio_get(ECHO_PIN) == 0);  // Wait for Echo to go HIGH
    absolute_time_t start_time = get_absolute_time();
    while (gpio_get(ECHO_PIN) == 1);  // Wait for Echo to go LOW
    absolute_time_t end_time = get_absolute_time();

    int64_t pulse_duration = absolute_time_diff_us(start_time, end_time);
    return (pulse_duration * 0.034) / 2.0;  // Distance in cm
}
void init_ultrasonic(int trig_pin, int echo_pin) {
    gpio_init(TRIG_PIN);
    gpio_init(ECHO_PIN);
    gpio_set_dir(TRIG_PIN, GPIO_OUT);
    gpio_set_dir(ECHO_PIN, GPIO_IN);

}
