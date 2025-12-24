/*
 * my_led.c
 *
 *  Created on: Dec 17, 2025
 *      Author: kiran_z6dopa8
 */

#include "my_led.h"

void led_init(void)
{
    RCC->AHB1ENR |= BV(3);        // Enable GPIOD clock

    LED_PORT->MODER &= ~(BV(24) | BV(25));
    LED_PORT->MODER |=  BV(24);  // PD12 as output

    LED_PORT->OTYPER &= ~BV(12); // Push-pull
    LED_PORT->OSPEEDR &= ~(BV(24) | BV(25));
    LED_PORT->PUPDR &= ~(BV(24) | BV(25));
}

void led_on(uint8_t pin)
{
    LED_PORT->ODR |= BV(pin);
}

void led_off(uint8_t pin)
{
    LED_PORT->ODR &= ~BV(pin);
}

void led_toggle(uint8_t pin)
{
    LED_PORT->ODR ^= BV(pin);
}
