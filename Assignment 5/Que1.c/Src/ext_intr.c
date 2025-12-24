/*
 * ext_intr.c
 *
 *  Created on: Dec 18, 2025
 *      Author: kiran_z6dopa8
 */


#include "ext_intr.h"
#include "my_led.h"

/* ✅ ONLY definition */
volatile int ext_flag = 0;

void extint_init(void)
{
    RCC->AHB1ENR |= BV(0);

    GPIOA->MODER &= ~(BV(0) | BV(1));
    GPIOA->PUPDR &= ~(BV(0) | BV(1));

    SYSCFG->EXTICR[0] &= ~(BV(0) | BV(1) | BV(2) | BV(3));

    EXTI->IMR |= BV(0);

    /* Trigger on RELEASE (falling edge) */
    EXTI->RTSR &= ~BV(0);
    EXTI->FTSR |=  BV(0);

    NVIC_EnableIRQ(EXTI0_IRQn);
}

void EXTI0_IRQHandler(void)
{
    EXTI->PR |= BV(0);
    ext_flag = 1;
}
