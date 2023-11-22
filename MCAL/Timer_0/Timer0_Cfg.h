/*
 * Timer0_Cfg.h
 *
 *  Created on: Oct 23, 2023
 *      Author: Lenovo
 */

#ifndef MCAL_TIMER_0_TIMER0_CFG_H_
#define MCAL_TIMER_0_TIMER0_CFG_H_


/*options for timer0
 *1-TMR0_NORMAL_MODE
 *2-TIMER0_CTC_MODE
 *3-TIMER0_FASTPWM
 *4-TIMER0_PHASECORRECT
 * */
#define Timer0_PreLoad   113
#define Timer0_counter 	 977
#define TMR0_MODE      TMR0_CTC_MODE

/*Macros for prescaler mode options
 *1-PRESCALER_8
 *2-PRESCALER_32
 *3-PRESCALER_64
 *4-PRESCALER_128
 *5-PRESCALER_256
 *6-PRESCALER_1024*/
#define PRESCALER_MODE     PRESCALER_64

/*modes in Fast PWM and Phase Correct
 * 1-NON_INVERTONG_MODE
 * 2-INVERTING_MODE*/
#define TIMER0_FASTPWM_MODE         INVERTING_MODE
#define TIMER0_PHASECORRECT_MODE    INVERTING_MODE



#endif /* MCAL_TIMER_0_TIMER0_CFG_H_ */
