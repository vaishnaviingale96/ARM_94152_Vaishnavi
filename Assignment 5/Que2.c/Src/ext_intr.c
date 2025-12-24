/*
 * ext_intr.c
 *
 *  Created on: Dec 18, 2025
 *      Author: kiran_z6dopa8
 */


#include "ext_intr.h"

/*
 * volatile is required because ext_flag is modified inside ISR.
 * Without volatile, compiler may cache the value in a register,
 * and main() may never see the update done by ISR.
 */
volatile int ext_flag = 0;

void extint_init(void)
{
    RCC->AHB1ENR |= BV(0);   // Enable GPIOA clock

    GPIOA->MODER &= ~(BV(0) | BV(1));   // PA0 as input
    GPIOA->PUPDR &= ~(BV(0) | BV(1));   // No pull-up/down

    SYSCFG->EXTICR[0] &= ~(BV(0) | BV(1) | BV(2) | BV(3)); // PA0 -> EXTI0

    EXTI->IMR  |= BV(0);    // Unmask EXTI0
    EXTI->RTSR &= ~BV(0);   // Disable rising edge
    EXTI->FTSR |=  BV(0);   // Enable falling edge

    NVIC_EnableIRQ(EXTI0_IRQn);
}

void EXTI0_IRQHandler(void)
{
    EXTI->PR |= BV(0);  // Clear pending interrupt

    /* ISR ONLY sets the software flag */
    ext_flag = 1;
}
