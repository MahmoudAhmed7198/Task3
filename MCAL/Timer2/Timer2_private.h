/*
 * Timer2_private.h
 *
 *  Created on: Oct 25, 2023
 *      Author: Lenovo
 */

#ifndef MCAL_TIMER2_TIMER2_PRIVATE_H_
#define MCAL_TIMER2_TIMER2_PRIVATE_H_
//private.h takes private macros used in cfg.h and can takes registers
#define TIMER2_OVF_MODE     1
#define TIMER2_CTC_MODE     2
#define TIMER2_FASTPWM      3
#define TIMER2_PHASECORRECT 4

#define PRESCALER_8           1
#define PRESCALER_32          2
#define PRESCALER_64          3
#define PRESCALER_128         4
#define PRESCALER_256         5
#define PRESCALER_1024        6


//modes of Fast PWM and phase correct
#define INVERTING_MODE     1
#define NON_INVERTONG_MODE 2




#endif /* MCAL_TIMER2_TIMER2_PRIVATE_H_ */
