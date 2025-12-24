/*
 * my_led.h
 *
 *  Created on: Dec 17, 2025
 *      Author: kiran_z6dopa8
 */

#ifndef MY_LED_H
#define MY_LED_H

#include "stm32f4xx.h"
#include <stdint.h>

#define BV(x) (1U << (x))
#define LED_PORT GPIOD

void led_init(void);
void led_on(uint8_t pin);
void led_off(uint8_t pin);
void led_toggle(uint8_t pin);

#endif
