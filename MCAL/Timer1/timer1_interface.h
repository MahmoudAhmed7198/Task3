/*
 * timer1_interface.h
 *
 *  Created on: Oct 29, 2023
 *      Author: Lenovo
 */

#ifndef MCAL_TIMER1_TIMER1_INTERFACE_H_
#define MCAL_TIMER1_TIMER1_INTERFACE_H_

#include"../../Std_Types.h"
void Timer1_init(void);
void Timer1_start();
void Timer1_stop();
void set_compare_match_A(u16 comapre);
void set_frequency(u16 freq); //mode14,, under condition 4us
void set_duty(f32_t d);    //mode14






#endif /* MCAL_TIMER1_TIMER1_INTERFACE_H_ */
