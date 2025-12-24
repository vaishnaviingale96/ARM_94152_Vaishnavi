/*
 * ext_intr.h
 *
 *  Created on: Dec 18, 2025
 *      Author: kiran_z6dopa8
 */

#ifndef __EXT_INTR_H
#define __EXT_INTR_H

#include "stm32f4xx.h"

/* extern declaration */
extern volatile int ext_flag;

void extint_init(void);

#endif
