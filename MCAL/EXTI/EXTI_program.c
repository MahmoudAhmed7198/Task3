/*
 * EXTI_program.c
 *
 *  Created on: Oct 22, 2023
 *      Author: Lenovo
 */

#include"EXTI_interface.h"
#include"EXTI_register.h"
#include"../../Bit_Math.h"
#include"../../Std_Types.h"
#include<avr/interrupt.h>

static void (*prvivate_pCallBackINT0)(void) = NULL;
static void (*prvivate_pCallBackINT1)(void) = NULL;
static void (*prvivate_pCallBackINT2)(void) = NULL;



void EXTI_voidInit(uint8_t copy_u8InterruptSource,
		uint8_t copy_u8InterruptTriggerEdge) {
	switch (copy_u8InterruptSource) {
	case EXTI_INT0:
		switch (copy_u8InterruptTriggerEdge) {
		case EXTI_RISING_EDGE:
			SET_BIT(MCUCR_reg, ISC00);
			SET_BIT(MCUCR_reg, ISC01);
			break;
		case EXTI_FALLING_EDGE:
			CLR_BIT(MCUCR_reg, ISC00);
			SET_BIT(MCUCR_reg, ISC01);
			break;
		case EXTI_LOW_LEVEL:
			CLR_BIT(MCUCR_reg, ISC00);
			CLR_BIT(MCUCR_reg, ISC01);
			break;
		case EXTI_ANY_LOGICAL_CHANGE:
			SET_BIT(MCUCR_reg, ISC00);
			CLR_BIT(MCUCR_reg, ISC01);
			break;
		}
		break;
	case EXTI_INT1:
		switch (copy_u8InterruptTriggerEdge) {
		case EXTI_RISING_EDGE:
			SET_BIT(MCUCR_reg, ISC10);
			SET_BIT(MCUCR_reg, ISC11);
			break;
		case EXTI_FALLING_EDGE:
			CLR_BIT(MCUCR_reg, ISC10);
			SET_BIT(MCUCR_reg, ISC11);
			break;
		case EXTI_LOW_LEVEL:
			CLR_BIT(MCUCR_reg, ISC10);
			CLR_BIT(MCUCR_reg, ISC11);
			break;
		case EXTI_ANY_LOGICAL_CHANGE:
			SET_BIT(MCUCR_reg, ISC10);
			CLR_BIT(MCUCR_reg, ISC11);
			break;
		}
		break;
	case EXTI_INT2:
		switch (copy_u8InterruptTriggerEdge) {
		case EXTI_RISING_EDGE:
			SET_BIT(MCUCSR_reg, ISC2);
			break;
		case EXTI_FALLING_EDGE:
			CLR_BIT(MCUCR_reg, ISC2);
			break;
		}
		break;
	}
}
void EXTI_voidEnable(uint8_t copy_u8InterruptSource) {
	switch (copy_u8InterruptSource) {
	case EXTI_INT0:
		SET_BIT(GICR_reg, INT0);
		break;
	case EXTI_INT1:
		SET_BIT(GICR_reg, INT1);
		break;
	case EXTI_INT2:
		SET_BIT(GICR_reg, INT2);
		break;
	}
}
void EXTI_voidDisable(uint8_t copy_u8InterruptSource) {
	switch (copy_u8InterruptSource) {
	case EXTI_INT0:
		CLR_BIT(GICR_reg, INT0);
		break;
	case EXTI_INT1:
		CLR_BIT(GICR_reg, INT1);
		break;
	case EXTI_INT2:
		CLR_BIT(GICR_reg, INT2);
		break;
	}
}

void EXTI_voidSetCallBackINT0(void (*ptrToFun)(void)) {
	if (ptrToFun != NULL) {
		prvivate_pCallBackINT0 = ptrToFun;
	}
}
void EXTI_voidSetCallBackINT1(void (*ptrToFun)(void)) {
	if (ptrToFun != NULL) {
		prvivate_pCallBackINT1 = ptrToFun;
	}
}
void EXTI_voidSetCallBackINT2(void (*ptrToFun)(void)) {
	if (ptrToFun != NULL) {
		prvivate_pCallBackINT1 = ptrToFun;
	}
}

ISR(INT0_vect) {
	if (prvivate_pCallBackINT0 != NULL) {
		prvivate_pCallBackINT0();
	}
}
ISR(INT1_vect) {
	// Call Action
	if (prvivate_pCallBackINT1 != NULL) {
		(*prvivate_pCallBackINT1)();
	}
}
ISR(INT2_vect) {
	if (prvivate_pCallBackINT2 != NULL) {
		prvivate_pCallBackINT2();
	}
}

