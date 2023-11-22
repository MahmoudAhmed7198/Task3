/*
 * Timer0_register.h
 *
 *  Created on: Oct 23, 2023
 *      Author: Lenovo
 */

#ifndef MCAL_TIMER_0_TIMER0_REGISTER_H_
#define MCAL_TIMER_0_TIMER0_REGISTER_H_

#include"../../Std_Types.h"
//Timer0 registers
#define OCR0_reg  *((volatile uint8_t*)(0x5C))
#define TIMSK_reg *((volatile uint8_t*)(0x59))
#define TIFR_reg  *((volatile uint8_t*)(0x58))
#define TCCR0_reg *((volatile uint8_t*)(0x53))
#define TCNT0_reg *((volatile uint8_t*)(0x52))


//register bits
//TIMSK register bits
#define TOIE0 0
#define OCIE0 1

//TIFR register bits
#define TOV0  0
#define OCF0  1

//TCCR0 register bits
#define CS00  0
#define CS01  1
#define CS02  2
#define WGM01 3
#define COM00 4
#define COM01 5
#define WGM00 6
#define FOC0  7



#endif /* MCAL_TIMER_0_TIMER0_REGISTER_H_ */
