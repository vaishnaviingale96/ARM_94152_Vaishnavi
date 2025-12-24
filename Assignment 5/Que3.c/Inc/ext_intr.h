/*
 * ext_intr.h
 *
 *  Created on: Dec 18, 2025
 *      Author: kiran_z6dopa8
 */

#ifndef EXT_INTR_H
#define EXT_INTR_H

#include "stm32f4xx.h"

#define BV(x) (1U << (x))

void extint_init(void);

/*
 * Software flag shared between ISR and main
 * Must be volatile because it is modified inside ISR
 */
extern volatile int ext_flag;

#endif
