/*
 * main_training.c
 *
 *  Created on: Sep 22, 2025
 *      Author: dilgill
 */

#include "stm32f1xx.h"
#include "gpio_training.h"
#include "main.h"
#include <stdbool.h>

#define LED_PORT GPIOC
#define LED_PIN  13

int main(void) {
    setup_training();
    rcc_enable(GPIO_C_ENABLE);
    rcc_enable(GPIO_A_ENABLE);
    gpio_configureMode(LED_PORT, LED_PIN, GPIO_OUTPUT_PUSH_PULL, GPIO_LOW_SPEED);
    for (int i = 0; i < 4; i++) {
        gpio_toggle(LED_PORT, LED_PIN);  // LED OFF
        HAL_Delay(1000);
    }
    while (true) {
        gpio_toggle(LED_PORT, LED_PIN);         // Toggle LED
        HAL_Delay(450);
    }
}
