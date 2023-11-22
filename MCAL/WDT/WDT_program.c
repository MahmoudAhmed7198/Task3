/*
 * WDT_program.c
 *
 *  Created on: Nov 13, 2023
 *      Author: Lenovo
 */

#include"../../Bit_Math.h"
#include"../../Std_Types.h"
#include"WDT_interface.h"
#include"WDT_private.h"


void WDT_Enable (uint8_t overflow_time)
{
	switch(overflow_time)
	{
	case WDT_TIME_16_3:
		CLR_BIT(WDTCR_reg,WDP0);
		CLR_BIT(WDTCR_reg,WDP1);
		CLR_BIT(WDTCR_reg,WDP2);
		break;
	case WDT_TIME_32_3:
		SET_BIT(WDTCR_reg,WDP0);
		CLR_BIT(WDTCR_reg,WDP1);
		CLR_BIT(WDTCR_reg,WDP2);
		break;
	case WDT_TIME_65:
		CLR_BIT(WDTCR_reg,WDP0);
		SET_BIT(WDTCR_reg,WDP1);
		CLR_BIT(WDTCR_reg,WDP2);
		break;
	case WDT_TIME_0_13:
		SET_BIT(WDTCR_reg,WDP0);
		SET_BIT(WDTCR_reg,WDP1);
		CLR_BIT(WDTCR_reg,WDP2);
		break;
	case WDT_TIME_0_26:
		CLR_BIT(WDTCR_reg,WDP0);
		CLR_BIT(WDTCR_reg,WDP1);
		SET_BIT(WDTCR_reg,WDP2);


	}
}
void WDT_Disable()
{

	/* Write logical one to WDTOE and WDE */
	WDTCR_reg = (1<<WDTOE) | (1<<WDE);
	/* Turn off WDT */
	WDTCR_reg = 0x00;
}

