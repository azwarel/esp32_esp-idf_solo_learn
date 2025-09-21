#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"

#define BLINK_GPIO 48  // Ganti dengan GPIO yang sesuai

void blink_task(void *pvParameter)
{
    gpio_set_direction(BLINK_GPIO, GPIO_MODE_OUTPUT);

    while (1) {
        gpio_set_level(BLINK_GPIO, 1); // LED ON
        vTaskDelay(5000 / portTICK_PERIOD_MS);
        gpio_set_level(BLINK_GPIO, 0); // LED OFF
        vTaskDelay(5000 / portTICK_PERIOD_MS);
    }
}

void app_main(void)
{
    xTaskCreate(&blink_task, "blink_task", 1024, NULL, 5, NULL);
}