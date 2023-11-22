/*
 * timer1_register.h
 *
 *  Created on: Oct 29, 2023
 *      Author: Lenovo
 */

#ifndef MCAL_TIMER1_TIMER1_REGISTER_H_
#define MCAL_TIMER1_TIMER1_REGISTER_H_

#define TCCR1A_reg *((volatile uint8_t*)(0x4F))
#define TCCR1B_reg *((volatile uint8_t*)(0x4E))
#define TCNT1_reg  *((volatile u16*)(0x4C))
#define OCR1A_reg  *((volatile u16*)(0x4A))
#define OCR1B_reg  *((volatile u16*)(0x48))
#define ICR1_reg   *((volatile u16*)(0x46))
#define TIMSK_reg  *((volatile uint8_t*)(0x59))
#define TIFR_reg   *((volatile uint8_t*)(0x58))

//TCCR1A register bits
#define WGM10 	0
#define WGM11 	1
#define FOC1B 	2
#define FOC1A 	3
#define COM1B0 	4
#define COM1B1 	5
#define COM1A0 	6
#define COM1A1 	7

//TCCR1B register bits
#define CS11  1
#define CS10  0
#define CS12  2
#define WGM12 3
#define WGM13 4






#endif /* MCAL_TIMER1_TIMER1_REGISTER_H_ */
