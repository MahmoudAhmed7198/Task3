/*
 * Timer2_program.c
 *
 *  Created on: Oct 25, 2023
 *      Author: Lenovo
 */

#include"../../Bit_Math.h"
#include"../../Std_Types.h"
#include"Timer2_register.h"
#include"Timer2_interface.h"
#include"Timer2_cfg.h"
#include"Timer2_private.h"
static void (*g_ptrToFun)(void)=NULL;
static void (*g_ptrToFunCTC)(void)=NULL;

//delay static that calculate number of overflows or number of interrupts
volatile static u16 CTC_Counter;
void Timer2_init()
{
	//configure timer2 in normal mode and enable PIE
	#if TIMER2_MODE == TIMER2_OVF_MODE
	SET_BIT(TCCR2_reg,FOC2);
	CLR_BIT(TCCR2_reg,WGM20);
	CLR_BIT(TCCR2_reg,WGM21);
	SET_BIT(TIMSK_reg,TOIE2);
	TCNT2_reg=TIMER2_PRELOAD;
	#elif TIMER2_MODE == TIMER2_CTC_MODE
	//configure timer2 in CTC mode and enable PIE
	SET_BIT(TCCR2_reg,FOC2);
	CLR_BIT(TCCR2_reg,WGM20);
	SET_BIT(TCCR2_reg,WGM21);
	SET_BIT(TIMSK_reg,OCIE2);
	//configure timer2 in Fast PWM
	#elif TIMER2_MODE == TIMER2_FASTPWM
		#if TIMER2_FASTPWM_MODE==NON_INVERTONG_MODE
			SET_BIT(TCCR2_reg,WGM20);
			SET_BIT(TCCR2_reg,WGM21);
			CLR_BIT(TCCR2_reg,COM20);
			SET_BIT(TCCR2_reg,COM21);
		#elif TIMER2_FASTPWM_MODE==INVERTING_MODE
			SET_BIT(TCCR2_reg,WGM20);
			SET_BIT(TCCR2_reg,WGM21);
			SET_BIT(TCCR2_reg,COM20);
			SET_BIT(TCCR2_reg,COM21);
		#endif
	#elif TIMER2_MODE == TIMER2_PHASECORRECT
		#if TIMER2_PHASECORRECT_MODE==NON_INVERTONG_MODE
			SET_BIT(TCCR2_reg,WGM20);
			CLR_BIT(TCCR2_reg,WGM21);
			CLR_BIT(TCCR2_reg,COM20);
			SET_BIT(TCCR2_reg,COM21);
		#elif TIMER2_PHASECORRECT_MODE==INVERTING_MODE
			SET_BIT(TCCR2_reg,WGM20);
			CLR_BIT(TCCR2_reg,WGM21);
			SET_BIT(TCCR2_reg,COM20);
			SET_BIT(TCCR2_reg,COM21);
		#endif
	//configure timer2 in Phase correct
	#endif

}
void Timer2_startTimer()
{
	//configure prescaler to be 64
#if   PRESCALER_MODE==PRESCALER_8
	   CLR_BIT(TCCR2_reg,CS20);
	   SET_BIT(TCCR2_reg,CS21);
	   SET_BIT(TCCR2_reg,CS22);
#elif  PRESCALER_MODE==PRESCALER_32
	   SET_BIT(TCCR2_reg,CS20);
	   SET_BIT(TCCR2_reg,CS21);
	   CLR_BIT(TCCR2_reg,CS22);
#elif  PRESCALER_MODE==PRESCALER_64
	   CLR_BIT(TCCR2_reg,CS20);
	   CLR_BIT(TCCR2_reg,CS21);
	   SET_BIT(TCCR2_reg,CS22);
#elif PRESCALER_MODE==PRESCALER_128
	   SET_BIT(TCCR2_reg,CS20);
	   CLR_BIT(TCCR2_reg,CS21);
	   SET_BIT(TCCR2_reg,CS22);
#elif PRESCALER_MODE==PRESCALER_256
	   CLR(TCCR2_reg,CS20);
	   SET_BIT(TCCR2_reg,CS21);
	   SET_BIT(TCCR2_reg,CS22);
#elif PRESCALER_MODE==PRESCALER_1024
	   SET_BIT(TCCR2_reg,CS20);
	   SET_BIT(TCCR2_reg,CS21);
	   SET_BIT(TCCR2_reg,CS22);
#endif

}
void Timer2_stopTimer()
{
	CLR_BIT(TCCR2_reg,CS20);
	CLR_BIT(TCCR2_reg,CS21);
	CLR_BIT(TCCR2_reg,CS22);
}

void set_callBackOVF(void (*ptrToFun)(void))
{
	if(*ptrToFun!=NULL)
	{
		g_ptrToFun=ptrToFun;
	}
}

void set_callBackCTC(void (*ptrToFun)(void))
{
	if(ptrToFun!=NULL)
	{
		g_ptrToFunCTC=ptrToFun;
	}

}
/*void set_compare_value()
{
	OCR2_reg=128;
}*/
//this function under condition that tick time=4us and OCR=249
void set_delay_usingCTC(u16 delay_ms)
{
	#if PRESCALER_MODE==PRESCALER_8
	CTC_Counter=delay_ms*8;
	#elif PRESCALER_MODE==PRESCALER_32
	CTC_Counter=delay_ms*2;
	#elif PRESCALER_MODE == PRESCALER_64
	CTC_Counter=delay_ms;
	#elif PRESCALER_MODE==PRESCALER_128
	CTC_Counter=delay_ms/2;
	#elif PRESCALER_MODE==PRESCALER_256
	CTC_Counter=delay_ms/4;
	#elif PRESCALER_MODE==PRESCALER_1024
	CTC_Counter=delay_ms/16;
	#endif
}
void set_duty_cycleUsingFastPWM(uint8_t duty_cycle)//range of duty_cycle is from 0 to 100
{
	if(duty_cycle<=100)
	{
	#if TIMER2_FASTPWM_MODE==NON_INVERTONG_MODE
	OCR2_reg=(((u16)duty_cycle*256)/100)-1;
	#elif TIMER2_FASTPWM_MODE==INVERTING_MODE
	duty_cycle=100-duty_cycle;
	OCR2_reg=(((u16)duty_cycle*256)/100)-1;
	#endif
	}
}
void set_duty_cycleUsingPhaseCorrect(uint8_t duty)
{
	if(duty<=100)
	{
		#if TIMER2_PHASECORRECT_MODE==NON_INVERTONG_MODE
		OCR2_reg=((u16)duty*510)/200;
	    #elif TIMER2_PHASECORRECT_MODE==INVERTING_MODE
		duty=100-duty;
		OCR2_reg=((u16)duty*510)/200;
		#endif

	}
}


void __vector_5(void) __attribute__((signal));
void __vector_5(void)
{
	static u16 counter=0;
	counter++;
	if(counter==TIMER2_OVF_COUNTER)
	{
		TCNT2_reg=TIMER2_PRELOAD;
		counter=0;
		if(g_ptrToFun!=NULL)
			g_ptrToFun();
	}
}

void __vector_4(void) __attribute__((signal));
void __vector_4(void)
{
	static u16 counter=0;
	counter++;
	if(counter==CTC_Counter)
	{
		counter=0;
		if(g_ptrToFunCTC!=NULL)
		{
			g_ptrToFunCTC();
		}
	}
}





