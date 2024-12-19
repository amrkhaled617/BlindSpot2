#include "motor_driver2.h"
#include "hardware/pwm.h"


void motor2_init(void) {
    gpio_init(MOTOR2_DIR_PIN1);
    gpio_set_dir(MOTOR2_DIR_PIN1, GPIO_OUT);
    gpio_init(MOTOR2_DIR_PIN2);
    gpio_set_dir(MOTOR2_DIR_PIN2, GPIO_OUT);

    gpio_set_function(MOTOR2_PWM_PIN, GPIO_FUNC_PWM);

    uint slice_num = pwm_gpio_to_slice_num(MOTOR2_PWM_PIN);

    pwm_set_wrap(slice_num, 255);
    pwm_set_clkdiv(slice_num, 4.0f);

    pwm_set_enabled(slice_num, true);
}

void motor2_control(uint16_t speed, bool forward) {
    if(speed > 255) speed = 255;
    if(speed == 0) {
        pwm_set_enabled(pwm_gpio_to_slice_num(MOTOR2_PWM_PIN), false);
        gpio_put(MOTOR2_DIR_PIN1, 0);
        gpio_put(MOTOR2_DIR_PIN2, 0);
        return;
    }
    if (forward) {
        gpio_put(MOTOR2_DIR_PIN1, 1);
        gpio_put(MOTOR2_DIR_PIN2, 0);
    } else {
        gpio_put(MOTOR2_DIR_PIN1, 0);
        gpio_put(MOTOR2_DIR_PIN2, 1);
    }

    pwm_set_gpio_level(MOTOR2_PWM_PIN, speed);
    
}