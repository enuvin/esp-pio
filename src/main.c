#include <driver/gpio.h>
#include <driver/uart.h>
// Include FreeRTOS for delay
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include<stdio.h>
int app_main() {
    uart_config_t uart_config = {
        .baud_rate = 115200,
        .data_bits = UART_DATA_8_BITS,
        .parity    = UART_PARITY_DISABLE,
        .stop_bits = UART_STOP_BITS_1,
        .flow_ctrl = UART_HW_FLOWCTRL_DISABLE
    };
    uart_driver_install(UART_NUM_0, 2048, 0, 0, NULL, 0);
    uart_param_config(UART_NUM_0, &uart_config);
    uart_set_pin(UART_NUM_0, 10, 9, UART_PIN_NO_CHANGE, UART_PIN_NO_CHANGE);
    // Main loop
    while(true) {
        uart_write_bytes(UART_NUM_0, "CAFE", 4);
        vTaskDelay(100 / portTICK_RATE_MS);
        printf("Cafe-printf\n");
    }
}