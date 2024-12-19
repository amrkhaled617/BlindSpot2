
// #include <stdio.h>
// #include "pico/stdlib.h"
// #include "servo_driver.h"     // Ensure this file exists and contains the function servo_motor_set_angle
// #include "ultrasonic_driver.h" // Ensure this file exists and contains the function measure_distance
// #include "buzzer_driver.h"     // Ensure this file exists and contains the functions buzzer_on and buzzer_off
// #include "infrared_driver.h"   // Ensure this file exists and contains the function is_infrared_triggered
// #include "light_driver.h"      // Ensure this file exists and contains the function is_light_triggered
// #include "motor_driver.h"      // Ensure this file exists and contains the functions motor_init and motor_control
// #include <FreeRTOS.h>
// #include <task.h>
// #include <queue.h>
// #include <timers.h>
// #include <semphr.h>

// // Pin assignments

// const uint LED_PIN = 6;

// // Mapping function for servo angle based on distance

// // Task handles
// // TaskHandle_t motorTaskHandle = NULL;
// // TaskHandle_t buzzerTaskHandle = NULL;
// // TaskHandle_t lightTaskHandle = NULL;
// // void light_task(void *pvParameters);

// // Motor control task
// // void motor_task(void *pvParameters) {
// //     while (true) {
// //         motor_control(60, true);
// //         vTaskDelay(pdMS_TO_TICKS(100)); // Delay for 100 ms
// //     }
// // }


// // // Buzzer control task
// // void buzzer_task(void *pvParameters) {
// //     while (true) {
// //         float distance = measure_distance();
// //         if (distance <= 5) {
// //             printf("Distance lower than 5\n");
// //             motor_control(0, true);
// //             buzzer_on(BUZZER_PIN);
// //             vTaskDelay(pdMS_TO_TICKS(10000)); // Delay for 10 seconds
// //             buzzer_off(BUZZER_PIN);
// //         } else if (distance >= 5 && distance <= 15) {
// //             buzzer_on(BUZZER_PIN);
// //             vTaskDelay(pdMS_TO_TICKS(50)); // Delay for 50 ms
// //             buzzer_off(BUZZER_PIN);
// //             vTaskDelay(pdMS_TO_TICKS(50)); // Delay for 50 ms
// //         }

// //         if (is_infrared_triggered(INFRARED_PIN)) {
// //             buzzer_on(BUZZER_PIN);
// //             printf("Infrared sensor triggered! buzzer ON\n");
// //         } else {
// //             buzzer_off(BUZZER_PIN);
// //             printf("Infrared sensor not triggered. buzzer OFF\n");
// //         }

// //         vTaskDelay(pdMS_TO_TICKS(100)); // Delay for 100 ms
// //     }
// // }

// // Light control task
// void light_task(void *pvParameters) {
//     vTaskDelay(pdMS_TO_TICKS(100));  // Ensure hardware is initialized
//     init_buzzer(BUZZER_PIN);
//     printf("Buzzer initialized\n");

//     while (true) {
//         buzzer_on(BUZZER_PIN);  
//         printf("Buzzer on\n");
//         vTaskDelay(pdMS_TO_TICKS(1000));  // Delay for 1 second
//     }
// }
// // Hook function for memory allocation failure
// void vApplicationMallocFailedHook(void) {
//     // Handle memory allocation failure
//     printf("Memory allocation failed!\n");
//     taskDISABLE_INTERRUPTS();
//     for(;;);
// }

// // Hook function for stack overflow
// void vApplicationStackOverflowHook(TaskHandle_t xTask, char *pcTaskName) {
//     // Handle stack overflow
//     printf("Stack overflow in task %s!\n", pcTaskName);
//     taskDISABLE_INTERRUPTS();
//     for(;;);
// }

// int main() {
//     stdio_init_all();

//     // Initialize pins


//     // init_buzzer(BUZZER_PIN);
//     // buzzer_on(BUZZER_PIN);
//     // init_infrared(INFRARED_PIN);
//     // init_light(LIGHT_PIN);
//     // init_ultrasonic(TRIG_PIN, ECHO_PIN);
//     // motor_init();
//     xTaskCreate(light_task, "Light Task", 512, NULL, 1, NULL);
//     // xTaskCreate( vErrorChecks, "Check", configMINIMAL_STACK_SIZE, NULL, mainCHECK_TASK_PRIORITY, NULL );

//     // Create tasks
//     // xTaskCreate(motor_task, "Motor Task", 256, NULL, 1, &motorTaskHandle);
//     // xTaskCreate(buzzer_task, "Buzzer Task", 256, NULL, 1, &buzzerTaskHandle);
//     // xTaskCreate(light_task, "Light Task", 256, NULL, 1, &lightTaskHandle);

//     // Start the scheduler
//     vTaskStartScheduler();
//     // Should never reach here
//     while (true) {
//     }
// }

#include <stdio.h>
#include "pico/stdlib.h"
#include "servo_driver.h"     // Ensure this file exists and contains the function servo_motor_set_angle
#include "ultrasonic_driver.h" // Ensure this file exists and contains the function measure_distance
#include "buzzer_driver.h"     // Ensure this file exists and contains the functions buzzer_on and buzzer_off
#include "infrared_driver.h"   // Ensure this file exists and contains the function is_infrared_triggered
#include "light_driver.h"      // Ensure this file exists and contains the function is_light_triggered
#include "motor_driver.h"      // Ensure this file exists and contains the functions motor_init and motor_control
#include "motor_driver2.h"     // Ensure this file exists and contains the functions motor2_init and motor2_control
#include <FreeRTOS.h>
#include <task.h>

// Pin assignments
const uint LED_PIN = 6;

// Mapping function for servo angle based on distance
int map_value(int value, int in_min, int in_max, int out_min, int out_max) {
    return (value - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}





int main() {
    stdio_init_all();

    // Initialize pins
    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);

    init_buzzer(BUZZER_PIN);
        
    init_infrared(INFRARED_PIN);

    init_light(LIGHT_PIN);

    init_servo(SERVO_PIN);

    init_ultrasonic(TRIG_PIN, ECHO_PIN);

    motor_init();
    motor2_init();
    bool flag = false;
    while (true) {
        motor_control(60, true);
        motor2_control(60, true);

        float distance = measure_distance();
        printf("Distance: %.2f cm\n", distance);

        // // Map distance to servo angle (e.g., 0 cm = 0°, 100 cm = 180°)
        // int angle = map_value((int)distance, 0, 100, 0, 180);
        // servo_motor_set_angle(SERVO_PIN, angle);
        // sleep_ms(100);

        // Activate buzzer based on distance
        if (distance <= 5) {
            printf("Distance lower than 5\n");
            motor2_control(0, true);
            motor_control(0, true);
            buzzer_on(BUZZER_PIN);
            sleep_ms(1000);
            buzzer_off(BUZZER_PIN);
            sleep_ms(2000);
        } else if (distance >= 5 && distance <= 15) {
            buzzer_on(BUZZER_PIN);
            sleep_ms(50);
            buzzer_off(BUZZER_PIN);
            sleep_ms(50);
        }

        // Handle infrared sensor
        if (is_infrared_triggered(INFRARED_PIN)) {
            buzzer_on(BUZZER_PIN);
            printf("Infrared sensor triggered! buzzer ON\n");
        } else {
            buzzer_off(BUZZER_PIN);
            printf("Infrared sensor not triggered. buzzer OFF\n");
        }

        // Handle light sensor
        if (is_light_triggered(LIGHT_PIN)) {
            gpio_put(LED_PIN, true);
        } else {
            gpio_put(LED_PIN, false);
        }

        sleep_ms(100); // Add a delay before the next loop
    }
}
