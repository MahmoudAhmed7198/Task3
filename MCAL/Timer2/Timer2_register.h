/*
 * Timer2_register.h
 *
 *  Created on: Oct 25, 2023
 *      Author: Lenovo
 */

#ifndef MCAL_TIMER2_TIMER2_REGISTER_H_
#define MCAL_TIMER2_TIMER2_REGISTER_H_
#include"../../Std_Types.h"
//define timer2 registers

#define TCCR2_reg *((volatile uint8_t*)(0x45))
#define TCNT2_reg *((volatile uint8_t*)(0x44))
#define OCR2_reg  *((volatile uint8_t*)(0x43))
#define TIMSK_reg *((volatile uint8_t*)(0x59))
#define TIFR_reg  *((volatile uint8_t*)(0x58))

//define bits of these registers
//1-bits of TCCR2 register
#define CS20  0
#define CS21  1
#define CS22  2
#define WGM21 3
#define COM20 4
#define COM21 5
#define WGM20 6
#define FOC2  7

//2-bits of TIMSK register
#define TOIE2 6
#define OCIE2 7

//3-bits of TIFR_register
#define TOV2 6
#define OCF2 7






#endif /* MCAL_TIMER2_TIMER2_REGISTER_H_ */
