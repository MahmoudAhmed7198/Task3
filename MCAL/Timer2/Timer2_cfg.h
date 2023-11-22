/*
 * Timer2_cfg.h
 *
 *  Created on: Oct 25, 2023
 *      Author: Lenovo
 */

#ifndef MCAL_TIMER2_TIMER2_CFG_H_
#define MCAL_TIMER2_TIMER2_CFG_H_
//FCPU=16MHZ, prescaler=64, Ftimer=16MHZ/64=250KHZ, Ttimer=1/250KHZ=4us(1 tick timer)
//1overflow occurs after 256ticks in case of timer2(8bit resolution)
//Time for 1 overflow = tick time*(TCNT0+1)=(256) = 1024us
//to generate 1 second we need 976.56 overflow
//1- need counter increments after every overflow for 976 overflow
//2- 1ovf=256tick, 0.56ovf=0.56*256=143ticks, preload=256-143=113
//3-total number of overflows to generate 1 second 976+1(preload) = 977
//Ttimer=4us, Toverflow=Ttimer*(OCR0+1)=4us*(249+1)=1000us
//To generate 1.5 second using CTC mode 1.5second=1500000us
//1OVF=1000us ,,, 1500000us=?  #of overflows=1500000/1000=1500overflows=1500interrupts

/*Macros for timer2 modes options
 *1-TIMER2_OVF_MODE
 *2-TIMER2_CTC_MODE
 *3-TIMER2_FASTPWM
 *4-TIMER2_PHASECORRECT
 */
#define TIMER2_PRELOAD       113
#define TIMER2_OVF_COUNTER   977
#define TIMER2_MODE          TIMER2_PHASECORRECT

/*Macros for prescaler mode options
 *1-PRESCALER_8
 *2-PRESCALER_32
 *3-PRESCALER_64
 *4-PRESCALER_128
 *5-PRESCALER_256
 *6-PRESCALER_1024*/
#define PRESCALER_MODE      PRESCALER_64

/*modes in Fast PWM and Phase Correct
 * 1-NON_INVERTONG_MODE
 * 2-INVERTING_MODE*/
#define TIMER2_FASTPWM_MODE         NON_INVERTONG_MODE
#define TIMER2_PHASECORRECT_MODE    NON_INVERTONG_MODE

#endif /* MCAL_TIMER2_TIMER2_CFG_H_ */
