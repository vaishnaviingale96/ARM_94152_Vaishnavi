/*
 * ext_intr.c
 *
 *  Created on: Dec 18, 2025
 *      Author: kiran_z6dopa8
 */


#include "ext_intr.h"

/*
 * volatile ensures main() always sees updates
 * made by the ISR
 */
volatile int ext_flag = 0;

void extint_init(void)
{
    RCC->AHB1ENR |= BV(0);   // Enable GPIOA clock

    GPIOA->MODER &= ~(BV(0) | BV(1));  // PA0 input
    GPIOA->PUPDR &= ~(BV(0) | BV(1));  // No pull-up/down

    /* Map PA0 to EXTI0 */
    SYSCFG->EXTICR[0] &= ~(BV(0) | BV(1) | BV(2) | BV(3));

    EXTI->IMR  |= BV(0);    // Unmask EXTI0
    EXTI->RTSR &= ~BV(0);   // Disable rising edge
    EXTI->FTSR |=  BV(0);   // Enable falling edge

    NVIC_EnableIRQ(EXTI0_IRQn);
}

void EXTI0_IRQHandler(void)
{
    /* Clear pending interrupt */
    EXTI->PR |= BV(0);

    /* ISR only sets software flag */
    ext_flag = 1;
}
