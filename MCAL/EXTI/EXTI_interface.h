/*
 * EXTI_interface.h
 *
 *  Created on: Oct 22, 2023
 *      Author: Lenovo
 */

#ifndef MCAL_EXTI_EXTI_INTERFACE_H_
#define MCAL_EXTI_EXTI_INTERFACE_H_

#include"../../Std_Types.h"

#define EXTI_INT0                     0        //PD2
#define EXTI_INT1                     1        //PD3
#define EXTI_INT2                     2        //PB2

/* Macros For Interrupt Trigger Edge */
#define EXTI_RISING_EDGE              0
#define EXTI_FALLING_EDGE             1
#define EXTI_LOW_LEVEL                2
#define EXTI_ANY_LOGICAL_CHANGE       3

                /*************** APIS PROTOTYPES ***************/
//select Interrupt peripheral(INT0 , INT1 , INT2) and make the sense control bits for it
void EXTI_voidInit           (uint8_t copy_u8InterruptSource, uint8_t copy_u8InterruptTriggerEdge);
void EXTI_voidEnable         (uint8_t copy_u8InterruptSource);
void EXTI_voidDisable        (uint8_t copy_u8InterruptSource);
void EXTI_voidSetCallBackINT0(void (*ptrToFun)(void));
void EXTI_voidSetCallBackINT1(void(*ptrToFun)(void));
void EXTI_voidSetCallBackINT2(void (*ptrToFun)(void));


#endif /* MCAL_EXTI_EXTI_INTERFACE_H_ */
