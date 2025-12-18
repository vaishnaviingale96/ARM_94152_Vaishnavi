/*
 * gpio.h
 *
 *  Created on: Dec 18, 2025
 *      Author: hp
 */

#ifndef gpio
#define gpio

#include <stdint.h>
#include <stdio.h>
#include"stm32f407xx.h"

#define BV(n) (1 << (n))

void led_init(void);
int button(void);

void led_on(void);
void led_off(void);

#endif
