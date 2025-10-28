/*
 * gpio.c
 *
 * FOR SSS SOFTWARE FALL 2025 TRAINING
 *
 *  Created on: Sep 21, 2025
 *      Author: nithinsenthil
 */

#include "gpio_training.h"

void gpio_toggle(GPIO_TypeDef *port, int pin) {
	// Sets it to opposite (on -> off) and (off -> on)
	*(volatile uint32_t *)(0x4001100C) ^= (1 << 13);
}

void gpio_set(GPIO_TypeDef *port, int pin, GPIO_VALUE value) {
	// Check the state of the current GPIO
    if (value == GPIO_HIGH) {
    	*(volatile uint32_t *)(0x4001100C) |= (1 << 13);
    } else {
    	*(volatile uint32_t *)(0x4001100C) &= ~(1 << 13);
    }
}

void gpio_configureMode(GPIO_TypeDef *port, int pin, GPIO_CNF cnf, GPIO_MODE mode) {
	int *reg = (pin < 8) ? &port->CRL : &port->CRH;
	*(reg) = (*(reg) & ~(0xF << ((pin % 8) * 4))) | (((cnf << 2) | mode) << ((pin % 8) * 4));
}

/*
 * Please don't modify — this one just enables GPIO clocks :)
 */
void rcc_enable(RCC_SELECT reg) {
    RCC->APB2ENR |= reg;
}
