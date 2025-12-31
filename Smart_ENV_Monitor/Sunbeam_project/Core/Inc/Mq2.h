/*
 * mq2.h
 *
 *  Created on: Dec 30, 2025
 *      Author: anjal
 */

#ifndef MQ2_H
#define MQ2_H

#include "stm32f4xx_hal.h"
void mq2_Init(ADC_HandleTypeDef* hadc1);
uint16_t mq2_Read();
#endif
