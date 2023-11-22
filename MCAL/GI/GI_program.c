/*
 * GI_program.c
 *
 *  Created on: Oct 23, 2023
 *      Author: Lenovo
 */
#include"GI_interface.h"
#include"GI_register.h"
#include"../../Bit_Math.h"
void enable_global_int()
{
	SET_BIT(SREG_reg,I_bit);
}
void disable_global_int()
{
	CLR_BIT(SREG_reg,I_bit);
}

