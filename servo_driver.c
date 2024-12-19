#include "servo_driver.h"
#include "pico/stdlib.h"

// Function to set the angle of the servo motor
void servo_motor_set_angle(uint servo_pin, uint angle) {
    uint16_t pulse_width = (angle * 1000 / 180) + 1000; // 1000-2000 microseconds

    // Send PWM signal to the servo
    gpio_put(servo_pin, 1);
    sleep_us(pulse_width);
    gpio_put(servo_pin, 0);
    sleep_us(20000 - pulse_width); // Wait for the rest of the 20ms period
}
void init_servo(uint servo_pin) {
    gpio_init(SERVO_PIN);
    gpio_set_dir(SERVO_PIN, GPIO_OUT);
}