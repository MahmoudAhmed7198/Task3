/*
 * Timer0_program.c
 *
 *  Created on: Oct 23, 2023
 *      Author: Lenovo
 */

#include"../../Bit_Math.h"
#include"../../Std_Types.h"
#include"Timer0_interface.h"
#include"Timer0_Cfg.h"
#include"Timer0_register.h"
#include"Timer0_private.h"
static void (*g_ptrToFunOVF)(void)=NULL;
volatile static u16 CTC_Counter;
void Timer0_init(void)
{
	#if TMR0_MODE == TMR0_NORMAL_MODE
		SET_BIT(TCCR0_reg,FOC0);
		CLR_BIT(TCCR0_reg,WGM00);
		CLR_BIT(TCCR0_reg,WGM01);
		//init TCNT0 with preload which is 113
		TCNT0_reg=Timer0_PreLoad;
		SET_BIT(TIMSK_reg,TOIE0);
	#elif TMR0_MODE == TMR0_CTC_MODE
		SET_BIT(TCCR0_reg,FOC0);
		CLR_BIT(TCCR0_reg,WGM00);
		SET_BIT(TCCR0_reg,WGM01);
		SET_BIT(TIMSK_reg,OCIE0);
	#elif TMR0_MODE == TMR0_FASTPWM
		#if TIMER0_FASTPWM_MODE == INVERTING_MODE
			SET_BIT(TCCR0_reg,WGM00);
			SET_BIT(TCCR0_reg,WGM01);
			SET_BIT(TCCR0_reg,COM00);
			SET_BIT(TCCR0_reg,COM01);
		#elif TIMER0_FASTPWM_MODE == NON_INVERTONG_MODE
			SET_BIT(TCCR0_reg,WGM00);
			SET_BIT(TCCR0_reg,WGM01);
			CLR_BIT(TCCR0_reg,COM00);
			SET_BIT(TCCR0_reg,COM01);
		#endif
	#elif TMR0_MODE == TMR0_PHASECORRECT
		#if TIMER0_PHASECORRECT_MODE == NON_INVERTONG_MODE
				SET_BIT(TCCR0_reg,WGM00);
				CLR_BIT(TCCR0_reg,WGM01);
				CLR_BIT(TCCR0_reg,COM00);
				SET_BIT(TCCR0_reg,COM01);
		#elif TIMER0_PHASECORRECT_MODE==INVERTING_MODE
				SET_BIT(TCCR0_reg,WGM00);
				CLR_BIT(TCCR0_reg,WGM01);
				SET_BIT(TCCR0_reg,COM00);
				SET_BIT(TCCR0_reg,COM01);
		#endif

	#endif

}
void Timer0_start()
{
	#if PRESCALER_MODE==PRESCALER_8
		CLR_BIT(TCCR0_reg,CS00);
		SET_BIT(TCCR0_reg,CS01);
		CLR_BIT(TCCR0_reg,CS02);
	#elif PRESCALER_MODE==PRESCALER_64
		SET_BIT(TCCR0_reg,CS00);
		SET_BIT(TCCR0_reg,CS01);
		CLR_BIT(TCCR0_reg,CS02);
	#elif PRESCALER_MODE==PRESCALER_256
		CLR_BIT(TCCR0_reg,CS00);
		CLR_BIT(TCCR0_reg,CS01);
		SET_BIT(TCCR0_reg,CS02);
	#elif PRESCALER_MODE==PRESCALER_1024
		SET_BIT(TCCR0_reg,CS00);
		CLR_BIT(TCCR0_reg,CS01);
		SET_BIT(TCCR0_reg,CS02);
	#endif

}

void Timer0_stop()
{
	CLR_BIT(TCCR0_reg,CS00);
	CLR_BIT(TCCR0_reg,CS01);
	CLR_BIT(TCCR0_reg,CS02);

}
/*void set_compare_match(uint8_t comapre)
{
	OCR0_reg=comapre;
}*/
void Timer0_setCallBack(void (*ptrToFun)(void))
{
	if(ptrToFun!=NULL)
	{
		g_ptrToFunOVF=ptrToFun;
	}
}

void Timer0_voidSetDelayCTC(u16 delay_ms)
{
	//make all options of prescaler
	#if PRESCALER_MODE == PRESCALER_8
	CTC_Counter=delay_ms*8;
	#elif PRESCALER_MODE == PRESCALER_64
	CTC_Counter=delay_ms;
	#elif PRESCALER_MODE==PRESCALER_256
	CTC_Counter=delay_ms/4;
	#elif PRESCALER_MODE==PRESCALER_1024
	CTC_Counter=delay_ms/16;
	#endif
}

void Timer0_set_duty_cycleFastPWM(uint8_t d)
{
	if(d <= 100)
	{
	#if TIMER0_FASTPWM_MODE == INVERTING_MODE
	OCR0_reg = 255-(d/100*256);
	#elif TIMER0_FASTPWM_MODE == NON_INVERTONG_MODE
	OCR0_reg = (((d*256)/100))-1;
	#endif
	}
}

void Timer0_set_duty_cyclePhaseCorrect(uint8_t d)
{
	#if TIMER0_PHASECORRECT_MODE == INVERTING_MODE
		d=100-d;
		OCR0_reg=((u16)d*510)/200;
	#elif TIMER0_PHASECORRECT_MODE == NON_INVERTONG_MODE
		OCR0_reg=((u16)d*510)/200;
	#endif
}




void __vector_10(void) __attribute__((signal));
void __vector_10(void)
{
	static u16 counter=0;
		counter++;
		if(counter == Timer0_counter)
		{
		TCNT0_reg=Timer0_PreLoad;
		counter=0;
		if(g_ptrToFunOVF!=NULL){
			g_ptrToFunOVF();}
		}
}


