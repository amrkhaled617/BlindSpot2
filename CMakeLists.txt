cmake_minimum_required(VERSION 3.13)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# == DO NOT EDIT THE FOLLOWING LINES for the Raspberry Pi Pico VS Code Extension to work ==
if(WIN32)
    set(USERHOME $ENV{USERPROFILE})
else()
    set(USERHOME $ENV{HOME})
endif()
set(sdkVersion 1.5.1)
set(toolchainVersion 13_2_Rel1)
set(picotoolVersion 2.0.0)
set(picoVscode ${USERHOME}/.pico-sdk/cmake/pico-vscode.cmake)
if (EXISTS ${picoVscode})
    include(${picoVscode})
endif()
# ====================================================================================
set(PICO_BOARD arduino_nano_rp2040_connect CACHE STRING "Board type")

# Pull in Raspberry Pi Pico SDK (must be before project)
include(pico_sdk_import.cmake)

# Initialise the Raspberry Pi Pico SDK (must be done after defining the board)
pico_sdk_init()

project(BlindSpot2 C CXX ASM)

# Add all driver .c files to the executable
add_executable(BlindSpot2 BlindSpot2.c
    servo_driver.c
    ultrasonic_driver.c
    buzzer_driver.c
    infrared_driver.c
    light_driver.c
    motor_driver.c
    motor_driver2.c
)

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/FreeRTOS-Kernel FreeRTOS-Kernel)

# Link FreeRTOS and necessary libraries to the executable
target_link_libraries(BlindSpot2
    pico_stdlib
    hardware_pwm
    freertos_kernel
    freertos_config
)

# Set program name and version
pico_set_program_name(BlindSpot2 "BlindSpot2")
pico_set_program_version(BlindSpot2 "0.1")

# Modify the below lines to enable/disable output over UART/USB
pico_enable_stdio_uart(BlindSpot2 0)
pico_enable_stdio_usb(BlindSpot2 1)

# Add the standard include files and driver headers to the build
target_include_directories(BlindSpot2 PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}
    # ${CMAKE_CURRENT_LIST_DIR}/drivers  # Add the path to your driver headers here
)

# Add extra outputs like UF2
pico_add_extra_outputs(BlindSpot2)
