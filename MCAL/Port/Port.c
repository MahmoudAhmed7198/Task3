/*
 * Port.c
 *
 *  Created on: Oct 22, 2023
 *      Author: Lenovo
 */
#include"Port.h"
#include"Port_Cfg.h"
#include"../../Bit_Math.h"
#include<avr/io.h>
extern PinCfg pfg[MAX_ACTIVATED_PINS];
void PortInit()
{
	int i=0;
	for(i=0;i<32;i++)
	{
		//if(pfg[i].port==-1)break;
		switch(pfg[i].port)
		{
		case Dio_PORTA:
			if(pfg[i].dir==OUTPUT)
			SET_BIT(DDRA,pfg[i].pin);
			else
				CLR_BIT(DDRA,pfg[i].pin);
			break;
		case Dio_PORTB:
			if(pfg[i].dir==OUTPUT)
			SET_BIT(DDRB,pfg[i].pin);
			else
				CLR_BIT(DDRB,pfg[i].pin);
			break;
		case Dio_PORTC:
			if(pfg[i].dir==OUTPUT)
			SET_BIT(DDRC,pfg[i].pin);
			else
				CLR_BIT(DDRC,pfg[i].pin);
			break;
		case Dio_PORTD:
			if(pfg[i].dir==OUTPUT)
			SET_BIT(DDRD,pfg[i].pin);
			else
				CLR_BIT(DDRD,pfg[i].pin);
			break;

		}
	}
}


