#include "common.h"
#include "mini_uart.h"
#include "gpio.h"
#include "printf_custom.h"

#define RESET_PIN 26

void putc(void *p, char c) {
    if (c =='\n') {
        uart_send('\r');
    }
    uart_send(c);
}

u32 get_el();

void kernel_main() {
    uart_init();
    init_printf(0, putc);
    printf("Raspberry Pi Bare Metal OS Initializing...\n");

    printf("GPIO Pin 26 is being used as a RESET!\n");
    
    // TODO init GPIO for using pin 26 as interrupt ?????
    // gpio_pin_set_func(RESET_PIN, GPIO_IN);
    // gpio_pin_enable(RESET_PIN);
    // REGS_GPIO->lo_detect_enable = ;

#if RPI_VERSION == 3
    uart_send_string("\nBoard: Raspberry Pi 3 \n");
#elif RPI_VERSION == 4
    uart_send_string("\nBoard: Raspberry Pi 4 \n");
#endif

    printf("\n\nException Level: %d\n", get_el());

    // just echo for now...
    while (1)
    {
        uart_send(uart_recv());
    }
    
}