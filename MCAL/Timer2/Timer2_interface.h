/*
 * Timer2_interface.h
 *
 *  Created on: Oct 25, 2023
 *      Author: Lenovo
 */

#ifndef MCAL_TIMER2_TIMER2_INTERFACE_H_
#define MCAL_TIMER2_TIMER2_INTERFACE_H_
//interface macro is public macros can be used by higher layers
//prototypes of functions
void Timer2_init();
void Timer2_startTimer();
void Timer2_stopTimer();
void set_callBackOVF(void (*ptrToFun)(void));
void set_callBackCTC(void (*ptrToFun)(void));
void set_compare_value();
void set_delay_usingCTC(u16 delay_ms);
void set_duty_cycleUsingFastPWM(uint8_t duty_cycle);//duty represent duty percentage
void set_duty_cycleUsingPhaseCorrect(uint8_t duty);
#endif /* MCAL_TIMER2_TIMER2_INTERFACE_H_ */
