/*
 * timer1_program.c
 *
 *  Created on: Oct 29, 2023
 *      Author: Lenovo
 */

#include"../../Std_Types.h"
#include"../../Bit_Math.h"
#include"timer1_interface.h"
#include"timer1_Cfg.h"
#include"timer1_private.h"
#include"timer1_register.h"

void Timer1_init(void)
{
	//select mode fast PWM and non inverting

#if TIMR1_MODE == FASTPWM_MODE14
	CLR_BIT(TCCR1A_reg,WGM10);
	SET_BIT(TCCR1A_reg,WGM11);
	SET_BIT(TCCR1B_reg,WGM12);
	SET_BIT(TCCR1B_reg,WGM13);
	SET_BIT(TCCR1A_reg,COM1A1);
	CLR_BIT(TCCR1A_reg,COM1A0);

	//set ICR1
	//ICR1_reg= 4999;       //set top of timer1 (4us tick time) then Tp=20ms, frequency=50HZ
	//use set_freq instead    499 249 374


#endif

}
void Timer1_start()
{
  #if TMR1_PRESCALER_64==PRESCALER_64
	  SET_BIT(TCCR1B_reg,CS10);
	  SET_BIT(TCCR1B_reg,CS11);
	  CLR_BIT(TCCR1B_reg,CS12);

#endif

}
void Timer1_stop()
{
	CLR_BIT(TCCR1B_reg,CS10);
	CLR_BIT(TCCR1B_reg,CS11);
	CLR_BIT(TCCR1B_reg,CS12);

}
void set_compare_match_A(u16 comapre)
{
	OCR1A_reg=comapre;
}
void set_frequency(u16 freq)
{
//take frequency HZ
	ICR1_reg=((1000000UL/freq)/4)-1;//time with us 1000000/50=20000/4=5000-1=4999
}

void set_duty(f32_t d)
{
	//non_inverting
	if(d<=100)
	OCR1A_reg=((d*(ICR1_reg+1))/100)-1;
	//inverting

}
