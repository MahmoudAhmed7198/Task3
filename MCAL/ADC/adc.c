/*
 * adc.c
 *
 *  Created on: Oct 27, 2023
 *      Author: Lenovo
 */
#include"adc.h"
#include<avr/io.h>


/*******************************************************************************
 *                          Functions Definitions                              *
 *******************************************************************************/

void ADC_init(void)
{
	/* ADMUX Register Bits Description:
	 * REFS1:0 = 00 to choose to connect external reference voltage by input this voltage through AREF pin
	 * ADLAR   = 0 right adjusted
	 * MUX4:0  = 00000 to choose channel 0 as initialization
	 */
	ADMUX_reg = 0;

	//frequency range of ADC 50KHZ to 200KHZ
	//FCPU=16MHZ,,prescaler=128  ADC_frequecncy=125KHZ between range
	#if ADC_PRESCALER == PRESCALER_1
		SET_BIT(ADCSRA_reg,ADPS0);
		CLR_BIT(ADCSRA_reg,ADPS1);
		CLR_BIT(ADCSRA_reg,ADPS2);
	#elif ADC_PRESCALER == PRESCALER_128
		SET_BIT(ADCSRA_reg,ADPS0);
		SET_BIT(ADCSRA_reg,ADPS1);
		SET_BIT(ADCSRA_reg,ADPS2);
	#endif
		//enable ADC
		SET_BIT(ADCSRA_reg,ADEN);
}

u16 ADC_ReadChannel(uint8_t channel){
	channel &= 0x07; /* channel number must be from 0 --> 7 */
	ADMUX_reg &= 0xE0; /* clear first 5 bits in the ADMUX (channel number MUX4:0 bits) before set the required channel */
	ADMUX_reg = ADMUX_reg | channel; /* choose the correct channel by setting the channel number in MUX4:0 bits */
	SET_BIT(ADCSRA_reg,ADSC); /* start conversion write '1' to ADSC */
	while(BIT_IS_CLEAR(ADCSRA_reg,ADIF)); /* wait for conversion to complete ADIF becomes '1' */
	SET_BIT(ADCSRA_reg,ADIF); /* clear ADIF by write '1' to it :) */
	return ADC; /* return the data register */
}





