/*
 * Timer0_interface.h
 *
 *  Created on: Oct 23, 2023
 *      Author: Lenovo
 */

#ifndef MCAL_TIMER_0_TIMER0_INTERFACE_H_
#define MCAL_TIMER_0_TIMER0_INTERFACE_H_





//timer0 functions prototype

void Timer0_init(void);
void Timer0_start();
void Timer0_stop();
void Timer0_setCallBack(void (*ptrToFun)(void));
void set_compare_match(uint8_t comapre);
void Timer0_voidSetDelayCTC(u16 delay_ms);
void Timer0_set_duty_cycleFastPWM(uint8_t d);
void Timer0_set_duty_cyclePhaseCorrect(uint8_t d);


#endif /* MCAL_TIMER_0_TIMER0_INTERFACE_H_ */
