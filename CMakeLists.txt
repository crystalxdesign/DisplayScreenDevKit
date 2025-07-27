cmake_minimum_required(VERSION 3.14)
set(PICO_BOARD pico)

include(pico_sdk_import.cmake)
project(ST7567_example VERSION 1.0.0)

set(PICO_CXX_ENABLE_EXCEPTIONS 1)

set(PICO_CXX_ENABLE_RTTI 1)

pico_sdk_init()

add_executable(${PROJECT_NAME}
    src/main.cpp
    src/HCDisplay.cpp
    src/demos.cpp
)

pico_enable_stdio_usb(${PROJECT_NAME} 1)
pico_enable_stdio_uart(${PROJECT_NAME} 1)
pico_add_extra_outputs(${PROJECT_NAME})

target_link_libraries(${PROJECT_NAME}
    pico_stdlib
    pico_time
    hardware_gpio
    hardware_spi
)

target_include_directories(${PROJECT_NAME} PUBLIC
    inc
)
