/*
 * my_led.c
 *
 *  Created on: Dec 17, 2025
 *      Author: kiran_z6dopa8
 */
#include "my_led.h"

void led_init(void)
{
    /* Enable clock for GPIOD */
    RCC->AHB1ENR |= BV(3);

    /* PD12 as output */
    LED_PORT->MODER &= ~(BV(25) | BV(24));
    LED_PORT->MODER |=  BV(24);

    /* Push-pull */
    LED_PORT->OTYPER &= ~BV(12);

    /* Low speed */
    LED_PORT->OSPEEDR &= ~(BV(25) | BV(24));

    /* No pull-up/down */
    LED_PORT->PUPDR &= ~(BV(25) | BV(24));
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
