/*
 * mq2.c
 *
 *  Created on: Dec 30, 2025
 *      Author: anjal
 */
#include "mq2.h"
#include "stm32f4xx_hal.h"
extern ADC_HandleTypeDef hadc1;


int val;

uint16_t mq2_Read()

{
	HAL_ADC_Start(&hadc1);
	HAL_ADC_PollForConversion(&hadc1, HAL_MAX_DELAY);
	val = HAL_ADC_GetValue(&hadc1);
	HAL_ADC_Stop(&hadc1);
	return val;

}
