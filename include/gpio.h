#pragma once

#include "peripherals/gpio.h"

typedef enum _GpioFunc {
    GPIO_IN = 0,
    GPIO_OUT = 1,
    GPIO_ALTFN_0 = 4,
    GPIO_ALTFN_1 = 5,
    GPIO_ALTFN_2 = 6,
    GPIO_ALTFN_3 = 7,
    GPIO_ALTFN_4 = 3,
    GPIO_ALTFN_5 = 2,
} GpioFunc;

void gpio_pin_set_func(u8 pinNumber, GpioFunc func);

void gpio_pin_enable(u8 pinNumber);