/*
 * mq2.c
 *
 *  Created on: Dec 30, 2025
 *      Author: aupat
 */

#include "mq2.h"
#include "stm32f4xx_hal.h"
#include <stdio.h>
#include "my_lcd.h"

#define SMOKE_THRESHOLD 200

uint32_t mq2_value(uint32_t adc_raw)
{
    uint32_t adc_val = adc_raw / 10;

    if (adc_val > SMOKE_THRESHOLD)
    {
        HAL_Delay(500);
        lcd16x2_i2c_setCursor(0, 0);
        HAL_Delay(500);
        lcd16x2_i2c_printf("Alert PPM :");
        HAL_Delay(500);
        HAL_GPIO_WritePin(GPIOD, GPIO_PIN_12, GPIO_PIN_SET);
        HAL_GPIO_WritePin(GPIOD, GPIO_PIN_13, GPIO_PIN_SET);
        HAL_GPIO_WritePin(GPIOD, GPIO_PIN_14, GPIO_PIN_SET);
        HAL_GPIO_WritePin(GPIOD, GPIO_PIN_15, GPIO_PIN_SET);
        //HAL_Delay(1000);
        //lcd16x2_i2c_clear();
    }
    else
    {
    	HAL_GPIO_WritePin(GPIOD, GPIO_PIN_12, GPIO_PIN_RESET);
    	HAL_GPIO_WritePin(GPIOD, GPIO_PIN_13, GPIO_PIN_RESET);
    	HAL_GPIO_WritePin(GPIOD, GPIO_PIN_14, GPIO_PIN_RESET);
        HAL_GPIO_WritePin(GPIOD, GPIO_PIN_15, GPIO_PIN_RESET);

        lcd16x2_i2c_clear();
        HAL_Delay(250);
        lcd16x2_i2c_setCursor(0, 0);
        HAL_Delay(250);
        lcd16x2_i2c_printf("Normal :");
    }

    return adc_val;
}

